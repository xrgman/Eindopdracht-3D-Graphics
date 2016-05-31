#include <iostream>
#include <fstream>
#include <algorithm>

#include "Model.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"

std::string replace(std::string str, std::string toReplace, std::string replacement) {
	size_t index = 0;
	while (true) {
		index = str.find(toReplace, index);
		if (index == std::string::npos)
			break;
		str.replace(index, toReplace.length(), replacement);
		++index;
	}
	return str;
}

std::vector<std::string> split(std::string str, std::string sep) {
	std::vector<std::string> ret;
	size_t index;
	while (true) {
		index = str.find(sep);
		if (index == std::string::npos)
			break;
		ret.push_back(str.substr(0, index));
		str = str.substr(index + 1);
	}
	ret.push_back(str);
	return ret;
}

inline std::string toLower(std::string data) {
	std::transform(data.begin(), data.end(), data.begin(), ::tolower);
	return data;
}

Model::Texture::Texture(const std::string & fileName)
{
	int bpp;
	stbi_set_flip_vertically_on_load(true);
	char* imgData = (char*)stbi_load(fileName.c_str(), &width, &height, &bpp, 4);

	if (!imgData)
		std::cout << stbi_failure_reason() << "nooo" << std::endl;
	glGenTextures(1, &textureID);
	glBindTexture(GL_TEXTURE_2D, textureID);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, imgData);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	stbi_image_free(imgData);
}

void Model::Texture::bind()
{
	glBindTexture(GL_TEXTURE_2D, textureID);
}

Model::MaterialInfo::MaterialInfo()
{
	hasTexture = false;
}

Model::Vec::Vec(float x, float y, float z, float nx, float ny, float nz, float tx, float ty)
{
	this->x = x;
	this->y = y;
	this->z = z;
	this->normalx = nx;
	this->normaly = ny;
	this->normalz = nz;
	this->texcoordx = tx;
	this->texcoordy = ty;
}

Model::Vec::~Vec()
{
}

void Model::loadMaterialFile(std::string fileName, std::string dirName)
{
	std::ifstream pFile(fileName.c_str());
	if (!pFile.is_open()) {
		std::cout << "Could not open file " << fileName << std::endl;
		return;
	}

	MaterialInfo *currentMaterial = NULL;

	while (!pFile.eof()) {
		std::string line;
		std::getline(pFile, line);

		line = replace(line, "\t", " ");
		while (line.find("  ") != std::string::npos)
			line = replace(line, "  ", " ");
		if (line == "")
			continue;
		if (line[0] == ' ')
			line = line.substr(1);
		if (line == "")
			continue;
		if (line[line.length() - 1] == ' ')
			line = line.substr(0, line.length() - 1);
		if (line == "")
			continue;
		if (line[0] == '#')
			continue;

		std::vector<std::string> params = split(line, " ");
		params[0] = toLower(params[0]);
		if (params[0] == "newmtl") {
			if (currentMaterial != NULL) {
				materials.push_back(currentMaterial);
			}
			currentMaterial = new MaterialInfo();
			currentMaterial->name = params[1];
		}
		else if (params[0] == "map_kd") {
			currentMaterial->hasTexture = true;
			currentMaterial->texture = new Texture(dirName + "/" + params[1]);
			std::cout << "Made material named " << params[1] << std::endl;
		}
		else
			std::cout << "Didn't parse " << params[0] << " in material file" << std::endl;
	}
	if (currentMaterial != NULL)
		materials.push_back(currentMaterial);
}

Model::Model(std::string fileName)
{
	std::string dirName = fileName;
	if (dirName.rfind("/") != std::string::npos)
		dirName = dirName.substr(0, dirName.rfind("/"));
	if (dirName.rfind("\\") != std::string::npos)
		dirName = dirName.substr(0, dirName.rfind("\\"));
	if (fileName == dirName)
		dirName = "";


	std::ifstream pFile(fileName.c_str());

	if (!pFile.is_open()) {
		std::cout << "Could not open file " << fileName << std::endl;
		return;
	}

	ObjGroup *currentGroup = new ObjGroup();
	currentGroup->materialIndex = -1;

	while (!pFile.eof()) {
		std::string line;
		std::getline(pFile, line);

		line = replace(line, "\t", " ");
		while (line.find("  ") != std::string::npos)
			line = replace(line, "  ", " ");
		if (line == "")
			continue;
		if (line[0] == ' ')
			line = line.substr(1);
		if (line == "")
			continue;
		if (line[line.length() - 1] == ' ')
			line = line.substr(0, line.length() - 1);
		if (line == "")
			continue;
		if (line[0] == '#')
			continue;

		std::vector<std::string> params = split(line, " ");
		params[0] = toLower(params[0]);

		if (params[0] == "v")
			vertices.push_back(new Vec3f((float)atof(params[1].c_str()), (float)atof(params[2].c_str()),
				(float)atof(params[3].c_str())));
		else if (params[0] == "vn")
			normals.push_back(new Vec3f((float)atof(params[1].c_str()), (float)atof(params[2].c_str()),
				(float)atof(params[3].c_str())));
		else if (params[0] == "vt")
			texcoords.push_back(new Vec2f((float)atof(params[1].c_str()), (float)atof(params[2].c_str())));
		else if (params[0] == "f") {
			for (size_t ii = 4; ii <= params.size(); ii++) {
				Face face;

				for (size_t i = ii - 3; i < ii; i++)    //magische forlus om van quads triangles te maken ;)
				{
					Vertex vertex;
					std::vector<std::string> indices = split(params[i == (ii - 3) ? 1 : i], "/");
					if (indices.size() >= 1)    //er is een positie
						vertex.position = atoi(indices[0].c_str()) - 1;
					if (indices.size() == 2)        //alleen texture
						vertex.texcoord = atoi(indices[1].c_str()) - 1;
					if (indices.size() == 3)        //v/t/n of v//n
					{
						if (indices[1] != "")
							vertex.texcoord = atoi(indices[1].c_str()) - 1;
						vertex.normal = atoi(indices[2].c_str()) - 1;
					}
					face.vertices.push_back(vertex);
				}
				currentGroup->faces.push_back(face);
			}
		}
		else if (params[0] == "s") {//smoothing
		}
		else if (params[0] == "mtllib") {
			loadMaterialFile(dirName + "/" + params[1], dirName);
		}
		else if (params[0] == "usemtl") {
			if (currentGroup->faces.size() != 0)
				groups.push_back(currentGroup);
			currentGroup = new ObjGroup();
			currentGroup->materialIndex = -1;

			for (size_t i = 0; i < materials.size(); i++) {
				MaterialInfo *info = materials[i];
				if (info->name == params[1]) {
					currentGroup->materialIndex = i;
					break;
				}
			}
			if (currentGroup->materialIndex == -1)
				std::cout << "Could not find material name " << params[1] << std::endl;
		}
	}
	groups.push_back(currentGroup);

	//Turning to vec:
	for (ObjGroup *group : groups) {
		for (Face &face : group->faces) {
			for (auto &vertex : face.vertices) {
				group->vecs.push_back(Vec(vertices[vertex.position]->x, vertices[vertex.position]->y, vertices[vertex.position]->z, normals[vertex.normal]->x, normals[vertex.normal]->y, normals[vertex.normal]->z, texcoords[vertex.texcoord]->x, texcoords[vertex.texcoord]->y));
			}
		}
	}
}

Model::~Model(void)
{
}


void Model::draw()
{
	glPushMatrix();
	for (auto group : groups) {
		ObjGroup gr = *group;

		if (materials[gr.materialIndex]->hasTexture) {
			glEnable(GL_TEXTURE_2D);
			materials[gr.materialIndex]->texture->bind();
		}

		glEnableClientState(GL_VERTEX_ARRAY);
		glEnableClientState(GL_NORMAL_ARRAY);
		glEnableClientState(GL_TEXTURE_COORD_ARRAY);

		glVertexPointer(3, GL_FLOAT, sizeof(Vec), ((float*)gr.vecs.data()));
		glNormalPointer(GL_FLOAT, sizeof(Vec), ((float*)gr.vecs.data()) + 3);
		glTexCoordPointer(2, GL_FLOAT, sizeof(Vec), ((float*)gr.vecs.data()) + 6);
		glDrawArrays(GL_TRIANGLES, 0, gr.vecs.size());

		glDisableClientState(GL_VERTEX_ARRAY);
		glDisableClientState(GL_NORMAL_ARRAY);
		glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	}
	glPopMatrix();
}



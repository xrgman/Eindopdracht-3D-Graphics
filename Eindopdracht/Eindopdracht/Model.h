#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <list>
#include <windows.h>
#include "GL\freeglut.h"
#include "Vec2f.h"
#include "Vec3f.h"

using namespace std;

class Model {
	private:
		class Vertex {
			public:
				int position;
				int normal;
				int texcoord;
		};

		class Face {
			public:
				list<Vertex> vertices;
		};

		class Texture {
			private:
				GLuint textureID;
				int width, height;
			public:
				Texture(const std::string &fileName);
				void bind();
		};

		class MaterialInfo {
			public:
				MaterialInfo();
				string name;
				Texture *texture;
				bool hasTexture;
		};

		class Vec {
			public:
				float x;
				float y;
				float z;
				float normalx;
				float normaly;
				float normalz;
				float texcoordx;
				float texcoordy;
				Vec(float, float, float, float, float, float, float, float);
		};

		class ObjGroup {
			public:
				string name;
				int materialIndex;
				list<Face> faces;
				vector<Vec> vecs; 
		};

		std::vector<Vec3f *> vertices;
		std::vector<Vec3f *> normals;
		std::vector<Vec2f *> texcoords;
		std::vector<ObjGroup *> groups;
		std::vector<MaterialInfo *> materials;


		void loadMaterialFile(std::string fileName, std::string dirName);

	public:
		Model(std::string filename);
		void draw();
};
#endif

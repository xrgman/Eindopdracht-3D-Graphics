#ifndef MODEL_H
#define MODEL_H

#include <string>
#include <vector>
#include <list>
#include <windows.h>
#include "GL\freeglut.h"
#include "Vec2f.h"
#include "Vec3f.h"
#include "Texture.h"

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
				~Vec();
		};

		class ObjGroup {
			public:
				string name;
				int materialIndex;
				list<Face> faces;
				vector<Vec> vecs; 
		};

		std::vector<Vec3f > vertices;
		std::vector<Vec3f > normals;
		std::vector<Vec2f > texcoords;
		std::vector<ObjGroup *> groups;
		std::vector<MaterialInfo *> materials;


		void loadMaterialFile(std::string fileName, std::string dirName);

	public:
		Model(std::string filename);
		~Model(void);
		void draw();

		Vec3f minVertex;
		Vec3f maxVertex;
		Vec3f center;
		float radius;
};
#endif

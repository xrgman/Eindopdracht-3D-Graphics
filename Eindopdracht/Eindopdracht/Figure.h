#ifndef FIGURE_H
#define FIGURE_H

#include <vector>

class Figure {
	public:
		virtual void Draw() = 0;
	protected:
		virtual void Intialize() = 0;
		Figure() {  }
		struct Vertex
		{
			float x, y, z;
			float nx, ny, nz;
			float r, g, b, a;
		};
		std::vector<Vertex> vertices;
};
#endif

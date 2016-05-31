#ifndef CUBE_H
#define CUBE_H

#include <vector>
#include "Figure.h"

class Cube : public Figure {
	public:
		// Inherited via Figure
		virtual void Draw() override;
		Cube();
		~Cube();
	private:
		virtual void Intialize() override;
};
#endif

#include "Vec2f.h"

Vec2f::Vec2f() {
	this->x = 0;
	this->y = 0;
}

Vec2f::Vec2f(float x, float y) {
	this->x = x;
	this->y = y;
}

Vec2f::Vec2f(Vec2f &other) {
	this->x = other.x;
	this->y = other.y;
}

float &Vec2f::operator[](int index) {
	return v[index];
}
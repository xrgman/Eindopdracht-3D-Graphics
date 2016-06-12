#include "Vec3f.h"

Vec3f::Vec3f()
{
	this->x = 0;
	this->y = 0;
	this->z = 0;
}

Vec3f::Vec3f(Vec3f & other)
{
	this->x = other.x;
	this->y = other.y;
	this->z = other.z;
}

Vec3f::Vec3f(float x, float y, float z)
{
	this->x = x;
	this->y = y;
	this->z = z;
}

float & Vec3f::operator[](int index)
{
	return v[index];
}

Vec3f Vec3f::operator+(const Vec3f & other)
{
	return Vec3f(x + other.x, y + other.y, z + other.z);
}

Vec3f Vec3f::operator/(float value)
{
	return Vec3f(x/value,y/value,z/value);
}

#ifndef VEC3F_H
#define VEC3F_H

class Vec3f {
	public:
		union {
			struct {
				float x, y, z;
			};
			float v[3];
		};
		Vec3f();
		Vec3f(Vec3f &other);
		Vec3f(float x, float y, float z);
		float &operator[](int);
};

#endif

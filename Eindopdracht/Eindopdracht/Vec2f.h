#ifndef VEC2F_H
#define VEC2F_H

class Vec2f {
	public:
		union {
			struct {
				float x, y;
			};
			float v[2];
		};
		Vec2f();
		Vec2f(float x, float y);
		Vec2f(Vec2f &other);
		float &operator[](int);
};
#endif

#ifndef CAMERA_H
#define CAMERA_H

class Camera {
	public:
		float posX = 0;
		float posY = 0;
		float posZ = 0;
		float rotX = 0;
		float rotY = 0;
		int width, height = 0;
		void move(float angle, float fac);
};

#endif

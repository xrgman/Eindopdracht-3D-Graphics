#include "Camera.h"
#define _USE_MATH_DEFINES
#include <cmath>

void Camera::move(float angle, float fac)
{
	posX += (float)cos((rotY + angle) / 180 * M_PI) * fac;
	posY += (float)sin((rotY + angle) / 180 * M_PI) * fac;
}

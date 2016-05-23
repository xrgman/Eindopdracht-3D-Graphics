#include <windows.h>
#include "GL\freeglut.h"
#include "GameStateManager.h"
#include "Camera.h"

GameStateManager gameManager;
Camera camera;
bool keys[255];
bool specialKeys[109];


void onDisplay() {
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.0f, (float)camera.width / camera.height, 0.1, 50);

	glMatrixMode(GL_MODELVIEW);

	glLoadIdentity();
	glTranslatef(camera.posX, -camera.posY, 0);
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);

	glPushMatrix();
	glBegin(GL_QUADS);
	glVertex3f(-15, -1, -15);
	glVertex3f(15, -1, -15);
	glVertex3f(15, -1, 15);
	glVertex3f(-15, -1, 15);
	glEnd();
	glPopMatrix();
	
	glColor3f(1.0f, 1.0f, 1.0f);
	gameManager.Draw();

	glutSwapBuffers();
}

void onIdle() {
	glutPostRedisplay();
}

void onKeyboard(unsigned char key, int x, int y) {
	if (key == 27)
		exit(0);
	keys[key] = true;
	gameManager.HandleEvents(keys, specialKeys);
}

void onKeyboardUp(unsigned char key, int x, int y) {
	keys[key] = false;
	gameManager.HandleEvents(keys, specialKeys);
}

void onKeyboardSpecial(int key, int x, int y) {
	specialKeys[key] = true;
	gameManager.HandleEvents(keys, specialKeys);
}

void onKeyboardSpecialUp(int key, int x, int y) {
	specialKeys[key] = false;
	gameManager.HandleEvents(keys, specialKeys);
}

void onMousePassiveMotion(int x, int y) {
	int dx = x - camera.width / 2;
	int dy = y - camera.height / 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
	{
		camera.rotX += dy / 10.0f;
		if (camera.rotX > 30) {
			camera.rotX = 30;
		}
		else if (camera.rotX < -30) {
			camera.rotX = -30;
		}
		camera.rotY += dx / 10.0f;
		glutWarpPointer(camera.width / 2, camera.height / 2);
	}
}

void onTimer(int id) {
	gameManager.Update();
	glutTimerFunc(1000 / 60, onTimer, 1);
}


int main(int argc, char* argv[]) {
	gameManager = GameStateManager();
	gameManager.Init(&camera);

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(1920, 1080); //Apperently my laptop needs this...
	glutCreateWindow("Eindopdracht");

	glEnable(GL_DEPTH_TEST);
	glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);

	//Set functions:
	glutIdleFunc(onIdle);
	glutDisplayFunc(onDisplay);
	glutReshapeFunc([](int w, int h) { camera.width = w; camera.height = h; glViewport(0, 0, w, h); });
	glutKeyboardFunc(onKeyboard);
	glutTimerFunc(1000 / 60, onTimer, 1);
	glutKeyboardUpFunc(onKeyboardUp);
	glutSpecialFunc(onKeyboardSpecial);
	glutSpecialUpFunc(onKeyboardSpecialUp);
	glutPassiveMotionFunc(onMousePassiveMotion);

	glutWarpPointer(camera.width / 2, camera.height / 2); //Center mouse

	memset(keys, 0, sizeof(keys));
	memset(specialKeys, 0, sizeof(specialKeys));

	glutMainLoop();
}
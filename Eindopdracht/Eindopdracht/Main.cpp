#include <windows.h>
#include "GL\freeglut.h"
#include "GameStateManager.h"
#include "Camera.h"
#include <vector>
#include "Model.h"
#include "ModelLoader.h"

GameStateManager gameManager;
Camera camera;
int width, height;
bool keys[255];
bool specialKeys[255];


void onDisplay() {
	glClearColor(0.6f, 0.6f, 1, 1);
	glClear(GL_DEPTH_BUFFER_BIT | GL_COLOR_BUFFER_BIT);

	//Setting Perspective:
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(60.0f, (float)width / height, 0.1, 30);

	//Setting camera:
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(camera.rotX, 1, 0, 0);
	glRotatef(camera.rotY, 0, 1, 0);
	glTranslatef(camera.posX, camera.posZ, camera.posY);

	//Setting light:
	float pos[4] = { 0.5, 1, -1, 0 };
	glLightfv(GL_LIGHT0, GL_POSITION, pos);

	//Draw the game state:
	gameManager.Draw();
	
	glFlush();
	
	glutSwapBuffers();
}

void onIdle() {
	gameManager.Idle();
	
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
	int dx = x - width / 2;
	int dy = y - height / 2;
	int camDY = y - camera.height / 2;
	if ((dx != 0 || dy != 0) && abs(dx) < 400 && abs(dy) < 400)
	{
		camera.rotY += dx / 10.0f;
		camera.rotX += dy / 10.0f;
		glutWarpPointer(width / 2, height / 2);
	}
}

void onTimer(int id) {
	gameManager.Update();
	glutPostRedisplay();
	glutTimerFunc(1000 / 60, onTimer, 1);
}

int main(int argc, char* argv[]) {
	gameManager = GameStateManager();
	gameManager.Init(&camera);

	width = 1920;
	height = 1080;

	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
	glutInit(&argc, argv);
	glutInitWindowSize(width, height); //Apperently my laptop needs this...
	glutCreateWindow("Eindopdracht");
	
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);

	glutFullScreen();
	glutSetCursor(GLUT_CURSOR_NONE);

	//Set functions:
	glutIdleFunc(onIdle);
	glutDisplayFunc(onDisplay);
	glutReshapeFunc([](int w, int h) { width = w; height = h; glViewport(0, 0, w, h); });
	glutKeyboardFunc(onKeyboard);
	glutTimerFunc(1000 / 60, onTimer, 1);
	glutKeyboardUpFunc(onKeyboardUp);
	glutSpecialFunc(onKeyboardSpecial);
	glutSpecialUpFunc(onKeyboardSpecialUp);
	glutPassiveMotionFunc(onMousePassiveMotion);

	glutWarpPointer(width / 2, height / 2); //Center mouse

	memset(keys, 0, sizeof(keys));
	memset(specialKeys, 0, sizeof(specialKeys));

	gameManager.getModelLoader()->loadModels();
	gameManager.getTextureLoader()->loadTextures();

	glutMainLoop();
}
// Make sure to run in c++11
#include <iostream>
#include <cmath>

#if defined WIN32
#include <freeglut.h>
#elif defined __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/freeglut.h>
#endif

void reset(void);
void appMotionFunc(int mX, int mY);
void key(unsigned char key, int x, int y);
void inititialization(void);
void display(void);
void clear(void);
void action(int id);
void color(int id);

struct coords {
	float cX;
	float cY;
};

auto windowHeight = 500, windowWidth = 500, bSize = 6;
GLfloat R = 1.0, G = 1.0, B = 1.0;
auto count = 0;
struct coords coordinates[3];

void reset(void) {
	for (auto i = 0; i < 3; ++i) {
		coordinates[i].cX = 0.0;
		coordinates[i].cY = 0.0;
	}
}

void appMotionFunc(int mx, int my) {
	glColor3f(R, G, B);
	GLint x = mx;
	GLint y = windowHeight - my;
	glRecti(x, y, x + bSize, y + bSize);
	glRecti(x, y, x + bSize, y + bSize);
	glFlush();
}
    
void display(void) {
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void key(unsigned char key, int x, int y) {
	switch(key) {
		case 'a':
			glClear(GL_COLOR_BUFFER_BIT);
			glFlush();
			break;
		case 'b':
			exit(-1);
		default:
			break;
	}
}

void appDrawScene(void) {
	glMatrixMode(GL_MODELVIEW);
	glViewport(0, 0, windowWidth, windowHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0.0, windowWidth, 0.0, windowHeight,  -1.0, 1.0);
	clear();
}

void clear(void) {
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);
	glFlush();
}

void action(int id) {
	if (id == 1) {
		clear();
	} else if (id == 6) {
		R = 1.0;
		G = 1.0;
		B = 1.0;
	} else {
		exit(1);
	}
}

void color(int id) {
	switch (id) {
		case 1:
			R = 1.0;
			G = 0.0;
			B = 0.0;
			break;
		case 2:
			R = 0.0;
			G = 1.0;
			B = 0.0;
			break;
		case 3:
			R = 0.0;
			G = 0.0;
			B = 1.0;
			break;
		case 4:
			R = 1.0;
			G = 0.0;
			B = 1.0; 
			break;
		default:
			break;

	}
}

int main(int argc, char **argv) {
	glutInit(&argc, argv);
	glutInitWindowSize(windowHeight,windowWidth);
	glutCreateWindow("Paint Application");
	glutDisplayFunc(display);
	glutKeyboardFunc(key);
	glutMotionFunc(appMotionFunc);
	appDrawScene();
	auto define = [&](void) {
		auto colorMenuHandle = glutCreateMenu(color);
		glutAddMenuEntry("Red",     1);
		glutAddMenuEntry("Green",   2);
		glutAddMenuEntry("Blue",    3);
		glutAddMenuEntry("Purple",  4);
		glutCreateMenu(action);
		glutAddSubMenu("Color", colorMenuHandle);
		glutAddMenuEntry("Clear Page", 1);
		glutAddMenuEntry("Eraser", 6);
		glutAddMenuEntry("Quit",  2);
		glutAttachMenu(GLUT_RIGHT_BUTTON);
	};
	define();
	glutMainLoop();
}

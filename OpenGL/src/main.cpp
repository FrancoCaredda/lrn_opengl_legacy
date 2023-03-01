#include <freeglut.h>

#include <iostream>

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glBegin(GL_TRIANGLES);
	glVertex2f(-1.0, -1.0);
	glVertex2f(0.0, 1.0);
	glVertex2f(1.0, -1.0);
	glEnd();
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// Initialize glut
	glutInit(&argc, argv);

	// Initialize and create window
	glutInitDisplayMode(GLUT_RGB);
	glutInitWindowPosition(450, 450);
	glutInitWindowSize(600, 480);
	int windowHandle = glutCreateWindow("Hello world!");
	glutDisplayFunc(&Draw);
	glutMainLoop();

	glutDestroyWindow(windowHandle);

	return 0;
}

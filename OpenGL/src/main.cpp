#include <freeglut.h>
#include <cstring>

#include <iostream>
#include <stb_image.h>

float verteciesRect[] = {
	-0.50f,  -0.50f,	1.0f, 0.0f, 0.0f,
	-0.50f,  -0.25f,	0.0f, 1.0f, 0.0f,
	-0.25f,  -0.50f,	0.0f, 0.0f, 1.0f,
	-0.25f,  -0.25f,	1.0f, 1.0f, 0.0f
};

uint32_t rectIndecies[] = {
	0, 1, 2, 2, 1, 3
};

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);
	glVertexPointer(2, GL_FLOAT, 5 * sizeof(float), verteciesRect);


	// Drawing coordinate system
	glBegin(GL_LINES);
	glVertex2f(0.0f, -1.0f);
	glVertex2f(0.0f,  1.0f);


	glVertex2f(-1.0f, 0.0f);
	glVertex2f( 1.0f,  0.0f);
	glEnd();

	// Drawing the original rectangle
	glDrawElements(GL_TRIANGLES, sizeof(rectIndecies) / sizeof(uint32_t), GL_UNSIGNED_INT, rectIndecies);

	// Drawing transformed rectangle
	glMatrixMode(GL_MODELVIEW);
	glPushMatrix();

	glRotatef(180.0, 0.0, 0.0, 1.0);

	glEnableClientState(GL_COLOR_ARRAY);
	glColorPointer(3, GL_FLOAT, 5 * sizeof(float), &verteciesRect[2]);
	glDrawElements(GL_TRIANGLES, sizeof(rectIndecies) / sizeof(uint32_t), GL_UNSIGNED_INT, rectIndecies);

	glPopMatrix();

	glDisableClientState(GL_COLOR_ARRAY);
	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// Initialize glut
	glutInit(&argc, argv);

	// Initialize and create window
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(450, 450);
	glutInitWindowSize(600, 480);

	int windowHandle = glutCreateWindow("Hello world!");

	if (windowHandle <= 0) 
	{
		std::cout << "The main window wasn\'t created!";
		return -2;
	}

	glutDisplayFunc(&Draw);
	glutMainLoop();

	glutDestroyWindow(windowHandle);

	return 0;
}

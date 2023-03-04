#include <freeglut.h>

#include <iostream>

float verteciesRect[] = {
	-0.50f,  -0.50f,
	-0.50f,  -0.25f,
	-0.25f,  -0.50f,
	-0.25f,  -0.25f
};

uint32_t rectIndecies[] = {
	0, 1, 2, 2, 1, 3
};

float verteciesTriangle[] = {
	0.25f, -0.50f,
	0.25f, -0.25f,
	0.50f, -0.50f
};

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glEnableClientState(GL_VERTEX_ARRAY);

	// We need to write first object from CPU to GPU directly every frame.
	// In OpenGL 1.1 exists only one vertex buffer
	glVertexPointer(2, GL_FLOAT, 0, verteciesRect);
	glDrawElements(GL_TRIANGLES, sizeof(rectIndecies) / sizeof(uint32_t), GL_UNSIGNED_INT, rectIndecies);

	// We need to write second object from CPU to GPU directly every frame.
	glVertexPointer(2, GL_FLOAT, 0, verteciesTriangle);
	glDrawArrays(GL_TRIANGLES, 0, 3);

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

    glEnableClientState(GL_DEPTH_TEST);

	int windowHandle = glutCreateWindow("Hello world!");

	if (windowHandle <= 0) 
	{
		std::cout << "The main window wasn\'t created!";
		return -1;
	}

	glutDisplayFunc(&Draw);
	glutMainLoop();

	glutDestroyWindow(windowHandle);

	return 0;
}

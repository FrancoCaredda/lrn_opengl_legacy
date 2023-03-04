#include <freeglut.h>
#include <cstring>

#include <iostream>
#include <stb_image.h>

uint8_t* img_data = nullptr;
int width, height, channels;

const char* title = "Smile";

float vertecies[] = {
	// VERTEX_POS	VERTEX_COLOR
	-1.0f, -1.0f,	1.0f, 0.0f, 0.0f,
	-1.0f,  0.0f,	0.0f, 1.0f, 0.0f,
	 0.0f, -1.0f,	0.0f, 0.0f, 1.0f,
	 0.0f,  0.0f,   1.0f, 1.0f, 0.0f
};

uint32_t indecies[] = {
	0, 1, 2, 2, 1, 3
};

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glRasterPos2d(0.2, 0.2);
	glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, img_data);


	int length = strlen(title);

	glRasterPos2d(0.40, -0.1);
	for (int i = 0; i < length; i++)
		glutBitmapCharacter(GLUT_BITMAP_TIMES_ROMAN_24, title[i]);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_COLOR_ARRAY);

	glVertexPointer(2, GL_FLOAT, 5 * sizeof(float), vertecies);
	glColorPointer(3, GL_FLOAT, 5 * sizeof(float), &vertecies[2]);

	glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, indecies);

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// Initialize glut
	glutInit(&argc, argv);

	stbi_set_flip_vertically_on_load(1);
	img_data = stbi_load("resource/Smiley.png", &width, &height, &channels, 0);

	if (img_data == nullptr)
	{
		std::cout << "Error: can\'t load data!";
		return -1;
	}

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

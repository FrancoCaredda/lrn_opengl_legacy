#include <freeglut.h>

#include <iostream>
#include <stb_image.h>

uint8_t* img_data = nullptr;
int width, height, channels;

void Draw()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glDrawPixels(width, height, GL_RGBA, GL_UNSIGNED_BYTE, img_data);

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

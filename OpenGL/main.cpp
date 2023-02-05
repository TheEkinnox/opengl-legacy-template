#include <Windows.h>
#include <GL/glew.h>
#include <GL/freeglut.h>
#include <iostream>

using namespace std;

void ChangeViewPort(const int w, const int h)
{
	glViewport(0, 0, w, h);
}

void Render()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glutSwapBuffers();
}


int main(int argc, char* argv[]) {

	// Initialize GLUT
	glutInit(&argc, argv);

	// Set up some memory buffers for our display
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH);

	// Set the window size
	glutInitWindowSize(800, 600);

	// Create the window with the title "Hello,GL"
	const int windowId = glutCreateWindow("Hello, GL");

	// Bind the callback functions to respond when necessary
	glutReshapeFunc(ChangeViewPort);
	glutDisplayFunc(Render);

	// Very important! This initializes the entry points in the OpenGL driver
	// so we can call all the functions in the API.
	const GLenum err = glewInit();

	if (GLEW_OK != err)
		return fprintf(stderr, "GLEW error") > 0 ? 1 : -1;

	glutMainLoop();
	glutDestroyWindow(windowId);
	return 0;
}
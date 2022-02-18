#define GLFW_PRESS   1
#define GLFW_RELEASE   0
#define GLFW_REPEAT   2


#include <glad/glad.h>
#include <GLFW/glfw3.h>
#include <iostream>
#include "Shader.h"


class Window
{
	
public:

	int Width;
	int Height;
	static float x;
	static float y;
	static float z;
	static float r;
	static float i;
	static float j;

	GLFWwindow* window;
	Shader shader;
	

	Window(unsigned int Width, unsigned int Height);
	void main_loop(unsigned int VAO);
	void create_shader(const char* vertexPath, const char* fragmentPath);
	float tri(float x);
	static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods);
	






	

};



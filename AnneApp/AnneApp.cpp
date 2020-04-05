#include <stdlib.h>
#include <exception>
#include <iostream>
#include <glad/glad.h>		// Figure out where OpenGL implementation located.
#include <GLFW/glfw3.h>		// Window creation and events handling.

typedef const char* const* const CONST_STRING_ARRAY;
#define UNREFERENCED_ARGUMENT(argument) (argument)
static const wchar_t* g_UNHANDLED_EXCEPTION = L"";

static const int g_GLFW_CONTEXT_VERSION_MAJOR = 3;
static const int g_GLFW_CONTEXT_VERSION_MINOR = 3;
static const int g_WIDTH = 800;
static const int g_HEIGHT = 600;
static const char* g_TITLE = "AnneApp";

void framebuffer_size_callback(GLFWwindow* window, int width, int height);
void cursor_move_callback(GLFWwindow* window, double x, double y);
void cursor_pressed_release_callback(GLFWwindow*, int, int, int);

int main(const size_t argc, CONST_STRING_ARRAY argv)
{
	try
	{
		glfwInit();
		glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

		UNREFERENCED_ARGUMENT(argc);
		UNREFERENCED_ARGUMENT(argv);
		glfwInit();
		glfwInitHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
		glfwInitHint(GLFW_CONTEXT_VERSION_MINOR, 3);
		glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
		GLFWwindow* window = glfwCreateWindow(g_WIDTH, g_HEIGHT, g_TITLE, NULL, NULL);
		if (nullptr == window)
		{
			const auto code = glfwGetError(NULL);
			std::cout << "Failed to create GLFW window" << std::endl;
			glfwTerminate();
			return EXIT_FAILURE;
		}
		
		glfwMakeContextCurrent(window);
		glfwSetCursorPosCallback(window, (GLFWcursorposfun)cursor_move_callback);
		glfwSetMouseButtonCallback(window, (GLFWmousebuttonfun)cursor_pressed_release_callback);
		
		if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
		{
			std::cout << "Failed to initialize GLAD" << std::endl;
			return EXIT_FAILURE;
		}

		glViewport(0, 0, g_WIDTH, g_HEIGHT);

		glfwMakeContextCurrent(window);
		glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

		while (!glfwWindowShouldClose(window))
		{
			glfwSwapBuffers(window);
			glfwPollEvents();
		}

		glfwTerminate();
		return EXIT_SUCCESS;
	}

	catch (const std::exception& error)
	{
		std::cout << error.what() << std::endl;
		return EXIT_FAILURE;
	}

	catch (...)
	{
		std::wcout << g_UNHANDLED_EXCEPTION << std::endl;
	}
}

void framebuffer_size_callback(GLFWwindow* window, int width, int height)
{
	UNREFERENCED_ARGUMENT(window);
	glViewport(0, 0, width, height);
}

void cursor_move_callback(GLFWwindow* window, double x, double y)
{
	UNREFERENCED_ARGUMENT(window);
	std::cout << "X:" << x << ", " << "Y:" << y << std::endl;
}

void cursor_pressed_release_callback(GLFWwindow* window, int botton , int action, int mode)
{
	UNREFERENCED_ARGUMENT(window);
	UNREFERENCED_ARGUMENT(botton);
	UNREFERENCED_ARGUMENT(action);
	UNREFERENCED_ARGUMENT(mode);
	std::cout << "Clicked.\n";
}

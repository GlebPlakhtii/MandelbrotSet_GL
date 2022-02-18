#include "Window.h"


float Window::x = 0;
float Window::y = 0;
float Window::z = 1;
float Window::r = 256;
float Window::i = 0;
float Window::j = 0;
Window::Window(unsigned int Width, unsigned int Height)
{
    this->Width = Width;
    this->Height = Height;
   

    glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 6);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

	window = glfwCreateWindow(Width, Height, "Mandelbrot",NULL, NULL);
    if (window == NULL)
    {
        std::cout << "Failed to create GLFW window" << std::endl;
        glfwTerminate();
        
    }
    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(this->window, [](GLFWwindow* window, int width, int height)
    {
        glViewport(0, 0, width, height);
    });

    glfwSetKeyCallback(window, key_callback);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
    {
        std::cout << "Failed to initialize GLAD" << std::endl;
       
    }

}

void Window::main_loop(unsigned int VAO)
{
    
    

    while (!glfwWindowShouldClose(window))
    {

        glfwGetWindowSize(window, &Width, &Height);
        float q = (float)Width / Height;

        glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT);

        shader.use();
        
        shader.setFloat("q", q);
        shader.setFloat("x", x);
        shader.setFloat("y", y);
        shader.setFloat("z", z);
        shader.setFloat("r", r);
        shader.setFloat("i", i);
        shader.setFloat("j", j);


        glBindVertexArray(VAO);
        glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);

        glfwSwapBuffers(window);
        glfwPollEvents();
       
       
        
        //std::cout <<"i: " << i<<"\nk: "<<k<< std::endl;
        //std::cout<<q<<std::endl;
    }
}

void Window::create_shader(const char* vertexPath, const char* fragmentPath)
{
    shader = Shader(vertexPath, fragmentPath);
}





float Window::tri(float x) {
    if (abs(x) < 1)
        return 1.0f - abs(x);
    return 0;
}
void Window::key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
    float step = 1.0f/(5*z);
    if (action == GLFW_REPEAT || action == GLFW_PRESS) {
        if (key == GLFW_KEY_A)
            x -= step;
        if (key == GLFW_KEY_D)
            x += step;
        if (key == GLFW_KEY_S)
            y -= step;
        if (key == GLFW_KEY_W)
            y += step;
        if (key == GLFW_KEY_Z) {
            z += z / 100;
            std::cout << "z: " << z << std::endl;
        }
        if (key == GLFW_KEY_C) {
            z -= z / 100;
            std::cout << "z: " << z << std::endl;
        }
        if (key == GLFW_KEY_R) {
            r += 1;
            std::cout << "r: " << r << std::endl;
        }
        if (key == GLFW_KEY_E) {
            r -= 1;
            std::cout << "r: " << r << std::endl;
        }
        if (key == GLFW_KEY_G)
            i += 0.0001;
        if (key == GLFW_KEY_F)
            i -= 0.0001;
        if (key == GLFW_KEY_I) {
            std::cout << "r: ";
            std::cin >> r;
        }
        if (key == GLFW_KEY_B)
            j += 0.0001;
        if (key == GLFW_KEY_V)
            j -= 0.0001;

           

    }
        
}
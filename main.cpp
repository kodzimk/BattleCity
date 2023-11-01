#include"Map.h"
#include<iostream>

int g_windowSizeX = 640;
int g_windowSizeY = 480;

int main(void)
{
    GLFWwindow* window;


    if (!glfwInit())
        return -1;


    window = glfwCreateWindow(g_windowSizeX, g_windowSizeY, "Hello World", NULL, NULL);
    if (!window)
    {
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetMouseButtonCallback(window, NULL);

    if (glewInit() != GLEW_OK)
        return -1;
    
    float trianlgr[] = {
        0,0.5 ,
        0.5,0.5,
        0.5,0,
        0,0
    };

    float texCoord[] =
    {
        0,1,1,1,1,0,0,0
    };

    Map map;


    while (!glfwWindowShouldClose(window))
    {
        
        glClear(GL_COLOR_BUFFER_BIT);
    
        map.render(trianlgr);
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
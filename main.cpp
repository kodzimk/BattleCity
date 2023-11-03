#include"Map.h"
#include"Player.h"
#include"Enemy.h"
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
        0,0.1 ,
        0.1,0.1,
        0.1,0,
        0,0
    };

    float texCoord[] =
    {
        0,1,
        0.0625,1,
        0.0625,0.9375,
        0,0.9375
    };


    Map map;
    Player player;
    Enemy enemyies(0);
 
 
    

    while (!glfwWindowShouldClose(window))
    {
        
        glClear(GL_COLOR_BUFFER_BIT);
    
        map.render(trianlgr);
        player.render(trianlgr,window,map.checkCollision(player.x,player.y,0.1,0.1));     
        enemyies.render(window, trianlgr,true);

     
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
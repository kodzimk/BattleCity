#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include<iostream>

int g_windowSizeX = 640;
int g_windowSizeY = 480;

struct posi {
    float x, y;
}pos = { 0.5,0.5 };


bool functions(float x, float y, float width, float height,float x2,float y2,float width2,float height2)
{
    posi box1right;
    box1right.x = x;
    box1right.y = y;
    posi box1left;
     box1left.x = x + width;
     box1left.y = y + height ;

     posi box2left;
     posi box2right;
     box2right.x = x2;
     box2right.y = y2;
    box2left.x = x2 + width2;
    box2left.y = y2 + height2;

    if (box2right.x <= box1left.x &&
        box2left.x >= box1right.x &&
        box2right.y <= box1left.y &&
        box2left.y >= box1right.y)
    {
        std::cout << "nIGER";
        return false;
    }
    return true;
}

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
    Enemy enemy(0);

    while (!glfwWindowShouldClose(window))
    {
        glClear(GL_COLOR_BUFFER_BIT);



        map.render(trianlgr);
        enemy.render(window, trianlgr, map.checkCollision(-enemy.x, -enemy.y, 0.1, 0.1, 0.1, 0.1));
        player.render(trianlgr, window, map.checkCollision(-player.x, -player.y, 0.1, 0.1, 0.1, 0.1));

        
     
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}
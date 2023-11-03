#include"Map.h"
#include"Player.h"
#include"Enemy.h"
#include<iostream>

int g_windowSizeX = 640;
int g_windowSizeY = 480;

class posw
{
public:
    float x, y;
    posw()
    {

    }
};

 bool isEnemyCollide(float x, float y,float bullX,float bullY, float width, float height,bool isShoot)
{
    if (isShoot)
    {
        posw box1right;
        posw box1Left;

        posw box2right;
        posw box2Left;

        box1right.x = x;
        box1right.y = y;

        box1Left.x = x + width;
        box1Left.y = y + height;

        box2right.x = bullX;
        box2right.y = bullY;

        box2Left.x = width + bullX;
        box2Left.y = height + bullY;

        if (box2right.x <= box1Left.x &&
            box2Left.x >= box1right.x &&
            box2right.y <= box1Left.y &&
            box2Left.y >= box1right.y)
        {
            return false;
        }
    }
    return false;
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
      
        
            enemy.render(window, trianlgr, map.checkCollision(-enemy.x, -enemy.y, 0.1, 0.1, 0.1, 0.1),
             isEnemyCollide(enemy.x, enemy.y, player.bullX, player.bullY, 0.1, 0.1, player.isShoot));

        
        player.render(trianlgr, window, map.checkCollision(-player.x, -player.y, 0.1, 0.1, 0.1, 0.1));

     
        glfwSwapBuffers(window);

        glfwPollEvents();
    }

    glfwTerminate();
    return 0;
}





























#include "GLFW/glfw3.h"
#include <string>
#include <cmath>

// Bressenham Line Drawing Algorithm

void bresenham(float x1, float x2, float y1, float y2)
{
    float delX = x2 - x1;
    float delY = y2 - y1;

    float pixelX = x1 < x2 ? 0.01f : -0.01f;
    float pixelY = y1 < y2 ? 0.01f : -0.01f;

    float pixel = delX - delY;
    glColor3f(0.078f, 0.75f, 0.078f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    while (true)
    {
        glVertex2f(x1, y1);

        if (x1 >= x2 && y1 >= y2)
        {
            break;
        }

        float nextPixel = 2 * pixel;

        if (nextPixel > -delY)
        {
            pixel -= delY;
            x1 += pixelX;
        }

        if (nextPixel < delX)
        {
            pixel += delX;
            y1 += pixelY;
        }
    }
    glEnd();
}
float get_y(float y)
{
    return (y / 480.0f * 2.0f - 1.0f);
};

float get_x(float x)
{
    return (x / 640.0f * 2.0f - 1.0f);
}
int main()
{
    glfwInit(); // init glfw library
    GLFWwindow *window = glfwCreateWindow(640, 480, "Triangle", NULL, NULL);

    float x1 = get_x(20);
    float x2 = get_x(30);
    float y1 = get_y(200);
    float y2 = get_y(400);
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        // display();
        glClear(GL_COLOR_BUFFER_BIT);
        bresenham(x1, y1, x2, y2);
        glfwSwapBuffers(window); // redraws contents
        glfwPollEvents();        // listen incoming messages from OS
    }
    glfwTerminate();
}
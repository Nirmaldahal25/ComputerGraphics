#include <iostream>
#include <cmath>
#include <algorithm>
#include <GLFW/glfw3.h>

float get_y(float y)
{
    return (y / 480.0f * 2.0f - 1.0f);
};

float get_x(float x)
{
    return (x / 640.0f * 2.0f - 1.0f);
}

void DDA(float x1, float y1, float x2, float y2)
{
    const float dy = y2 - y1;
    const float dx = x2 - x1;

    const float slope = dy / dx;

    const float incrementX = x2 >= x1 ? 1.0f : -1.0f;
    const float incrementY = y2 >= y1 ? 1.0f : -1.0f;

    glColor3f(0.078f, 0.75f, 0.078f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);
    glVertex2f(get_x(x1), get_y(y1));
    if (std::abs(slope) < 1)
    {
        while (x1 != x2)
        {
            x1 += incrementX;
            y1 += slope;
            glVertex2f(get_x(x1), get_y(y1));
        }
    }
    else if (std::abs(slope) > 1)
    {
        while (y1 != y2)
        {
            y1 += incrementY;
            x1 += 1 / slope;
            glVertex2f(get_x(x1), get_y(y1));
        }
    }
    else
    {
        while (x1 != x2)
        {
            y1 += incrementY;
            x1 += incrementX;
            glVertex2f(get_x(x1), get_y(y1));
        }
    }
    glEnd();
}

int main()
{
    glfwInit(); // init glfw libraryc
    GLFWwindow *window = glfwCreateWindow(640, 480, "Triangle", NULL, NULL);

    float x1 = 600;
    float x2 = 450;
    float y1 = 12;
    float y2 = 200;
    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        // display();
        glClear(GL_COLOR_BUFFER_BIT);
        DDA(x1, y1, x2, y2);
        glfwSwapBuffers(window); // redraws contents
        glfwPollEvents();        // listen incoming messages from OS
    }
    glfwTerminate();
}
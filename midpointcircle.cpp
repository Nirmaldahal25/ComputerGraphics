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

void draw8points(float x, float y, float tx, float ty)
{
    glVertex2f(get_x(x + tx), get_y(y + ty));   // x,y
    glVertex2f(get_x(y + tx), get_y(x + ty));   // y,x
    glVertex2f(get_x(-x + tx), get_y(-y + ty)); //-x, -y
    glVertex2f(get_x(-x + tx), get_y(y + ty));  //-x, y
    glVertex2f(get_x(x + tx), get_y(-y + ty));  // x, -y
    glVertex2f(get_x(-y + tx), get_y(x + ty));  //-y, x
    glVertex2f(get_x(y + tx), get_y(-x + ty));  // y , -x
    glVertex2f(get_x(-y + tx), get_y(-x + ty)); //-y,-x
}

void midPointCircle(float center1, float center2, float radius)
{
    float y = radius;
    float x = 0;

    float pk = 5 / 4 - radius;

    glColor3f(0.078f, 0.75f, 0.078f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);

    draw8points(x, y, 400, 350);
    while (x < y)
    {
        if (pk < 0)
        {
            x += 1.0f;
            pk += 2.0f * x + 1.0f;
        }
        else
        {
            x += 1.0f;
            y -= 1.0f;
            pk += 2.0f * x + 1 - 2.0f * y;
        }
        draw8points(x, y, 400, 350);
    }
    glEnd();
}

int main()
{
    glfwInit(); // init glfw libraryc
    GLFWwindow *window = glfwCreateWindow(640, 480, "Mid Point Circle", NULL, NULL);

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        // display();
        glClear(GL_COLOR_BUFFER_BIT);
        midPointCircle(0, 0, 50);
        glfwSwapBuffers(window); // redraws contents
        glfwPollEvents();        // listen incoming messages from OS
    }
    glfwTerminate();
}
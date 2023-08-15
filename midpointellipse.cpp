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

void draw4points(float x, float y, float tx, float ty)
{
    glVertex2f(get_x(x + tx), get_y(y + ty)); // x,y
    // glVertex2f(get_x(y + tx), get_y(x + ty));   // y,x
    glVertex2f(get_x(-x + tx), get_y(-y + ty)); //-x, -y
    glVertex2f(get_x(-x + tx), get_y(y + ty));  //-x, y
    glVertex2f(get_x(x + tx), get_y(-y + ty));  // x, -y
    // glVertex2f(get_x(-y + tx), get_y(x + ty));  //-y, x
    // glVertex2f(get_x(y + tx), get_y(-x + ty));  // y , -x
    // glVertex2f(get_x(-y + tx), get_y(-x + ty)); //-y,-x
}

void midPointeEllipse(float center1, float center2, float rx, float ry)
{
    float y = ry;
    float x = 0;

    glColor3f(0.078f, 0.75f, 0.078f);
    glPointSize(5.0f);
    glBegin(GL_POINTS);

    // region one
    draw4points(x, y, 400, 300);
    float terminator = 9;
    float pk = ry * ry - rx * rx * ry + rx * rx / 4.0f;
    while (terminator > 0)
    {
        if (pk < 0)
        {
            x = x + 1.0f;
            pk += ry * ry * (2.0f * x + 1.0f);
        }
        else
        {
            y = y - 1.0f;
            x = x + 1.0f;
            pk += ry * ry * (2.0f * x + 1.0f) - 2 * rx * rx * y;
        }
        terminator = 2.0f * y * rx * rx - 2.0f * x * ry * ry;
        draw4points(x, y, 400, 300);
    }

    // region 2
    pk = ry * ry * (x + 0.5f) * (x + 0.5f) + rx * rx * (y - 1.0f) * (y - 1.0f) - rx * rx * ry * ry;
    while (y >= 0)
    {
        if (pk <= 0)
        {
            x += 1.0f;
            y -= 1.0f;
            pk += 2 * ry * ry * x - 2 * rx * rx * y + rx * rx;
        }
        else
        {
            y = y - 1.0f;
            pk += rx * rx - 2 * rx * rx * y;
        }
        draw4points(x, y, 400, 300);
    }

    glEnd();
}

int main()
{
    glfwInit(); // init glfw libraryc
    GLFWwindow *window = glfwCreateWindow(640, 480, "Mid Point Ecllipse", NULL, NULL);

    glfwMakeContextCurrent(window);
    while (!glfwWindowShouldClose(window))
    {
        // display();
        glClear(GL_COLOR_BUFFER_BIT);
        midPointeEllipse(0, 0, 50, 30);
        glfwSwapBuffers(window); // redraws contents
        glfwPollEvents();        // listen incoming messages from OS
    }
    glfwTerminate();
}
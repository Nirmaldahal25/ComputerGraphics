#include <iostream>
#include <cmath>
#include <algorithm>
#include <GLFW/glfw3.h>
#include <Eigen/Core>

enum REFLECTIONS
{
    REFLECTION_X = 1,
    REFLECTION_Y = 2,
    REFLECTION_XY_LINE = 4,
};

float get_y(float y)
{
    return (y / 480.0f * 2.0f - 1.0f);
};

float get_x(float x)
{
    return (x / 640.0f * 2.0f - 1.0f);
}

void translation(Eigen::Matrix3f &mat, float tx, float ty)
{
    const Eigen::Matrix3f trans{{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};
    mat = trans * mat;
}

void rotation(Eigen::Matrix3f &mat, float angle)
{
    const float co = std::cos(angle);
    const float si = std::sin(angle);
    const Eigen::Matrix3f trans{{co, -si, 0}, {si, co, 0}, {0, 0, 1}};
    mat = trans * mat;
}

void scaling(Eigen::Matrix3f &mat, float Sx, float Sy)
{
    const Eigen::Matrix3f trans{{Sx, 0, 0}, {0, Sy, 0}, {0, 0, 1}};
    mat = trans * mat;
}

void shearing(Eigen::Matrix3f &mat, float Shx, float Shy)
{
    const Eigen::Matrix3f trans{{1, Shy, 0}, {Shx, 1, 0}, {0, 0, 1}};
    mat = trans * mat;
}

void reflection(Eigen::Matrix3f &mat, REFLECTIONS reflect)
{
    float sx = 1, sy = 1;
    if (reflect & REFLECTIONS::REFLECTION_XY_LINE)
    {
        const Eigen::Matrix3f trans{{0, 1, 0}, {1, 0, 0}, {0, 0, 1}};
        mat = trans * mat;
    }
    if (reflect & REFLECTIONS::REFLECTION_X)
    {
        sy = -1;
    }
    if (reflect & REFLECTIONS::REFLECTION_Y)
    {
        sx = -1;
    }

    const Eigen::Matrix3f trans{{sx, 0, 0}, {0, sy, 0}, {0, 0, 1}};
    mat = trans * mat;
}

void drawTriangles(const Eigen::Matrix3f &mat)
{
    glBegin(GL_TRIANGLES);
    glColor3f(0.5f, 0.5f, 0.1f);
    for (int i = 0; i < mat.rows(); i++)
    {
        const auto &col = mat.col(i);
        glVertex3f(col[0], col[1], col[2]);
    }
    glEnd();
}
void displaytriangle()
{
    static Eigen::Matrix3f points{{0.0f, 0.0f, 0.3f}, {0.0f, 0.3f, 0.0f}, {1.0f, 1.0f, 1.0f}};
    static Eigen::Matrix3f translated = points;

    static int value = 0;

    if (value < 1)
    {
        // translation(translated, 0.5f, 0.5f);
        // std::cout << "translated\n"
        //           << translated << "\nPoints\n"
        //           << points << std::endl;

        float cent_x = 0;
        float cent_y = 0;
        for (int i = 0; i < points.cols(); i++)
        {
            const auto &data = points.col(i);
            cent_x += data[0];
            cent_y += data[1];
        }
        cent_y /= 3;
        cent_x /= 3;

        translation(translated, -cent_x, -cent_y);
        rotation(translated, 30);
        scaling(translated, 2.0f, 2.0f);
        reflection(translated, REFLECTIONS::REFLECTION_Y);
        shearing(translated, 1.2f, 0.0f);

        translation(translated, cent_x + 0.4f, cent_y);
        value++;
    }
    drawTriangles(points);
    drawTriangles(translated);
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
        displaytriangle();
        glfwSwapBuffers(window); // redraws contents
        glfwPollEvents();        // listen incoming messages from OS
    }
    glfwTerminate();
}
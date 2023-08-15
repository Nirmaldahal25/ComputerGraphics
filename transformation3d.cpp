#include <iostream>
#include <cmath>
#include <algorithm>
#include <GLFW/glfw3.h>
#include <Eigen/Core>
#include <gl/GL.h>
void scale(Eigen::Matrix<float, 4, 24> &matrix, float sx, float sy, float sz)
{
    const Eigen::Matrix4f scale{
        {sx, 0, 0, 0},
        {0, sy, 0, 0},
        {0, 0, sz, 0},
        {0, 0, 0, 1}};
    matrix = scale * matrix;
}

void translate(Eigen::Matrix<float, 4, 24> &matrix, float tx, float ty, float tz)
{
    const Eigen::Matrix4f translate{
        {1, 0, 0, tx},
        {0, 1, 0, ty},
        {0, 0, 1, tz},
        {0, 0, 0, 1}};
    matrix = translate * matrix;
}

void rotate(Eigen::Matrix<float, 4, 24> &matrix, float angle, int axis = 0)
{
    const float cosine = std::cos(angle);
    const float sine = std::sin(angle);
    Eigen::Matrix4f rotate{
        {1, 0, 0, 0},
        {0, cosine, -sine, 0},
        {0, sine, cosine, 0},
        {0, 0, 0, 1}};

    if (axis == 1)
    {
        rotate = Eigen::Matrix4f{
            {cosine, 0, -sine, 0},
            {0, 1, 0, 0},
            {sine, 0, cosine, 0},
            {0, 0, 0, 1}};
    }
    else if (axis == 2)
    {
        rotate = Eigen::Matrix4f{
            {cosine, -sine, 0, 0},
            {sine, cosine, 0, 0},
            {0, 0, 1, 0},
            {0, 0, 0, 1}};
    }
    matrix = rotate * matrix;
}

auto getCube()
{
    Eigen::Matrix<float, 24, 4> vertices{
        // Front
        {-0.5f, -0.5f, 0.5f, 1.0f},
        {0.5f, -0.5f, 0.5f, 1.0f},
        {0.5f, 0.5f, 0.5f, 1.0f},
        {-0.5f, 0.5f, 0.5f, 1.0f},

        // Back
        {-0.5f, -0.5f, -0.5f, 1.0f},
        {-0.5f, 0.5f, -0.5f, 1.0f},
        {0.5f, 0.5f, -0.5f, 1.0f},
        {0.5f, -0.5f, -0.5f, 1.0f},

        // Left
        {-0.5f, -0.5f, 0.5f, 1.0f},
        {-0.5f, 0.5f, 0.5f, 1.0f},
        {-0.5f, 0.5f, -0.5f, 1.0f},
        {-0.5f, -0.5f, -0.5f, 1.0f},

        // Right
        {0.5f, -0.5f, -0.5f, 1.0f},
        {0.5f, 0.5f, -0.5f, 1.0f},
        {0.5f, 0.5f, 0.5f, 1.0f},
        {0.5f, -0.5f, 0.5f, 1.0f},

        // Top
        {-0.5f, 0.5f, 0.5f, 1.0f},
        {0.5f, 0.5f, 0.5f, 1.0f},
        {0.5f, 0.5f, -0.5f, 1.0f},
        {-0.5f, 0.5f, -0.5f, 1.0f},

        // Bottom
        {-0.5f, -0.5f, 0.5f, 1.0f},
        {-0.5f, -0.5f, -0.5f, 1.0f},
        {0.5f, -0.5f, -0.5f, 1.0f},
        {0.5f, -0.5f, 0.5f, 1.0f},
    };
    return vertices.transpose();
}

void DrawCube()
{
    static Eigen::Matrix<float, 4, 24> vertices = getCube();

    static Eigen::Matrix<float, 6, 3> colors{
        {0.0f, 1.0f, 0.0f},    // Front
        {1.0f, 0.0f, 0.0f},    // Back
        {0.0f, 0.0f, 1.0f},    // Left
        {0.5f, 0.5f, 0.5f},    // Right,
        {0.25f, 0.25f, 0.25f}, // Top
        {0.75f, 0.75f, 0.75f}, // Bottom
    };
    static int count = 0;
    if (count == 0)
    {
        rotate(vertices, 30, 2);
        rotate(vertices, 50, 1);
        scale(vertices, 1.0f, 1.0f, 0.7f);
        translate(vertices, 0.0f, 0.3f, 0.0f);
        count += 1;
    }

    int it = 0;
    glBegin(GL_QUADS);
    for (int i = 0; i < vertices.cols(); i++)
    {
        const auto &row = vertices.col(i);
        glVertex3f(row[0], row[1], row[2]);
        if (i % 4 == 0)
        {
            const auto &color = colors.row(it);
            glColor3f(color[0], color[1], color[2]);
            it += 1;
        }
    }

    glEnd();
}

int main()
{
    glfwInit(); // init glfw libraryc
    GLFWwindow *window = glfwCreateWindow(640, 480, "Mid Point Circle", NULL, NULL);
    glfwMakeContextCurrent(window);

    glEnable(GL_DEPTH_TEST); // Depth Testing
    glDepthFunc(GL_LEQUAL);
    glDisable(GL_CULL_FACE);
    glCullFace(GL_BACK);

    while (!glfwWindowShouldClose(window))
    {
        // Draw stuff
        glClearColor(0.f, 0.f, 0.f, 1.f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glViewport(0, 0, 640, 480);
        glMatrixMode(GL_PROJECTION_MATRIX);
        glLoadIdentity();
        glOrtho(0, 0, 640, 480, -1.0f, 1.0f);
        glMatrixMode(GL_MODELVIEW);

        DrawCube();

        glfwSwapBuffers(window); // redraws contents
        glfwPollEvents();        // listen incoming messages from OS
    }
    glfwTerminate();
}
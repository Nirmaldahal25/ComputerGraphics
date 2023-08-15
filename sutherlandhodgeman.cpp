#include <iostream>
#include <cmath>
#include <algorithm>
#include <GLFW/glfw3.h>
#include <Eigen/Core>
#include <memory>
#include <array>
#include <vector>
#include <memory>
enum REGION
{
    TOP = 8,
    BOTTOM = 4,
    RIGHT = 2,
    LEFT = 1,
};
bool isleft(uint8_t bit)
{
    return bit & REGION::LEFT;
}
bool istop(uint8_t bit)
{
    return bit & REGION::TOP;
}

bool isright(uint8_t bit)
{
    return bit & REGION::RIGHT;
}

bool isbottom(uint8_t bit)
{
    return bit & REGION::BOTTOM;
}
uint8_t getbit(const Eigen::Matrix<float, 4, 2> &region, const Eigen::Vector2f &point)
{
    // check top
    const auto topright = region.row(0);
    const auto bottomleft = region.row(2);
    uint8_t bit = 0;

    if (point[0] > topright[0]) // right
    {
        bit |= REGION::RIGHT;
    }

    if (point[1] > topright[1]) // top
    {
        bit |= REGION::TOP;
    }

    if (point[0] < bottomleft[0]) // left
    {
        bit |= REGION::LEFT;
    }

    if (point[1] < bottomleft[1]) // bottom
    {
        bit |= REGION::BOTTOM;
    }

    return bit;
}

void intersection(const Eigen::Vector2f &point1, const Eigen::Vector2f &point2, const Eigen::Matrix<float, 4, 2> &region, std::vector<Eigen::Vector2f> &vertices, int index, uint8_t bit1, uint8_t bit2)
{
    float a1 = point2[1] - point1[1];
    float b1 = point1[0] - point2[0];
    float c1 = a1 * point1[0] + b1 * point1[1];

    const auto &topright = region.row(0);
    const auto &bottomleft = region.row(2);

    const auto &p1 = region.row(index);
    const auto &p2 = region.row((index + 1) % region.rows());

    const float a2 = p2[1] - p1[1];
    const float b2 = p1[0] - p2[0];

    const float determinant = a1 * b2 - a2 * b1;
    if (determinant != 0)
    {
        float c2 = a2 * p1[0] + b2 * p1[1];
        float x = (b2 * c1 - b1 * c2) / determinant;
        float y = (a1 * c2 - a2 * c1) / determinant;
        vertices.emplace_back(Eigen::Vector2f{x, y});
    }
}
void clipline(const Eigen::Vector2f &point1, const Eigen::Vector2f &point2, const Eigen::Matrix<float, 4, 2> &region, int index, std::vector<Eigen::Vector2f> &vertices)
{
    const auto topborder = region.row(0);
    const auto bottom = region.row(1);

    uint8_t bit1 = getbit(region, point1);
    uint8_t bit2 = getbit(region, point2);

    if (bit1 == 0)
    {
        if (bit2 == 0)
        {
            vertices.push_back(point2);
        }
        else
        {
            intersection(point1, point2, region, vertices, index, bit1, bit2);
        }
    }
    else
    {
        if (bit2 == 0)
        {
            intersection(point1, point2, region, vertices, index, bit1, bit2);
            vertices.push_back(point2);
        }
    }
}

void displayLine()
{
    const static Eigen::Matrix<float, 4, 2> region{
        {0.5f, 0.5f},   // top right
        {-0.5, 0.5f},   // top left
        {-0.5f, -0.5f}, // bottom left
        {0.5, -0.5}};   // bottom right

    static std::array<Eigen::Vector2f, 5> vertices{{{-0.7f, 0.7f},
                                                    {-0.7f, -0.2f},
                                                    {0.4f, 0.2f},
                                                    {0.5f, 0.6f},
                                                    {0.8f, 0.8f}}};

    glColor3f(255.0f, 0.f, 0.f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < region.rows(); i++)
    {
        const auto row = region.row(i);
        glVertex2f(row[0], row[1]);
    }
    glEnd();

    glColor3f(0.f, 0.f, 1.0f);
    glBegin(GL_LINE_LOOP);
    for (const auto &vertex : vertices)
    {
        glVertex2f(vertex[0], vertex[1]);
    }
    glEnd();

    static std::vector<Eigen::Vector2f> clipped_vertices;

    static int count = 0;
    if (count < 1)
    {
        std::vector<Eigen::Vector2f> temp_vert1;
        for (int i = 0; i < region.rows(); i++)
        {
            if (i == 0)
            {
                for (int j = 0; j < vertices.size(); j++)
                {
                    clipline(vertices[j], vertices[(j + 1) % vertices.size()], region, i, temp_vert1);
                }
            }
            else
            {
                for (int j = 0; j < clipped_vertices.size(); j++)
                {
                    clipline(clipped_vertices[j], clipped_vertices[(j + 1) % clipped_vertices.size()], region, i, temp_vert1);
                }
            }
            clipped_vertices = std::move(temp_vert1);
        }
        count += 1;
    }

    glColor3f(0.f, 1.0f, 0.f);
    glBegin(GL_LINE_LOOP);
    for (const auto &vert : clipped_vertices)
    {
        glVertex2f(vert[0], vert[1]);
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
        displayLine();
        glfwSwapBuffers(window); // redraws contents
        glfwPollEvents();        // listen incoming messages from OS
    }
    glfwTerminate();
}

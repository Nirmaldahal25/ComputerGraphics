#include <iostream>
#include <cmath>
#include <algorithm>
#include <GLFW/glfw3.h>
#include <Eigen/Core>
#include <memory>
#include <array>

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
void clipline(std::unique_ptr<Eigen::Vector2f> &point1, std::unique_ptr<Eigen::Vector2f> &point2, const Eigen::Matrix<float, 4, 2> &region)
{
    const auto topborder = region.row(0);
    const auto bottom = region.row(1);

    uint8_t bit1 = getbit(region, *(point1.get()));
    uint8_t bit2 = getbit(region, *(point2.get()));

    if (bit1 & bit2)
    {
        return;
    }
    const float slope = ((*point2)[1] - (*point1)[1]) / ((*point2)[0] - (*point1)[0]);

    float x = (*point1)[0];
    float y = (*point1)[1];

    if (istop(bit1))
    {
        x = x + (topborder[1] - y) / slope;
        y = topborder[1];
    }
    else if (isbottom(bit1))
    {
        x = x + (bottom[1] - y) / slope;
        y = bottom[1];
    }
    else if (isleft(bit1))
    {
        y = y + slope * (bottom[0] - x);
        x = bottom[0];
    }
    else if (isright(bit1))
    {
        y = y + slope * (topborder[0] - x);
        x = topborder[0];
    }
    (*point1)[0] = x;
    (*point1)[1] = y;

    x = (*point2)[0];
    y = (*point2)[1];
    if (istop(bit2))
    {
        x = x + (topborder[1] - y) / slope;
        y = topborder[1];
    }
    else if (isbottom(bit2))
    {
        x = x + (bottom[1] - y) / slope;
        y = bottom[1];
    }
    else if (isleft(bit2))
    {
        y = y + slope * (bottom[0] - x);
        x = bottom[0];
    }
    else if (isright(bit2))
    {
        y = y + slope * (topborder[0] - x);
        x = topborder[0];
    }
    (*point2)[0] = x;
    (*point2)[1] = y;
}

void displayLine()
{
    const static Eigen::Matrix<float, 4, 2> region{
        {0.5f, 0.5f},   // top right
        {-0.5, 0.5f},   // top left
        {-0.5f, -0.5f}, // bottom left
        {0.5, -0.5}};   // bottom right

    static Eigen::Vector2f point1{-0.6f, -0.3f};
    static Eigen::Vector2f point2{0.4f, 0.7f};
    static int count = 0;

    static std::unique_ptr<Eigen::Vector2f> vec1{new Eigen::Vector2f(point1)};
    static std::unique_ptr<Eigen::Vector2f> vec2{new Eigen::Vector2f(point2)};

    glColor3f(255.0f, 0.f, 0.f);
    glBegin(GL_LINE_LOOP);
    for (int i = 0; i < region.rows(); i++)
    {
        const auto row = region.row(i);
        glVertex2f(row[0], row[1]);
    }
    glEnd();

    if (count < 1)
    {
        clipline(vec1, vec2, region);
        count++;
    }

    glBegin(GL_LINES);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(point1[0], point1[1]);
    glVertex2f(point2[0], point2[1]);
    glEnd();

    glColor3f(0.f, 1.0f, 0.f);
    glBegin(GL_LINES);
    glVertex2f((*vec1)[0], (*vec1)[1]);
    glVertex2f((*vec2)[0], (*vec2)[1]);
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

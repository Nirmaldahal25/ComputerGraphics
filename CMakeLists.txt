cmake_minimum_required(VERSION 3.2)
project("CircleCollision")


add_subdirectory(eigen-3.4.0)
add_subdirectory(glfw-3.3.8)
link_directories(${Eigen_INCLUDE_DIRS})

find_package (Eigen3 3.3 REQUIRED NO_MODULE)
add_executable(${PROJECT_NAME} cohensutherland.cpp)

find_package(OpenGL REQUIRED)
target_link_libraries(${PROJECT_NAME} glfw opengl32 Eigen3::Eigen)
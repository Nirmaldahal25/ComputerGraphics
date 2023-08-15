# Install script for directory: C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "C:/Program Files/NepalFlag")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "Release")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE FILE FILES
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/AdolcForward"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/AlignedVector3"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/ArpackSupport"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/AutoDiff"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/BVH"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/EulerAngles"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/FFT"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/IterativeSolvers"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/KroneckerProduct"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/LevenbergMarquardt"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/MatrixFunctions"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/MoreVectorization"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/MPRealSupport"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/NonLinearOptimization"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/NumericalDiff"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/OpenGLSupport"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/Polynomials"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/Skyline"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/SparseExtra"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/SpecialFunctions"
    "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/Splines"
    )
endif()

if(CMAKE_INSTALL_COMPONENT STREQUAL "Devel" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include/eigen3/unsupported/Eigen" TYPE DIRECTORY FILES "C:/Users/nirma/Desktop/Computer Graphics/eigen-3.4.0/unsupported/Eigen/src" FILES_MATCHING REGEX "/[^/]*\\.h$")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("C:/Users/nirma/Desktop/Computer Graphics/build/eigen-3.4.0/unsupported/Eigen/CXX11/cmake_install.cmake")

endif()


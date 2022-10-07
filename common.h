#include <glad/glad.c>
#include <GLFW/glfw3.h>

#include <algorithm>
#include <string>
#include <vector>
#include <tuple>
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

const int n = 21;//no. of cubes each side + 1 = no. of points along each axis

std::vector<float> vertex_data;
//3 position, 3 colors

unsigned int grey_lines[6*n*n];

void change_cube_state(int a, int b, int c, std::vector<float> &color);
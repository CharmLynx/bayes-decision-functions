#pragma once

#include <vector>
#include <string>

std::vector<std::vector<double>> read_double_matrix(const std::string& path);

std::vector<std::vector<int>> read_int_matrix(const std::string& path);

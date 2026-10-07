#pragma once

#include <vector>

std::vector<int> build_deterministic(const std::vector<std::vector<double>>& p_m_given_c);
std::vector<std::vector<double>> build_stochastic(const std::vector<std::vector<double>>& p_m_given_c);
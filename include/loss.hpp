#pragma once

#include <vector>

double loss_deterministic(const std::vector<std::vector<double>>& p_mc, const std::vector<int>& det);
double loss_stochastic(const std::vector<std::vector<double>>& p_mc, const std::vector<std::vector<double>>& stoch);
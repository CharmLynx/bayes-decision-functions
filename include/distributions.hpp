#pragma once

#include <vector>
#include "cipher_model.hpp"

std::vector<std::vector<double>> compute_p_mc(const CipherModel& model);
std::vector<double> compute_p_c(const std::vector<std::vector<double>>& p_mc);

std::vector<std::vector<double>> compute_p_m_given_c(
    const std::vector<std::vector<double>>& p_mc,
    const std::vector<double>& p_c);
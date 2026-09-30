#pragma once

#include <vector>
#include <string>

struct CipherModel{
    std::vector<double> p_m;
    std::vector<double> p_k;
    std::vector<std::vector<int>> enc;
};

CipherModel load_model(const std::string& prob_path, const std::string& table_path);
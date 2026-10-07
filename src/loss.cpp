#include "loss.hpp"

using namespace std;

double loss_deterministic(const vector<vector<double>>& p_mc, const vector<int>& det){
    double loss = 0.0;
    size_t n = p_mc.size();

    for (size_t m = 0; m < n; m++) {
        for (size_t c = 0; c < n; c++) {
            if (det[c] != (int)m) {
                loss += p_mc[m][c];
            }
        }
    }
    return loss;
}
double loss_stochastic(const vector<vector<double>>& p_mc, const vector<vector<double>>& stoch){
    return{};
}
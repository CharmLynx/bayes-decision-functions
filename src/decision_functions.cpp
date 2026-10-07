#include "decision_functions.hpp"

using namespace std;

vector<int> build_deterministic(const vector<vector<double>>& p_m_given_c){
    size_t n = p_m_given_c.size();
    vector<int> deterministic(n, 0);

    for (size_t c = 0; c < n; c++) {
        int best = 0;
        for (size_t m = 1; m < n; m++) {
            if (p_m_given_c[c][m] > p_m_given_c[c][best]) {
                best = m;
            }
        }
        deterministic[c] = best;
    }
    return deterministic;
}
vector<vector<double>> build_stochastic(const vector<vector<double>>& p_m_given_c){

    return{};
}
#include "distributions.hpp"

using namespace std;

vector<vector<double>> compute_p_mc(const CipherModel& model){
    size_t n = model.p_m.size();
    vector<vector<double>> p_mc(n, vector<double>(n, 0.0));

    for (size_t m = 0; m < n; m++) {
        for (size_t k = 0; k < n; k++) {
            int c = model.enc[k][m];
            p_mc[m][c] += model.p_m[m] * model.p_k[k];
        }
    }
    return p_mc;
}
vector<double> compute_p_c(const vector<vector<double>>& p_mc){
    size_t n = p_mc.size();
    vector<double> p_c(n, 0.0);

    for (size_t m = 0; m < n; m++) {
        for (size_t c = 0; c < n; c++) {
            p_c[c] += p_mc[m][c];
        }
    }
    return p_c;
}
vector<vector<double>> compute_p_m_given_c(const vector<vector<double>>& p_mc, const vector<double>& p_c){
    size_t n = p_mc.size();
    vector<vector<double>> p_m_given_c(n, vector<double>(n, 0.0));

    for (size_t m = 0; m < n; m++) {
        for (size_t c = 0; c < n; c++) {
            if (p_c[c] > 0) {
                p_m_given_c[m][c] = p_mc[m][c] / p_c[c];
            }
        }
    }
    return p_m_given_c;
}
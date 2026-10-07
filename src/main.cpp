#include <iomanip>
#include <iostream>

#include "cipher_model.hpp"
#include "distributions.hpp"
#include "decision_functions.hpp"
#include "loss.hpp"

using namespace std;

void print_matrix(const string& title, const vector<vector<double>>& a) {
    cout << "\n" << title << endl;
    for (const auto& row : a) {
        for (double x : row) {
            cout << setw(8) << fixed << setprecision(4) << x;
        }
        cout << endl;
    }
}

vector<vector<double>> det_to_matrix(const vector<int>& det) {
    size_t n = det.size();
    vector<vector<double>> a(n, vector<double>(n, 0.0));
    for (size_t c = 0; c < n; c++) {
        a[c][det[c]] = 1.0;
    }
    return a;
}

int main() {
    CipherModel model = load_model("data/prob_18.csv", "data/table_18.csv");

    auto p_mc = compute_p_mc(model);
    auto p_c = compute_p_c(p_mc);
    auto post = compute_p_m_given_c(p_mc, p_c);
    auto det = build_deterministic(post);
    auto stoch = build_stochastic(post);

    print_matrix("P(M,C): rows = M, columns = C", p_mc);

    cout << "\nP(C):" << endl;
    for (double x : p_c) {
        cout << setw(8) << fixed << setprecision(4) << x;
    }
    cout << endl;

    print_matrix("P(M|C): rows = C, columns = M", post);

    cout << "\nDeterministic function (C -> M):" << endl;
    for (size_t c = 0; c < det.size(); c++) {
        cout << "C" << c << " -> M" << det[c] << endl;
    }

    print_matrix("Deterministic function: rows = C, columns = M", det_to_matrix(det));
    print_matrix("Stochastic function: rows = C, columns = M", stoch);

    cout << "\nLoss (deterministic) = " << loss_deterministic(p_mc, det) << endl;
    cout << "\nLoss (stochastic) = " << loss_stochastic(p_mc, stoch) << endl;
}
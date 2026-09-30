#include "cipher_model.hpp"
#include "csv_reader.hpp"

using namespace std;

CipherModel load_model(const string& prob_path, const string& table_path){
    auto prob = read_double_matrix(prob_path);
    auto table = read_int_matrix(table_path);
    CipherModel model;
    model.p_m = prob[0];
    model.p_k = prob[1];
    model.enc = table;
    return model;
}
#include "csv_reader.hpp"
#include <fstream>
#include <sstream> 
#include <vector> 

using namespace std;

namespace{
    vector<string> split_line(const string& line){
        stringstream ss(line);
        vector<string> result;
        string cell;
        while(getline(ss, cell, ',')){
            result.push_back(cell);
        }
        return result;
    }
    double parse_double(const string& cell){
        size_t pos;
        double value = stod(cell, &pos);
        return value;
    }
}

vector<vector<double>> read_double_matrix(const string& path) {
    return {};
}

vector<vector<int>> read_int_matrix(const string& path) {
    return {};
}
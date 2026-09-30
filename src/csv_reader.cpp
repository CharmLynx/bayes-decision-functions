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
        double value = stod(cell);
        return value;
    }
    int parse_int(const string& cell){
        int value = stoi(cell);
        return value;
    }

}

vector<vector<double>> read_double_matrix(const string& path) {
    ifstream f(path);
    vector<vector<double>> matrix;
    string line;
    while (getline(f, line)){
        vector<string> cells = split_line(line);
        vector<double> row;
        for (const string& cell : cells) {
            row.push_back(parse_double(cell));
        }
        matrix.push_back(row);
    }
    return matrix;
}

vector<vector<int>> read_int_matrix(const string& path) {
    ifstream f(path);
    vector<vector<int>> matrix;
    string line;
    while (getline(f, line)){
        vector<string> cells = split_line(line);
        vector<int> row;
        for (const string& cell : cells) {
            row.push_back(parse_int(cell));
        }
        matrix.push_back(row);
    }
    return matrix;
}
cmake_minimum_required(VERSION 3.16)
project(bayes_decision_functions LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(bayes
    src/main.cpp
    src/csv_reader.cpp
    src/cipher_model.cpp
    src/distributions.cpp
)

target_include_directories(bayes PRIVATE include)
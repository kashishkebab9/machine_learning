#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <thread>
#include <boost/range/combine.hpp>


// make sure to compile with g++ -std=c++11 main.cpp

int main() {
    std::vector<float> inputs_1 = {1.0, 2.0, 3.0, 2.5};
    

    std::vector<float> weights_1 = {0.2, 0.8, -0.5, 1.0};
    std::vector<float> weights_2 = {0.5, -0.91, 0.26, -0.5};
    std::vector<float> weights_3 = {-0.26, -0.27, 0.17, 0.87};
    
    float bias_1 = 2.0;
    float bias_2 = 3.0;
    float bias_3 = 0.5;

    float output_1 = 0;
    float output_2 = 0;
    float output_3 = 0;

    for (int i = 0; i < inputs_1.size(); i++ ) {
        output_1 +=  inputs_1.at(i) * weights_1.at(i);
    }

    for (int i = 0; i < inputs_1.size(); i++ ) {
        output_2 +=  inputs_1.at(i) * weights_2.at(i);
    }

    for (int i = 0; i < inputs_1.size(); i++ ) {
        output_3 +=  inputs_1.at(i) * weights_3.at(i);
    }

    output_1 = output_1 + bias_1;
    output_2 = output_2 + bias_2;
    output_3 = output_3 + bias_3;

    std::cout << "Node 1: " << output_1 << std::endl << "Node 2: " << output_2 << std::endl << "Node 3: " << output_3 << std::endl;
    
    
}
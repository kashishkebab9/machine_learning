#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <thread>

#include <boost/range/combine.hpp>
//sentedex episode 3

template<typename T, typename P>
std::vector<std::tuple<T, P>> zip(typename std::vector<T>::iterator firstArrayBegin, 
			 typename std::vector<P>::iterator secondArrayBegin,
			 typename std::vector<P>::const_iterator secondArrayEnd)
{
	const auto size = std::distance(static_cast<decltype(secondArrayEnd)>(secondArrayBegin), secondArrayEnd);
	std::vector<std::tuple<T, P>> zipped;
	zipped.reserve(size);
	while (secondArrayBegin != secondArrayEnd) {
		zipped.emplace_back(*firstArrayBegin++, *secondArrayBegin++);
	}
	return zipped;
}


// make sure to compile with g++ -std=c++11 name.cpp

int main() {
    std::vector<float> inputs = {1.0, 2.0, 3.0, 2.5};
    

    std::vector<std::vector<float>> weights{{0.2, 0.8, -0.5, 1.0},
                                            {0.5, -0.91, 0.26, -0.5} 
                                            {-0.26, -0.27, 0.17, 0.87}};
  
    std::vector<float> biases = {2.0, 3.0, 0.5};

    auto zipped_weights_and_biases = 
		zip<decltype(weights)::value_type, double>(weights.begin(), biases.begin(), biases.end());

    float output = 0;
    

    for (int i = 0; i < inputs_1.size(); i++ ) {
        output +=  inputs_1.at(i) * weights_1.at(i);
    }

    

    output_1 = output_1 + bias_1;
    output_2 = output_2 + bias_2;
    output_3 = output_3 + bias_3;

    std::cout << "Node 1: " << output << std::endl;
    
    
}
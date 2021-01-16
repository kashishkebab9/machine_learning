#include <iostream>
#include <vector>
#include <time.h>
#include <algorithm>
#include <chrono>
#include <thread>


// make sure to compile with g++ -std=c++11 main.cpp

struct Member {
    std::string DNA;
    int Fitness;
};

struct Population {
    std::vector<Member> VecMembers = std::vector<Member>(5000); // this will create a vector called members that contains the data structure member, 50000 times 
};


int main() {
    std::string DNA;
    std::cout << "Enter what you want me to learn: ";
    getline(std::cin, DNA);;
    bool SequenceFound = false;
    int MutationRate = 25;
    srand(time(NULL));


    Population Pop;
    for (int i = 0; i < Pop.VecMembers.size(); i++) {
        Pop.VecMembers.at(i).DNA.resize(DNA.size()); // my guess this line is here to clear all the memory we might have in the memory when we re run this script
    
        for (int j = 0; j < DNA.size(); j++) {
            Pop.VecMembers.at(i).DNA.at(j) = (unsigned char) rand() % 96 + 32;
        }
        Pop.VecMembers.at(i).Fitness = 0;
    }

    int Generation = 0;
    while (!SequenceFound) {
        Generation++;
        for (int i = 0; i < Pop.VecMembers.size(); i++) {
            Pop.VecMembers.at(i).Fitness = 0;

            for (int j = 0; j< DNA.size(); j++) {
                if (Pop.VecMembers.at(i).DNA.at(j) == DNA.at(j)) {
                    Pop.VecMembers.at(i).Fitness += 10;
                }
                if (Pop.VecMembers.at(i).Fitness == DNA.size()* 10) {
                    SequenceFound = true;
                }
                
            }
        }
        
        sort(Pop.VecMembers.begin(), Pop.VecMembers.end(), [](Member const &a, Member &b) {return a.Fitness > b.Fitness; });
        std::vector<Member> Parents{Pop.VecMembers.at(0), Pop.VecMembers.at(1)};
        

        for (int i = 0; i < Pop.VecMembers.size(); i++) {
            for (int j = 0; j < Pop.VecMembers.at(i).DNA.size(); j++) {
                int TempSelection = rand() % Parents.size();
                Pop.VecMembers.at(i).DNA.at(j) = Parents.at(TempSelection).DNA.at(j);
                if (rand() % 1000 < MutationRate) {
                    Pop.VecMembers.at(i).DNA.at(j) = (unsigned char)rand() % 96 + 32;  

                }


            }


        }
        std::cout << " Generation : " << Generation << " Highest Fitness : " << Parents.at(0).Fitness << " With Sequence : " << Parents.at(0).DNA.c_str() << std::endl;
        
    }
    std::cout << "Generation " << Generation << " Evolved to the full Sequence" << std::endl;
    
    return 0;








}
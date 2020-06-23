#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dpp/digestpp.hpp"

int main (int argc, char* argv[])
{
    std::string basicString = "ckczppom";
    std::vector<std::string> results;
    for (int i = 0; i > -1; i++)
    {
        std::string newString = basicString + std::to_string(i);
        std::string newHash = digestpp::md5().absorb(newString).hexdigest();
        std::cout << newString << ": " << newHash << std::endl;
        if (newHash.compare(0,5,"00000") == 0)
        {
            results.push_back(newString);
            break;
        }
    }
    std::cout << "-------------------------RESULTS-----------------------" << std::endl;
    for (auto a : results)
        std::cout << a << std::endl;

    return 0; 
}
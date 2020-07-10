#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "dpp/digestpp.hpp"

int main(int argc, char *argv[])
{
    std::string basicString = "ckczppom";
    std::vector<std::string> results;
    for (int i = 0; i > -1; i++)
    {
        std::string newString = basicString + std::to_string(i);
        std::string newHash = digestpp::md5().absorb(newString).hexdigest();
        //std::cout << newString << ": " << newHash << std::endl;
        if (newHash.compare(0, 6, "000000") == 0)
        {
            results.push_back(newString);
            break;
        }
        if (i % 10000 == 0)
            std::cout << i << std::endl;
    }
    std::cout << "-------------------------RESULTS-----------------------" << std::endl;
    for (auto a : results)
        std::cout << a << std::endl;

    return 0;
}
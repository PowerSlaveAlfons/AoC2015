#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream myfile("Day2Input.txt"); // hardcoded because lazy
    std::string input;
    std::vector<int> Tokens;
    int Sum = 0;
    int TotalSum = 0;
    if (myfile.is_open())
    {
        while (myfile >> input)
        {
            std::string delimiter = "x";
            std::cout << input << std::endl;
            size_t pos = 0;
            std::string token;
            while ((pos = input.find(delimiter)) != std::string::npos)
            {
                token = input.substr(0, pos);
                Tokens.push_back(std::stoi(token));
                input.erase(0, pos + delimiter.length());
            }
            Tokens.push_back(std::stoi(input));
            std::sort(Tokens.begin(), Tokens.end());
            Sum = 0;
            Sum += 2*Tokens[0] + 2*Tokens[1];
            Sum += Tokens[0]*Tokens[1]*Tokens[2];

            TotalSum += Sum;
            std::cout << "Sum is now " << TotalSum << std::endl;
            Tokens.clear();
        }
    }
    std::cout << "Sum is " << TotalSum << std::endl;
    return 0;
}
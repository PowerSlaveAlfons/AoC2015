#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

int main()
{
    std::ifstream myfile("Day9Input2.json"); // hardcoded because lazy
    std::string Input = "";
    char c;
    std::string CurrentString = "";
    int CurrentNumber = 0;
    std::vector<int> Numbers;
    bool isNegative;
    int Result = 0;

    while (myfile.get(c))
    {
        if (c == '-')
        {
            isNegative = true;
            continue;
        }
        if (!std::isdigit(c))
            continue;
        else
            isNegative = false;
        while (std::isdigit(c))
        {
            CurrentString+=c;
            myfile.get(c);
        }
        
        CurrentNumber = std::stoi(CurrentString);
        CurrentString = "";
        if (isNegative)
            CurrentNumber = -CurrentNumber;
        Numbers.push_back(CurrentNumber);
    }
    std::cout << Numbers.size() << std::endl;

    for (auto a : Numbers)
    {
        Result += a;
        std::cout << a << std::endl;
    }

    std::cout << Result << std::endl;

    return 0;
}
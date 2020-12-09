#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

std::string EvaluateString(std::string Input)
{
    std::string ReturnString = "";
    int CurrentCount = 0;
    char lastC = Input[0];

    for (auto c : Input)
    {
        if (c == lastC)
        {
            CurrentCount++;
        }
        else
        {
            ReturnString += std::to_string(CurrentCount);
            ReturnString += lastC;
            CurrentCount = 1;
        }
        lastC = c;
    }
    ReturnString += std::to_string(CurrentCount);
    ReturnString += lastC;

    return ReturnString;
}

int main()
{
    std::string Output = "1321131112";

    for (int i = 0; i < 40; i++) // For Puzzle 2, change this to 50
    {
        Output = EvaluateString(Output);
    }
    std::cout << Output.length() << std::endl;

    return 0;
}
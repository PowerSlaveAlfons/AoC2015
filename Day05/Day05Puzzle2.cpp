#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ifstream myfile("Day5Input.txt"); // hardcoded because lazy
    std::string input;
    int VowelCount = 0;
    int NiceStrings = 0;
    bool ContainsPair = false;
    bool IllegalStrings = false;
    char beforelast;
    char last;
    int Counter = 0;
    std::vector<std::pair<std::string, int>> pairs;
    std::string tempPair = "";
    if (myfile.is_open())
    {
        while (myfile >> input)
        {
            VowelCount = 0;
            Dupes = false;
            IllegalStrings = false;
            last = '1';
            beforelast = '2';
            for (auto a : input)
            {
                tempPair = last + a;
                if (std::find(pairs.begin(), pairs.end(), pairs.first) != pairs.end())
                {
                    ContainsPair = true;
                }
                pairs.push_back(tempPair);

                beforelast = last;
                last = a;
            }
            if ((input.find("ab") != std::string::npos) || (input.find("cd") != std::string::npos) || (input.find("pq") != std::string::npos) || (input.find("xy") != std::string::npos))
            {
                std::cout << "found!" << '\n';
                IllegalStrings = true;
            }

            if (VowelCount > 2 && Dupes && !IllegalStrings)
                NiceStrings++;
        }
    }
    std::cout << "Sum is " << NiceStrings << std::endl;
    return 0;
}
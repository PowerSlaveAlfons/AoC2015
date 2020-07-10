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
    bool Dupes = false;
    bool IllegalStrings = false;
    char last;
    if (myfile.is_open())
    {
        while (myfile >> input)
        {
            VowelCount = 0;
            Dupes = false;
            IllegalStrings = false;
            last = '1';
            for (auto a : input)
            {
                if (a == 'a' || a == 'e' || a == 'i' || a == 'o' || a == 'u')
                    VowelCount++;
                if (a == last)
                    Dupes = true;
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
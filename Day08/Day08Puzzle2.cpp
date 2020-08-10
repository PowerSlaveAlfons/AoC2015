#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::ifstream myfile("Day8Input.txt"); // hardcoded because lazy
    std::string input;
    int CodeCharacters = 0;
    int NewStringCharacters = 0;

    if (myfile.is_open())
    {
        for (std::string input; std::getline(myfile, input);)
        {
            CodeCharacters += input.length();
            NewStringCharacters += input.length() + 2;
            for (int i = 0; i < input.length(); i++)
            {
                if (input[i] == '\\' || input[i] == '\"')
                {
                    NewStringCharacters += 1;
                }
            }
        }
    }
    std::cout << "CodeCharacters: " << CodeCharacters << std::endl;
    std::cout << "StringCharacters: " << NewStringCharacters << std::endl;
    std::cout << "Difference: " << (CodeCharacters - NewStringCharacters) << std::endl;


    return 0;
}
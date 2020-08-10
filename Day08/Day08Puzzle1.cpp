#include <iostream>
#include <fstream>
#include <string>


int main()
{
    std::ifstream myfile("Day8Input.txt"); // hardcoded because lazy
    std::string input;
    int CodeCharacters = 0;
    int StringCharacters = 0;

    if (myfile.is_open())
    {
        for (std::string input; std::getline(myfile, input);)
        {
            CodeCharacters += input.length();
            StringCharacters += input.length() - 2; //The 2 "" are in every line
            for (int i = 0; i < input.length(); i++)
            {
                if (input[i] == '\\')
                {
                    if (input[i+1] == 'x')
                        StringCharacters -= 3;
                    else
                        StringCharacters -= 1;
                    i++;
                }
            }
        }
    }
    std::cout << "CodeCharacters: " << CodeCharacters << std::endl;
    std::cout << "StringCharacters: " << StringCharacters << std::endl;
    std::cout << "Difference: " << (CodeCharacters - StringCharacters) << std::endl;


    return 0;
}
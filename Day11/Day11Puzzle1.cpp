#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>

bool isValid(std::string Password)
{
    bool TwoIncreasing = false;
    char lastA = 'K';
    bool ThreeIncreasing = false;
    int Repeating = 0;
    bool OverlapProtection = false;


    for (auto a : Password)
    {
        if (a == 'i' || a == 'o' || a == 'l')
            return false;
        
        if (TwoIncreasing)
        {
            if (a == ((char)lastA+1))
                ThreeIncreasing = true;
        }
        TwoIncreasing = false;

        if (a == ((char)lastA+1))
            TwoIncreasing = true;
        
        if (a == lastA && !OverlapProtection)
        {
            Repeating++;
            OverlapProtection = true;
        }
        else
        {
            OverlapProtection = false;
        }

        lastA = a;
    }
    if ((Repeating >= 2) && ThreeIncreasing)
        return true;
    else
        return false;
}

std::string Increment(std::string Input)
{
    int size = Input.size() - 1;
    Input[size]++;
    while (Input[size] == '{')
    {
        if (size == 0)
        {
            Input = 'a' + Input;
        }
        Input[size] = 'a';
        size--;
        Input[size]++;
    }

    return Input;
}

int main()
{
    std::string Output = "cqjxxyzz"; // Again, run the program twice to solve Part B. Kinda lame.

    do
    {
        Output = Increment(Output);
    } while (!isValid(Output));



    std::cout << Output << std::endl;

    return 0;
}
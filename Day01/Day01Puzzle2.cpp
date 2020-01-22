#include <iostream>
#include <fstream>
#include <string>


int main()
{
	std::ifstream myfile("Day1Input.txt"); // hardcoded because lazy
    int Count = 1;
    int Score = 0;
	int FinalCount = 0;
	bool FinalCountSet = false;
    char c;
	if (myfile.is_open())
	{
		while (myfile.get(c))
		{
			if (c == '(')
                Score++;
            else if (c == ')')
                Score--;
				
			if (Score == -1 && !FinalCountSet)
			{
				FinalCount = Count;
				FinalCountSet = true;
			}
            Count++;

		}
	}
    std::cout << "Count is " << FinalCount << std::endl;
	return 0;
}
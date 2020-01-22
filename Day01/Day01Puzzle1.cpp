#include <iostream>
#include <fstream>
#include <string>


int main()
{
	std::ifstream myfile("Day1Input.txt"); // hardcoded because lazy
    int Score = 0;
    char c;
	if (myfile.is_open())
	{
		while (myfile.get(c))
		{
			if (c == '(')
                Score++;
            else if (c == ')')
                Score--;
		}
	}
    std::cout << "Score is " << Score << std::endl;
	return 0;
}
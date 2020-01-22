#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
	std::ifstream myfile("Day3Input.txt"); // hardcoded because lazy
	int currentX = 0;
	int currentY = 0;
	std::map<std::pair<int, int>, bool> VisitedPlaces;
	std::pair<int, int> TempPair;
	int HouseCount = 0;
	char c;
	if (myfile.is_open())
	{
		while (myfile.get(c))
		{
			if (c == 'v')
                currentY--;
            else if (c == '^')
                currentY++;
			else if (c == '>')
				currentX++;
			else if (c == '<')
				currentX--;
			else
				continue;

			TempPair = std::make_pair(currentX, currentY);
			if (VisitedPlaces[TempPair] == false)
			{
				VisitedPlaces[TempPair] = true;
				HouseCount++;
			}

		}
	}
    std::cout << "Counted " << HouseCount << std::endl;
	return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <map>

int main()
{
	std::ifstream myfile("Day3Input.txt"); // hardcoded because lazy
	int currentX = 0;
	int currentY = 0;
	int RoboX = 0;
	int RoboY = 0;
	std::map<std::pair<int, int>, bool> VisitedPlaces;
	std::pair<int, int> TempPair;
	int HouseCount = 0;
	bool RoboMoving = false;
	char c;
	if (myfile.is_open())
	{
		while (myfile.get(c))
		{
			if (!RoboMoving)
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
				{
					RoboMoving = true;
					continue;
				}

				TempPair = std::make_pair(currentX, currentY);
				if (VisitedPlaces[TempPair] == false)
				{
					VisitedPlaces[TempPair] = true;
					HouseCount++;
				}
				RoboMoving = true;
			}
			else
			{
				if (c == 'v')
					RoboY--;
				else if (c == '^')
					RoboY++;
				else if (c == '>')
					RoboX++;
				else if (c == '<')
					RoboX--;
				else
				{
					RoboMoving = false;
					continue;
				}

				TempPair = std::make_pair(RoboX, RoboY);
				if (VisitedPlaces[TempPair] == false)
				{
					VisitedPlaces[TempPair] = true;
					HouseCount++;
				}
				RoboMoving = false;
			}
			
		}
	}
	std::cout << "Counted " << HouseCount << std::endl;
	return 0;
}
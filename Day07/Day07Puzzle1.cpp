#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

int main()
{
    std::ifstream myfile("Day7Input.txt"); // hardcoded because lazy
    std::string input;
    std::vector<std::string> Tokens;
    std::map<std::string, unsigned short> Wires;
    std::vector<std::vector<std::string>> Commands;
    bool toDelete;

    if (myfile.is_open())
    {
        for (std::string input; std::getline(myfile, input);)
        {
            //std::cout << line << std::endl;

            Tokens.clear();
            std::string delimiter = " ";
            std::cout << input << std::endl;
            size_t pos = 0;
            std::string token;
            while ((pos = input.find(delimiter)) != std::string::npos)
            {
                token = input.substr(0, pos);
                Tokens.push_back(token);
                input.erase(0, pos + delimiter.length());
            }
            Tokens.push_back(input);
            Wires[Tokens[Tokens.size() - 1]] = 65535;
            Commands.push_back(Tokens);
        }
    }

    while (Commands.size() > 0)
    {
        int i = 0;
        while (i < Commands.size())
        {
            toDelete = false;
            Tokens.clear();
            Tokens = Commands[i];
            //std::cout << Tokens.size() << std::endl;
            if (Tokens.size() == 3) //One Argument; Can be either number or another wire
            {
                if (std::isdigit(Tokens[0][0]))
                {
                    Wires[Tokens[2]] = std::stoi(Tokens[0]);
                    toDelete = true;
                }
                else if (Wires[Tokens[0]] != 65535)
                {
                    Wires[Tokens[2]] = Wires[Tokens[0]];
                    toDelete = true;
                }
            }

            else if (Tokens.size() == 4) // Can only be NOT if 2 arguments
            {
                if (std::isdigit(Tokens[1][0]))
                {
                    Wires[Tokens[3]] = ~std::stoi(Tokens[1]);
                    toDelete = true;
                }

                else if (Wires[Tokens[1]] != 65535)
                {
                    Wires[Tokens[3]] = ~Wires[Tokens[1]];
                    toDelete = true;
                }
            }
            else if (Tokens.size() == 5)
            {

                if (!std::isdigit(Tokens[0][0]))
                {
                    if (Wires[Tokens[0]] == 65535)
                    {
                        i++;
                        continue;
                    }
                    Tokens[0] = std::to_string(Wires[Tokens[0]]);
                }
                if (!std::isdigit(Tokens[2][0]))
                {
                    if (Wires[Tokens[2]] == 65535)
                    {
                        i++;
                        continue;
                    }
                    Tokens[2] = std::to_string(Wires[Tokens[2]]);
                }

                if (Tokens[1] == "AND")
                {
                    Wires[Tokens[4]] = (std::stoi(Tokens[0]) & std::stoi(Tokens[2]));
                    toDelete = true;
                }
                else if (Tokens[1] == "OR")
                {
                    Wires[Tokens[4]] = (std::stoi(Tokens[0]) | std::stoi(Tokens[2]));
                    toDelete = true;
                }
                else if (Tokens[1] == "LSHIFT")
                {
                    Wires[Tokens[4]] = (std::stoi(Tokens[0]) << std::stoi(Tokens[2]));
                    toDelete = true;
                }
                else if (Tokens[1] == "RSHIFT")
                {
                    Wires[Tokens[4]] = (std::stoi(Tokens[0]) >> std::stoi(Tokens[2]));
                    toDelete = true;
                }
                else
                {
                    std::cout << "Unrecognized Command" << std::endl;
                }
            }

            if (toDelete)
            {
                Commands.erase(Commands.begin() + i);
                --i;
            }
            std::cout << "Commands size: " << Commands.size() << std::endl;

            i++;
        }
    }
    for (auto a : Wires)
    {
        std::cout << "Wire " << a.first << " is " << a.second << std::endl;
    }
    std::cout << Wires.size() << std::endl;

    return 0;
}
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cctype>

class Structure
{
public:
    std::vector<Structure *> Contents;
    std::ifstream *myfile;

    Structure(std::ifstream *myfile)
    {
        this->myfile = myfile;
    }

    Structure()
    {
    }

    void Loop();

    virtual int Ret()
    {
        for (auto a : this->Contents)
        {
            this->StructSum += a->Ret();
        }
        return this->StructSum;
    }

    char c;
    std::string CurrentString = "";
    int CurrentNumber;
    bool isNegative;
    int StructSum = 0;
};

class JustNumber : public Structure
{
public:
    int Num;
    JustNumber(int Number)
    {
        this->Num = Number;
    }

    int Ret()
    {
        return this->Num;
    }
};

class JSArray : public Structure
{
public:
    JSArray(std::ifstream *myfile)
    {
        this->myfile = myfile;
        this->Loop();
    }
};

class JSObject : public Structure
{
public:
    JSObject(std::ifstream *myfile)
    {
        this->myfile = myfile;
        this->Loop();
    }

    void Loop();
    bool isRed = false;
};

void Structure::Loop()
{
    while (this->myfile->get(c))
    {
        std::cout << c;
        if (c == ']')
            return;
        if (c == '[')
        {
            Contents.push_back(new JSArray(this->myfile));
        }
        if (c == '{')
        {
            Contents.push_back(new JSObject(this->myfile));
        }
        if (c == '-')
            isNegative = true;
        if (!std::isdigit(c))
            continue;
        do
        {
            CurrentString += c;
            myfile->get(c);
            std::cout << c;

            CurrentNumber = std::stoi(CurrentString);
        } while (std::isdigit(c));
        if (isNegative)
            CurrentNumber = -CurrentNumber;
        isNegative = false;
        Contents.push_back(new JustNumber(CurrentNumber));
        CurrentString = "";
        if (c == ']')
            return;
    }
}

void JSObject::Loop()
{
    while (this->myfile->get(c))
    {
        std::cout << c;
        if (c == '"')
        {
            while (this->myfile->get(c))
            {
                if (c == '\"')
                    break;
                CurrentString += c;
            }
            if (CurrentString == "red")
            {
                this->isRed = true;
            }
            CurrentString = "";
        }
        if (c == '}')
        {
            if (isRed)
            {
                this->Contents.clear(); //this leaks
            }
            return;
        }
        if (c == '[')
        {
            Contents.push_back(new JSArray(this->myfile));
        }
        if (c == '{')
        {
            Contents.push_back(new JSObject(this->myfile));
        }
        if (c == '-')
            isNegative = true;
        if (!std::isdigit(c))
            continue;
        do
        {
            CurrentString += c;
            myfile->get(c);
            std::cout << c;
            if (c == '}')
            {
                CurrentNumber = std::stoi(CurrentString);
                if (isNegative)
                    CurrentNumber = -CurrentNumber;
                Contents.push_back(new JustNumber(CurrentNumber));
                if (isRed)
                {
                    this->Contents.clear(); //this leaks
                }
                return;
            }
            CurrentNumber = std::stoi(CurrentString);
        } while (std::isdigit(c));
        if (isNegative)
            CurrentNumber = -CurrentNumber;
        isNegative = false;
        Contents.push_back(new JustNumber(CurrentNumber));
        CurrentString = "";
    }
}

int main()
{
    std::ifstream myfile("Day12Input.txt"); // hardcoded because lazy

    Structure *struc = new Structure(&myfile);
    struc->Loop();

    std::cout << struc->Ret() << std::endl;
    return 0;
}
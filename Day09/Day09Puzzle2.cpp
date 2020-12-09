#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

int TravellingSanta(std::vector<std::vector<int>> Graph, int s)
{
    std::vector<int> Vertices;
    // Stores all the edges (Vertices) of the graph
    for (int i = 0; i < Graph[0].size(); i++)
    {
        if (i != s)
            Vertices.push_back(i);
    }

    int maxPath = 0;
    do
    {
        int currentPath = 0;

        int k = s;
        for (int i = 0; i < Vertices.size(); i++)
        {
            currentPath += Graph[k][Vertices[i]];
            k = Vertices[i];
        }
        maxPath = std::max(maxPath, currentPath);

    } while (std::next_permutation(Vertices.begin(), Vertices.end()));
    // This is a brute force approach that just slams through all of the possibilities, and returns the shortest path.

    return maxPath; // Very easy change between Puzzle 1 and 2, literally just rename min to max.
}

int main()
{
    // The Input file is definitely parsable, but since this is a one off thing, I figured it would save a lot of time 
    // just parsing it by hand

    std::vector<std::vector<int>> Graph =
        {{0, 34, 100, 63, 108, 111, 89, 132},
         {34, 0, 4, 79, 44, 147, 133, 74},
         {100, 4, 0, 105, 95, 48, 88, 7},
         {63, 79, 105, 0, 68, 134, 107, 40},
         {108, 44, 95, 68, 0, 11, 66, 144},
         {111, 147, 48, 134, 11, 0, 115, 135},
         {89, 133, 88, 107, 66, 115, 0, 127},
         {132, 74, 7, 40, 144, 135, 127, 0}};

    std::vector<int> Values;

    for (int i = 0; i < 8; i++)
        Values.push_back(TravellingSanta(Graph, i));

    //Sorting for easier readabilty of output
    std::sort(Values.begin(), Values.end());

    for (auto a : Values)
        std::cout << a << std::endl;

    return 0;
}
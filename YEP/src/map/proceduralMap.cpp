/*
** EPITECH PROJECT, 2021
** Untitled (Workspace)
** File description:
** proceduralMap
*/
#include <string>
#include <string.h>
#include <algorithm>
#include <stdlib.h>
#include <fstream>
#include <time.h>
#include <iostream>

std::ifstream openFile(int LR, std::string TB)
{
    srand(time(NULL) + LR);
    int resRand = (rand() % 4) + 1;
    std::string filePath;
    std::ifstream res;

    for (int i = resRand; i != 0; i--)
        resRand = (rand() % 4) + 1;
    if (LR >= 1) {
        filePath = std::string() + "src/map/parts/" + TB + "Right/p" +
            std::to_string(resRand) + ".txt";
        std::cout << "Opening: " << filePath << std::endl;
        res.open(filePath);
    } else if (LR <= 0) {
        filePath = std::string() + "src/map/parts/" + TB + "Left/p" +
            std::to_string(resRand) + ".txt";
        std::cout << "Opening: " << filePath << std::endl;
        res.open(filePath);
    }
    return (res);
}

char **generateMap(void)
{
    char **map = (char**)malloc(sizeof(char*) * 12);
    std::ifstream left = openFile(0, "top");
    std::ifstream right = openFile(1, "top");
    std::string buf;

    for (int i = 0; i != 6; i++) {
        map[i] = (char*)malloc(sizeof(char) * 13);
        std::getline(left, buf);
        buf.substr(0, buf.size()-1);
        strcpy(map[i], buf.c_str());
        std::getline(right, buf);
        buf.insert(buf.end(), '\n');
        strcat(map[i], buf.c_str());
    }
    left = openFile(-1, "bot");
    right = openFile(2, "bot");
    for (int i = 6; i != 12; i++) {
        map[i] = (char*)malloc(sizeof(char) * 13);
        std::getline(left, buf);
        buf.substr(0, buf.size()-1);
        strcpy(map[i], buf.c_str());
        std::getline(right, buf);
        buf.insert(buf.end(), '\n');
        strcat(map[i], buf.c_str());
    }
    return (map);
}

// int main()
// {
//     char **map = generateMap();

//     for (int i = 0; i != 12; i++)
//         std::cout << map[i];
// }
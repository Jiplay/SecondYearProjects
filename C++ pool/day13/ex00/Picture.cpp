/*
** Picture.cpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:41:20 AM 2021 julien.garsia
** Last update Tue Jan 18 11:17:49 AM 2021 julien.garsia
*/

#include "Picture.hpp"

Picture::Picture()
{
    data = "";
}

Picture::~Picture()
{
}

Picture::Picture(const std::string &file)
{
    Picture::getPictureFromFile(file);
}

bool Picture::getPictureFromFile(const std::string &files)
{
    if (files == "") {
        data = "";
        return true;
    }

    std::ifstream file(files);
    if (file.is_open()) {
        std::string line;
        while (getline(file, line)) {
            data.append(line);
            data.append("\n");
        }
        file.close();
    }
    else {
        data = "ERROR";
        return false;
    }
    return true;
}

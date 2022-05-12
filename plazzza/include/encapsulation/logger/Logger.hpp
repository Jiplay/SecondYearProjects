/*
** EPITECH PROJECT, 2021
** Logger.hpp
** File description:
** Logger
*/

#ifndef _LOGGER_HPP_
#define _LOGGER_HPP_

#include <iostream>
#include <sys/stat.h>
#include <fstream>
#include <string>
#include <ctime>
#include <cstring>
#include <algorithm>
#include <vector>
#include <sstream>


class Logger {
    public:
        Logger();
        Logger(const char *path);
        ~Logger();
        void AddLine(std::string string);

    protected:
        std::string filename;
    private:
};

#endif /* !_LOGGER_HPP_ */

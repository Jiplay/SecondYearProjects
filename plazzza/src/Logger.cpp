/*
** EPITECH PROJECT, 2021
** Logger.cpp
** File description:
** Logger
*/

#include <iostream>
#include <sys/stat.h>
#include <sys/types.h>
#include <fstream>

#include "../include/encapsulation/logger/Logger.hpp"

Logger::Logger() 
{
    const char *path = "Logs/";
    if (mkdir(path, 0777) == -1)
    ;
    std::string _filename(path);
    this->filename = _filename;
    filename.append("/logs.log");
    std::fstream app;

    app.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    if (!app) {
        app.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
        app.close();
    } else {
        app.close();
    }    
}

Logger::Logger(const char *path) 
{

    std::string line(path);
    std::string folder = line.substr(0, line.find("/"));

    const char *tocut = folder.c_str();
    if (mkdir(tocut, 0777) == -1)
    ;
    std::string _filename(path);
    this->filename = _filename;    
    std::fstream app;

    app.open(filename, std::fstream::in | std::fstream::out | std::fstream::app);
    if (!app) {
        app.open(filename, std::fstream::in | std::fstream::out | std::fstream::trunc);
        app.close();
    } else {
        app.close();
    }    
}

Logger::~Logger()
{
}

void Logger::AddLine(std::string string)
{
    std::ofstream foutput;
    std::ifstream finput;

    finput.open(filename);
    foutput.open(filename, std::ios::app);

    time_t now = time(0);
    tm *ltm = localtime(&now);

    std::string time = '[' + std::to_string(ltm->tm_mday) + '/' + std::to_string((1 + ltm->tm_mon)) + '/' + std::to_string((1900 + ltm->tm_year)) + '-' + std::to_string(ltm->tm_hour) + ':' + std::to_string(ltm->tm_min) + ':' + std::to_string(ltm->tm_sec) + ']' + ' ';

    if (finput.is_open())
        foutput << time << string;
    
    finput.close();
    foutput.close();
}
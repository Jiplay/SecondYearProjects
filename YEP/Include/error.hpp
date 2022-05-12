/*
** EPITECH PROJECT, 2021
** error.hpp
** File description:
** error.hpp
*/

#ifndef _ERROR_HPP_
#define _ERROR_HPP_

#include <string>

class IndieError : public std::exception
{
public:
    IndieError(std::string const &msg, std::string const &component);
    const char *what() const noexcept {return _msg.c_str();};
    
private:
    std::string _msg;
    std::string _cmp;
};

class MenuError : public IndieError
{
public:
    MenuError(std::string const &m, std::string const &c);
};

class GameError : public IndieError
{
public:
    GameError(std::string const &m, std::string const &c);
};

class AssetError : public IndieError
{
public:
    AssetError(std::string const &m, std::string const &c);
};

#endif /* !_ERROR_HPP_ */

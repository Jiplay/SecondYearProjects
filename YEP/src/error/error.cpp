/*
** EPITECH PROJECT, 2021
** error.cpp
** File description:
** error.cpp
*/

#include "../../Include/error.hpp"
#include <stdlib.h>


IndieError::IndieError(std::string const &m, std::string const &c)
{
    _msg = m;
    _cmp = c;
}

MenuError::MenuError(std::string const &m, std::string const &c) : IndieError(m, c)
{

}

GameError::GameError(std::string const &m, std::string const &c) : IndieError(m, c)
{

}

AssetError::AssetError(std::string const &m, std::string const &c) : IndieError(m, c)
{
    
}

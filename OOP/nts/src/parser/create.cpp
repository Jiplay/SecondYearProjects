/*
** create.cpp for NTS in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/NTS/B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar/src/parser
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Feb 9 10:37:30 AM 2021 julien.garsia
** Last update Thu Mar 3 10:41:06 AM 2021 julien.garsia
*/

#include "parser.hpp"
#include "../compo/c4001.hpp"
#include "../compo/c4011.hpp"
#include "../compo/c4030.hpp"
#include "../compo/c4071.hpp"
#include "../compo/c4081.hpp"
#include "../compo/output.hpp"
#include "../compo/true.hpp"
#include "../compo/false.hpp"
#include "../compo/input.hpp"
#include "../exceptions/errors.hpp"

// Segfault when something is not in the list

std::unique_ptr<nts::IComponent> Parser::createComponent(const std::string &type)
{
    if (type == "4001")
        return std::make_unique<c4001>(type);
    if (type == "4011")
        return std::make_unique<c4011>(type);
    if (type == "4030")
        return std::make_unique<c4030>(type);
    if (type == "4071")
        return std::make_unique<c4071>(type);
    if (type == "4081")
        return std::make_unique<c4081>(type);
    if (type == "output")
        return std::make_unique<Output>(type);
    if (type == "input")
        return std::make_unique<Input>(type);
    if (type == "true")
        return std::make_unique<True>(type);
    if (type == "false")
        return std::make_unique<False>(type);
    
    throw Errors("Unknown component", type);
}
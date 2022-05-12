/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar
** File description:
** cli
*/

#ifndef CLI_HPP_
#define CLI_HPP_

#include <iostream>
#include <csignal>
#include <string>
#include <map>
#include <chrono>
#include <thread>
#include "../compo/Acomponent.hpp"
#include "../parser/parser.hpp"
#include "../exceptions/errors.hpp"


int maincli(std::map<std::string, std::unique_ptr<nts::IComponent>> *components);

#endif /* !CLI_HPP_ */

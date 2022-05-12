/*
** EPITECH PROJECT, 2021
** B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar
** File description:
** cli
*/

#include "cli.hpp"

void check_legal(std::string value, std::string name, std::map<std::string, std::unique_ptr<nts::IComponent>> *components)
{
    if (components->count(name)>0)
    {
        auto s = components->find(name);
        Acomponent *a = static_cast<Acomponent *>(s->second.get());
        a->setValue(value);
    }
    else
        throw Errors("Name not found.", name);
}

void parscli(std::string s, std::map<std::string, std::unique_ptr<nts::IComponent>> *components)
{
    std::string delimiter = "=";

    size_t pos = 0;
    std::string token;
    std::string val;
    int value = 0;
    while ((pos = s.find(delimiter)) != std::string::npos) {
        token = s.substr(0, pos);
        value++;
        val = s.substr(token.length() + 1);
        s.erase(0, pos + delimiter.length());
    }
    check_legal(val, token, components);
}

void simulate(std::map<std::string, std::unique_ptr<nts::IComponent>> *components)
{
    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it = components->begin();
    int a = 0;
    std::string j = " ";

    while (it != components->end())
    {
        Acomponent *a = static_cast<Acomponent *>(it->second.get());
        if (a->getType() == "Input" && a->getValue() == (-1))
            a++;
        if (a->getType() == "CMP")
            j = a->getName();
        it++;
    }
    if (a != 0)
        throw Errors ("Some inputs are undefined, please define them before simulating", ".");
    if (j != " ")
    {
        components->at(j)->compute(1);
    }
}

int display_print(std::string str, std::map<std::string, std::unique_ptr<nts::IComponent>> *components)
{
    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it = components->begin();
    
    if (str == "input(s):")
    {
        std::cout << str << std::endl;
        while (it != components->end())
        {
            Acomponent *a = static_cast<Acomponent *>(it->second.get());
            if (a->getType() == "Input")
            {
                if (a->getValue() == -1)
                    std::cout << "  " << a->getName() << ": U" << std::endl;
                else
                    std::cout << "  " << a->getName() << ": " << a->getValue() << std::endl;
            }
            it++;
        }
        return 1;
    }
    else
    {
        std::cout << str << std::endl;
        while (it != components->end())
        {
            Acomponent *a = static_cast<Acomponent *>(it->second.get());
            if (a->getType() == "Output")
            {
                std::cout << "  " << a->getName() << ": " << a->getstate() << std::endl;
            }
            it++;
        }
        return 1;
    }
    return 2;
}

int display(std::map<std::string, std::unique_ptr<nts::IComponent>> *components, int tick, bool state)
{
    int a = 0;
    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it = components->begin();
    std::map<std::string, int> plan;

    std::cout << "tick: " << tick << std::endl;
    if (state == false)
        a = 1;
    while (it != components->end() && a != 2)
    {
        Acomponent *a1 = static_cast<Acomponent *>(it->second.get());
        if (a1->getType() == "Input" && a == 0)
            a = display_print("input(s):", components);
        if (a1->getType() == "Output" && a == 1) {
            a = display_print("output(s):", components);
            return 1;
        }
        it++;
    }
    return 0;
}

void cmd_dump(std::map<std::string, std::unique_ptr<nts::IComponent>> *components)
{
    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it = components->begin();

    while (it != components->end())
    {
        it->second->dump();
        it++;
    }
}

void signalHandler(int signum)
{
   std::cout << "Interrupt signal (" << signum << ") received." << std::endl;
   exit (signum);
}

bool is_there_input(std::map<std::string, std::unique_ptr<nts::IComponent>> *components)
{
    std::map<std::string, std::unique_ptr<nts::IComponent>>::iterator it = components->begin();

    while (it != components->end())
    {
        Acomponent *a = static_cast<Acomponent *>(it->second.get());
        if (a->getType() == "Input")
            return true;
        it++;
    }
    return false;
}

int maincli(std::map<std::string, std::unique_ptr<nts::IComponent>> *components)
{
    int tick = 0;
    std::chrono::milliseconds atik(1000);
    
    while (1) {
        std::cout << "> ";
        std::string command;
        std::cin >> command;
        if (command == "exit" || std::cin.eof())
            return 0;
        else if (command == "display")
            display(components, tick, is_there_input(components));
        else if (command == "simulate")
        {
            tick++;
            simulate(components);
        }
        else if (command == "loop")
        {
            signal (SIGINT, signalHandler);
            while (1)
            {
                simulate(components);
                display(components, tick, is_there_input(components));
                tick++;
                std::this_thread::sleep_for(atik);
            }
            return 0;
        }
        else if (command == "dump")
            cmd_dump(components);
        else
        {
            parscli(command, components);
        }
    }
}
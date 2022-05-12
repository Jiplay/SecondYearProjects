/*
** parser.cpp for NTS in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/NTS/src/parser
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Feb 8 10:38:10 AM 2021 julien.garsia
** Last update Sat Mar 12 11:47:45 AM 2021 julien.garsia
*/

#include "parser.hpp"
#include "../compo/Icomponent.hpp"
#include "../exceptions/errors.hpp"
#include "../compo/Acomponent.hpp"

void Acomponent::setname(std::string s, std::string v)
{
    _name = s;
    _value = v;
}

bool Parser::is_non_empty(std::string &line)
{
    unsigned long int i = 0;
    while (i < line.size())
    {
        if (line[i] != '\t' && line[i] != ' ')
            return true;
        i++;
    }
    return false;
} 

void Parser::set_links(std::stringstream &str, std::map<std::string, std::unique_ptr<nts::IComponent>> *chipsets)
{
    std::string line;
    std::regex rgx("^(\\S+):(\\d+)\\s+(\\S+):(\\d+)");
    std::smatch match;

    while (std::getline(str, line)) {
        if (std::regex_search(line, match, rgx))
        {
            chipsets->at(std::string(match[1]))->setLink(stoi(match[2]), *chipsets->at(std::string(match[3])), stoi(match[4]));
            chipsets->at(std::string(match[3]))->setLink(stoi(match[4]), *chipsets->at(std::string(match[1])), stoi(match[2]));
        }
    }
}

std::string Parser::extract_v(std::string &v)
{
    std::string find_me_1 ("(1)");
    std::string find_me_0 ("(0)");

    std::size_t found = v.find(find_me_1);
    if (found!=std::string::npos) { 
        v.erase(found, find_me_1.length());
        return "1";
    }

    found = v.find(find_me_0);
    if (found!=std::string::npos) {
        v.substr(found);
        return "0";
    }
    return "-1";
}

std::string Parser::padd_line(std::string s)
{
    int last = s.size() - 1;

    while (last >= 0 && s[last] == ' ')
        --last;
    return s.substr(0, last + 1);
}

std::map<std::string, std::unique_ptr<nts::IComponent>> Parser::create_chipset(std::stringstream &str)
{
    std::string line;
    std::regex rgx("^(\\S+)\\s+([^\\s(]+)(?:\\(([^\\s]+)\\))?$");
    std::smatch match;
    std::map<std::string, std::unique_ptr<nts::IComponent>> chipsets;
    std::string a;

    while (getline(str, line) && line.find(".links:")) {
        a = extract_v(line);
        line = padd_line(line);
        if (std::regex_search(line, match, rgx)) {
            if (chipsets.find(match[2]) == chipsets.end()) {
                chipsets[match[2]] = createComponent(match[1]);
                auto *t = chipsets[match[2]].get();
                dynamic_cast<Acomponent *>(t)->setname(std::string(match[2]), a);
            } else
                throw Errors("Several components share the same name.", match[2]);
        } else
            throw Errors("Syntax error.", line);
        }
    try
    {
        set_links(str, &chipsets);
    }
    catch(const std::exception& e)
    {
        throw Errors("Failed linkage", ".");
    }

    return (chipsets);
}

std::map<std::string, std::unique_ptr<nts::IComponent>> &Parser::getmap()
{
    return _map;
}

Parser::Parser(const char *file)
{
    std::ifstream _file(file);
    std::string line;
    std::regex rgx("^([^#]+)");
    std::stringstream str;
    std::smatch match;
    int a = 0;

    if (_file)
    {
        while (std::getline(_file, line)) {
            if (!line.find(".links:"))
                a = 1;
            if (std::regex_search(line, match, rgx)) {
                line = match[1];
                if (is_non_empty(line))
                    str << line << std::endl;
            }
        }
        std::getline(str, line);

        if (!line.find(".chipsets:") && a == 1) {
            _map = create_chipset(str);
        }

        else {
            throw Errors("No chipset section.", file);
        }
    }
    else
        throw Errors("No such file.", file);
}

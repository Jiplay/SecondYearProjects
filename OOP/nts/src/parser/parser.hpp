/*
** parser.hpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Feb 8 10:43:47 AM 2021 julien.garsia
** Last update Sat Mar 12 11:41:21 AM 2021 julien.garsia
*/

#ifndef PARSER_HPP_
#define PARSER_HPP_

#include <fstream>
#include "../compo/Icomponent.hpp"
#include <sstream>

class Parser
{
    public:
        Parser(const char *file);
        ~Parser() = default;

        bool is_non_empty(std::string &line);
        std::string extract_v(std::string &line);
        std::string padd_line(std::string line);
        void set_links(std::stringstream &str, std::map<std::string, std::unique_ptr<nts::IComponent>> *chipsets);
        std::map<std::string, std::unique_ptr<nts::IComponent>> create_chipset(std::stringstream &str);
        std::unique_ptr<nts::IComponent> createComponent(const std::string &type);
        std::map<std::string, std::unique_ptr<nts::IComponent>> &getmap();
    private:
        std::map<std::string, std::unique_ptr<nts::IComponent>> _map;

};

#endif /* !PARSER_HPP_ */

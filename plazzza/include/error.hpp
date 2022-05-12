/*
** error.hpp for plazza
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Apr 7 11:39:14 AM 2021 julien.garsia
** Last update Wed Apr 20 9:58:38 AM 2021 julien.garsia
*/

#ifndef ERROR_HPP_
#define ERROR_HPP_

#include <string>

class PlazzaError : public std::exception
{
    public:
        PlazzaError(std::string const &msg, std::string const &component);
        const char *what() const noexcept {return _msg.c_str();};
    private:
        std::string _msg;
        std::string _cmp;
};

class ReceptionError : public PlazzaError
{
    public:
        ReceptionError(std::string const &msg, std::string const &component);
};

class ProcessError : public PlazzaError
{
    public:
        ProcessError(std::string const &msg, std::string const &component);
};


#endif /* !ERROR_HPP_ */

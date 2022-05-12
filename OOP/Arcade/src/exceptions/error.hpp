/*
** error.hpp for B-OOP-400-PAR-4-1-arcade-ibrahim.zafar
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 16 10:55:22 AM 2021 julien.garsia
** Last update Wed Mar 16 11:35:40 AM 2021 julien.garsia
*/

#ifndef ERROR_HPP_
# define ERROR_HPP_

#include <string>

class ArcadeError : public std::exception
{
    public:
        ArcadeError(std::string const &msg, std::string const &component);
        const char *what() const noexcept {return _msg.c_str();};
    private:
        std::string _msg;
        std::string _cmp;
};

class CoreError : public ArcadeError
{
    public:
        CoreError(std::string const &msg, std::string const &component);
};


#endif /* !ERROR_HPP_ */

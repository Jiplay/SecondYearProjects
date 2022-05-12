/*
** errors.hpp for NTS in /Users/juliengarsia/Documents/EPITECH/Delivery/2yearbis/OOP/NTS/B-OOP-400-PAR-4-1-tekspice-ibrahim.zafar/src/exceptions
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Feb 19 10:17:37 AM 2021 julien.garsia
** Last update Tue Feb 22 10:13:47 AM 2021 julien.garsia
*/

#ifndef ERRORS_HPP_
# define ERRORS_HPP_

#include <exception>
#include <string>

class Errors : public std::exception
{
    public:
        Errors(std::string const &msg, std::string const &what) noexcept;
        ~Errors() noexcept {};
        const char *what() const noexcept;

    private:
        std::string _msg;
        std::string _indi;

};


#endif /* !ERRORS_HPP_ */

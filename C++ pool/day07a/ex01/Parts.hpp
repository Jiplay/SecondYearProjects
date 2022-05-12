/*
** Parts.hpp for B-CPP-300-PAR-3-2-CPPD07A-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 4:00:16 PM 2021 julien.garsia
** Last update Thu Jan 13 9:39:01 PM 2021 julien.garsia
*/

#ifndef PARTS_HPP_
# define PARTS_HPP_

#include <iostream>

class Arms
{
private:
    std::string _serial = "A-01";
    bool _functional = true;
public:
    Arms(std::string serial = "A-01", bool functional = true);
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
};

class Head
{
private:
    std::string _serial = "H-01";
    bool _functional = true;
public:
    Head(std::string serial = "H-01", bool functional = true);
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
};

class Legs
{
private:
    std::string _serial = "L-01";
    bool _functional = true;
public:
    Legs(std::string serial = "L-01", bool functional = true);
    bool isFunctional() const;
    std::string serial() const;
    void informations() const;
};


#endif /* !PARTS_HPP_ */

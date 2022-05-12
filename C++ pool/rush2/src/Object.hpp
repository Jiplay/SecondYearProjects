/*
** Object.hpp for B-CPP-300-PAR-3-2-CPPrush2-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 16 9:01:29 AM 2021 julien.garsia
** Last update Sun Jan 16 9:01:46 AM 2021 julien.garsia
*/

#ifndef OBJECT_HPP_
# define OBJECT_HPP_

#include <iostream>
#include <string>

class Object {
    public:
        Object(const std::string &name);
        virtual ~Object();
        const std::string &getName() const;
        const std::string &getType() const;
    protected:
        std::string _name;
        std::string type;
};

std::ostream &operator<<(std::ostream &o, Object const &obj);

#endif /* !OBJECT_HPP_ */

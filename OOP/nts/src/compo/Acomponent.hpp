/*
** Acomponent.hpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Mar 11 10:31:17 AM 2021 julien.garsia
** Last update Sat Mar 12 11:43:43 AM 2021 julien.garsia
*/

#ifndef ACOMPONENT_HPP_
#define ACOMPONENT_HPP_

#include "Icomponent.hpp"


class Acomponent : public nts::IComponent {
    public:
        virtual ~Acomponent() = default;
        virtual void setstate(std::string state) = 0;
        virtual void setValue(std::string value) = 0;
        virtual int getValue() = 0;
        virtual std::string getType() = 0;
        void setname(std::string s, std::string v);
        virtual nts::Tristate getstate() const = 0;
        virtual std::string getName() = 0;
    protected:
        std::string _name;
        std::string _value;
        std::string _type;
};

#endif /* !ACOMPONENT_HPP_ */

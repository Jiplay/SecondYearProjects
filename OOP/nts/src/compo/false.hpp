/*
** true.hpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Mar 2 11:24:06 AM 2021 julien.garsia
** Last update Thu Mar 3 10:42:40 AM 2021 julien.garsia
*/

#ifndef FALSE_HPP_
#define FALSE_HPP_

#include "Icomponent.hpp"
#include "Acomponent.hpp"
#include "pin.hpp"

class False : public Acomponent
{
public:
    False(const std::string & = "");
    nts::Tristate compute(std::size_t pin_num_this = 1);
    void setLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
    void dump(void) const;
    void simulate(std::size_t tick);
    ~False() = default;
    nts::Tristate getstate() const;
    std::string getName();
    int getValue();
    std::string getType();
    void setstate(std::string state);
    void setValue(std::string value);
private:
    std::vector<nts::Pin> _pins;
    nts::Tristate _state;
    // const std::string &save() const;
};

#endif /* !TRUE_HPP_ */

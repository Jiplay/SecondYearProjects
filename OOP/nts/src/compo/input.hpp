/*
** output.hpp for NTS
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Thu Feb 11 9:57:13 AM 2021 julien.garsia
** Last update Tue Feb 15 9:34:55 AM 2021 julien.garsia
*/

#ifndef INPUT_HPP_
#define INPUT_HPP_

#include "Icomponent.hpp"
#include "Acomponent.hpp"
#include "pin.hpp"

class Input : public Acomponent
{
public:
    Input(const std::string & = "");
    nts::Tristate compute(std::size_t pin_num_this = 1);
    void setLink(std::size_t pin_num_this, nts::IComponent &component, std::size_t pin_num_target);
    void dump(void) const;
    void simulate(std::size_t tick);
    ~Input() = default;
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

#endif /* !INPUT_HPP_ */

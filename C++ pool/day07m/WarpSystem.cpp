/*
** WarpSystem.cpp for B-CPP-300-PAR-3-2-CPPD07M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 9:05:36 AM 2021 julien.garsia
** Last update Wed Jan 12 12:28:26 PM 2021 julien.garsia
*/

#include "WarpSystem.hpp"

bool WarpSystem::QuantumReactor::isStable()
{
    return (this->_stability);
}

WarpSystem::QuantumReactor::QuantumReactor()
{
    _stability = true;
}

void WarpSystem::QuantumReactor::setStability(bool stability)
{
    this->_stability = stability;
}

WarpSystem::Core::Core(QuantumReactor *q)
{
    this->_coreReactor = q;
}

WarpSystem::QuantumReactor *WarpSystem::Core::checkReactor()
{
    return (this->_coreReactor);
}


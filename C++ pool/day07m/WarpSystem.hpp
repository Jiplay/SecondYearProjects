/*
** WarpSystem.hpp for B-CPP-300-PAR-3-2-CPPD07M-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Jan 12 9:05:41 AM 2021 julien.garsia
** Last update Wed Jan 12 11:23:11 AM 2021 julien.garsia
*/

#ifndef WARPSYSTEM_HPP_
# define WARPSYSTEM_HPP_

namespace WarpSystem
{
    class QuantumReactor
    {
        public:
            bool _stability;
            bool isStable();
            void setStability(bool stability);
            QuantumReactor();
    };
    class Core
    {
        public:
            QuantumReactor *_coreReactor;
            QuantumReactor *checkReactor();
            Core(QuantumReactor *q);
    };
}

#endif /* !WARPSYSTEM_HPP_ */

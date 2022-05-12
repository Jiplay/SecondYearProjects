/*
** ex01.hpp for B-CPP-300-PAR-3-2-CPPD15-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 20 12:06:57 PM 2021 julien.garsia
** Last update Thu Jan 20 3:45:12 PM 2021 julien.garsia
*/

#ifndef EX01_HPP_
# define EX01_HPP_

#include "string"

class toto {
    public:
        toto() = default;

        toto &operator=(const toto&) = delete;
        toto(const toto &) = delete;

        bool operator==(const toto&) const { return  true; }
        bool operator>(const toto&) const { return  false; }
        bool operator<(const toto&) const { return  false; }
};

template <typename T>
int compare(const T &a, const T &b)
{
    if (a > b) {
        return (1);
    } else if (a < b) {
        return -1;
    } else
        return 0;
}

template <>
int compare(const char * const &a, const char * const &b)
{
    std::string aa(a);
    std::string bb(b);

    if (aa.compare(bb) > 0) {
        return 1;
    } else if (aa.compare(b) < 0) {
        return -1;
    } else
        return 0;
}

#endif /* !EX01_HPP_ */

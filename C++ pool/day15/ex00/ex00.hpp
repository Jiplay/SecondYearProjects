/*
** ex00.hpp for B-CPP-300-PAR-3-2-CPPD15-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed Jan 20 11:52:57 AM 2021 julien.garsia
** Last update Thu Jan 20 12:02:45 PM 2021 julien.garsia
*/

#ifndef EX00_HPP_
# define EX00_HPP_

template <typename T>
void swap(T &a, T &b)
{
    T tmp = a;

    a = b;
    b = tmp;
}

template <typename T>
T min(T a, T b)
{
    if (a >= b)
        return b;
    return a;
}

template <typename T>
T max(T a, T b)
{
    if (a <= b)
        return b;
    return a;
}

template <typename T>
T add(T a, T b)
{
    return (a + b);
}


#endif /* !EX00_HPP_ */

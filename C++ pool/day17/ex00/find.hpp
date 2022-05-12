/*
** find.hpp for B-CPP-300-PAR-3-2-CPPD17-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Fri Jan 22 9:42:16 AM 2021 julien.garsia
** Last update Sat Jan 22 9:44:49 AM 2021 julien.garsia
*/

#ifndef FIND_HPP_
# define FIND_HPP_

#include <iostream>
#include <algorithm>

template<typename T>
typename T::iterator do_find(T &temp, int a) {
    return (std::find(temp.begin(), temp.end(), a));
}

#endif /* !FIND_HPP_ */

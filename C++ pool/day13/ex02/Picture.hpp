/*
** Picture.hpp for B-CPP-300-PAR-3-2-CPPD13-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Mon Jan 18 9:41:15 AM 2021 julien.garsia
** Last update Tue Jan 18 11:00:40 PM 2021 julien.garsia
*/

#ifndef PICTURE_HPP_
# define PICTURE_HPP_

#include <iostream>
#include <fstream>

class Picture {
    public:
        Picture();
        ~Picture();
        Picture(const Picture &p);
        Picture &operator=(Picture const &t);

        std::string data;
        bool getPictureFromFile(const std::string &file);
        Picture(const std::string &file);
    protected:
    private:
};

#endif /* !PICTURE_HPP_ */

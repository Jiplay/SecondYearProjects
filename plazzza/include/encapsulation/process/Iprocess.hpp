/*
** Iprocess.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 9:50:56 AM 2021 julien.garsia
** Last update Tue May 3 10:56:13 AM 2021 julien.garsia
*/

#ifndef IPROCESS_HPP_
# define IPROCESS_HPP_

enum STATUS {
    NOT_BEGIN,
    RUNNING,
    OVER
};

class Iprocess {
    public:
    virtual ~Iprocess() = default;

    virtual pid_t start() = 0;
    virtual void wait() = 0;
    virtual bool isChild() const = 0;
};

#endif /* !IPROCESS_HPP_ */

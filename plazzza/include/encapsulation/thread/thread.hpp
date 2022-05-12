/*
** thread.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Wed May 12 10:25:35 AM 2021 julien.garsia
** Last update Thu May 12 10:39:35 AM 2021 julien.garsia
*/

#ifndef THREAD_HPP_
#define THREAD_HPP_

#include <thread>

class IThread {
    public:
    virtual ~IThread() = default;

    virtual void join() = 0;
    virtual void detach() = 0;
    virtual void swap(std::thread thread) = 0;
    virtual std::thread::id getId() = 0;

};

class Thread : public IThread {
    public:
        Thread();
        ~Thread();
        void join();
        void detach();
        void swap(std::thread thread);
        std::thread::id getId();
    private:
        std::thread t;
};

#endif /* !THREAD_HPP_ */

/*
** EPITECH PROJECT, 2021
** my_thread_pool.cpp
** File description:
** my_thread_pool
*/

#include "../include/encapsulation/threadpool/my_thread_pool.hpp"

ThreadPool::ThreadPool(unsigned int n)
    : busy()
    , stop()
{
    for (unsigned int i=0; i<n; ++i)
        workers.emplace_back(std::bind(&ThreadPool::thread_proc, this));
}

ThreadPool::~ThreadPool()
{
    // set stop-condition
    std::unique_lock<std::mutex> latch(queue_mutex);
    stop = true;
    cv_task.notify_all();
    latch.unlock();

    // all threads terminate, then we're done.
    for (auto& t : workers)
        t.join();
}

void ThreadPool::thread_proc()
{
    while (true)
    {
        std::unique_lock<std::mutex> latch(queue_mutex);
        cv_task.wait(latch, [this](){ return stop || !tasks.empty(); });
        if (!tasks.empty())
        {
            // got work. set busy.
            ++busy;

            // pull from queue
            auto fn = tasks.front();
            tasks.pop();

            // release lock. run async
            latch.unlock();

            // run function outside context
            fn();

            latch.lock();
            --busy;
            cv_finished.notify_one();
        }
        else if (stop)
        {
            break;
        }
    }
}

void ThreadPool::waitFinished()
{
    std::unique_lock<std::mutex> lock(queue_mutex);
    cv_finished.wait(lock, [this](){ return tasks.empty() && (busy == 0); });
}

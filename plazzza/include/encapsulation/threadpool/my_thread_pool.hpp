/*
** EPITECH PROJECT, 2021
** my_thread_pool.hpp
** File description:
** my_thread_pool.hpp
*/

#ifndef _MY_THREAD_POOL_HPP_
#define _MY_THREAD_POOL_HPP_

#include <vector>
#include <thread>
#include <mutex>
#include <future>
#include <queue>
#include <functional>

// class ThreadPool {
//     public:
//         ThreadPool() = default;
//         ThreadPool(size_t);
//         ~ThreadPool();

//         template<class F, class... Args>
//         auto enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;
//     private:
//         std::vector<std::thread> my_workers;
//         std::queue<std::function<void()>> my_function_list;    
//         std::mutex my_mutex_thread;
//         std::condition_variable my_condition_variable;
//         bool is_not_working;
// };

// template<class F, class... Args>
// auto ThreadPool::enqueue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
// {
//     using return_type = typename std::result_of<F(Args...)>::type;
//     auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
//     std::future<return_type> res = task->get_future();
//     {
//         std::unique_lock<std::mutex> lock(my_mutex_thread);
//         my_function_list.emplace([task](){ (*task)(); });
//     }
//     my_condition_variable.notify_one();
//     return res;
// }


class ThreadPool
{
public:
    ThreadPool(unsigned int n = std::thread::hardware_concurrency());

    template<class F, class... Args>
    auto my_thread_queue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>;
    void waitFinished();
    ~ThreadPool();

private:
    std::vector< std::thread > workers;
    std::queue< std::function<void()> > tasks;
    std::mutex queue_mutex;
    std::condition_variable cv_task;
    std::condition_variable cv_finished;
    unsigned int busy;
    bool stop;

    void thread_proc();
};

// template<class F>
// void ThreadPool::enqueue(F&& f)
// {
//     std::unique_lock<std::mutex> lock(queue_mutex);
//     tasks.emplace_back(std::forward<F>(f));
//     cv_task.notify_one();
// }

template<class F, class... Args>
auto ThreadPool::my_thread_queue(F&& f, Args&&... args) -> std::future<typename std::result_of<F(Args...)>::type>
{
    using return_type = typename std::result_of<F(Args...)>::type;
    auto task = std::make_shared<std::packaged_task<return_type()>>(std::bind(std::forward<F>(f), std::forward<Args>(args)...));
    std::future<return_type> res = task->get_future();
    {
        std::unique_lock<std::mutex> lock(queue_mutex);
        tasks.emplace([task](){ (*task)(); });
    }
    cv_task.notify_one();
    return res;
}

#endif /* !_MY_THREAD_POOL_HPP_ */

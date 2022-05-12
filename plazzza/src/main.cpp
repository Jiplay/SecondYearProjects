/*
** Iprocess.hpp for B-CCP-400-PAR-4-1-theplazza-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Tue Apr 20 9:50:56 AM 2021 julien.garsia
** Last update Wed Apr 5 16:02:42 2022 julien.garsia
*/

#include <iostream>
#include <string>
#include <unistd.h>
#include <stdio.h>
#include <math.h> // round
#include <sys/wait.h> 

#include "../include/encapsulation/process/process.hpp"
#include "../include/IPC/pipe.hpp"
#include "../include/error.hpp"
#include "../include//kitchen/kitchen.hpp"

#define YELLOW  "\033[33m"      /* Yellow */
#define RESET   "\033[0m"

namespace receptionist {
    
    void allocate_kitchens(std::list<std::shared_ptr<Kitchen>> *places, std::string s, int a, int b, int c)
    {
        std::list<std::shared_ptr<Pizza>> lp = parser::master_order_function(s);
        float nb_kitchens = float(lp.size()) / float(b);
        int _final = roundf(nb_kitchens);

        for (int i = places->size(); i < _final; i++)
            kitchen_management::kitchenFactory(a, b, c, places);
    }

    void dump_places(std::list<std::shared_ptr<Kitchen>> *places)
    {
        for (std::list<std::shared_ptr<Kitchen>>::iterator it = places->begin(); it != places->end() ;it++)
            it->get()->dump();
    }

    void process_manager(std::string s, int a, int b, int c, std::list<std::shared_ptr<Kitchen>> *places)
    {
        std::list<std::shared_ptr<Pizza>> lp = parser::master_order_function(s);
        float nb_kitchens = float(lp.size()) / float(b);
        int _final = roundf(nb_kitchens);
        std::list<std::shared_ptr<Pizza>> temp;
        std::list<std::shared_ptr<Pizza>> bis;
        std::list<std::shared_ptr<pid_t>> pid_list;
        int status;
        Mutex m;

        if (lp.size() %2 != 0)
            lp.emplace_back(std::make_shared<Pizza>(0, 0, 0));

        std::list<std::shared_ptr<Kitchen>>::iterator iterator = places->begin();
        for (std::list<std::shared_ptr<Pizza>>::iterator it = lp.begin(); it != lp.end() ;it++) {
            if (temp.size() == b) {
                bis = temp;
                temp.clear();
                Process *p = new Process;
                pid_t a = p->start();
                if (a > 0) {
                    iterator->get()->set_objectives(bis, 0);
                    iterator++;
                }
            }
            temp.push_back(*it);
        }


        waitpid(-1, &status, 0);
        m.lock();
        if (temp.size() != 0 && a > 0) {
            iterator->get()->set_objectives(temp, 1);
            temp.clear();
            m.unlock();
        }
    }

    void listen_command(int multiplier, int cooks, int time_reassort)
    {
        mknod("/tmp/pipefile", S_IFIFO | S_IRUSR | S_IWUSR, 0);
        mknod("/tmp/pipefile_length", S_IFIFO | S_IRUSR | S_IWUSR, 0);
        mknod("/tmp/pipefile_status", S_IFIFO | S_IRUSR | S_IWUSR, 0);

        Process p;
        IPC_read r;

        IPC ipc;
        IPC ipc1;

        pid_t pid_p = p.start();

        std::string sentence = "";
        std::string dest = "";
        std::list<std::shared_ptr<Kitchen>> places;

        /* child process */
        if(pid_p == 0)
        {
            while (1) {
                std::string s = "";
                std::string s1 = "";
                std::string s2 = "";
                r.lets_read("/tmp/pipefile_length", &s1, 10);

                try
                {
                    int a = 0;
                    a = std::stoi(s1);
                    r.lets_read("/tmp/pipefile", &s2, a);
                    r.lets_read("/tmp/pipefile_status", &s, 10);
                    if (s.compare("status") == 0) {
                        std::cout << "test" << std::endl;
                        dump_places(&places);
                        s.clear();
                    } else {
                        allocate_kitchens(&places, s2, multiplier, cooks, time_reassort);
                        process_manager(s2, multiplier, cooks, time_reassort, &places);
                    }
                }
                catch(const std::invalid_argument&e) // Weird but it works even if it returns a error 
                {
                    // std::cerr << e.what() << '\n';
                }
            }
        /* second son process */
        } else {
            std::string path = "/tmp/pipefile_status";
            while (1) {
                std::cout << YELLOW << "May I help you honey ? " << RESET;
                std::getline(std::cin, sentence);
                if (sentence.compare("exit") == 0) {
                    break;
                } else if (sentence.compare("status") == 0) {
                    ipc << path;
                    path = "status"; 
                    ipc >> path;
                } else {
                    std::string path1 = "/tmp/pipefile_length";
                    std::string path2 = "/tmp/pipefile";

                    ipc << path1;
                    std::string s = std::to_string(sentence.length());
                    ipc >> s;
                    
                    ipc << path2;
                    ipc >> sentence;

                    ipc << path;
                    path = "bad";
                    ipc >> path;

                    sleep(1);
                }
            }
        }
    }
}

int main(int ac, char **av) 
{
    if (useful::check_parameters(ac, av) == false) {
        throw PlazzaError("Bad parametters", "");
        return 84;
    }

    try
    {
        receptionist::listen_command(atoi(av[1]), atoi(av[2]), atoi(av[3]));
    }
    catch(const PlazzaError &e)
    {
        std::cerr << e.what() << '\n';
    }
    return 0;
}

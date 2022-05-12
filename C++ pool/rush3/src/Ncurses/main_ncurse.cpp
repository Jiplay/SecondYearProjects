/*
** main_ncurse.cpp for B-CPP-300-PAR-3-2-CPPrush3-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 23 10:34:54 AM 2021 julien.garsia
** Last update Sat Jan 23 10:34:54 AM 2021 julien.garsia
*/

#include <curses.h>
#include <ncurses.h>
#include <unistd.h>
#include <list>
#include <chrono>
#include <iomanip>
#include "../Core/Includes/core.hpp"

static std::string get_time()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

static std::list<int> memory_utilisation()
{
    std::string line;
    std::ifstream finfo("/proc/meminfo");
    int memtot;
    int memuse;
    std::string t1;
    std::string t2;
    int a = 0;
    int percent;
    std::list<int> l;
    while (getline(finfo, line))
    {
        if (a == 0) {
            t1 = line;
            t1.erase(0, 10);
            memtot = std::stoi(t1);
        }
        if (a == 2) {
            t2 = line;
            t2.erase(0, 13);
            memuse = std::stoi(t2);
        }
        a += 1;
    }
    l.push_back(memtot);
    l.push_back(memuse);
    return l;
}

void my_clear(Core *c)
{
    std::list<int> l = memory_utilisation();
    clear();
    if (c->getBool_Username() == true) {
        mvprintw(3, 1, "%s %s", "Hostname is : ", c->getHostname().c_str());
        mvprintw(5, 1, "%s %s", "Username is : ", c->getUsername().c_str());
    }
    if (c->getBool_Kernel() == true) {
        mvprintw(7, 1, "%s %s", "Operator System is : ", c->get_operatingSys().c_str());
        mvprintw(9, 1, "%s %s", "Kernel is : ", c->get_kernel().c_str());
    }
    if (c->getBool_Cpu() == true) {
        mvprintw(11, 1, "%s %d", "Number of cores is :", c->getNb_cores());
        mvprintw(13, 1, "%s %s", "CPU name is : ", c->get_cpu_name().c_str());
    }
    if (c->getRam_bool() == true) {
        mvprintw(15, 1, "%s %d %d = %d%", "RAM is at :", l.front(), l.back(), (l.front()/l.back()* 100));
    }
    if (c->getBool_Time() == true) {
        mvprintw(17, 1, "%s %s", "What time is it ? ", get_time().c_str());
    }
}

void UserName_Print(Core *c)
{
    if (c->getBool_Username() == false) {
        c->set_bool_username(true);
        my_clear(c);
        mvprintw(3, 1, "%s %s", "Hostname is : ", c->getHostname().c_str());
        mvprintw(5, 1, "%s %s", "Username is : ", c->getUsername().c_str());
    } else {
        mvprintw(3, 1, "");
        mvprintw(5, 1, "");
        c->set_bool_username(false);
        my_clear(c);
    }
    refresh();
}

void Core_Print(Core *c)
{
    if (c->getBool_Cpu() == false) {
        c->set_bool_cpu(true);
        my_clear(c);
        mvprintw(11, 1, "%s %d", "Number of cores is :", c->getNb_cores());
        mvprintw(13, 1, "%s %s", "CPU name is : ", c->get_cpu_name().c_str());
    } else {
        c->set_bool_cpu(false);
        my_clear(c);
	mvprintw(11, 1, "");
        mvprintw(13, 1, "");
    }
    refresh();
}

void Operator_Kernel_Print(Core *c)
{
    if (c->getBool_Kernel() == false) {
        c->set_bool_kernel(true);
        my_clear(c);
        mvprintw(7, 1, "%s %s", "Operator System is :", c->get_operatingSys().c_str());
        mvprintw(9, 1, "%s %s", "Kernel is : ", c->get_kernel().c_str());
    } else {
        c->set_bool_kernel(false);
        my_clear(c);
        mvprintw(7, 1, "");
        mvprintw(9, 1, "");
    }
    refresh();
}


bool Ram_print(Core *c)
{
    std::list<int> l = memory_utilisation();
    if (c->getRam_bool() == false) {
        c->set_bool_ram(true);
        my_clear(c);
        mvprintw(15, 1, "%s %d %d = %d%", "RAM is at :", l.front(), l.back(), (l.front()/l.back()* 100));
    } else {
        c->set_bool_ram(false);
        mvprintw(15, 1, "");
        my_clear(c);
    }
    refresh();
}

void Time_print(Core *c)
{
    if (c->getBool_Time() == false) {
        c->set_bool_time(true);
        my_clear(c);
        mvprintw(17, 1, "%s %s", "What time is it ? ", get_time().c_str());
    } else {
        c->set_bool_time(false);
        mvprintw(17, 1, "");
        my_clear(c);
    }
    refresh();
}


int ncurse_main()
{
    Core core;
    char key;
    int i = 1;
    std::list<int> l = memory_utilisation();

    nodelay(initscr(), TRUE);
    wrefresh(initscr());
    noecho();
    mvprintw(3, 1, "%s %s", "Host name is:", core.getHostname().c_str());
    mvprintw(5, 1, "%s %s", "User name is:", core.getUsername().c_str());
    mvprintw(7, 1, "%s %s", "Operator System is:", core.get_operatingSys().c_str());
    mvprintw(9, 1, "%s %s", "Kernel is:", core.get_kernel().c_str());
    mvprintw(11, 1, "%s %d", "Number of cores is :", core.getNb_cores());
    mvprintw(13, 1, "%s %s", "CPU name is :", core.get_cpu_name().c_str());
    mvprintw(15, 1, "%s %d %d = %d%", "RAM is at :", l.front(), l.back(), (l.front()/l.back()* 100));
    mvprintw(17, 1, "%s %s", "What time is it ? ", get_time().c_str());
    while(i == 1)
    {
        key = getch();
        if (key == 72 || key == 104)
            UserName_Print(&core);
        if (key == 75 || key == 107)
            Operator_Kernel_Print(&core);
        if (key == 67 || key == 99)
            Core_Print(&core);
        if (key == 114 || key == 82)
            Ram_print(&core);
        if (key == 84 || key == 116)
            Time_print(&core);
        if (key == 81 || key == 113)
            i = 0;
        refresh();
    }
        endwin();
        return(1);
}

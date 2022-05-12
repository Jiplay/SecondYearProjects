/*
** main_core.cpp for B-CPP-300-PAR-3-2-CPPrush3-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 23 10:40:01 AM 2021 julien.garsia
** Last update Sat Jan 23 10:40:01 AM 2021 julien.garsia
*/

#include "Includes/core.hpp"
#include <sys/utsname.h>

void Core::getFromUTSName(void)
{
    struct utsname e;
    uname(&e);
    _hostname = e.nodename;
    _operatingSystem = e.sysname;

    _kernel_version.append(e.version);
    _kernel_version.append(" : ");
    _kernel_version.append(e.machine);
    _kernel_version.append(" : ");
    _kernel_version.append(e.release);

    _username_is_print = true;
    _kernel_is_print = true;
    _cpu_name_is_print = true;
    _time_is_print = true;
    _ram_is_print = true;
}

void Core::show_nb_core(void)
{
    int a = 0;

    while (a < std::thread::hardware_concurrency())
        a++;
    nb_core = a;
}

void Core::show_cpu_name()
{
    std::string line;
    std::ifstream finfo("/proc/cpuinfo");
    std::string itype;
    std::string info;
    int a = 0;

    while (getline(finfo, line))
    {
        std::stringstream str(line);
        if (getline(str, itype, ':') && getline(str, info) && itype.substr(0, 10) == "model name")
            _cpu_name = info;
    }
}


void Core::getEnv()
{
   if(const char* env_p = std::getenv("USER")) {
        _username = env_p;
   }
}

Core::Core(void)
{
    show_cpu_name();
    getFromUTSName();
    getEnv();
    show_nb_core();
}

Core::~Core()
{
}


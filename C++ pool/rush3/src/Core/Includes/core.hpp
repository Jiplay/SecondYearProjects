/*
** core.hpp for B-CPP-300-PAR-3-2-CPPrush3-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 23 10:40:44 AM 2021 julien.garsia
** Last update Sat Jan 23 10:40:44 AM 2021 julien.garsia
*/

#ifndef CORE_HPP_
# define CORE_HPP_

#include <iostream>
#include <cstdlib>
#include <thread>
#include <fstream>
#include <sstream>

class Core
{
private:
    std::string _hostname;
    std::string _username;
    std::string _operatingSystem;
    std::string _kernel_version;
    std::string _cpu_name;
    int nb_core;

    bool _username_is_print;
    bool _kernel_is_print;
    bool _cpu_name_is_print;
    bool _time_is_print;
    bool _ram_is_print;

public:
    Core(void);
    ~Core();

    std::string getHostname(void) const {return _hostname;}
    std::string getUsername(void) const {return _username;}
    std::string get_operatingSys(void) const {return _operatingSystem;}
    std::string get_kernel(void) const {return _kernel_version;}
    std::string get_cpu_name(void) const {return _cpu_name;}

    bool getBool_Username(void) const { return _username_is_print;}
    bool getBool_Kernel(void) const { return _kernel_is_print;}
    bool getBool_Time(void) const { return _time_is_print;}
    bool getBool_Cpu(void) const { return _cpu_name_is_print;}
    bool getRam_bool(void) const { return _ram_is_print;}
    int getNb_cores(void) const { return nb_core;}

    void set_bool_username(bool t) { _username_is_print = t; }
    void set_bool_ram(bool t) { _ram_is_print = t; }
    void set_bool_kernel(bool t) { _kernel_is_print = t; }
    void set_bool_cpu(bool t) { _cpu_name_is_print = t; }
    void set_bool_time(bool t) { _time_is_print = t; }

    void getEnv();
    void getFromUTSName(void);
    void show_nb_core(void);
    void show_cpu_name(void);
};

#endif /* !CORE_HPP_ */

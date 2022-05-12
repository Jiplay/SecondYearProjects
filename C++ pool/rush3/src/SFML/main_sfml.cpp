/*
** main_sfml.cpp for B-CPP-300-PAR-3-2-CPPrush3-julien.garsia
**
** Made by julien.garsia
** Login   <julien.garsia>
**
** Started on  Sat Jan 23 10:34:48 AM 2021 julien.garsia
** Last update Sat Jan 23 10:34:48 AM 2021 julien.garsia
*/

#include <SFML/Graphics.hpp>
#include <csignal>
#include <iostream>
#include <iomanip>
#include <chrono>
#include <list>
#include "../Core/Includes/core.hpp"
#include "main_sfml.hpp"


std::list<int> memory_utilisation()
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

std::string get_time()
{
    auto now = std::chrono::system_clock::now();
    auto in_time_t = std::chrono::system_clock::to_time_t(now);
    std::stringstream ss;
    ss << std::put_time(std::localtime(&in_time_t), "%Y-%m-%d %X");
    return ss.str();
}

int sfml_main(Core core)
{
    sf::RenderWindow window(sf::VideoMode(1920, 1080), "MyGKrellm");
    sf::Sprite bgs;
    sf::Texture bgt;
    if (!bgt.loadFromFile("src/SFML/ressources/background1.png")) {
        std::cerr << "cannot find path \"" << "src/SFML/ressources/background1.png" << "\"." << std::endl;
        raise(84);
    }
    bgs.setTexture(bgt);
    bgs.setScale(0.22, 0.22);

    sf::Sprite bts;
    sf::Sprite bts2;
    sf::Sprite bts3;
    sf::Sprite bts4;
    sf::Sprite bts5;
    sf::Texture btt;
    if (!btt.loadFromFile("src/SFML/ressources/button.png")) {
        std::cerr << "cannot find path \"" << "src/SFML/ressources/button.png" << "\"." << std::endl;
        raise(84);
    }
    bts.setTexture(btt);
    bts2.setTexture(btt);
    bts3.setTexture(btt);
    bts4.setTexture(btt);
    bts5.setTexture(btt);
    bts.setScale(0.03, 0.03);
    bts2.setScale(0.03, 0.03);
    bts3.setScale(0.03, 0.03);
    bts4.setScale(0.03, 0.03);
    bts5.setScale(0.03, 0.03);
    bts.setPosition(1767, 55);
    bts2.setPosition(1767, 242);
    bts3.setPosition(1767, 379);
    bts4.setPosition(1767, 522);
    bts5.setPosition(1767, 640);


    sf::Font font;
    if(!font.loadFromFile("src/SFML/ressources/Code.ttf")) {
        return 84;
    }
    sf::Text text;
    text.setFont(font);
    text.setString("\n" + core.getUsername() + "\n\n" + core.getHostname());
    text.setCharacterSize(30);
    text.setColor(sf::Color::Yellow);
    sf::Text text2;
    text2.setFont(font);
    text2.setString("UserName:\n\nHostName:");
    text2.setCharacterSize(30);
    text2.setColor(sf::Color::Yellow);

    sf::Text tok;
    tok.setFont(font);
    tok.setString("\n" + core.get_operatingSys() + "\n\n" + core.get_kernel());
    tok.setCharacterSize(30);
    tok.setColor(sf::Color::Yellow);
    sf::Text tok2;
    tok2.setFont(font);
    tok2.setString("Operating System:\n\nKernel version:");
    tok2.setCharacterSize(30);
    tok2.setColor(sf::Color::Yellow);
    tok.setPosition(12, 174);
    tok2.setPosition(12, 174);


    sf::Text tdt;
    tdt.setFont(font);
    tdt.setCharacterSize(30);
    tdt.setColor(sf::Color::Yellow);
    sf::Text tdt2;
    tdt2.setFont(font);
    tdt2.setString("Date and time:");
    tdt2.setCharacterSize(30);
    tdt2.setColor(sf::Color::Yellow);
    tdt.setPosition(12, 348);
    tdt2.setPosition(12, 348);

    sf::Text tmc;
    tmc.setFont(font);
    std::string nbcore = std::to_string(core.getNb_cores());
    tmc.setString("\n" + core.get_cpu_name() + "\n\n " + nbcore);
    tmc.setCharacterSize(30);
    tmc.setColor(sf::Color::Yellow);
    sf::Text tmc2;
    tmc2.setFont(font);
    tmc2.setString("Monitor core:\n\nNumber of cores:");
    tmc2.setCharacterSize(30);
    tmc2.setColor(sf::Color::Yellow);
    tmc.setPosition(-5, 460);
    tmc2.setPosition(12, 460);

    sf::Text tmu;
    tmu.setFont(font);
    //std::string memuse = std::to_string(mem.back());
    //std::string memtot = std::to_string(mem.front());
    //int percent = (mem.back()*100/mem.front());
    //std::string percentstr = std::to_string(percent);
    //tmu.setString("\n" + percentstr + "%\n\n" + memuse + "/" + memtot);
    tmu.setCharacterSize(30);
    tmu.setColor(sf::Color::Yellow);
    sf::Text tmu2;
    tmu2.setFont(font);
    tmu2.setString("Percent:\n\nMemory use/Total memory:");
    tmu2.setCharacterSize(30);
    tmu2.setColor(sf::Color::Yellow);
    tmu.setPosition(12, 700);
    tmu2.setPosition(12, 700);
    bool btmu = true;

    while (window.isOpen()) {
        sf::Event event;
        std::list <int>mem = memory_utilisation();
        std::string memuse = std::to_string(mem.back());
        std::string memtot = std::to_string(mem.front());
        int percent = (mem.back()*100/mem.front());
        std::string percentstr = std::to_string(percent);
        tmu.setString("\n" + percentstr + "%\n\n" + memuse + "/" + memtot);
        tdt.setString("\n" + get_time());
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::MouseButtonPressed) {
                if (sf::Mouse::getPosition(window).x >= 1764 && sf::Mouse::getPosition(window).x <= 1833 && sf::Mouse::getPosition(window).y >= 52 && sf::Mouse::getPosition(window).y <= 111) {
                    if (core.getBool_Username())
                        core.set_bool_username(false);
                    else
                        core.set_bool_username(true);
                    window.display();
                }
                if (sf::Mouse::getPosition(window).x >= 1764 && sf::Mouse::getPosition(window).x <= 1833 && sf::Mouse::getPosition(window).y >= 241 && sf::Mouse::getPosition(window).y <= 305) {
                    if (core.getBool_Kernel())
                        core.set_bool_kernel(false);
                    else
                        core.set_bool_kernel(true);
                    window.display();
                }
                if (sf::Mouse::getPosition(window).x >= 1764 && sf::Mouse::getPosition(window).x <= 1833 && sf::Mouse::getPosition(window).y >= 380 && sf::Mouse::getPosition(window).y <= 449) {
                    if (core.getBool_Time())
                        core.set_bool_time(false);
                    else
                        core.set_bool_time(true);
                    window.display();
                }
                if (sf::Mouse::getPosition(window).x >= 1764 && sf::Mouse::getPosition(window).x <= 1833 && sf::Mouse::getPosition(window).y >= 522 && sf::Mouse::getPosition(window).y <= 562) {
                    if (core.getBool_Cpu())
                        core.set_bool_cpu(false);
                    else
                        core.set_bool_cpu(true);
                    window.display();
                }
                if (sf::Mouse::getPosition(window).x >= 1764 && sf::Mouse::getPosition(window).x <= 1833 && sf::Mouse::getPosition(window).y >= 640 && sf::Mouse::getPosition(window).y <= 680) {
                    if (btmu)
                        btmu = false;
                    else
                        btmu = true;
                    window.display();
                }
            }
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.draw(bgs);
        window.draw(bts);
        window.draw(bts2);
        window.draw(bts3);
        window.draw(bts4);
        window.draw(bts5);
        if (core.getBool_Username()) {
            window.draw(text);
            window.draw(text2);
        }
        if (core.getBool_Kernel()) {
            window.draw(tok);
            window.draw(tok2);
        }
        if (core.getBool_Time()) {
            window.draw(tdt);
            window.draw(tdt2);
        }
        if (core.getBool_Cpu()) {
            window.draw(tmc);
            window.draw(tmc2);
        }
        if (btmu) {
            window.draw(tmu);
            window.draw(tmu2);
        }
        window.display();
    }

    return 0;
}

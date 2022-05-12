/* 
        I'm the header mother fuckers
*/


#include "../include/kitchen/order.hpp"
#include "../include/error.hpp"

#include <string>
#include <cstddef>
#include <memory>


namespace parser {
    std::string newPizzaSize(std::shared_ptr<Pizza> p)
    {
        if (p->getSize() == 1)
            return "S";
        if (p->getSize() == 2)
            return "M";
        if (p->getSize() == 4)
            return "L";
        if (p->getSize() == 8)
            return "XL";
        if (p->getSize() == 16)
            return "XXL";
        return "";
    }

    int check_pizza_name(std::string str)
    {
        std::list<std::string> pizzas = {"regina", "margarita", "americana", "fantasia"};
        std::size_t found;
        int y = 0;

        for (auto &&i : pizzas) {
            found = str.find(i);
            if (found != -1) {
                if (y == 0)
                    return 1;
                else
                    return 2 * y;
            }
            y += 1;
        }

        return -1;
    }

    int check_pizza_size(std::string str)
    {
        std::list<std::string> pizzas = {"S", "M", "L", "XL", "XXL"};
        std::list<int> result = {1, 2, 4, 8, 16};
        std::size_t found;
        str = useful::splitonsize(str);

        int y = 1;

        for (auto &&i : pizzas) {
            if (str.compare(i) == 0) {
                return result.front();
            }
            y += 1;
            result.pop_front();
        }

        return -1;
    }

    int check_pizza_number(std::string str)
    {
        std::size_t found = str.find('x');
        char buffer[20];
        int nb = 0;

        if (found != -1) {
            str.copy(buffer, 6, found + 1);
            nb = std::atoi(buffer);
            if (nb == 0)
                return -1;
            return nb;
        }

        return -1;
    }

    std::shared_ptr<Pizza> pizza_order_check(std::string str)
    {
        int a = 0;
        int b = 0;
        int c = 0;

        a = check_pizza_name(str);
        b = check_pizza_size(str);
        c = check_pizza_number(str);
        
        if (a == 6) // Oops i did it again ^^
            a = 8;

        if (a != -1 && b != -1 && c != -1) {
            return std::make_shared<Pizza>(a, b, c);
        }
        // std::cerr << "Bad news bro.." << a << b << c << std::endl;
        return std::make_shared<Pizza>(0, 0, 0);
    }


    void print_order_to_check(std::list<Pizza> pizzas)
    {
        for (auto const& i: pizzas) {
            std::cout << i.getType() << i.getSize() << i.getNumber() << std::endl;
        }
    }

    std::list<std::shared_ptr<Pizza>> master_order_function(std::string str)
    {
        std::list<std::shared_ptr<Pizza>> pizzas;
        std::string word = "";
        int a = 0;

        for (auto x : str) {
            if (x == ';') {
                std::shared_ptr<Pizza> p = pizza_order_check(word);
                if (p.get()->getNumber() != 1) {
                    for (size_t i = 0; i < p.get()->getNumber(); i++)
                        pizzas.push_back(p);
                } else
                    pizzas.push_back(p);
                word = "";
                a = 6;
            }
            else if (a != 6) {
                word = word + x;
            } else {
                a = 0;
            }
        }
        std::shared_ptr<Pizza> p1 = pizza_order_check(word);
        if (p1.get()->getNumber() != 1) {
            for (size_t i = 0; i < p1.get()->getNumber(); i++)
                pizzas.push_back(p1);
        } else
            pizzas.push_back(p1);

        return pizzas;
    }
}

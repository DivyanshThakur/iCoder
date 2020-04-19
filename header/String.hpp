#ifndef STRING_HPP
#define STRING_HPP

#include "../namespace/header/cod_string.hpp"

void String();

class StringHandler
{
    cod::string str;
    cod::scan sc;
    bool show_adv_opn{false};
    std::vector<int> menuIndex; // It stored the index of the string to display

    void pressi_display();
    std::vector<std::string> menu_screen_selector();
    void fn_caller(int ch);
    void string_controller(int ch);
    void update_string();
    void insert_substr();
    void remove_substr();
    void display_str();
    void change_case();

public:
    void start();
};

#endif
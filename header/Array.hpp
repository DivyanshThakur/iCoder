#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>
#include "../namespace/header/cod_array.hpp"

void Arrays();
bool array_type_selector(int ch);

template <typename T>
class ArrayHandler
{
    cod::array<T> arr;
    Scanner sc;
    bool show_adv_opn{false};

    std::vector<std::string> menu_screen_selector();
    void arrays_controller(int ch);
    void arrays_controller_adv(int ch);
    void update_size();
    void add_elements();
    void insert_value();
    void remove_value();
    void remove_multiple_values();
    void display_arr() const;

public:
    void start();
};

#endif
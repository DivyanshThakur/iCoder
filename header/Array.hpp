#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <vector>
#include "../namespace/header/cod_array.hpp"
#include "../namespace/header/cod_scan.hpp"

void Arrays();
void array_type_selector(int ch);

template <typename T>
class ArrayHandler
{
    cod::array<T> arr;
    cod::scan sc;
    bool show_adv_opn{false};
    std::vector<int> menuIndex; // It stored the index of the string to display

    void pressi_display(bool isArrayUpdated = false);
    std::vector<std::string> menu_screen_selector();
    void array_controller(int ch);
    void fn_caller(int c);
    void update_size();
    void add_values();
    void insert_value();
    void remove_multiple_values();
    void remove_value();
    void display_arr() const;
    void linear_search_arr();
    void binary_search_arr();
    void merge_arr();
    void set_opn_arr();
    void sort_opn_arr();
    void sort(const std::string &heading = " SORT ", const std::string &message = "Checking array...");
    void reverse_arr();
    void shift_rotate_arr();
    void find_miss_val_arr();
    void find_dup_val_arr();
    void find_pair_sum_arr();
    void max_min();
    void get_value();
    void set_value();
    void average();
    void sum();

public:
    void start();
};

#endif
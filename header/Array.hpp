#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "../namespace/header/cod_array.hpp"

void Arrays();
bool array_type_selector(int ch);

template <typename T>
void init_array();

template <typename T>
void arrays_controller(cod::array<T> &arr, int ch);

template <typename T>
void update_size(cod::array<T> &arr);

template <typename T>
void add_elements(cod::array<T> &arr);

template <typename T>
void display_arr(cod::array<T> &arr);

#endif
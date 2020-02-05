#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "../namespace/header/cod_array.hpp"

void Arrays();
bool array_type_selector(int ch);
void arrays_controller(int ch);

template <typename T>
void init_array();

template <typename T>
void create_array(cod::array<T> &arr);

#endif
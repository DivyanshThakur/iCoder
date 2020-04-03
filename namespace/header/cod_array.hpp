#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

#include <iostream>
#include "../header/cod_pair.hpp"
#include "../../header/Constants.hpp"

namespace cod
{
template <typename T>
class array
{

    /*******************************************************************************************************************
 * 
 *                                                    ITERATOR METHODS                                                  
 * 
 ***********************************************************************************************************************/

    /****************************************************** ITERATOR ***************************************************/

    class iterator
    {
        T *ptr;

    public:
        iterator();
        iterator(T *ptr);

        iterator &operator++();
        iterator operator++(int);
        iterator &operator--();
        iterator operator--(int);

        T *operator+(size_t i);
        iterator &operator+=(size_t i);
        T *operator-(size_t i);
        iterator &operator-=(size_t i);

        T &operator*();
        T *operator->();

        bool operator<(const iterator &rhs);
        bool operator<=(const iterator &rhs);
        bool operator>(const iterator &rhs);
        bool operator>=(const iterator &rhs);

        bool operator!=(const iterator &rhs);
        bool operator==(const iterator &rhs);

        T *get_ptr() const;
    };

    /*************************************************** CONST ITERATOR *************************************************/

    class const_iterator
    {
        const T *ptr;

    public:
        const_iterator();
        const_iterator(const T *ptr);

        const_iterator &operator++();
        const_iterator operator++(int);
        const_iterator &operator--();
        const_iterator operator--(int);

        const T *operator+(size_t i);
        const_iterator &operator+=(size_t i);
        const T *operator-(size_t i);
        const_iterator &operator-=(size_t i);

        const T &operator*();
        const T *operator->();

        bool operator<(const const_iterator &rhs);
        bool operator<=(const const_iterator &rhs);
        bool operator>(const const_iterator &rhs);
        bool operator>=(const const_iterator &rhs);

        bool operator!=(const const_iterator &rhs);
        bool operator==(const const_iterator &rhs);

        const T *get_ptr() const;
    };

    /*******************************************************************************************************************
 * 
 *                                                     ARRAY METHODS                                                  
 * 
 ***********************************************************************************************************************/

    friend std::ostream &operator<<(std::ostream &os, const array &arr)
    {
        if (arr._size)
            for (const auto &val : arr)
            {
                if (val != arr.at(arr._size - 1))
                    std::cout << val << " ";
                else
                    std::cout << val;
            }
        else
            os << "No value to display";

        return os;
    }

private:
    T *A;
    size_t _max_size;
    size_t _size;
    T DEF_VAL;
    T MIN_VAL;

    bool unique(const std::vector<T> &temp, const T &val);

public:
    /***************************************************** CONSTRUCTOR **************************************************/
    array();                                     // no-args
    array(size_t _max_size);                     // paramaterized
    array(const array &rhs);                     // copy
    array(array &&rhs);                          //move
    array(const std::initializer_list<T> &list); // initializer list

    /************************************************* ASSIGNMENT OPERATOR **********************************************/
    array &operator=(const array &rhs);
    array &operator=(array &&rhs);

    /*************************************************** ARRAY ITERATOR *************************************************/
    iterator begin() const;
    iterator end() const;
    const const_iterator cbegin() const;
    const const_iterator cend() const;

    /****************************************************** CAPACITY ****************************************************/
    size_t size() const;
    size_t max_size() const;
    bool empty() const;
    void update_size(int x);
    void clear();

    /*************************************************** ELEMENT ACCESS *************************************************/
    T &operator[](size_t pos);
    const T &operator[](size_t pos) const;
    T &at(size_t pos);
    const T &at(size_t pos) const;
    T &front();
    const T &front() const;
    T &back();
    const T &back() const;
    T *data();
    const T *data() const;

    /****************************************************** MODIFIERS ***************************************************/
    void fill(const T &x);
    void fill(const T &x, size_t start, size_t end);
    void swap(array &rhs);
    void swap(size_t i, size_t j);
    void insert(T &x, size_t pos);
    T remove(size_t pos);
    array remove(size_t pos, size_t n);
    void push_back(const T &x);

    /************************************************ RELATIONAL OPERATORS **********************************************/
    bool operator==(const array &rhs);
    bool operator!=(const array &rhs);
    bool operator<(const array &rhs);
    bool operator<=(const array &rhs);
    bool operator>(const array &rhs);
    bool operator>=(const array &rhs);

    /************************************************** SHIFT/ROTATE ****************************************************/
    void shift(Side s, size_t n);
    void rotate(Side s, size_t n);
    size_t lsearch(const T &x);
    size_t bsearch(const T &x) const;
    bool isSorted() const;
    bool hasDuplicates() const;
    void sort();
    array merge(const array &rhs);

    /******************************************************** SET *******************************************************/
    array Union(const array &rhs);
    array Intersection(const array &rhs);
    array Difference(const array &rhs);

    /**************************************************** FIND VALUES ***************************************************/
    std::vector<cod::pair<T, int>> find_duplicates(size_t start, size_t end);
    std::vector<T> find_missing(size_t start, size_t end);
    std::vector<array<T>> find_pair_sum(size_t start, size_t end, T &k);

    /************************************************** BASIC OPERATION *************************************************/
    void reverse(size_t start, size_t end);
    double average(size_t start, int n) const;
    T sum(size_t start, int n) const;
    T min() const;
    T max() const;

    ~array();
};
} // namespace cod

#endif
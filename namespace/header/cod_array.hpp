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
    /*** ITERATORS ***/

    // iterator - array
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

    // const_iterator - array
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

    /*** ARRAY IMPLEMENTATION ***/

    friend std::ostream &operator<<(std::ostream &os, const array &arr)
    {
        if (arr.len)
            for (const auto &val : arr)
            {
                if (val != arr.at(arr.len - 1))
                    std::cout << val << " ";
                else
                    std::cout << val;
            }
        else
            os << "No elements to display";

        return os;
    }

private:
    T *A;
    size_t size;
    size_t len;
    T DEF_VAL;
    T MIN_VAL;

    bool unique(const std::vector<T> &temp, const T &val);

public:
    array();
    array(size_t size);
    array(const array &rhs);
    array(array &&rhs);

    // iterator methods
    iterator begin() const;
    iterator end() const;

    // const_iterator methods
    const const_iterator cbegin() const;
    const const_iterator cend() const;

    const T &operator[](size_t x) const;
    T &operator[](size_t x);

    T at(size_t x) const;
    T &at(size_t x);

    array &operator=(const array &rhs);
    array &operator=(array &&rhs);

    void insert(T &x, size_t pos);
    T remove(size_t pos);
    array remove(size_t pos, size_t n);

    void push_back(T &x);

    // basic operations
    T front() const;
    T back() const;
    size_t max_size() const;
    size_t length() const;
    void update_size(int x);
    void fill(const T &x);
    void fill(const T &x, size_t start, size_t end);
    bool empty() const;
    void clear();
    void swap(array &rhs);
    void swap(size_t i, size_t j);

    // shift & roate functions
    void shift(Side s, size_t n);
    void rotate(Side s, size_t n);
    size_t lsearch(const T &x);
    size_t bsearch(const T &x) const;
    bool isSorted() const;
    bool hasDuplicates() const;
    void sort();
    array merge(const array &rhs);

    // sets
    array Union(const array &rhs);
    array Intersection(const array &rhs);
    array Difference(const array &rhs);

    // finding values
    std::vector<cod::pair<T, int>> find_duplicates(size_t start, size_t end);
    std::vector<T> find_missing(size_t start, size_t end);
    std::vector<array<T>> find_pair_sum(size_t start, size_t end, T &k);

    // basic operations
    void reverse(size_t start, size_t end);
    double average(size_t start, int n) const;
    T sum(size_t start, int n) const;
    T min() const;
    T max() const;

    ~array();
};
} // namespace cod

#endif
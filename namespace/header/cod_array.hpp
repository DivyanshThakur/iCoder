#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

#include <iostream>
#include "../../header/Constants.hpp"

namespace cod
{
template <typename T>
class array
{
    friend std::ostream &operator<<(std::ostream &os, const array &arr)
    {
        if (arr.len)
            for (size_t i{0}; i < arr.len; ++i)
            {
                if (i < arr.len - 1)
                    std::cout << arr[i] << " ";
                else
                    std::cout << arr[i];
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

public:
    array();
    array(size_t size);
    array(const array &rhs);
    array(array &&rhs);

    T operator[](size_t x) const;
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
    void sort();
    array merge(const array &rhs);

    // sets
    array Union(const array &rhs);
    array Intersection(const array &rhs);
    array Difference(const array &rhs);

    // finding values
    std::vector<T> find_duplicates(size_t start, size_t end);
    std::vector<T> find_missing(size_t start, size_t end);
    std::vector<T> find_pair_sum(size_t start, size_t end);

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
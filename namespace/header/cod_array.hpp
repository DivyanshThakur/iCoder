#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

#include <iostream>
#include "../../header/Scanner.hpp"

namespace cod
{
template <typename T>
class array
{
    friend std::ostream &operator<<(std::ostream &os, const array &arr)
    {
        os << std::endl;

        for (size_t i = 0; i < arr.max_size(); ++i)
        {
            os << arr[i] << " ";
        }
        os << std::endl;
        return os;
    }

    friend Scanner &operator>>(Scanner &sc, array &arr)
    {
        size_t i;
        for (i = 0; i < arr.max_size(); ++i)
        {
            if (!sc.scan(arr[i]))
                break;
        }
        arr.fill(arr.get_min_val(), i);
        return sc;
    }

private:
    T *A;
    size_t size;
    size_t len;
    T MIN_VALUE;
    T DEF_VALUE;

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

    void insert(T &x, int pos = length());

    T front() const;
    T back() const;
    size_t max_size() const;
    size_t length() const;
    T get_min_val() const;
    void set_size(int x);
    void fill(const T &x, size_t start = 0, size_t end = max_size());
    bool empty() const;
    void clear();
    void swap(array &rhs);

    ~array();
};
} // namespace cod

#endif
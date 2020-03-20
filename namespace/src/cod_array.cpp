#include <iostream>
#include "../header/cod_array.hpp"
#include "../header/cod_limits.hpp"
#include "../header/cod_pair.hpp"
#include "../../header/UIhandler.hpp"
#include "../../header/ExHandler.hpp"

/*************************************************** ITERATOR METHODS ***************************************************/

// Iterator -array
template <typename T>
cod::array<T>::iterator::iterator() : ptr(nullptr)
{
}

template <typename T>
cod::array<T>::iterator::iterator(T *ptr) : ptr(ptr)
{
}

template <typename T>
typename cod::array<T>::iterator &cod::array<T>::iterator::operator++()
{
    ++ptr;
    return *this;
}

template <typename T>
typename cod::array<T>::iterator cod::array<T>::iterator::operator++(int)
{
    auto temp(*this);
    ++ptr;
    return temp;
}

template <typename T>
typename cod::array<T>::iterator &cod::array<T>::iterator::operator--()
{
    --ptr;
    return *this;
}

template <typename T>
typename cod::array<T>::iterator cod::array<T>::iterator::operator--(int)
{
    auto temp(*this);
    --ptr;
    return temp;
}

template <typename T>
T *cod::array<T>::iterator::operator+(size_t i)
{
    return (ptr + i);
}

template <typename T>
typename cod::array<T>::iterator &cod::array<T>::iterator::operator+=(size_t i)
{
    ptr += i;
    return *this;
}

template <typename T>
T *cod::array<T>::iterator::operator-(size_t i)
{
    return (ptr - i);
}

template <typename T>
typename cod::array<T>::iterator &cod::array<T>::iterator::operator-=(size_t i)
{
    ptr -= i;
    return *this;
}

template <typename T>
T &cod::array<T>::iterator::operator*()
{
    return *ptr;
}

template <typename T>
T *cod::array<T>::iterator::operator->()
{
    return ptr;
}

template <typename T>
bool cod::array<T>::iterator::operator<(const iterator &rhs)
{
    return (ptr < rhs.ptr);
}

template <typename T>
bool cod::array<T>::iterator::operator<=(const iterator &rhs)
{
    return (ptr <= rhs.ptr);
}

template <typename T>
bool cod::array<T>::iterator::operator>(const iterator &rhs)
{
    return (ptr > rhs.ptr);
}

template <typename T>
bool cod::array<T>::iterator::operator>=(const iterator &rhs)
{
    return (ptr >= rhs.ptr);
}

template <typename T>
bool cod::array<T>::iterator::operator!=(const iterator &rhs)
{
    return (ptr != rhs.ptr);
}

template <typename T>
bool cod::array<T>::iterator::operator==(const iterator &rhs)
{
    return (ptr == rhs.ptr);
}

template <typename T>
T *cod::array<T>::iterator::get_ptr() const
{
    return ptr;
}

// const_iterator -array
template <typename T>
cod::array<T>::const_iterator::const_iterator() : ptr(nullptr)
{
}

template <typename T>
cod::array<T>::const_iterator::const_iterator(const T *ptr) : ptr(ptr)
{
}

template <typename T>
typename cod::array<T>::const_iterator &cod::array<T>::const_iterator::operator++()
{
    ++ptr;
    return *this;
}

template <typename T>
typename cod::array<T>::const_iterator cod::array<T>::const_iterator::operator++(int)
{
    auto temp(*this);
    ++ptr;
    return temp;
}

template <typename T>
typename cod::array<T>::const_iterator &cod::array<T>::const_iterator::operator--()
{
    --ptr;
    return *this;
}

template <typename T>
typename cod::array<T>::const_iterator cod::array<T>::const_iterator::operator--(int)
{
    auto temp(*this);
    --ptr;
    return temp;
}

template <typename T>
const T *cod::array<T>::const_iterator::operator+(size_t i)
{
    return (ptr + i);
}

template <typename T>
typename cod::array<T>::const_iterator &cod::array<T>::const_iterator::operator+=(size_t i)
{
    ptr += i;
    return *this;
}

template <typename T>
const T *cod::array<T>::const_iterator::operator-(size_t i)
{
    return (ptr - i);
}

template <typename T>
typename cod::array<T>::const_iterator &cod::array<T>::const_iterator::operator-=(size_t i)
{
    ptr -= i;
    return *this;
}

template <typename T>
const T &cod::array<T>::const_iterator::operator*()
{
    return *ptr;
}

template <typename T>
const T *cod::array<T>::const_iterator::operator->()
{
    return ptr;
}

template <typename T>
bool cod::array<T>::const_iterator::operator<(const const_iterator &rhs)
{
    return (ptr < rhs.ptr);
}

template <typename T>
bool cod::array<T>::const_iterator::operator<=(const const_iterator &rhs)
{
    return (ptr <= rhs.ptr);
}

template <typename T>
bool cod::array<T>::const_iterator::operator>(const const_iterator &rhs)
{
    return (ptr > rhs.ptr);
}

template <typename T>
bool cod::array<T>::const_iterator::operator>=(const const_iterator &rhs)
{
    return (ptr >= rhs.ptr);
}

template <typename T>
bool cod::array<T>::const_iterator::operator!=(const const_iterator &rhs)
{
    return (ptr != rhs.ptr);
}

template <typename T>
bool cod::array<T>::const_iterator::operator==(const const_iterator &rhs)
{
    return (ptr == rhs.ptr);
}

template <typename T>
const T *cod::array<T>::const_iterator::get_ptr() const
{
    return ptr;
}

/**************************************************** ARRAY METHODS ****************************************************/

template <typename T>
bool cod::array<T>::unique(const std::vector<T> &temp, const T &val)
{
    for (const auto &v : temp)
        if (v == val)
            return false;
    return true;
}

template <typename T>
cod::array<T>::array() : A(nullptr), size(0), len(0), DEF_VAL(cod::limits<T>::def()), MIN_VAL(cod::limits<T>::min()) {}

template <typename T>
cod::array<T>::array(size_t size) : A(nullptr), size(size), len(0), DEF_VAL(cod::limits<T>::def()), MIN_VAL(cod::limits<T>::min())
{
    if (size < 0)
        throw NegativeValueException();
    else
        A = new T[size];
}

template <typename T>
cod::array<T>::array(const array &rhs)
{
    if (this != &rhs)
    {
        clear();

        size = rhs.size;
        len = rhs.len;
        A = new T[size];

        size_t i{0};

        for (const auto &val : rhs)
            A[i++] = val;
    }
}

template <typename T>
cod::array<T>::array(array &&rhs)
{
    if (this != &rhs)
    {
        clear();
        *this = rhs;

        rhs.A = nullptr;
    }
}

template <typename T>
typename cod::array<T>::iterator cod::array<T>::begin() const
{
    return iterator(A);
}

template <typename T>
typename cod::array<T>::iterator cod::array<T>::end() const
{
    return iterator(A + len);
}

template <typename T>
const typename cod::array<T>::const_iterator cod::array<T>::cbegin() const
{
    return const_iterator(A);
}

template <typename T>
const typename cod::array<T>::const_iterator cod::array<T>::cend() const
{
    return const_iterator(A + len);
}

template <typename T>
const T &cod::array<T>::operator[](size_t x) const
{
    if (x < 0 || x >= len)
        throw OutofBoundsException();

    return A[x];
}

template <typename T>
T &cod::array<T>::operator[](size_t x)
{
    if (x < 0 || x >= len)
        throw OutofBoundsException();

    return A[x];
}

template <typename T>
T cod::array<T>::at(size_t x) const
{
    if (x < 0 || x >= len)
        throw OutofBoundsException();

    return A[x];
}

template <typename T>
T &cod::array<T>::at(size_t x)
{
    if (x < 0 || x >= len)
        throw OutofBoundsException();

    return A[x];
}

template <typename T>
cod::array<T> &cod::array<T>::operator=(const array &rhs)
{
    if (this != &rhs)
    {
        clear();

        size = rhs.size;
        len = rhs.len;
        A = new T[size];

        size_t i{0};

        for (const auto &val : rhs)
            A[i++] = val;
    }

    return *this;
}

template <typename T>
cod::array<T> &cod::array<T>::operator=(array &&rhs)
{
    if (this != &rhs)
    {
        clear();

        A = rhs.A;
        size = rhs.size;
        len = rhs.len;

        rhs.A = nullptr;
    }
    return *this;
}

template <typename T>
void cod::array<T>::insert(T &x, size_t pos)
{

    if (len >= size)
        throw ArrayFullException();

    if (len == 0)
        throw ArrayEmptyException();

    if (pos > len || pos <= 0)
        throw InvalidPositionException();

    size_t i;

    for (i = len++; i >= pos; --i)
    {
        A[i] = A[i - 1];
    }

    A[i] = x;
}

template <typename T>
T cod::array<T>::remove(size_t pos)
{
    T value;

    if (len == 0)
        throw ArrayEmptyException();

    if (pos > len || pos <= 0)
        throw InvalidPositionException();

    size_t i = pos - 1;

    value = A[i];

    --len;

    while (i < len)
    {
        A[i] = A[i + 1];
        ++i;
    }

    return value;
}

template <typename T>
cod::array<T> cod::array<T>::remove(size_t pos, size_t n)
{
    array values(n);

    if (len == 0)
        throw ArrayEmptyException();

    if (pos > len || pos <= 0)
        throw InvalidPositionException();

    if (n < 0)
        throw NegativeValueException();

    size_t i, j;
    i = pos - 1;
    for (j = 0; j < n; ++j, ++i)
    {
        if (pos + j > len)
            break;
        values.push_back(A[i]);
    }
    for (i = pos - 1; i + n < len; ++i)
        A[i] = A[i + n];

    len -= values.length();

    return values;
}

template <typename T>
void cod::array<T>::push_back(const T &x)
{
    if (len >= size)
        throw ArrayFullException();

    A[len++] = x;
}

template <typename T>
T cod::array<T>::front() const
{
    if (len == 0)
        throw ArrayEmptyException();

    return A[0];
}

template <typename T>
T cod::array<T>::back() const
{
    if (len == 0)
        throw ArrayEmptyException();

    return A[len - 1];
}

template <typename T>
size_t cod::array<T>::max_size() const
{
    return size;
}

template <typename T>
size_t cod::array<T>::length() const
{
    return len;
}

template <typename T>
void cod::array<T>::update_size(int x)
{
    if (x < 0)
        throw NegativeValueException();

    if (static_cast<int>(size) == x)
        return;

    if (x < static_cast<int>(len))
    {
        bool in;

        in = confirm_the_change(std::string{"Entered size is less than actual\nSome elements might get deleted!"});

        if (!in)
            return;
    }

    size = x;

    if (len > size)
        len = size;

    T *temp_Arr = new T[size];

    size_t i{0};

    for (const auto &val : *this)
        temp_Arr[i++] = val;

    delete[] A;
    A = temp_Arr;
}

template <typename T>
void cod::array<T>::fill(const T &x)
{
    fill(x, 0, len);
}

template <typename T>
void cod::array<T>::fill(const T &x, size_t start, size_t end)
{
    for (size_t i{start}; i < end; ++i)
        A[i] = x;
}

template <typename T>
bool cod::array<T>::empty() const
{
    return (len > 0);
}

template <typename T>
void cod::array<T>::clear()
{
    delete[] A;
    size = len = 0;
}

template <typename T>
void cod::array<T>::swap(array &rhs)
{
    array temp{*this};
    *this = rhs;
    rhs = temp;
}

template <typename T>
void cod::array<T>::swap(size_t i, size_t j)
{
    T temp = A[i];
    A[i] = A[j];
    A[j] = temp;
}

template <typename T>
void cod::array<T>::shift(Side s, size_t n)
{
    if (len == 0)
        throw ArrayEmptyException();

    // code to shift the elements

    if (n > len)
        n %= len; // using rotation for any value of n,it adjusts with the array length

    size_t i, j;
    switch (s)
    {
    case LEFT:
        for (i = n, j = 0; i < len; ++i, ++j)
            A[j] = A[i];
        fill(DEF_VAL, j, i);
        break;

    case RIGHT:
        for (i = len - n - 1, j = len - 1; i + 1 > 0; --i, --j)
            A[j] = A[i];
        fill(DEF_VAL, i + 1, j + 1);
        break;
    }
}

template <typename T>
void cod::array<T>::rotate(Side s, size_t n)
{
    if (len == 0)
        throw ArrayEmptyException();

    // code to rotate the array

    n %= len; // using rotation for any value of n,it adjusts with the array length

    size_t i, j;
    array temp_arr(n);

    switch (s)
    {
    case LEFT:
        for (i = 0; i < n; ++i)
            temp_arr.push_back(A[i]);

        for (i = n, j = 0; i < len; ++i, ++j)
            A[j] = A[i];

        for (i = 0; j < len; ++i, ++j)
            A[j] = temp_arr[i];
        break;

    case RIGHT:
        for (i = 0, j = len - 1; i < n; ++i)
            temp_arr.push_back(A[j--]);

        for (i = len - n - 1, j = len - 1; i + 1 > 0; --i, --j)
            A[j] = A[i];

        for (i = 0; j < len; ++i, --j)
            A[j] = temp_arr[i];
        break;
    }
}

template <typename T>
size_t cod::array<T>::lsearch(const T &x)
{
    size_t i{0};
    for (; i < len; ++i)
        if (A[i] == x)
        {
            switch (stats)
            {
            case DEFAULT:
                ++i; // add 1 to i to return position
                break;

            case EASY:
                if (i) // check for i !=0 and swap with previous index
                    swap(i - 1, i);
                else
                    i = 1;
                break;

            case ADV:
                if (i) // swap with first value each time
                    swap(0, i);
                i = 1;
                break;
            }
            break;
        }

    if (i == len)
        i = 0;

    return i;
}

template <typename T>
size_t cod::array<T>::bsearch(const T &x) const
{
    int l, h, mid;

    l = 0;
    h = static_cast<int>(len) - 1;

    while (l <= h)
    {
        mid = (l + h) / 2;

        if (A[mid] == x)
            return mid + 1;

        if (A[mid] > x)
            h = mid - 1;
        else
            l = mid + 1;
    }

    return 0;
}

template <typename T>
bool cod::array<T>::isSorted() const
{
    for (size_t i{1}; i < len; ++i)
        if (A[i - 1] > A[i])
            return false;

    return true;
}

template <typename T>
bool cod::array<T>::hasDuplicates() const
{
    for (size_t i{0}; i < len - 1; ++i)
        for (size_t j{i + 1}; j < len; ++j)
            if (A[i] == A[j])
                return true;

    return false;
}

template <typename T>
void cod::array<T>::sort()
{
    bool toSort = confirm_the_change(std::string{"The array is not sorted"}, std::string{"Do you want to sort?"});
    if (!toSort)
        throw EscPressed();

    for (size_t i{0}; i < len; ++i)
        for (size_t j{i + 1}; j < len; ++j)
            if (A[i] > A[j])
                swap(i, j);
}

template <typename T>
cod::array<T> cod::array<T>::merge(const array &rhs)
{
    array mix_arr(len + rhs.len);

    size_t i{0}, j{0};

    while (i < len && j < rhs.len)
    {
        if (A[i] < rhs[j])
            mix_arr.push_back(A[i++]);
        else
            mix_arr.push_back(rhs.A[j++]);
    }

    while (i < len)
        mix_arr.push_back(A[i++]);

    while (j < rhs.len)
        mix_arr.push_back(rhs.A[j++]);

    return mix_arr;
}

template <typename T>
cod::array<T> cod::array<T>::Union(const array &rhs)
{
    array temp_arr(len + rhs.len);

    if (this->isSorted() && rhs.isSorted())
    {
        size_t i{0}, j{0};

        while (i < len && j < rhs.len)
        {
            if (A[i] < rhs.A[j])
                temp_arr.push_back(A[i++]);
            else if (A[i] > rhs.A[j])
                temp_arr.push_back(rhs.A[j++]);
            else
            {
                temp_arr.push_back(A[i++]);
                ++j;
            }
        }

        while (i < len)
            temp_arr.push_back(A[i++]);

        while (j < rhs.len)
            temp_arr.push_back(rhs.A[j++]);
    }
    else
    {
        bool isNew{true};

        for (const auto &val : *this)
            temp_arr.push_back(val);

        for (const auto &rightVal : rhs)
        {
            isNew = true;
            for (const auto &leftVal : *this)
            {
                if (leftVal == rightVal)
                    isNew = false;
            }
            if (isNew)
                temp_arr.push_back(rightVal);
        }
    }
    return temp_arr;
}

template <typename T>
cod::array<T> cod::array<T>::Intersection(const array &rhs)
{
    array temp_arr(len + rhs.len);

    if (this->isSorted() && rhs.isSorted())
    {
        size_t i{0}, j{0};

        while (i < len && j < rhs.len)
        {
            if (A[i] < rhs.A[j])
                ++i;
            else if (A[i] > rhs.A[j])
                ++j;
            else
            {
                temp_arr.push_back(A[i++]);
                ++j;
            }
        }
    }
    else
    {
        for (const auto &leftVal : *this)
        {
            for (const auto &rightVal : rhs)
            {
                if (leftVal == rightVal)
                {
                    temp_arr.push_back(leftVal);
                    break;
                }
            }
        }
    }

    return temp_arr;
}

template <typename T>
cod::array<T> cod::array<T>::Difference(const array &rhs)
{
    array temp_arr(len + rhs.len);

    if (this->isSorted() && rhs.isSorted())
    {
        size_t i{0}, j{0};

        while (i < len && j < rhs.len)
        {
            if (A[i] < rhs.A[j])
                temp_arr.push_back(A[i++]);
            else if (A[i] > rhs.A[j])
                temp_arr.push_back(rhs.A[j++]);
            else
            {
                ++i;
                ++j;
            }
        }

        while (i < len)
            temp_arr.push_back(A[i++]);

        while (j < rhs.len)
            temp_arr.push_back(rhs.A[j++]);
    }
    else
    {

        bool isNew{true};

        for (const auto &leftVal : *this)
        {
            isNew = true;
            for (const auto &rightVal : rhs)
            {
                if (leftVal == rightVal)
                    isNew = false;
            }
            if (isNew)
                temp_arr.push_back(leftVal);
        }
    }
    return temp_arr;
}

template <typename T>
std::vector<cod::pair<T, int>> cod::array<T>::find_duplicates(size_t start, size_t end) // all
{
    if (len == 0)
        throw ArrayEmptyException();

    if (start > end)
        throw InvalidPositionException();

    if (start < 0 || end >= len)
        throw InvalidInputException();

    std::vector<cod::pair<T, int>> vec;
    size_t i{start};

    if (this->isSorted())
    {
        for (int count{1}; i <= end; ++i, count = 1)
        {
            if (A[i] == A[i + 1])
            {
                while (A[i] == A[i + 1])
                {
                    ++count;
                    ++i;
                }
                vec.push_back(cod::pair<T, int>{A[i], count});
            }
        }
    }
    else
    {
        std::vector<T> dup;

        for (int count{1}; i < end; ++i, count = 1)
        {
            if (unique(dup, A[i]))
            {
                for (size_t j{i + 1}; j <= end; ++j)
                    if (A[i] == A[j])
                        ++count;

                if (count > 1)
                {
                    dup.push_back(A[i]);
                    vec.push_back(cod::pair<T, int>{A[i], count});
                }
            }
        }
    }
    return vec;
}

template <typename T>
std::vector<T> cod::array<T>::find_missing(size_t start, size_t end) // not for string, double(if not sorted)
{
    if (len == 0)
        throw ArrayEmptyException();

    if (start > end)
        throw InvalidPositionException();

    if (start < 0 || end >= len)
        throw InvalidInputException();

    std::vector<T> vec;
    size_t i{start};
    T l = A[i];
    size_t diff = l - i;

    if (this->isSorted() && !hasDuplicates())
    {
        for (; i <= end; ++i)
            if (A[i] - i != diff)
                while (diff < A[i] - i)
                {
                    vec.push_back(i + diff);
                    ++diff;
                }
    }
    else
    {
        T min = this->min();
        array hash(max() - min + 1);
        hash.len = hash.size;
        hash.fill(DEF_VAL);

        for (; i <= end; ++i)
            ++hash[A[i] - min];

        for (i = 0; i < hash.len; ++i)
            if (hash[i] == DEF_VAL)
                vec.push_back(min + i);
    }
    return vec;
}

template <>
std::vector<double> cod::array<double>::find_missing(size_t start, size_t end) // not for string, double(if not sorted)
{
    if (len == 0)
        throw ArrayEmptyException();

    if (start > end)
        throw InvalidPositionException();

    if (start < 0 || end >= len)
        throw InvalidInputException();

    std::vector<double> vec;
    size_t i{start};
    double l = A[i];
    size_t diff = l - i;

    if (!this->isSorted())
    {
        border(widthMenu);
        wait_message(std::string{"Checking array..."});
        this->sort();
    }

    for (; i <= end; ++i)
        if (A[i] - i != diff)
            while (diff < A[i] - i)
            {
                vec.push_back(i + diff);
                ++diff;
            }

    return vec;
}

template <typename T>
std::vector<cod::array<T>> cod::array<T>::find_pair_sum(size_t start, size_t end, T &k) // only for numbers
{
    if (len == 0)
        throw ArrayEmptyException();

    if (start > end)
        throw InvalidPositionException();

    if (start < 0 || end >= len)
        throw InvalidInputException();

    std::vector<array<T>> vec;

    if (this->isSorted())
    {
        size_t i{start}, j{end};

        while (i < j)
        {
            if (A[i] + A[j] == k)
            {
                array temp(3);
                temp.push_back(A[i++]);
                temp.push_back(A[j--]);
                temp.push_back(k);
                vec.push_back(temp);
            }
            else if (A[i] + A[j] < k)
                ++i;
            else
                --j;
        }
    }
    else
    {
        for (size_t i{start}; i < end; ++i)
            for (size_t j{i + 1}; j <= end; ++j)
                if (A[i] + A[j] == k)
                {
                    array temp(3);
                    temp.push_back(A[i]);
                    temp.push_back(A[j]);
                    temp.push_back(k);
                    vec.push_back(temp);
                }
    }
    return vec;
}

template <typename T>
void cod::array<T>::reverse(size_t start, size_t end) // start and end are the first and last elements of array
{
    size_t i = start, j = end;

    if (len == 0)
        throw ArrayEmptyException();

    if (start > end)
        throw InvalidPositionException();

    if (start < 0 || end >= len)
        throw InvalidInputException();

    while (i < j)
        swap(i++, j--);
}

template <typename T>
double cod::array<T>::average(size_t start, int n) const
{
    if (len == 0)
        throw ArrayEmptyException();

    if (start >= len || start < 0)
        throw InvalidPositionException();

    if (n < 0)
        throw NegativeValueException();

    double avg{0.0};
    int i;

    for (i = 0; i < n; ++i)
    {
        if (start == len)
            break;
        avg += A[start++];
    }

    return (avg / i);
}

template <typename T>
T cod::array<T>::sum(size_t start, int n) const
{
    if (len == 0)
        throw ArrayEmptyException();

    if (start >= len || start < 0)
        throw InvalidPositionException();

    if (n < 0)
        throw NegativeValueException();

    T sum{DEF_VAL};
    int i;

    for (i = 0; i < n; ++i)
    {
        if (start == len)
            break;
        sum += A[start++];
    }
    return sum;
}

template <typename T>
T cod::array<T>::min() const
{
    if (len == 0)
        throw ArrayEmptyException();

    T min;

    min = A[0];

    for (size_t i{1}; i < len; ++i)
    {
        if (min > A[i])
            min = A[i];
    }

    return min;
}

template <typename T>
T cod::array<T>::max() const
{
    if (len == 0)
        throw ArrayEmptyException();

    T max;

    max = A[0];

    for (size_t i{1}; i < len; ++i)
    {
        if (max < A[i])
            max = A[i];
    }

    return max;
}

template <typename T>
cod::array<T>::~array()
{
    delete[] A;
    size = len = 0;
}

// useless types in funcitons
template <>
double cod::array<char>::average(size_t start, int n) const
{
    return 0;
}

template <>
double cod::array<std::string>::average(size_t start, int n) const
{
    return 0;
}

template <>
char cod::array<char>::sum(size_t start, int n) const
{
    return 0;
}

template <>
std::string cod::array<std::string>::sum(size_t start, int n) const
{
    return 0;
}

template <>
std::vector<std::string> cod::array<std::string>::find_missing(size_t start, size_t end)
{
    return std::vector<std::string>();
}

template <>
std::vector<cod::array<std::string>> cod::array<std::string>::find_pair_sum(size_t start, size_t end, std::string &k)
{
    return std::vector<cod::array<std::string>>();
}

template <>
std::vector<cod::array<char>> cod::array<char>::find_pair_sum(size_t start, size_t end, char &k)
{
    return std::vector<cod::array<char>>();
}

// template class declaration
template class cod::array<int>;
template class cod::array<long long>;
template class cod::array<double>;
template class cod::array<char>;
template class cod::array<std::string>;
#ifndef COD_ARRAY_HPP
#define COD_ARRAY_HPP

namespace cod
{
template <typename T>
class array
{
private:
    T *arr;
    int size;
    int length;
    T MIN_VALUE;

public:
    array();
    array(int size);

    void fill(const T &x);
};
} // namespace cod

#endif
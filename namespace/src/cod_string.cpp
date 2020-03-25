#include <cstring>
#include "../header/cod_string.hpp"

cod::string::string() : string(nullptr)
{
}

cod::string::string(const char *s) : str(nullptr)
{
    if (s == nullptr)
    {
        str = new char[1];
        *str = '\0';
    }
    else
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }
}

cod::string::string(const string &source) : str(nullptr)
{
    str = new char[strlen(source.str) + 1];
    strcpy(str, source.str);
}

cod::string::string(string &&source) : str(nullptr)
{
    str = source.str;
    source.str = nullptr;
}

cod::string::~string()
{
    delete[] str;
}
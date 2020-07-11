#ifndef ISAVEABLE_HPP
#define ISAVEABLE_HPP

#include "Constants.hpp"
#include "../namespace/header/cod_pair.hpp"

class ISaveable
{
public:
    virtual std::vector<cod::pair<std::string, std::string>> save() const = 0;
    virtual void load(const std::vector<cod::pair<std::string, std::string>> &vecData) = 0;
    virtual std::string getPath() const = 0;
    virtual bool generate() const;

    virtual ~ISaveable() = default;
};

#endif
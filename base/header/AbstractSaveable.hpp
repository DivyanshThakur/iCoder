#ifndef ABSTRACT_SAVEABLE
#define ABSTRACT_SAVEABLE

#include <vector>
#include <string>

class AbstractSaveable
{
public:
    virtual std::vector<std::pair<std::string, std::string>> save() const = 0;
    virtual void load(const std::vector<std::pair<std::string, std::string>> &vecData) = 0;
    virtual std::string getPath() const = 0;
    virtual bool generate() const;

    virtual ~AbstractSaveable() = default;
};

#endif
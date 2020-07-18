#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include "FileHandler.hpp"

class Account
{
    static std::string userId, pass;

    /**
 * Data has all the methods necessary for saving
 * and retreiving user data from the files
 * It inherit the ISaveable abstract class.
 **/
    class Data : public ISaveable
    {
        virtual std::vector<std::pair<std::string, std::string>> save() const override;
        virtual void load(const std::vector<std::pair<std::string, std::string>> &vecData) override;
        virtual std::string getPath() const override;
        virtual bool generate() const override;
    };

    static Data userData;
    static std::pair<std::string, std::string> pairBuffer;

public:
    static Data &data();
    static void input();
    static void check();
    static void rememberMe();
    static std::string username();
    static std::string password();
};

#endif
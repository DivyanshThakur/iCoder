#ifndef ACCOUNT_HPP
#define ACCOUNT_HPP

#include <string>
#include "FileHandler.hpp"

class Account : ISaveable
{
    friend std::ostream &operator<<(std::ostream &os, Account &acc);
    friend std::ifstream &operator>>(std::ifstream &is, Account &acc);

private:
    int index;
    cod::pair<std::string, std::string> pairBuffer;

    std::string pass_to_asteric() const;

protected:
    std::string userID, pass;

public:
    /************************************ ISAVABLE PURE VIRTUAL FUNCTION ****************************************/

    virtual std::vector<cod::pair<std::string, std::string>> save() const override;
    virtual void load(const std::vector<cod::pair<std::string, std::string>> &vec) override;
    virtual std::string filename() const override;
    virtual bool generate() const override;

    /************************************** MEMBER FUNCTION OVERLOADS *******************************************/

    void input_data();
    void display_remember_me() const;
    void check_account() const;

    std::string get_userID() const;
    std::string get_pass() const;

    virtual ~Account() = default;
};

#endif
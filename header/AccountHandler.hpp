#ifndef ACCOUNTHANDLER_HPP
#define ACCOUNTHANDLER_HPP

/*********************************************** FUNCTION PROTOTYPES ***********************************************/

class AccountHandler
{
    static std::string pass_to_asteric(const std::string &pass);

public:
    static void login();
    static void create_account();
    static void display_users();
};

#endif
#ifndef ICODER_HPP
#define ICODER_HPP

#include "header/IMenu.hpp"

class Main
{
public:
    class Menu : public IMenu
    {
        virtual std::string title() const override;

        virtual std::vector<std::string> selector() override;
        virtual void caller() const override;
        virtual void controller() const override;
    };

    static void start();
    static void home(const std::string &userID);

private:
    static void load();
    static void sign_out();
    static void create_path();
    static bool check_directory();
    static void adjust_console_size();
};

/************************************************ FUNCTION PROTOTYPES **************************************************/

#endif
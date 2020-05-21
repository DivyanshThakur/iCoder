#include <iostream>
#include "../header/IMenu.hpp"
#include "../header/UIhandler.hpp"

// void menu(const std::vector<std::string> &vecMenu, const std::string &heading, bool showStatus, const std::string &statsVal, const std::string &statsStr)
void IMenu::player(const IMenu &iMenu)
{
    // show the specific menu

    logo(); // display logo - "iCoder"

    update_screen(iMenu.title()); // It will update the current screen enum variable

    if (Global::showHint) // checks if showHint is enabled or not
        show_hint();      // if enabled, it shows different hints based on the current screeen

    header(heading, false); // It prints the heading to console, accepts boolean to display logo or not

    if (showStatus)                      // It checks if it has access to show the current state of the specific screen
        show_status(statsStr, statsVal); // It accepts 2 strings that is displayed below heading

    // Here, the vecMenu passed from function contains the menu options in vector of string
    for (size_t index{0}; index < vecMenu.size(); ++index)
    {
        // Print the index starting 1 till vector size
        std::cout << std::setw(2) << std::right << index + 1 << ". " << vecMenu.at(index);

        if (index < vecMenu.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;
    }

    print_message(std::string{"Your Choice: "}); // ask user for input
}

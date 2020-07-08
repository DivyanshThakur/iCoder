#include <iomanip>
#include "../header/IMenu.hpp"
#include "../header/UIhandler.hpp"

// void menu(const std::vector<std::string> &vecMenu, const std::string &heading, bool showStatus, const std::string &statsVal, const std::string &statsStr)
void IMenu::player(IMenu &&iMenu)
{
    // show the specific menu

    Ui::logo(); // display logo - "iCoder"

    Ui::update_screen(iMenu.title()); // It will update the current screen enum variable

    if (Global::showHint) // checks if showHint is enabled or not
        Ui::show_hint();  // if enabled, it shows different hints based on the current screen

    Ui::header(iMenu.title(), false); // It prints the heading to console, accepts boolean to display logo or not

    if (showStatus)                          // It checks if it has access to show the current state of the specific screen
        Ui::show_status(statsStr, statsVal); // It accepts 2 strings that is displayed below heading

    auto menuToDisplay = iMenu.selector();
    // Here, the vecMenu passed from function contains the menu options in vector of string
    for (size_t index{0}; index < menuToDisplay.size(); ++index)
    {
        // Print the index starting 1 till vector size
        std::cout << std::setw(2) << std::right << index + 1 << ". " << menuToDisplay.at(index);

        if (index < menuToDisplay.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;
    }

    Ui::print_message(std::string{"Your Choice: "}); // ask user for input

    iMenu.check();
}

void IMenu::check() const
{
    try
    {
        this->controller();
        // sc.choice(ch); // scan user's choice

        // fn_caller(ch, menuIndex); // start as per user choice
    }
    catch (const EscPressed &e)
    {
        // do nothing
    }
    catch (const Exit &e)
    {
        e.what(); // call exit function
    }
    catch (const OpenSettings &e)
    {
        e.what();
    }
    catch (const OpenAbout &e)
    {
        e.what(); // open about screen
    }
    catch (const OpenHelp &e)
    {
        e.what(); // open help screen
    }
    catch (const OpenUpdate &e)
    {
        e.what();
    }
    catch (const OpenChangelog &e)
    {
        e.what(); // open changelog
    }
    catch (const OpenMoreScreen &e)
    {
        e.what(); // open home screen
    }
    catch (const OpenAnimeSetting &e)
    {
        e.what(); // open settings with animation
    }
}

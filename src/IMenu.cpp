#include <iomanip>
#include "../header/IMenu.hpp"
#include "../header/UIhandler.hpp"

#include "../constant/Constants.hpp"

void IMenu::stats(const std::vector<std::string> &vec) const
{
}

void IMenu::player(IMenu &&iMenu)
{
    Ui::logo();

    Ui::updateScreen(iMenu.title()); // It will update the current screen enum variable

    if (Global::showHint)
        Ui::print(Ui::getHint());

    print(iMenu.getStats());

    Ui::subHeader(iMenu.title()); // It prints the heading to console, accepts boolean to display logo or not

    // if (showStatus)                          // It checks if it has access to show the current state of the specific screen
    //     Ui::show_status(statsStr, statsVal); // It accepts 2 strings that is displayed below heading

    auto menuToDisplay = iMenu.selector();

    // Here, the vecMenu passed from function contains the menu options in vector of string
    for (size_t index{0}; index < menuToDisplay.size(); ++index)
    {
        // Print the index starting 1 till vector size
        std::cout << std::setw(2) << std::right << index + 1 << ". " << menuToDisplay.at(index);

        if (index < menuToDisplay.size() - 1) // New line is not printed at last menu option
            std::cout << std::endl;
    }

    Ui::print(std::string{"Your Choice: "}); // ask user for input

    iMenu.check();
}

void IMenu::check() const
{
    try
    {
        this->caller();
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

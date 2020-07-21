#include <iomanip>
#include "../header/IMenu.hpp"
#include "../header/UIhandler.hpp"
#include "../constant/Constants.hpp"

void IMenu::play(IMenu &&iMenu)
{
    Ui::logo();

    Ui::updateScreen(iMenu.title()); // It will update the current screen enum variable

    if (Global::showHint)
        Ui::print(Ui::getHint());

    Ui::print(iMenu.getStats());

    Ui::subHeader(iMenu.title()); // It prints the heading to console

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

void IMenu::player(IMenu &&iMenu)
{
    do
    {
        play(iMenu);

    } while (1);
}

void IMenu::check() const
{
    try
    {
        scan >> ch;
        this->caller();
    }
    catch (const cod::exception &e)
    {
        e.what();
    }

    // catch (const EscPressed &e)
    // {
    //     // do nothing
    // }
    // catch (const Exit &e)
    // {
    //     e.what(); // call exit function
    // }
    // catch (const OpenSettings &e)
    // {
    //     e.what();
    // }
    // catch (const OpenAbout &e)
    // {
    //     e.what(); // open about screen
    // }
    // catch (const OpenHelp &e)
    // {
    //     e.what(); // open help screen
    // }
    // catch (const OpenUpdate &e)
    // {
    //     e.what();
    // }
    // catch (const OpenChangelog &e)
    // {
    //     e.what(); // open changelog
    // }
    // catch (const OpenMoreScreen &e)
    // {
    //     e.what(); // open home screen
    // }
    // catch (const OpenAnimeSetting &e)
    // {
    //     e.what(); // open settings with animation
    // }
}

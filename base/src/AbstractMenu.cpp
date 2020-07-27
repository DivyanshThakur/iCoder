#include <iomanip>
#include <numeric>
#include "../header/AbstractMenu.hpp"
#include "../../header/Ui.hpp"
#include "../../constant/Constants.hpp"
#include "../../constant/enum.hpp"

cod::scan AbstractMenu::scan;
int AbstractMenu::ch;

void AbstractMenu::menuIndexer(size_t end, size_t start, size_t val)
{
    menuIndex.resize(end);
    std::iota(menuIndex.begin() + start, menuIndex.end(), val);
}

/**
 * The menuIndex stores the index of the menu options that is currently displayed in the screen
 * Menu::caller() calls the required function by using below logic
 * Any input less than 1 or greater than the menuIndex size, throws Invalid choice message
 * if the input is between the menuIndex size range, it calculates which function to call
 * Logic - the (input - 1) is passed as the index of menuIndex to get the index of Menu
 * Since, the index of Menu is stored in menuIndex and thus is passed in menu controller
 **/

void AbstractMenu::caller() const
{
    if (ch > 0 && ch <= static_cast<int>(menuIndex.size()))
        controller();
    else
        Ui::println(std::string{"Invalid choice"});
}

void AbstractMenu::player(AbstractMenu &&AbstractMenu)
{
    Global::openedScreen.push_back(AbstractMenu.title());

    do
    {
        Ui::logo();

        if (Global::showHint)
            Ui::print(Ui::getHint());

        Ui::print(AbstractMenu.getStats());

        Ui::subHeader(AbstractMenu.title()); // It prints the heading to console

        auto menuToDisplay = AbstractMenu.selector();

        // Here, the vecMenu passed from function contains the menu options in vector of string
        for (size_t index{0}; index < menuToDisplay.size(); ++index)
        {
            std::cout << std::setw(2) << std::right << index + 1 << ". " << menuToDisplay.at(index) << std::endl;
        }

        Ui::print(std::string{"Your Choice: "}); // ask user for input

        try
        {
            scan >> ch;
            AbstractMenu.caller();
        }
        catch (const EscPressed &e)
        {
            if (Global::openedScreen.back() != Constant::Title::MAIN)
                return;
        }
        catch (const cod::exception &e)
        {
            e.what();
        }

    } while (1);
}

AbstractMenu::~AbstractMenu()
{
    Global::openedScreen.pop_back();
}
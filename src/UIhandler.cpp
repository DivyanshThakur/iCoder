#include <iostream>
#include <iomanip>
#include <windows.h>
#include "../header/Settings.hpp"
#include "../namespace/header/cod_algorithm.hpp"
#include "../namespace/header/cod_scan.hpp" // UiHandler already included in cod_scan

void logo() /*********** LOGO ********/
{
    system("cls"); // clear the screen each time

    const std::string logo{"iCoder"}; // this display the logo at top of screen

    std::cout << std::setw(Ui::relativeTitleWidth) << ""
              << std::setw(Ui::widthTitle) << std::setfill('=') << ""
              << std::setfill(' ') << std::endl
              << std::setw(Ui::relativeTitleWidth + Ui::widthTitle / 2 - logo.size() / 2) << ""
              << logo << std::endl
              << std::setw(Ui::relativeTitleWidth) << ""
              << std::setw(Ui::widthTitle) << std::setfill('=') << ""
              << std::setfill(' ')
              << std::endl
              << std::endl;
}

void menu(const std::vector<std::string> &vecMenu, const std::string &heading, bool showStatus, const std::string &statsVal, const std::string &statsStr)
{ // show the specific menu

    logo(); // display logo - "iCoder"

    update_screen(heading); // It will update the current screen enum variable

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

void show_status(const std::string &statsStr, const std::string &statsVal, bool isFinal)
{
    std::cout << statsStr << statsVal; // It prints the status to console

    if (isFinal) // checks if 1 or more status is to be printed or not
        border(Ui::widthMenu);
    else
        std::cout << std::endl; // print new line at last status printed
}

std::string stats_selector(const enum Status &stats, const std::vector<std::string> &statsData)
{ // The status enum is passed and the specific stats is selected
    switch (stats)
    {
    case DEFAULT:
        return cod::toupper(statsData.at(0));

    case EASY:
        return cod::toupper(statsData.at(1));

    case ADV:
        return cod::toupper(statsData.at(2));

    default:
        return "";
    }
}

void update_last_screen()
{
    // The last screen is updated from current string
    switch (opnScreen)
    {
    case CUR_ARRAY:
        lstScreen = LAST_ARRAY;
        break;

    case CUR_DS:
        lstScreen = LAST_DS;
        break;

    case CUR_GAMES:
        lstScreen = LAST_GAMES;
        break;

    case CUR_MENU:
        lstScreen = LAST_MENU;
        break;

    case CUR_MORE:
        lstScreen = LAST_MORE;
        break;

    case CUR_SETTINGS:
        lstScreen = LAST_SETTINGS;
        break;

    case CUR_STRING:
        lstScreen = LAST_STRING;
        break;

    case CUR_UPDATES:
        lstScreen = LAST_UPDATES;
        break;
    }
}

void update_screen(const std::string &heading)
{
    update_last_screen();

    // This function updates the current screen
    if (heading == std::string{" ARRAY "})
        opnScreen = CUR_ARRAY;
    else if (heading == std::string{" DATA STRUCTURE "})
        opnScreen = CUR_DS;
    else if (heading == std::string{" GAMES "})
        opnScreen = CUR_GAMES;
    else if (heading == std::string{" MAIN "})
        opnScreen = CUR_MENU;
    else if (heading == std::string{" MORE "})
        opnScreen = CUR_MORE;
    else if (heading == std::string{" SETTINGS "} || heading == std::string{" CHANGE LINEAR SEARCH TYPE "} || heading == std::string{" CHANGE SHORTCUT ACCESS "})
        opnScreen = CUR_SETTINGS;
    else if (heading == std::string{" STRING "})
        opnScreen = CUR_STRING;
    else if (heading == std::string{" UPDATES "})
        opnScreen = CUR_UPDATES;
}

void header(const std::string &menuTitle, bool showTitle)
{
    if (showTitle) // displays logo ,if true
        logo();

    std::cout << std::setfill('-')
              << std::setw(2) << " "
              << menuTitle << " "
              << std::setw(Ui::widthMenu - (menuTitle.size() + 2)) << ""
              << std::setfill(' ')
              << std::endl;
}

void show_hint()
{
    header(std::string{" HINT "}, false); // print heading as " HINT "

    // Assigning correct shortcut key text based on user settings
    std::string hlp = (shortcutStats == EASY) ? " Ctrl + h " : " h ";
    std::string hme = (shortcutStats == EASY) ? " Ctrl + m " : " m ";
    std::string dsb = (shortcutStats == EASY) ? " Ctrl + d " : " d ";
    int wdth = (shortcutStats == EASY) ? 12 : 8;

    if (opnScreen != CUR_MENU) // It displays last screen shortcut,except when the main menu screen is opened
    {
        std::cout << std::setw(wdth) << std::left << " Esc "
                  << "Last Screen" << std::endl;
    }

    if (shortcutStats != ADV) // If shortcuts are disabled, below codes are not executed
    {
        std::cout << std::setw(wdth) << std::left << hlp
                  << "Help screen" << std::endl;

        if (opnScreen != CUR_MORE) // It displays more screen shortcut,except when the more screen is opened
        {
            std::cout << std::setw(wdth) << std::left << hme
                      << "More features" << std::endl;
        }

        if (opnScreen != CUR_SETTINGS) // It displays disable hint shortcut,except when settings is opened
        {
            std::cout << std::setw(wdth) << std::left << dsb
                      << "Disable this hint" << std::endl;
        }
    }

    std::cout << std::endl; // 1 line gap between Hints and Menu
}

void border(int size)
{ // This function displays the border
    std::cout << std::endl
              << std::setfill('-')
              << std::setw(size) << ""
              << std::setfill(' ')
              << std::endl;
}

void emessage(const std::string &message)
{
    animater(message); // Animated text is printed for user to get attention

    igetch(); // Accepts Esc,Enter, Space or Backspace key to continue

    for (size_t i{0}; i < message.size(); ++i)
    {
        std::cout << "\b \b";     // It erases 1 character at a time
        Sleep(Global::sleepTime); // time gap is based on user choice
    }
}

void igetch()
{
    char c;

    // This whilc loop only exits if the user presses, Esc, Enter, Space or Backspace
    while ((c = getch()))
        if (c == '\r' || c == ' ' || c == '\b' || c == 27)
            return;
}

void animater(const std::string &anime)
{ // Prints text in animation, time delay based on user choice
    for (const auto &c : anime)
    {
        std::cout << c;
        Sleep(Global::sleepTime);
    }
}

void print_message(const std::string &message, bool pressKey, const ReturnTo &rt)
{ // prints a border of "-" with a message for user
    border(Ui::widthMenu);

    std::cout << message;

    if (pressKey || message == std::string{"TO BE IMPLEMENTED..."}) // run press_key()
        press_key(rt);
}

void press_key(const ReturnTo &rt, const std::string &message)
{
    char ch;

    print_message(message);
    ch = getch();

    // Asks user to press any key to continue, if user presses Esc, below code is executed
    if (ch == Ui::ESC)
    {
        switch (rt)
        {
        case PRE: // Default - normal EscPressed exception thrown
            throw EscPressed();
        case HOME: // It will return to the Specific Home screen of the program.Eg-Data structure, Games, etc.
            throw ReturnHome();
        case NIL: // Nothing happens on pressing Esc, the current screen is loops again
            break;
        }
    }
}

bool press_i(const std::string &message)
{ // Ask user to press i to run specific task
    print_message(std::string{message});

    char ch = getch();

    if (::tolower(ch) == 'i')
        return true;

    return false;
}

void erase_line(size_t len)
{
    std::cout << "\r" << std::setw(len) << ""
              << "\r";
}

// Adds extra text to the message based on the condition below
std::string s_or_not_s(size_t num, const std::string &message, const std::string &extra, const std::string &updateFirst)
{
    auto temp = message;
    temp += (num < 2) ? updateFirst : extra;

    return temp;
}

void wait_message(const std::string &message)
{ // Simple wait message tells user that some large operations are performed in background

    border(Ui::widthMenu);

    std::cout << message;
    Sleep(1000);
}

bool confirm_the_change(const std::string &message, const std::string &txtConfirm)
{ // Asks user for confirmation, if the changes are to be accepted or rejected
    if (message != std::string{""})
        print_message(message);

    border(Ui::widthMenu);

    animater(txtConfirm + std::string{" (Y/N): "});

    // scanning character
    cod::scan sc;
    char c;

    try
    {
        sc >> c;
    }
    catch (const OpenAnimeSetting &e)
    {                                  // It will animate quit setting option for user if 'd' is pressed
        if (opnScreen != CUR_SETTINGS) // while the user is not in settings screen
            e.what();
    }
    catch (...)
    {
        return false; // returns false if user presses Esc or for other exception
    }

    return (::tolower(c) == 'y'); // returns true if user presses 'y'
}
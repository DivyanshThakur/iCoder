#include <iostream>
#include <iomanip>
#include <windows.h>
#include "../header/Settings.hpp"
#include "../namespace/header/cod_algorithm.hpp"
#include "../namespace/header/cod_scan.hpp" // UiHandler already included in cod_scan

#include "../constant/enum.hpp"

void Ui::logo()
{
    system("cls");

    const std::string TITLE{"iCoder"};

    std::cout << std::setw(Constant::Ui::RELATIVE_TITLE_WIDTH) << ""
              << std::setw(Constant::Ui::TITLE_WIDTH) << std::setfill('=') << ""
              << std::setfill(' ') << std::endl
              << std::setw(Constant::Ui::RELATIVE_TITLE_WIDTH + Constant::Ui::TITLE_WIDTH / 2 - TITLE.size() / 2) << ""
              << TITLE << std::endl
              << std::setw(Constant::Ui::RELATIVE_TITLE_WIDTH) << ""
              << std::setw(Constant::Ui::TITLE_WIDTH) << std::setfill('=') << ""
              << std::setfill(' ')
              << std::endl
              << std::endl;
}

// void menu(const std::vector<std::string> &vecMenu, const std::string &heading, bool showStatus, const std::string &statsVal, const std::string &statsStr)
// { // show the specific menu

//     logo(); // display logo - "iCoder"

//     updateScreen(heading); // It will update the current screen enum variable

//     if (Global::showHint) // checks if showHint is enabled or not
//         show_hint();      // if enabled, it shows different hints based on the current screeen

//     header(heading, false); // It prints the heading to console, accepts boolean to display logo or not

//     if (showStatus)                      // It checks if it has access to show the current state of the specific screen
//         show_status(statsStr, statsVal); // It accepts 2 strings that is displayed below heading

//     // Here, the vecMenu passed from function contains the menu options in vector of string
//     for (size_t index{0}; index < vecMenu.size(); ++index)
//     {
//         // Print the index starting 1 till vector size
//         std::cout << std::setw(2) << std::right << index + 1 << ". " << vecMenu.at(index);

//         if (index < vecMenu.size() - 1) // New line is not printed at last menu option
//             std::cout << std::endl;
//     }

//     print(std::string{"Your Choice: "}); // ask user for input
// }

// void show_status(const std::string &statsStr, const std::string &statsVal, bool isFinal)
// {
//     std::cout << statsStr << statsVal; // It prints the status to console

//     if (isFinal) // checks if 1 or more status is to be printed or not
//         border(Ui::widthMenu);
//     else
//         std::cout << std::endl; // print new line at last status printed
// }

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

void Ui::updateLastScreen()
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

void Ui::updateScreen(const std::string &heading)
{
    updateLastScreen();

    if (heading == Constant::Tag::ARRAY)
        opnScreen = CUR_ARRAY;
    else if (heading == Constant::Tag::DATA_STRUCTURE)
        opnScreen = CUR_DS;
    else if (heading == Constant::Tag::GAMES)
        opnScreen = CUR_GAMES;
    else if (heading == Constant::Tag::MAIN)
        opnScreen = CUR_MENU;
    else if (heading == Constant::Tag::MORE)
        opnScreen = CUR_MORE;
    else if (heading == Constant::Tag::SETTINGS || heading == Constant::Tag::CHANGE_LINEAR_SEARCH_TYPE)
        opnScreen = CUR_SETTINGS;
    else if (heading == Constant::Tag::STRING)
        opnScreen = CUR_STRING;
    else if (heading == Constant::Tag::UPDATES)
        opnScreen = CUR_UPDATES;
}

void Ui::header(const std::string &heading)
{
    logo();
    subHeader(heading);
}

void Ui::subHeader(const std::string &heading)
{
    std::cout << std::setfill('-')
              << std::setw(2) << " "
              << heading << " "
              << std::setw(Constant::Ui::MENU_WIDTH - (heading.size() + 2)) << ""
              << std::setfill(' ')
              << std::endl;
}

std::vector<std::string> Ui::getHint()
{
    std::vector<std::string> vec;

    vec.emplace_back(Constant::Tag::HINT);

    if (opnScreen != CUR_MENU)
        vec.emplace_back(" ESC    Last Screen");

    vec.emplace_back(" h      Help Screen");

    if (opnScreen != CUR_MORE)
        vec.emplace_back(" m      More features");

    if (opnScreen != CUR_SETTINGS)
        vec.emplace_back(" d      Disable this hint");

    return vec;
}

void Ui::border()
{ // This function displays the border
    std::cout << std::endl
              << std::setfill('-')
              << std::setw(Constant::Ui::MENU_WIDTH) << ""
              << std::setfill(' ')
              << std::endl;
}

void Ui::popUp(const std::string &message)
{
    animater(message); // Animated text is printed for user to get attention

    getchForced(); // Accepts Esc,Enter, Space or Backspace key to continue

    for (size_t i{0}; i < message.size(); ++i)
    {
        std::cout << "\b \b";       // It erases 1 character at a time
        Sleep(Constant::sleepTime); // time gap is based on user choice
    }
}

void Ui::getchForced()
{
    char c;

    // This while loop only exits if the user presses, Esc, Enter, Space or Backspace
    while ((c = getch()))
        if (c == '\r' || c == ' ' || c == '\b' || c == Constant::ESC)
            return;
}

void Ui::animater(const std::string &anime)
{
    for (const auto c : anime)
    {
        std::cout << c;
        Sleep(Constant::sleepTime);
    }
}

void Ui::print(const std::string &message)
{
    border();
    std::cout << message;
}

void Ui::print(const std::vector<std::string> &vec)
{
    subHeader(vec.at(0));

    for (auto it = vec.begin() + 1; it != vec.end(); it++)
        std::cout << *it << std::endl;
    std::cout << std::endl;
}

void Ui::println(const std::string &message)
{
    print(message);
    pressKey();
}

void Ui::pressKey(const std::string &message)
{
    print(message);

    // Asks user to press any key to continue, if user presses Esc, below code is executed
    if (getch() == Constant::ESC)
    {
        throw EscPressed();
    }
}

bool Ui::isIPressed(const std::string &message)
{ // Ask user to press i to run specific task
    print(message);

    return (::tolower(getch()) == 'i');
}

// void erase_line(size_t len)
// {
//     std::cout << "\r" << std::setw(len) << ""
//               << "\r";
// }

// // Adds extra text to the message based on the condition below
// std::string s_or_not_s(size_t num, const std::string &message, const std::string &extra, const std::string &updateFirst)
// {
//     auto temp = message;
//     temp += (num < 2) ? updateFirst : extra;

//     return temp;
// }

void Ui::waitMessage(const std::string &message)
{
    print(message);
    Sleep(1000);
}

bool Ui::confirmChange(const std::string &message, const std::string &txtConfirm)
{ // Asks user for confirmation, if the changes are to be accepted or rejected
    if (message != std::string{""})
        print(message);

    border();

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
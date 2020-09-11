#include <iostream>
#include <iomanip>
#include <windows.h>
#include <conio.h>
#include "Ui.hpp"
#include "../settings/Settings.hpp"
#include "../constant/Constants.hpp"
#include "../exception/Exception.hpp"

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

std::string Ui::getTip()
{
    // random tip generator

    return "Press 'h' for help :)";
}

void Ui::header(const std::string &heading)
{
    logo();
    subHeader(heading);
}

void Ui::subHeader(const std::string &heading)
{
    std::cout << std::setfill('-')
              << std::setw(3) << " "
              << heading << " "
              << std::setw(Constant::Ui::MENU_WIDTH - (heading.size() + 4)) << ""
              << std::setfill(' ')
              << std::endl;
}

void Ui::hint()
{
    subHeader(Constant::Title::HINT);

    std::vector<std::string> hints;

    if (Global::openedScreen.back() != Constant::Title::MAIN)
        hints.emplace_back("Esc  Last Screen");

    hints.emplace_back("h    Help Screen");

    if (Global::openedScreen.back() != Constant::Title::CP)
        hints.emplace_back("c    CP screen");

    if (Global::openedScreen.back() != Constant::Title::SETTINGS)
        hints.emplace_back("d    Disable this hint");

    print(hints);
}

void Ui::border()
{
    std::cout << std::setfill('-')
              << std::setw(Constant::Ui::MENU_WIDTH) << ""
              << std::setfill(' ')
              << std::endl;
}

void Ui::popUp(const std::string &message)
{
    animater(message); // Animated text is printed for user to get attention

    pause(); // Accepts Esc,Enter, Space or Backspace key to continue

    for (size_t i{0}; i < message.size(); ++i)
    {
        std::cout << "\b \b"; // It erases 1 character at a time
        Sleep(25);            // time gap is based on user choice
    }
}

void Ui::pause()
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
        Sleep(25);
    }
}

void Ui::print(const std::string &message)
{
    border();
    std::cout << message;
}

void Ui::print(const std::vector<std::string> &vec)
{
    for (const auto &str : vec)
        std::cout << " " << static_cast<char>(175) << " " << str << std::endl;
    std::cout << std::endl;
}

void Ui::println(const std::string &message)
{
    print(message);
    pressKey();
}

void Ui::println(const std::vector<std::string> &vec)
{
    for (const auto &str : vec)
        std::cout << " " << static_cast<char>(175) << " " << str << std::endl;
    pressKey();
}

void Ui::pressKey(const std::string &message)
{
    print(message);
    getch();
}

bool Ui::isKeyPressed(const std::string &message, char key)
{
    // Ask user to press i to run specific task
    print(message);

    return (::tolower(getch()) == key);
}

void Ui::waitMessage(const std::string &message)
{
    print(message);
    Sleep(1000);
}

bool Ui::confirmChange(const std::string &message)
{
    print(message + std::string{" (Y/N): "});

    // cod::scan sc;
    char c;

    // sc >> c;

    return (::tolower(c) == 'y'); // returns true if user presses 'y'
}
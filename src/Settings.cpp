#include "../header/Settings.hpp"

void settings()
{
    char ch;
    bool flag{true};
    do
    {
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        flag = menu(menu1_data, flag, std::string{" SETTINGS "}); // display the startup menu for settings screen

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        settings_controller(ch); // start as per user choice

    } while (ch != '3');
}

void settings_controller(char ch)
{
    std::string str;
    std::stringstream ss{str};

    switch (ch)
    {
    case '1': // change the animation speed of the menu

        std::cout << "\n\nEnter the speed" << std::endl;
        str = iscan(txtChar);
        if (str == "")
            return;

        if (!(ss >> sleep_time))
        {
            std::cout << "Enter a valid number" << std::endl;
        }
        break;
    case '2': // go to create account screen
        std::cout << "To be implemented" << std::endl;
        break;

    case 27: //ESC
        return;

    default:
        std::cout << std::endl
                  << std::endl
                  << "Invalid choice";
        break;
    }

    press_key(); // getch()
}
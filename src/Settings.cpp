#include "../header/Settings.hpp"
#include "../header/Constants.hpp"

void settings()
{
    char ch;
    bool flag{true};
    do
    {
        system("cls"); // clear the screen each time

        title(); // print the title = iCoder

        flag = menu(menu1_data, flag); // display the startup menu

        { // taking character from string
            std::string str = iscan(txtChar);
            (str != "") ? ch = str.at(0) : ch = ESC;
        }

        settings_controller(ch); // start as per user choice

    } while (ch != '7');

    std::string str;
    std::cout << "\n\nEnter the speed" << std::endl;
    str = iscan(txtChar);
    if (str == "")
        return;

    std::stringstream ss(str);

    if (!(ss >> sleep_time))
    {
        std::cout << "Enter a valid number" << std::endl;
    }
}

void settings_controller(char ch)
{
    switch (ch)
    {
    case '1': // go to log in screen

        break;
    case '2': // go to create account screen

        break;
    case '3': // login Anonymously

        break;
    case '4': // show saved user details

        break;
    case '5': // details about the software and the shortcut/hint that can be used in it
        break;

    case '6': // Customize the software using settings
        break;
    case '7': // exit the program
        break;
    case ESC: //ESC
        return;

    default:
        std::cout << std::endl
                  << std::endl
                  << "Invalid choice";
        break;
    }

    press_key(); // getch()
}
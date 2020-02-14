#include <iostream>
#include <conio.h>
#include "../header/About.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Scanner.hpp"
#include "../header/Constants.hpp"

void about()
{
    char ch;

    // system(std:: string("start https://github.com/DivyanshThakur/iCoder").c_str());

    system("cls"); // clear the screen each time

    title(); // print the title = iCoder

    header(std::string{" ABOUT "});

    //   "\nVersion: " + version_info + "\nSource code: \ngithub.com/DivyanshThakur/iCoder"
    std::cout << "Developer: " << dev_name << std::endl
              << "Version: " << version_info;

    border(width_menu);

    std::cout << "Source code:" << std::endl
              << "github.com/DivyanshThakur/iCoder";

    border(width_menu);

    std::cout << "Press i to open URL";

    ch = getch();

    if (::tolower(ch) == 'i')
        system(std::string("start https://github.com/DivyanshThakur/iCoder").c_str());
    else
        return;
}

void help()
{
}
/** HINTS **/
/*

Press ESC to go to home and main menu

press esc , enter, backspace, space to continue in animate warning

themes

settings to change speed animation

*/
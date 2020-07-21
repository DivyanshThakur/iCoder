#include <iostream>
#include <conio.h>
#include <iomanip>
#include "../Extras.hpp"
#include "../constant/Constants.hpp"
#include "../namespace/header/cod_scan.hpp"

void Extras::about()
{
    Ui::logo();

    std::vector<std::string> aboutVec;
    aboutVec.emplace_back(Constant::Title::ABOUT);
    aboutVec.emplace_back("Developer: " + Constant::iCoder::DEV);
    aboutVec.emplace_back("Version:   " + Constant::iCoder::VERSION);
    Ui::print(aboutVec);

    Ui::subHeader(Constant::Title::LINKS);

    std::cout << "Source code:" << std::endl
              << Constant::Url::SRC.substr(8);

    if (Ui::isKeyPressed("Press i to open URL"))
        system(("start " + Constant::Url::SRC).c_str());
}

// Help screen for new users to guide them through the shortcuts available in the software
void Extras::help()
{
    Ui::header(Constant::Title::HELP);

    std::cout << std::setw(Constant::Ui::INDEX_WIDTH) << std::left << " Key"
              << "    Description";

    Ui::border();

    size_t i, size{Constant::SubMenu::HELP_DATA.size()};

    for (i = 0; i < size; i++)
    {

        std::cout << " " << std::setw(Constant::Ui::INDEX_WIDTH) << std::left << Constant::SubMenu::HELP_DATA.at(i)
                  << "-> " << Constant::SubMenu::HELP_DESC.at(i);

        if (i < size - 1)
            std::cout << std::endl;
    }

    Ui::println("*Can be used only in menu screen");
}
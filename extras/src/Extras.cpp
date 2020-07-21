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

void Extras::changelog()
{
    header(std::string{" CHANGELOG "});

    std::cout << std::setw(Ui::widthIndex + 2) << std::left << "Version"
              << "   Description";
    border(Ui::widthMenu);

    size_t i{0};

    for (const auto &vInfo : SmallMenu::logVersionData)
    {
        // version info is printed
        std::cout << std::setw(Ui::widthIndex + 2) << std::left << vInfo;

        // A loop iterating the version description prints each feature detail to console
        // if it reads '\n' it breaks the inner loop to print next version features
        for (; i < SmallMenu::logVersionDesc.size(); ++i)
        {
            if (SmallMenu::logVersionDesc.at(i) == "\n")
            {
                std::cout << std::endl;
                ++i;
                break;
            }

            // Extra spaces are printed to seprate different versions
            if (i > 0 && SmallMenu::logVersionDesc.at(i - 1) != "\n")
                std::cout << std::setw(Ui::widthIndex + 2) << "";

            std::cout << "-> " << SmallMenu::logVersionDesc.at(i);

            // Except last version, all prints a new line
            if (vInfo != std::string{"1.0"})
                std::cout << std::endl;
        }
    }

    press_key(NIL);
}
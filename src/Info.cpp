#include <iostream>
#include <conio.h>
#include <iomanip>
#include "../header/Info.hpp"
#include "../namespace/header/cod_scan.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/Constants.hpp"

void about()
{
    header(std::string{" ABOUT "});

    std::cout << "Developer: " << devName << std::endl
              << "Version: " << versionInfo;

    border(widthMenu);

    std::cout << "Source code:" << std::endl
              << sCodeUrl.substr(8);

    if (press_i(std::string{"Press i to open URL"}))
        system(std::string("start " + sCodeUrl).c_str()); // this code will open github source code in default browser
}

void help()
{
    header(std::string{" HELP "});

    std::cout << std::setw(widthIndex) << std::left << " Key"
              << "   Description" << std::endl
              << std::endl;

    size_t i{0};

    for (const auto &sc : helpCharData)
    {
        std::cout << " " << std::setw(widthIndex) << std::left << sc;
        std::cout << "-> " << helpCharDesc.at(i++);

        if (sc != std::string{"u"})
            std::cout << std::endl;
    }
    print_message(std::string{"*Can be used only in menu screen"});
    press_key(NIL);
}

void update()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(updatesMenu, std::string{" UPDATES "}, true, versionInfo, std::string{"Version: "});

        try
        {
            sc.choice(ch);

            switch (ch)
            {
            case 1:
                system(std::string("start " + iCoderUrl).c_str());
                return;
            case 2:
                system(std::string("start " + iCoderBetaUrl).c_str());
                return;
            default:
                print_message(std::string{"Invalid choice"});
                press_key();
                break;
            }
        }
        catch (const EscPressed &e)
        {
            return;
        }
        catch (const Exit &e)
        {
            e.what();
        }
        catch (const OpenSettings &e)
        {
            e.what();
        }
        catch (const OpenAbout &e)
        {
            e.what();
        }
        catch (const OpenHelp &e)
        {
            e.what();
        }
        catch (const OpenUpdate &e)
        {
            continue;
        }
        catch (const OpenChangelog &e)
        {
            e.what();
        }
        catch (const OpenHintSetting &e)
        {
            e.what();
        }

    } while (1);
}

void changelog()
{
    header(std::string{" CHANGELOG "});

    std::cout << std::setw(widthIndex + 2) << std::left << "Version"
              << "   Description" << std::endl
              << std::endl;

    size_t i{0};

    for (const auto &vInfo : logVersionData)
    {
        std::cout << std::setw(widthIndex + 2) << std::left << vInfo;

        for (; i < logVersionDesc.size(); ++i)
        {
            if (logVersionDesc.at(i) == "\n")
            {
                ++i;
                break;
            }

            if (i > 0 && logVersionDesc.at(i - 1) != "\n")
                std::cout << std::setw(widthIndex + 2) << "";

            std::cout << "-> " << logVersionDesc.at(i) << std::endl;
        }

        if (vInfo != std::string{"1.0"})
            std::cout << std::endl;
    }
    press_key(NIL);
}
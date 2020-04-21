#include <iostream>
#include <conio.h>
#include <iomanip>
#include "../header/Help.hpp"
#include "../namespace/header/cod_scan.hpp"

void about()
{
    header(std::string{" ABOUT "});

    std::cout << "Developer: " << iCoder::devName << std::endl
              << "Version:   " << iCoder::versionInfo;

    border(Ui::widthMenu);

    std::cout << "Source code:" << std::endl
              << Url::source.substr(8);

    if (press_i(std::string{"Press i to open URL"}))
        system(std::string("start " + Url::source).c_str()); // this code will open github source code in default browser
}

void help()
{
    header(std::string{" HELP "});

    std::cout << std::setw(Ui::widthIndex) << std::left << " Key"
              << "    Description";
    border(Ui::widthMenu);

    size_t i{0};

    for (const auto &sc : SmallMenu::helpCharData)
    {
        if (Global::showHint || Global::showQuit || sc != std::string{"d"})
        {
            std::cout << " " << std::setw(Ui::widthIndex) << std::left << sc
                      << "-> " << SmallMenu::helpCharDesc.at(i++);

            if (sc != std::string{"u"})
                std::cout << std::endl;
        }
        else
            i++;
    }
    std::string message;

    if (shortcutStats == DEFAULT)
        message = std::string{"*Can be used only in menu screen"};
    else if (shortcutStats == EASY)
        message = std::string{"*Can be used only in menu screen\n Use ctrl + key to access it"};
    else if (shortcutStats == ADV)
        message = std::string{"*Enable shortcuts from setting!!"};

    print_message(message);
    press_key(NIL);
}

void update()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(SmallMenu::updates, std::string{" UPDATES "}, true, iCoder::versionInfo, std::string{"Version: "});

        try
        {
            sc.choice(ch);

            switch (ch)
            {
            case 1:
                system(std::string("start " + Url::iStable).c_str());
                return;
            case 2:
                system(std::string("start " + Url::iBeta).c_str());
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

            if (lstScreen == LAST_SETTINGS)
                return;

            lstScreen = LAST_UPDATES;
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
        catch (const OpenAnimeSetting &e)
        {
            e.what();
        }

    } while (1);
}

void changelog()
{
    header(std::string{" CHANGELOG "});

    std::cout << std::setw(Ui::widthIndex + 2) << std::left << "Version"
              << "   Description";
    border(Ui::widthMenu);

    size_t i{0};

    for (const auto &vInfo : SmallMenu::logVersionData)
    {
        std::cout << std::setw(Ui::widthIndex + 2) << std::left << vInfo;

        for (; i < SmallMenu::logVersionDesc.size(); ++i)
        {
            if (SmallMenu::logVersionDesc.at(i) == "\n")
            {
                std::cout << std::endl;
                ++i;
                break;
            }

            if (i > 0 && SmallMenu::logVersionDesc.at(i - 1) != "\n")
                std::cout << std::setw(Ui::widthIndex + 2) << "";

            std::cout << "-> " << SmallMenu::logVersionDesc.at(i);

            if (vInfo != std::string{"1.0"})
                std::cout << std::endl;
        }
    }
    press_key(NIL);
}
#include <iostream>
#include <conio.h>
#include <iomanip>
#include "../header/Info.hpp"
#include "../header/Scanner.hpp"
#include "../header/UIhandler.hpp"
#include "../header/ExHandler.hpp"
#include "../header/Constants.hpp"

void about()
{
    header(std::string{" ABOUT "});

    std::cout << "Developer: " << dev_name << std::endl
              << "Version: " << version_info;

    border(width_menu);

    std::cout << "Source code:" << std::endl
              << scode_url.substr(8);

    if (press_i(std::string{"Press i to open URL"}))
        system(std::string("start " + scode_url).c_str()); // this code will open github source code in default browser
}

void help()
{
    header(std::string{" HELP "});

    std::cout << std::setw(width_index) << std::left << " Key"
              << "   Description" << std::endl
              << std::endl;

    size_t i{0};

    for (const auto &sc : help_char_data)
    {
        std::cout << " " << std::setw(width_index) << std::left << sc;
        std::cout << "-> " << help_desc_data.at(i++);

        if (sc != std::string{"u"})
            std::cout << std::endl;
    }
    print_message(std::string{"*Can be used only in menu screen"});
    press_key(NIL);
}

void update()
{
    Scanner sc;
    int ch;

    do
    {
        menu(download_data, std::string{" UPDATES "}, true, version_info, std::string{"Version: "});

        try
        {
            sc.scanChoice(ch);

            switch (ch)
            {
            case 1:
                system(std::string("start " + icoder_url).c_str());
                return;
            case 2:
                system(std::string("start " + icoder_beta_url).c_str());
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
        catch (const OpenLsearchSetting &e)
        {
            e.what();
        }

    } while (1);
}

void changelog()
{
    header(std::string{" CHANGELOG "});

    std::cout << std::setw(width_index + 2) << std::left << "Version"
              << "   Description" << std::endl
              << std::endl;

    size_t i{0};

    for (const auto &vInfo : log_version_data)
    {
        std::cout << std::setw(width_index + 2) << std::left << vInfo;

        for (; i < log_vdescription_data.size(); ++i)
        {
            if (log_vdescription_data.at(i) == "\n")
            {
                ++i;
                break;
            }

            if (i > 0 && log_vdescription_data.at(i - 1) != "\n")
                std::cout << std::setw(width_index + 2) << "";

            std::cout << "-> " << log_vdescription_data.at(i) << std::endl;
        }

        if (vInfo != std::string{"1.0"})
            std::cout << std::endl;
    }
    press_key(NIL);
}
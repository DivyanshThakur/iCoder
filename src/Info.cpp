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
    char ch;

    header(std::string{" ABOUT "});

    std::cout << "Developer: " << dev_name << std::endl
              << "Version: " << version_info;

    border(width_menu);

    std::cout << "Source code:" << std::endl
              << scode_url.substr(8);

    print_message(std::string{"Press i to open URL"});

    ch = getch();

    if (::tolower(ch) == 'i') // this code will open github source code in default browser
        system(std::string("start " + scode_url).c_str());
    else
        return;
}

void help()
{
    print_message();
    press_key(NIL); // getch()
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

    } while (1);
}

void changelog()
{
    header(std::string{" CHANGELOG "});

    std::cout << std::setw(3 * width_index) << std::left << "Version Info"
              << "Description" << std::endl
              << std::endl;

    size_t i{0};

    for (const auto &vInfo : log_version_data)
    {
        std::cout << std::setw(3 * width_index) << std::left << vInfo;

        for (; i < log_vdescription_data.size(); ++i)
        {
            if (log_vdescription_data.at(i) == "\n")
            {
                ++i;
                break;
            }

            if (i > 0 && log_vdescription_data.at(i - 1) != "\n")
                std::cout << std::setw(3 * width_index) << "";

            std::cout << "-> " << log_vdescription_data.at(i) << std::endl;
        }

        if (vInfo != std::string{"1.0"})
            std::cout << std::endl;
    }
    press_key(NIL);
}
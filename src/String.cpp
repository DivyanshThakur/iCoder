#include <iostream>
#include "../namespace/header/cod_algorithm.hpp"
#include "../header/String.hpp"
#include "../header/UIhandler.hpp"

void String()
{
    StringHandler sh;
    sh.start();
}

void StringHandler::start()
{
    int ch;

    try
    {
        update_string();
    }
    catch (const EscPressed &e)
    {
        throw ReturnHome();
    }

    do
    {
        menu(menu_screen_selector(), std::string{" STRING "});

        try
        {
            try
            {
                sc.choice(ch);
            }
            catch (const EscPressed &e)
            {
                throw ReturnHome();
            }

            fn_caller(ch);
        }
        catch (const EscPressed &e)
        {
            // do nothing
        }
        catch (const InvalidInputException &e)
        {
            std::cerr << e.what();
            press_key(NIL);
        }
        catch (const InvalidPositionException &e)
        {
            std::cerr << e.what();
            press_key(NIL);
        }
        catch (const Exit &e)
        {
            e.what();
        }
        catch (const OpenSettings &e)
        {
            lstScreen = LAST_STRING;
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
            lstScreen = LAST_STRING;
            e.what();
        }
        catch (const OpenChangelog &e)
        {
            e.what();
        }
        catch (const OpenAnimeSetting &e)
        {
            e.what();
        }

    } while (1); // true
}

void StringHandler::input_data(size_t &pos, size_t &len)
{
    show_status(std::string{"String size:    "}, std::to_string(str.size()), false);
    show_status(std::string{"Current string: "}, str.c_str());

    animater(std::string{"Enter the position: "});

    sc >> pos;

    animater(std::string{"\nEnter size of sub-string: "});

    sc >> len;
}

void StringHandler::input_data(size_t &pos, cod::string &val)
{
    show_status(std::string{"String size:    "}, std::to_string(str.size()), false);
    show_status(std::string{"Current string: "}, str.c_str());

    animater(std::string{"Enter the position: "});

    sc >> pos;

    animater(std::string{"\nEnter the sub-string: "});

    cod::getline(sc, val);
}

void StringHandler::pressi_display(bool isStringUpdated)
{
    if (isStringUpdated)
        print_message(std::string{"String updated..."});

    if (press_i(std::string{"Press i to display string"}))
        this->display();
}

std::vector<std::string> StringHandler::menu_screen_selector()
{
    // select the correct menu to display as per need
    std::vector<std::string> toDisplayMenu;
    menuIndex.clear();

    size_t i;

    if (str.size())
    {
        toDisplayMenu.push_back(Menu::string.at(0));
        menuIndex.push_back(0);
    }
    else
    {
        toDisplayMenu.push_back(Menu::string.at(1));
        menuIndex.push_back(1);
    }

    if (str.size() == 0)
    {
        toDisplayMenu.push_back(Menu::string.at(5));
        menuIndex.push_back(5);
    }
    else
    {
        for (i = 2; i < Menu::string.size(); ++i)
        {
            toDisplayMenu.push_back(Menu::string.at(i));
            menuIndex.push_back(i);

            if (i == 5 && !show_adv_opn)
            {
                toDisplayMenu.push_back("Advanced Operations");
                menuIndex.push_back(i + 1);
                break;
            }
        }
    }

    return toDisplayMenu;
}

void StringHandler::fn_caller(int ch)
{
    if (ch == 1)
        string_controller(1);
    else
    {
        if (ch > 0 && ch <= static_cast<int>(menuIndex.size()))
            string_controller(menuIndex.at(ch - 1));
        else
        {
            print_message(std::string{"Invalid choice"});
            press_key(HOME);
        }
    }
}

void StringHandler::string_controller(int ch)
{
    switch (ch)
    {
    case 1: // add/update string
        update_string();
        break;

    case 2: // insert sub-string
        insert_substr();
        break;

    case 3: // delete sub-string
        remove_substr();
        break;

    case 4: // change case
        change_case();
        break;

    case 5:
        display();
        break;

    case 6:
        if (show_adv_opn)
            reverse();
        else
            show_adv_opn = true; // make show_adv_opn = true and shows all available options
        break;

    case 7:
        compare();
        break;

    case 8:
        merge();
        break;

    case 9:
        anagram();
        break;

    case 10:
        palindrome();
        break;

    case 11:
        permutation();
        break;

    case 12:
        find_unique();
        break;

    case 13:
        find_duplicates();
        break;
    }
}

void StringHandler::update_string()
{
    int ch;
    bool toStop;
    cod::string temp;

    if (str.size())
    {
        do
        {
            menu(SmallMenu::updateString, std::string{" UPDATE STRING "});

            toStop = true;
            sc.choice(ch);

            try
            {
                switch (ch)
                {
                case 1:
                    goto new_string_label;

                case 2:
                    header(std::string{" EXTEND STRING "});
                    show_status(std::string{"String size:    "}, std::to_string(str.size()), false);
                    show_status(std::string{"Current string: "}, str.c_str());

                    animater(std::string{"Enter new string: "});
                    cod::getline(sc, temp);
                    str.push_back(' ');
                    str.append(temp);
                    break;

                case Ui::ESC:
                    throw EscPressed();

                default:
                    toStop = false;
                    print_message(std::string{"Invalid choice"});
                    press_key();
                    break;
                }

                if (toStop)
                    this->pressi_display(true);
            }
            catch (const EscPressed &e)
            {
                toStop = false;
            }

        } while (!toStop);
    }
    else
    {
    new_string_label:

        header(std::string{" ADD STRING "});
        animater(std::string{"Enter string: "});
        cod::getline(sc, temp);
        str.assign(temp);

        this->pressi_display();
    }
}

void StringHandler::insert_substr()
{
    cod::string value;
    size_t pos;

    header(std::string{" INSERT SUB-STRING "});

    this->input_data(pos, value);

    str.insert(pos - 1, value);

    this->pressi_display(true);
}

void StringHandler::remove_substr()
{
    size_t pos, len;
    cod::string subStr;

    header(std::string{" DELETE SUB-STRING "});

    this->input_data(pos, len);

    subStr = str.erase(pos - 1, len);

    print_message(std::string{"Removed, "} + subStr.c_str());

    this->pressi_display();
}

bool StringHandler::is_range(const std::string &heading)
{
    int ch;
    bool toStop;

    do
    {
        menu(SmallMenu::rangeString, heading);

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1:
            return false;

        case 2:
            return true;

        default:
            print_message(std::string{"Invalid choice"});
            toStop = false;
            press_key();
            break;
        }

    } while (!toStop);

    return false;
}

void StringHandler::change_case()
{
    int ch;
    bool isRangeSelected;
    bool toStop;
    size_t pos = 1, len = -1;

    do
    {
        menu(SmallMenu::changeCaseString, std::string{" CHANGE CASE "});

        toStop = true;
        sc.choice(ch);

        try
        {
            switch (ch)
            {
            case 1:
                isRangeSelected = is_range(std::string{" TOGGLE CASE "});

                if (isRangeSelected)
                {
                    header(std::string{std::string{" TOGGLE CASE "}});
                    this->input_data(pos, len);
                }

                cod::toggle(str, pos - 1, len);
                break;

            case 2:
                isRangeSelected = is_range(std::string{" TO LOWER "});

                if (isRangeSelected)
                {
                    header(std::string{std::string{" TO LOWER "}});
                    this->input_data(pos, len);
                }

                cod::tolower(str, pos - 1, len);
                break;

            case 3:
                isRangeSelected = is_range(std::string{" TO UPPER "});

                if (isRangeSelected)
                {
                    header(std::string{std::string{" TO UPPER "}});
                    this->input_data(pos, len);
                }

                cod::toupper(str, pos - 1, len);
                break;

            case Ui::ESC:
                throw EscPressed();

            default:
                print_message(std::string{"Invalid choice"});
                press_key();
                toStop = false;
                break;
            }

            if (toStop)
            {
                this->pressi_display(true);
            }
        }
        catch (const EscPressed &e)
        {
            toStop = false;
        }

    } while (!toStop);
}

void StringHandler::display()
{
    header(std::string{" DISPLAY STRING "});

    std::cout << "String size: " << str.size() << std::endl
              << "Total words: " << str.words() << std::endl
              << "Consonants:  " << str.consonants() << std::endl
              << "Vowels:      " << str.vowels();

    border(Ui::widthMenu);

    std::cout << "String: "
              << str;

    press_key();
}

void StringHandler::reverse()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" REVERSE "});

    if (isRangeSelected)
    {
        this->input_data(pos, len);
    }

    str.reverse(pos - 1, len);

    this->pressi_display(true);
}

void StringHandler::compare()
{
}

void StringHandler::merge()
{
}

void StringHandler::anagram()
{
}

void StringHandler::palindrome()
{
}

void StringHandler::permutation()
{
}

void StringHandler::find_unique()
{
}

void StringHandler::find_duplicates()
{
}

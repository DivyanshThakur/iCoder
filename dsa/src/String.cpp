#include <iostream>
#include "../header/String.hpp"
#include "../../namespace/header/cod_algorithm.hpp"

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
            e.what();
        }
        catch (const OpenChangelog &e)
        {
            e.what();
        }
        catch (const OpenMoreScreen &e)
        {
            e.what();
        }
        catch (const OpenAnimeSetting &e)
        {
            e.what();
        }

    } while (1); // true
}

void StringHandler::input_data(size_t &pos, size_t &len, const std::string &heading)
{
    header(heading);

    show_status(std::string{"String size:    "}, std::to_string(str.size()), false);
    show_status(std::string{"Current string: "}, str.c_str());

    animater(std::string{"Enter the position: "});

    sc >> pos;

    animater(std::string{"\nEnter no of chars: "});

    sc >> len;
}

void StringHandler::input_data(size_t &pos, cod::string &val, const std::string &heading)
{
    header(heading);

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
            print_message(std::string{"Invalid choice"}, true, HOME);
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

    case 5: // display string
        display();
        break;

    case 6: // reverse the string
        if (show_adv_opn)
            reverse();
        else
            show_adv_opn = true; // make show_adv_opn = true and shows all available options
        break;

    case 7: // compare 2 strings
        compare();
        break;

    case 8: // merge 2 strings
        merge();
        break;

    case 9: // check for anagram
        anagram();
        break;

    case 10: // check for palindrome
        palindrome();
        break;

    case 11: // show all permutations
        permutation();
        break;

    case 12: // find unique characters
        find_unique();
        break;

    case 13: // find duplicate characters
        find_duplicates();
        break;
    }
}

void StringHandler::update_string()
{
    int ch;
    bool toStop, addSpace;
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

                    addSpace = confirm_the_change("", std::string{"Seprate them with space"});

                    if (addSpace)
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
    }
}

void StringHandler::insert_substr()
{
    cod::string value;
    size_t pos;

    this->input_data(pos, value, std::string{" INSERT SUB-STRING "});

    str.insert(pos - 1, value);

    this->pressi_display(true);
}

void StringHandler::remove_substr()
{
    size_t pos, len;
    cod::string subStr;

    this->input_data(pos, len, std::string{" DELETE SUB-STRING "});

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
                    this->input_data(pos, len, std::string{std::string{" TOGGLE CASE "}});

                cod::toggle(str, pos - 1, len);
                break;

            case 2:
                isRangeSelected = is_range(std::string{" TO LOWER "});

                if (isRangeSelected)
                    this->input_data(pos, len, std::string{std::string{" TO LOWER "}});

                cod::tolower(str, pos - 1, len);
                break;

            case 3:
                isRangeSelected = is_range(std::string{" TO UPPER "});

                if (isRangeSelected)
                    this->input_data(pos, len, std::string{std::string{" TO UPPER "}});

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
                this->pressi_display(true);
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
        this->input_data(pos, len, std::string{" REVERSE "});

    str.reverse(pos - 1, len);

    this->pressi_display(true);
}

void StringHandler::compare()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" COMPARE "});

    if (isRangeSelected)
        this->input_data(pos, len, std::string{" COMPARE "});

    StringHandler s2;
    s2.update_string();

    int result = str.compare(pos - 1, len, s2.str);

    char symbol = ((result) ? ((result > 0) ? '>' : '<') : '=');

    border(Ui::widthMenu);
    wait_message(std::string{"Comparing..."});

    header(std::string{" COMPARE "});

    show_status(std::string{"String 1: "}, std::string(str.c_str(), pos - 1, len), false);
    show_status(std::string{"String 2: "}, s2.str.c_str());

    std::cout << "String 1 " << symbol << " String 2";

    press_key();
}

void StringHandler::merge()
{
    StringHandler s2;
    s2.update_string();

    str.append(s2.str);

    border(Ui::widthMenu);
    wait_message(std::string{"Merging..."});

    std::cout << "\rString merged!";

    pressi_display();
}

void StringHandler::anagram()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" ANAGRAM "});

    if (isRangeSelected)
        this->input_data(pos, len, std::string{" ANAGRAM "});

    StringHandler s2;
    s2.update_string();

    bool isAnagram = str.isanagram(pos - 1, len, s2.str);

    border(Ui::widthMenu);
    wait_message(std::string{"Checking..."});

    header(std::string{" ANAGRAM "});

    show_status(std::string{"String 1: "}, std::string(str.c_str(), pos - 1, len), false);
    show_status(std::string{"String 2: "}, s2.str.c_str());

    std::string message = ((isAnagram) ? "(Y) The string is anagram" : "(N) The string is not anagram");

    std::cout << message;

    press_key();
}

void StringHandler::palindrome()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" PALINDROME "});

    if (isRangeSelected)
        this->input_data(pos, len, std::string{" PALINDROME "});

    bool isPalin = str.ispalindrome(pos - 1, len);

    std::string message = ((isPalin) ? "(Y) The string is palindrome" : "(N) The string is not palindrome");

    border(Ui::widthMenu);
    wait_message(std::string{"Checking..."});

    std::cout << "\r" << message;

    pressi_display();
}

void StringHandler::permutation()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" PERMUTATION "});

    if (isRangeSelected)
        this->input_data(pos, len, std::string{" PERMUTATION "});

    border(Ui::widthMenu);
    wait_message(std::string{"Generating..."});

    header(std::string{" PERMUTATION "});

    show_status(std::string{"String: "}, std::string(str.c_str(), pos - 1, len));

    std::cout << "Permutation:" << std::endl;

    str.permutation(pos - 1, len);

    std::cout << "\x1b[A"; // return to previous line

    pressi_display();
}

void StringHandler::find_unique()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" FIND UNIQUE "});

    if (isRangeSelected)
        this->input_data(pos, len, std::string{" FIND UNIQUE "});

    std::vector<char> vec = str.find_unique(pos - 1, len);

    border(Ui::widthMenu);
    wait_message(std::string{"Finding..."});

    header(std::string{" FIND UNIQUE "});

    show_status(std::string{"String: "}, std::string(str.c_str(), pos - 1, len));

    if (vec.size())
    {
        std::cout << vec.size() << " unique characters:" << std::endl;

        for (auto const &c : vec)
            std::cout << c << " ";
    }
    else
        std::cout << "No unique characters found";

    this->pressi_display();
}

void StringHandler::find_duplicates()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" FIND DUPLICATES "});

    if (isRangeSelected)
        this->input_data(pos, len, std::string{" FIND DUPLICATES "});

    std::vector<cod::pair<char, int>> vec = str.find_duplicates(pos - 1, len);

    border(Ui::widthMenu);
    wait_message(std::string{"Finding..."});

    header(std::string{" FIND DUPLICATES "});

    show_status(std::string{"String: "}, std::string(str.c_str(), pos - 1, len));

    if (vec.size())
    {
        std::cout << std::setw(12) << std::left << "Occurence"
                  << "Char" << std::endl;

        for (size_t i{0}; i < vec.size(); ++i)
            if (i < vec.size() - 1)
                std::cout << vec.at(i) << std::endl;
            else
                std::cout << vec.at(i);
    }
    else
        std::cout << "No duplicate characters found";

    this->pressi_display();
}

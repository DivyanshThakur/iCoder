#include <iostream>
#include "../header/String.hpp"
#include "../../constant/Constants.hpp"

/**************************************************************************************************************
 * 
 *                                           AbstractMenu IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

std::string StringHandler::Menu::title() const
{
    return std::string(Constant::Title::STRING);
}

std::vector<std::string> StringHandler::Menu::getStats() const
{
    Ui::subHeader(Constant::Title::STATS);

    std::vector<std::string> vec;

    vec.emplace_back("File Name: " + str.name());

    return vec;
}

std::vector<std::string> StringHandler::Menu::selector()
{
    menuIndexer(Constant::Menu::STRING.size());
    return Constant::Menu::STRING;
}

void StringHandler::Menu::controller() const
{
    switch (menuIndex.at(ch - 1))
    {
    }
}

/**************************************************************************************************************
 * 
 *                                        STRING HANDLER IMPLEMENTATIONS
 * 
 * ***********************************************************************************************************/

void StringHandler::start()
{
    Menu::player(Menu());
}

// This function accepts the pos as reference to assign values to it
void StringHandler::input_data(const std::string &heading, size_t &pos)
{
    header(heading); // display their particular heading

    show_status(std::string{"String size:    "}, std::to_string(str.size()), false);
    show_status(std::string{"Current string: "}, str.c_str());

    animater(std::string{"Enter the position: "});

    sc >> pos;
}

// This function accepts the pos and len as reference to assign values to it
void StringHandler::input_data(const std::string &heading, size_t &pos, size_t &len)
{
    input_data(heading, pos);

    animater(std::string{"\nEnter no of chars: "});

    sc >> len;
}

// This function accepts the pos and string value as reference to assign values to it
void StringHandler::input_data(const std::string &heading, size_t &pos, cod::string &val)
{
    input_data(heading, pos);

    animater(std::string{"\nEnter the sub-string: "});

    cod::getline(sc, val);
}

// display press i to display string whenever the string is updated
void StringHandler::pressi_display(bool isStringUpdated)
{
    if (isStringUpdated)
        print_message(std::string{"String updated..."});

    // calls the press_i() from Ui.hpp
    if (press_i(std::string{"Press i to display string"}))
        this->display();
}

std::vector<std::string> StringHandler::menu_screen_selector()
{
    std::vector<std::string> toDisplayMenu; // select the correct menu to display as per need
    menuIndex.clear();                      // clear each time to erase previous index values

    size_t i;

    if (str.size())
    {
        toDisplayMenu.push_back(Menu::string.at(0)); // If the string is not empty it shows to update the current string
        menuIndex.push_back(0);                      // The index of the menu::string is stored in menuIndex vector

        for (i = 2; i < Menu::string.size(); ++i)
        {
            toDisplayMenu.push_back(Menu::string.at(i));
            menuIndex.push_back(i);

            if (i == 5 && !show_adv_opn) // adds adv opns if show_adv_opn is false at index = 5
            {
                toDisplayMenu.push_back("Advanced Operations");
                menuIndex.push_back(i + 1);
                break;
            }
        }
    }
    else
    {
        toDisplayMenu.push_back(Menu::string.at(1)); // if string is empty it shows to add new string
        menuIndex.push_back(1);

        toDisplayMenu.push_back(Menu::string.at(5)); // with display string option
        menuIndex.push_back(5);
    }

    return toDisplayMenu;
}

// The fn_caller() calls the appropriate function based on the index stored in menuIndex
// logic- In menu_screen_selector() when a menu option is selected to display its index
// is stored in the menuIndex vector which tells about its position in menu screen
// The first func is called if ch = 1 and for values of ch <=0 or ch>size are invalid
// eg. for ch = 4, it menuIndex returns the menu index at position ch-1,i.e. 4-1 = 3
// At index 3, the appropriate func is called using string_controller().

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

// This function upadates the current string or add new string
void StringHandler::update_string()
{
    // ch stores the user's choice
    // toStop runs the loop till its true
    // addSpace adds space between old and new string
    // temp stored the inputed string temporary and updates the current string by assigning temp to it

    int ch;
    bool toStop, addSpace;
    cod::string temp;

    if (str.size())
    {
        do
        {
            menu(SmallMenu::updateString, std::string{" UPDATE STRING "});

            toStop = true; // make toStop true each time to make it stop at current itr,until invalid values are pressed
            sc.choice(ch);

            try
            {
                switch (ch)
                {
                case 1: // goto add new string section
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
                    toStop = false; // to run the loop again
                    print_message(std::string{"Invalid choice"}, true);
                    break;
                }

                if (toStop) // if true print the display array funtion and exits loop after it
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

    this->input_data(std::string{" INSERT SUB-STRING "}, pos, value);

    str.insert(pos - 1, value); // Insert substring at a position

    this->pressi_display(true);
}

void StringHandler::remove_substr()
{
    size_t pos, len;
    cod::string subStr;

    this->input_data(std::string{" DELETE SUB-STRING "}, pos, len);

    subStr = str.erase(pos - 1, len); // remove substring from a position

    print_message(std::string{"Removed, "} + subStr.c_str());

    this->pressi_display();
}

// is_range() is a base function for getting user's choice for slecting range of string
// user can select full string, or a substring, other values are invalid

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
        case 1: // returns false if opn 1 is selected
            return false;

        case 2: // returns true if opn 2 is selected
            return true;

        default:
            toStop = false; // loop again
            print_message(std::string{"Invalid choice"}, true);
            break;
        }

    } while (!toStop);

    return false; // useless return, to avoid warning
}

// This func changes the string case by toggling, changing to upper or lower, full string or substring
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
                    this->input_data(std::string{std::string{" TOGGLE CASE "}}, pos, len);

                cod::toggle(str, pos - 1, len);
                break;

            case 2:
                isRangeSelected = is_range(std::string{" TO LOWER "});

                if (isRangeSelected)
                    this->input_data(std::string{std::string{" TO LOWER "}}, pos, len);

                cod::tolower(str, pos - 1, len);
                break;

            case 3:
                isRangeSelected = is_range(std::string{" TO UPPER "});

                if (isRangeSelected)
                    this->input_data(std::string{std::string{" TO UPPER "}}, pos, len);

                cod::toupper(str, pos - 1, len);
                break;

            case Ui::ESC:
                throw EscPressed();

            default:
                toStop = false;
                print_message(std::string{"Invalid choice"}, true);
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

// Display the string with details about the size, words , consonants and vowels
void StringHandler::display()
{
    header(std::string{" DISPLAY STRING "});

    std::cout << "String size: " << str.size() << std::endl
              << "Total words: " << str.words() << std::endl
              << "Consonants:  " << str.consonants() << std::endl
              << "Vowels:      " << str.vowels();

    print_message(std::string{"String: "} + str.c_str(), true);
}

// Reverse the given string
void StringHandler::reverse()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" REVERSE "});

    if (isRangeSelected)
        this->input_data(std::string{" REVERSE "}, pos, len);

    str.reverse(pos - 1, len);

    this->pressi_display(true);
}

// Compare the given string with another temporary string
void StringHandler::compare()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" COMPARE "});

    if (isRangeSelected)
        this->input_data(std::string{" COMPARE "}, pos, len);

    StringHandler s2;
    s2.update_string();

    int result = str.compare(pos - 1, len, s2.str);

    char symbol = ((result) ? ((result > 0) ? '>' : '<') : '=');

    wait_message(std::string{"Comparing..."});

    header(std::string{" COMPARE "});

    show_status(std::string{"String 1: "}, std::string(str.c_str(), pos - 1, len), false);
    show_status(std::string{"String 2: "}, s2.str.c_str());

    std::cout << "String 1 " << symbol << " String 2";

    press_key();
}

// Merge temp string in current string
void StringHandler::merge()
{
    StringHandler s2;
    s2.update_string();

    str.append(s2.str);

    wait_message(std::string{"Merging..."});

    std::cout << "\rString merged!";

    this->pressi_display();
}

// Check for anagram - same number of chars but rearranged
void StringHandler::anagram()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" ANAGRAM "});

    if (isRangeSelected)
        this->input_data(std::string{" ANAGRAM "}, pos, len);

    StringHandler s2;
    s2.update_string();

    bool isAnagram = str.isanagram(pos - 1, len, s2.str);

    wait_message(std::string{"Checking..."});

    header(std::string{" ANAGRAM "});

    show_status(std::string{"String 1: "}, std::string(str.c_str(), pos - 1, len), false);
    show_status(std::string{"String 2: "}, s2.str.c_str());

    std::string message = ((isAnagram) ? "(Y) The string is anagram" : "(N) The string is not anagram");

    std::cout << message;

    press_key();
}

// Check for palindrome - String from left is same as string from right
void StringHandler::palindrome()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" PALINDROME "});

    if (isRangeSelected)
        this->input_data(std::string{" PALINDROME "}, pos, len);

    bool isPalin = str.ispalindrome(pos - 1, len);

    std::string message = ((isPalin) ? "(Y) The string is palindrome" : "(N) The string is not palindrome");

    wait_message(std::string{"Checking..."});

    std::cout << "\r" << message;

    this->pressi_display();
}

// Print all possible permutations of the string
void StringHandler::permutation()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" PERMUTATION "});

    if (isRangeSelected) // taking input from the user about the substring
        this->input_data(std::string{" PERMUTATION "}, pos, len);

    wait_message(std::string{"Generating..."}); // silly wait message to show off

    auto permCount = cod::fact(str.size(pos - 1, len));
    bool yesProceed{false};

    do
    {
        header(std::string{" PERMUTATION "});

        show_status(std::string{"String: "}, std::string(str.c_str(), pos - 1, len));

        std::cout << permCount << s_or_not_s(permCount, " Permutation");

        // If permutation count is greater than 1000, it will show a confirmation message asking user to generate
        // all permutations or not. This condition is executed 1 time, next time due to yesProceed equals true it
        // becomes false. If count is less than 1000 it will check 2 condition.
        // 1st- if count was greater than 1000 1st time and user confirmed to generate, it will not run press_i()
        // 2nd - else it will run press_i() and asks user to show or not.

        if (permCount > 1000 && !yesProceed)
        {
            yesProceed = confirm_the_change(std::string{"Generating all permutations can\ntake time longer then usual.."});
        }
        else
        {
            if (!yesProceed)
            {
                bool showPerm = press_i(std::string{"Press i to show all permutations"});

                if (!showPerm)
                    return;

                erase_line();
            }
            else
            {
                yesProceed = false;
                border(Ui::widthMenu);
            }

            str.permutation(pos - 1, len);

            std::cout << "\x1b[A"; // return to previous line
        }

    } while (yesProceed);

    this->pressi_display();
}

// Find unique chars in the string
void StringHandler::find_unique()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" FIND UNIQUE "});

    if (isRangeSelected)
        this->input_data(std::string{" FIND UNIQUE "}, pos, len);

    std::vector<char> vec = str.find_unique(pos - 1, len);

    wait_message(std::string{"Finding..."});

    header(std::string{" FIND UNIQUE "});

    show_status(std::string{"String: "}, std::string(str.c_str(), pos - 1, len));

    if (vec.size())
    {
        std::cout << vec.size() << s_or_not_s(vec.size(), "unique character", "s:", ":") << std::endl;

        for (auto const &c : vec)
            std::cout << c << " ";
    }
    else
        std::cout << "No unique characters found";

    this->pressi_display();
}

// Find duplicates
void StringHandler::find_duplicates()
{
    size_t pos = 1, len = -1;

    bool isRangeSelected = is_range(std::string{" FIND DUPLICATES "});

    if (isRangeSelected)
        this->input_data(std::string{" FIND DUPLICATES "}, pos, len);

    std::vector<std::pair<int, char>> vec = str.find_duplicates(pos - 1, len);

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

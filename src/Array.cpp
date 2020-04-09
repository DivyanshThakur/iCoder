#include <iostream>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include "../header/Array.hpp"
#include "../namespace/header/cod_array.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Constants.hpp"

void Arrays()
{
    cod::scan sc;
    int ch;

    do
    {
        menu(getDataTypeMenu, std::string{" SELECT DATA TYPE "});

        sc.choice(ch);

        array_type_selector(ch); // call the array funtion with user defined data type

    } while (1); // always true
}

void array_type_selector(int ch)
{
    ArrayHandler<int> int_handler;
    ArrayHandler<long long> long_handler;
    ArrayHandler<double> db_handler;
    ArrayHandler<char> char_handler;
    ArrayHandler<std::string> str_handler;

    switch (ch)
    {
    case 1:
        int_handler.start();
        break;

    case 2:
        long_handler.start();
        break;

    case 3:
        db_handler.start();
        break;

    case 4:
        char_handler.start();
        break;

    case 5:
        str_handler.start();
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(); // program paused
    }
}

/*** TEMPLATE  CLASS FUNTIONS ARE CODED BELOW ***/

template <typename T>
void ArrayHandler<T>::start()
{
    int ch;

    update_size();

    do
    {
        menu(menu_screen_selector());

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

            if (arr.size() == 0)
                empty_arrays_controller(ch);
            else if (show_adv_opn)
                arrays_controller_adv(ch);
            else
                arrays_controller(ch);
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
        catch (const NegativeValueException &e)
        {
            std::cerr << e.what();
            press_key(NIL);
        }
        catch (const OutofBoundsException &e)
        {
            std::cerr << e.what();
            press_key(NIL);
        }
        catch (const ArrayFullException &e)
        {
            std::cerr << e.what();
            press_key(NIL);
        }
        catch (const ArrayEmptyException &e)
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
        catch (const OpenHintSetting &e)
        {
            e.what();
        }

    } while (1); // true
}

template <typename T>
void ArrayHandler<T>::pressi_display()
{
    if (press_i(std::string{"Press i to display array"}))
        this->display_arr();
}

/** MENU SCREEN SELECTOR TEMPLATE FUNCTIONS **/

template <typename T>
std::vector<std::string> ArrayHandler<T>::menu_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> toDisplayMenu;
    size_t i;

    if (arr.max_size())
        toDisplayMenu.push_back(arrayMenu.at(0));
    else
        toDisplayMenu.push_back(arrayMenu.at(1));

    if (arr.size() == 0)
    {
        toDisplayMenu.push_back(arrayMenu.at(2));
        toDisplayMenu.push_back(arrayMenu.at(6));
    }
    else
    {
        for (i = 2; i < arrayMenu.size(); ++i)
        {
            if (!(i == 7 && show_adv_opn))
                toDisplayMenu.push_back(arrayMenu.at(i));

            if (i == 7 && !show_adv_opn)
                break;
        }
    }

    return toDisplayMenu;
}

template <>
std::vector<std::string> ArrayHandler<std::string>::menu_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> toDisplayMenu;
    size_t i;

    if (arr.max_size())
        toDisplayMenu.push_back(arrayMenu.at(0));
    else
        toDisplayMenu.push_back(arrayMenu.at(1));

    if (arr.size() == 0)
    {
        toDisplayMenu.push_back(arrayMenu.at(2));
        toDisplayMenu.push_back(arrayMenu.at(6));
    }
    else
    {
        for (i = 2; i < arrayMenu.size(); ++i)
        {
            if (!((i == 7 || i == 16 || i == 17) && show_adv_opn))
                toDisplayMenu.push_back(arrayMenu.at(i));

            if ((i == 7 && !show_adv_opn) || i == 20)
                break;
        }
    }

    return toDisplayMenu;
}

template <>
std::vector<std::string> ArrayHandler<char>::menu_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> toDisplayMenu;
    size_t i;

    if (arr.max_size())
        toDisplayMenu.push_back(arrayMenu.at(0));
    else
        toDisplayMenu.push_back(arrayMenu.at(1));

    if (arr.size() == 0)
    {
        toDisplayMenu.push_back(arrayMenu.at(2));
        toDisplayMenu.push_back(arrayMenu.at(6));
    }
    else
    {
        for (i = 2; i < arrayMenu.size(); ++i)
        {
            if (!((i == 7 || i == 17) && show_adv_opn))
                toDisplayMenu.push_back(arrayMenu.at(i));

            if ((i == 7 && !show_adv_opn) || i == 20)
                break;
        }
    }

    return toDisplayMenu;
}

/** END OF MENU SCREEN SELECTOR TEMPLATE FUNCTIONS **/

/** Empty Array Menu **/

template <typename T>
void ArrayHandler<T>::empty_arrays_controller(int ch)
{

    switch (ch)
    {
    case 1: // add or update size of array
        update_size();
        break;

    case 2: // add elements after last element in array
        add_elements();
        break;

    case 3: // display elements
        display_arr();
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(HOME);
        return;
    }
}

/** Array Controller **/

template <typename T>
void ArrayHandler<T>::arrays_controller(int ch)
{

    switch (ch)
    {
    case 1: // add or update size of array
        update_size();
        break;

    case 2: // add elements after last element in array
        add_elements();
        break;

    case 3: // insert a value at a given position
        insert_value();
        break;

    case 4: // delete a range of values
        remove_multiple_values();
        break;

    case 5: // delete from a given position
        remove_value();
        break;

    case 6: // display elements
        display_arr();
        break;

    case 7: // make show_adb_opn = true at end of while loop
        show_adv_opn = true;
        return;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(HOME);
        return;
    }
}

/** ARRAYS CONTROLLER ADVANCED TEMPLATE FUNCTIONS **/

template <typename T>
void ArrayHandler<T>::arrays_controller_adv(int ch)
{
    switch (ch)
    {
    case 1: // add or update size of array
        update_size();
        break;

    case 2: // add elements after last element in array
        add_elements();
        break;

    case 3: // insert a value at a given position
        insert_value();
        break;

    case 4: // delete a range of values
        remove_multiple_values();
        break;

    case 5: // delete from a given position
        remove_value();
        break;

    case 6: // display elements
        display_arr();
        break;

    case 7: // linear search
        linear_search_arr();
        break;

    case 8: // binary search
        binary_search_arr();
        break;

    case 9: // merge
        merge_arr();
        break;

    case 10: // set operations
        set_opn_arr();
        break;

    case 11: // sorting
        sort_opn_arr();
        break;

    case 12: // reverse the array
        reverse_arr();
        break;

    case 13: // shift/Rotation
        shift_rotate_arr();
        break;

    case 14: // finding duplicates
        find_dup_val_arr();
        break;

    case 15: // find missing elements
        find_miss_val_arr();
        break;

    case 16: // find a pair with sum K
        find_pair_sum_arr();
        break;

    case 17: // min and max value
        max_min();
        break;

    case 18: // get value
        get_value();
        break;

    case 19: // set value
        set_value();
        break;

    case 20: // average value
        average();
        break;

    case 21: // sum
        sum();
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(HOME);
        return;
    }
}

template <>
void ArrayHandler<char>::arrays_controller_adv(int ch)
{
    switch (ch)
    {
    case 1: // add or update size of array
        update_size();
        break;

    case 2: // add elements after last element in array
        add_elements();
        break;

    case 3: // insert a value at a given position
        insert_value();
        break;

    case 4: // delete a range of values
        remove_multiple_values();
        break;

    case 5: // delete from a given position
        remove_value();
        break;

    case 6: // display elements
        display_arr();
        break;

    case 7: // linear search
        linear_search_arr();
        break;

    case 8: // binary search
        binary_search_arr();
        break;

    case 9: // merge
        merge_arr();
        break;

    case 10: // set operations
        set_opn_arr();
        break;

    case 11: // sorting
        sort_opn_arr();
        break;

    case 12: // reverse the array
        reverse_arr();
        break;

    case 13: // shift/Rotation
        shift_rotate_arr();
        break;

    case 14: // finding duplicates
        find_dup_val_arr();
        break;

    case 15: // find missing elements
        find_miss_val_arr();
        break;

    case 16: // min and max value
        max_min();
        break;

    case 17: // get value
        get_value();
        break;

    case 18: // set value
        set_value();
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(HOME);
        return;
    }
}

template <>
void ArrayHandler<std::string>::arrays_controller_adv(int ch)
{
    switch (ch)
    {
    case 1: // add or update size of array
        update_size();
        break;

    case 2: // add elements after last element in array
        add_elements();
        break;

    case 3: // insert a value at a given position
        insert_value();
        break;

    case 4: // delete a range of values
        remove_multiple_values();
        break;

    case 5: // delete from a given position
        remove_value();
        break;

    case 6: // display elements
        display_arr();
        break;

    case 7: // linear search
        linear_search_arr();
        break;

    case 8: // binary search
        binary_search_arr();
        break;

    case 9: // merge
        merge_arr();
        break;

    case 10: // set operations
        set_opn_arr();
        break;

    case 11: // sorting
        sort_opn_arr();
        break;

    case 12: // reverse the array
        reverse_arr();
        break;

    case 13: // shift/Rotation
        shift_rotate_arr();
        break;

    case 14: // finding duplicates
        find_dup_val_arr();
        break;

    case 15: // min and max value
        max_min();
        break;

    case 16: // get value
        get_value();
        break;

    case 17: // set value
        set_value();
        break;

    default:
        print_message(std::string{"Invalid choice"});
        press_key(HOME);
        return;
    }
}

/** END OF ARRAYS CONTROLLER ADVANCED TEMPLATE FUNCTIONS **/

template <typename T>
void ArrayHandler<T>::update_size()
{
    int size;

    header(std::string{" ARRAY SIZE "});

    if (arr.max_size() != 0)
    {
        std::cout << "Current size: " << arr.max_size() << std::endl
                  << "Value stored: " << arr.size();
        border(widthMenu);
    }

    animater(std::string{"Enter max size: "});

    sc >> size;
    arr.update_size(size);
}

template <typename T>
void ArrayHandler<T>::add_elements()
{
    int size;
    T value;

    if (arr.size() == arr.max_size())
        throw ArrayFullException();

    header(std::string{" ADD VALUES "});

    std::cout << "Maximum size: " << arr.max_size() << std::endl
              << "Value stored: " << arr.size();
    border(widthMenu);

    animater(std::string{"Enter no of values: "});

    sc >> size;

    if (size < 0)
        throw NegativeValueException();

    // std::string message{" ENTER " + std::to_string(size)};
    border(widthMenu);

    std::string val = (size > 1) ? " values:\n" : " value ";
    std::cout << "Enter " << size << val;

    for (int i{0}; i < size; ++i)
    {
        if (arr.size() == arr.max_size())
            throw ArrayFullException();

        std::cout << static_cast<char>(175) << " ";
        sc >> ((i == size - 1) || (arr.size() + 1 == arr.max_size())) >> value;

        arr.push_back(value);
    }

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::insert_value()
{
    size_t pos;
    T value;

    if (arr.size() == arr.max_size())
        throw ArrayFullException();

    header(std::string{" INSERT VALUE "});

    show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

    animater(std::string{"Enter the value: "});

    sc >> value;

    std::cout << std::endl;

    animater(std::string{"Enter the position: "});

    sc >> pos;

    arr.insert(value, pos);

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::remove_multiple_values()
{
    size_t pos, n;
    cod::array<T> values;

    header(std::string{" DELETE MULTIPLE VALUES "});

    show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

    animater(std::string{"Enter the starting position: "});

    sc >> pos;

    std::cout << std::endl;

    animater(std::string{"Enter the number of elements: "});

    sc >> n;

    values = arr.remove(pos, n);

    n = values.size();

    if (!n) // if position is invalid return to menu screen
        return;

    border(widthMenu);

    std::cout << n;

    (n == 1) ? std::cout << " value: " : std::cout << " values:" << std::endl;

    std::cout << values << " deleted from array";

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::remove_value()
{
    size_t pos;
    T value;

    header(std::string{" DELETE VALUE "});

    show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

    animater(std::string{"Enter the position: "});

    sc >> pos;

    value = arr.remove(pos);

    std::cout << std::endl
              << value << " is deleted from the array";

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::display_arr() const
{
    header(std::string{" DISPLAY ARRAY "});

    std::cout << "Maximum size: " << arr.max_size() << std::endl
              << "Value stored: " << arr.size() << std::endl
              << "Array: "
              << arr;

    press_key();
}

template <typename T>
void ArrayHandler<T>::linear_search_arr()
{
    T val;
    size_t pos;

    header(std::string{" LINEAR SEARCH "});

    show_status(std::string{"Search Type: "}, stats_selector());

    animater(std::string{"Enter the value: "});

    sc >> val;

    pos = arr.lsearch(val);

    if (pos)
        print_message(std::string{"Found at position "} + std::to_string(pos));
    else
        print_message(std::string{"The value doesn't exists!"});

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::binary_search_arr()
{
    T val;
    size_t pos;

    if (!arr.isSorted())
    {
        this->sort(std::string{" BINARY SEARCH "});

        print_message(std::string{"Array Sorted!"});
        press_key();
    }

    header(std::string{" BINARY SEARCH "});

    animater(std::string{"Enter the value: "});

    sc >> val;

    pos = arr.bsearch(val);

    if (pos)
        print_message(std::string{"Found at position "} + std::to_string(pos));
    else
        print_message(std::string{"The value doesn't exists!"});

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::merge_arr()
{
    ArrayHandler arrHndlr;

    try
    {
        arrHndlr.update_size();
        arrHndlr.add_elements();
    }
    catch (const EscPressed &e)
    {
        // do nothing
    }
    catch (const ArrayFullException &e)
    {
        e.what();
        press_key();
    }

    if (!arr.isSorted())
        this->sort(std::string{" MERGE "}, std::string{"Checking array 1..."});

    if (!arrHndlr.arr.isSorted())
        arrHndlr.sort(std::string{" MERGE "}, std::string{"Checking array 2..."});

    header(std::string{" MERGE "});

    cod::array<T> mix_arr = arr.merge(arrHndlr.arr);

    std::cout << "Array merged!" << std::endl
              << "Array: ";

    std::cout << mix_arr;

    press_key();
}

template <typename T>
void ArrayHandler<T>::set_opn_arr()
{

    int ch;
    bool toStop;
    ArrayHandler arrHndlr;
    cod::array<T> set_arr;

    try
    {
        arrHndlr.update_size();
        arrHndlr.add_elements();
    }
    catch (const EscPressed &e)
    {
        // do nothing
    }
    catch (const ArrayFullException &e)
    {
        e.what();
        press_key();
    }

    do
    {
        menu(setMenu, std::string{" SET "});

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1: // union
            set_arr = arr.Union(arrHndlr.arr);
            print_message(std::string{"Union!"});
            break;

        case 2: // intersection
            set_arr = arr.Intersection(arrHndlr.arr);
            print_message(std::string{"Intersection!"});
            break;

        case 3: // difference
            set_arr = arr.Difference(arrHndlr.arr);
            print_message(std::string{"Difference!"});
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop)
        {
            std::cout << std::endl
                      << "Array: " << set_arr;
            press_key();
        }

    } while (!toStop);
}

template <typename T>
void ArrayHandler<T>::sort_opn_arr()
{

    if (arr.isSorted())
        print_message(std::string{"Array already Sorted!"});
    else
    {
        this->sort();
        print_message(std::string{"Array Sorted!"});
    }

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::sort(const std::string &heading, const std::string &message)
{
    header(heading);

    wait_message(std::string{message});

    arr.sort();
}

template <typename T>
void ArrayHandler<T>::reverse_arr()
{

    int ch;
    size_t start, end;
    bool toStop;

    do
    {
        menu(reverseMenu, std::string{" REVERSE ARRAY "});

        sc.choice(ch);
        toStop = true;

        switch (ch)
        {
        case 1:
            arr.reverse(0, arr.size() - 1);
            break;

        case 2:
            header(std::string{" REVERSE ARRAY "});

            show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

            animater(std::string{"Enter the starting position: "});

            sc >> start;

            std::cout << std::endl;

            animater(std::string{"Enter the ending position: "});

            sc >> end;

            arr.reverse(start - 1, end - 1);
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop)
        {
            print_message(std::string{"Array Updated!"});

            this->pressi_display();
        }

    } while (!toStop); // stops when toStop is true
}
template <typename T>
void ArrayHandler<T>::shift_rotate_arr()
{

    int ch, n;
    bool toStop;

    do
    {
        menu(shiftRotateMenu, std::string{" SHIFT/ROTATE ARRAY "});

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1:
            header(std::string{" LEFT SHIFT "});
            show_status(std::string{"Valid shifts: 1-"}, std::to_string(arr.size()));
            animater(std::string{"Enter the number of shifts: "});
            sc >> n;
            arr.shift(LEFT, n);
            break;

        case 2:
            header(std::string{" RIGHT SHIFT "});
            show_status(std::string{"Valid shifts: 1-"}, std::to_string(arr.size()));
            animater(std::string{"Enter the number of shifts: "});
            sc >> n;
            arr.shift(RIGHT, n);
            break;

        case 3:
            header(std::string{" LEFT ROTATE "});
            show_status(std::string{"Valid rotations: 1-"}, std::to_string(arr.size()));
            animater(std::string{"Enter the number of rotations: "});
            sc >> n;
            arr.rotate(LEFT, n);
            break;

        case 4:
            header(std::string{" RIGHT ROTATE "});
            show_status(std::string{"Valid rotations: 1-"}, std::to_string(arr.size()));
            animater(std::string{"Enter the number of rotations: "});
            sc >> n;
            arr.rotate(RIGHT, n);
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop && press_i(std::string{"Press i to display array"}))
            this->display_arr();

    } while (!toStop);
}

template <typename T>
void ArrayHandler<T>::find_miss_val_arr()
{

    int ch;
    bool toStop;
    size_t start, end;
    std::vector<T> vec;

    do
    {
        menu(findValueMenu, std::string{" FIND MISSING VALUES "});

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1:
            vec = arr.find_missing(0, arr.size() - 1);
            break;

        case 2:
            header(std::string{" FIND MISSING VALUES "});

            show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

            animater(std::string{"Enter the starting position: "});

            sc >> start;

            std::cout << std::endl;

            animater(std::string{"Enter the ending position: "});

            sc >> end;

            vec = arr.find_missing(start - 1, end - 1);
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop)
        {
            if (vec.size())
            {
                print_message(std::string{"Missing Values:\n"});

                for (auto &val : vec)
                    std::cout << val << " ";
            }
            else
                print_message(std::string{"No missing value found"});

            this->pressi_display();
        }

    } while (!toStop);
}

template <typename T>
void ArrayHandler<T>::find_dup_val_arr()
{

    int ch;
    bool toStop;
    size_t start, end;
    std::vector<cod::pair<T, int>> vec;

    do
    {
        menu(findValueMenu, std::string{" FIND DUPLICATE VALUES "});

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1:
            vec = arr.find_duplicates(0, arr.size() - 1);
            break;

        case 2:
            header(std::string{" FIND DUPLICATE VALUES "});

            show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

            animater(std::string{"Enter the starting position: "});

            sc >> start;

            std::cout << std::endl;

            animater(std::string{"Enter the ending position: "});

            sc >> end;
            vec = arr.find_duplicates(start - 1, end - 1);
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop)
        {
            if (vec.size())
            {
                border(widthMenu);
                std::cout << std::setw(12) << std::left << "Occurence"
                          << "Value" << std::endl;

                for (size_t i{0}; i < vec.size(); ++i)
                    if (i < vec.size() - 1)
                        std::cout << vec.at(i) << std::endl;
                    else
                        std::cout << vec.at(i);
            }
            else
                print_message(std::string{"No duplicated value found"});

            this->pressi_display();
        }
    } while (!toStop);
}

template <typename T>
void ArrayHandler<T>::find_pair_sum_arr()
{

    int ch;
    bool toStop;
    size_t start, end;
    std::vector<cod::array<T>> vec;
    T value;

    do
    {
        menu(findValueMenu, std::string{" FIND A PAIR WITH SUM K "});

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1:
            border(widthMenu);
            animater(std::string{"Enter the sum: "});

            sc >> value;
            vec = arr.find_pair_sum(0, arr.size() - 1, value);
            break;

        case 2:
            header(std::string{" FIND A PAIR WITH SUM K "});

            show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

            animater(std::string{"Enter the starting position: "});

            sc >> start;

            std::cout << std::endl;

            animater(std::string{"Enter the ending position: "});

            sc >> end;

            border(widthMenu);
            animater(std::string{"Enter the sum: "});

            sc >> value;

            vec = arr.find_pair_sum(start - 1, end - 1, value);
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop)
        {
            if (vec.size())
            {
                print_message(std::string{"Paired Values:\n"});

                for (size_t i{0}; i < vec.size(); ++i)
                    if (i < vec.size() - 1)
                        std::cout << vec.at(i)[0] << " + " << vec.at(i)[1] << " = " << vec.at(i)[2] << std::endl;
                    else
                        std::cout << vec.at(i)[0] << " + " << vec.at(i)[1] << " = " << vec.at(i)[2];
            }
            else
                print_message(std::string{"No paired value found"});

            this->pressi_display();
        }
    } while (!toStop);
}

template <typename T>
void ArrayHandler<T>::max_min()
{
    T min_val = arr.min();
    T max_val = arr.max();

    header(std::string{" MAX & MIN VALUE "});

    std::cout << "Min Value: " << min_val << std::endl
              << "Max Value: " << max_val;

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::get_value()
{
    size_t pos;

    header(std::string{" GET VALUE "});

    show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

    animater(std::string{"Enter the position: "});

    sc >> pos;

    T val = arr[pos - 1];

    border(widthMenu);
    std::cout << "Value: " << val;

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::set_value()
{
    size_t pos;
    T set_val, get_val;

    header(std::string{" SET VALUE "});

    show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

    animater(std::string{"Enter the position: "});

    sc >> pos;

    std::cout << std::endl;

    animater(std::string{"Enter the value: "});

    sc >> set_val;

    get_val = arr[pos - 1];
    arr[pos - 1] = set_val;

    border(widthMenu);
    std::cout << "Old Value: " << get_val << std::endl
              << "New Value: " << set_val;

    this->pressi_display();
}

template <typename T>
void ArrayHandler<T>::average()
{
    int ch;
    bool toStop;
    size_t pos, n;
    double avg;

    do
    {
        menu(averageMenu, std::string{" AVERAGE "});

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1:
            avg = arr.average(0, arr.size());
            break;

        case 2:
            header(std::string{" AVERAGE "});
            show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

            animater(std::string{"Enter the starting position: "});

            sc >> pos;

            std::cout << std::endl;

            animater(std::string{"Enter the number of elements: "});

            sc >> n;

            avg = arr.average(pos - 1, n);
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop)
        {
            print_message(std::string{"Average: "});
            std::cout << std::fixed << std::setprecision(4) << avg;

            this->pressi_display();
        }

    } while (!toStop);
}

template <typename T>
void ArrayHandler<T>::sum()
{
    int ch;
    bool toStop;
    size_t pos, n;
    T sum;

    do
    {
        menu(sumMenu, std::string{" SUM "});

        toStop = true;
        sc.choice(ch);

        switch (ch)
        {
        case 1:
            sum = arr.sum(0, arr.size());
            break;

        case 2:
            header(std::string{" SUM "});
            show_status(std::string{"Valid position: 1-"}, std::to_string(arr.size()));

            animater(std::string{"Enter the starting position: "});
            sc >> pos;

            std::cout << std::endl;

            animater(std::string{"Enter the number of elements: "});

            sc >> n;

            sum = arr.sum(pos - 1, n);
            break;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            press_key();
            toStop = false;
            break;
        }

        if (toStop)
        {
            print_message(std::string{"Sum: " + std::to_string(sum)});

            this->pressi_display();
        }

    } while (!toStop);
}
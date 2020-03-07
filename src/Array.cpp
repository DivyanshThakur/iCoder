#include <iostream>
#include <iomanip>
#include <sstream>
#include <windows.h>
#include "../header/Array.hpp"
#include "../namespace/header/cod_array.hpp"
#include "../header/Scanner.hpp"
#include "../header/ExHandler.hpp"
#include "../header/UIhandler.hpp"
#include "../header/Constants.hpp"

void Arrays()
{
    int ch{0};

    do
    {
        title(); // print the title = iCoder

        menu(get_dataType_data, std::string{" SELECT DATA TYPE "});

        Scanner sc;
        sc.scanChoice(ch);

        if (ch == ESC || ch == 6)
            return;

        if (array_type_selector(ch)) // call the array funtion with user defined data type
            return;

    } while (1); // always true
}

bool array_type_selector(int ch)
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
        press_key(); // program paused - getch()
        return false;
    }
    return true;
}

/*** TEMPLATE  CLASS FUNTIONS ARE CODED BELOW ***/

template <typename T>
void ArrayHandler<T>::start()
{
    int ch{0};

    try
    {
        update_size();
    }
    catch (const EscPressed &e)
    {
        // do nothing
    }
    catch (const InvalidInputException &e)
    {
        std::cerr << e.what();
    }
    catch (const NegativeValueException &e)
    {
        std::cerr << e.what();
    }

    do
    {
        title(); // print the title = iCoder

        menu(menu_screen_selector());

        sc.scanChoice(ch);

        try
        {
            if (show_adv_opn)
                arrays_controller_adv(ch);
            else
                arrays_controller(ch);
        }
        catch (const EscPressed &e)
        {
            continue;
        }
        catch (const Esc &e)
        {
            return;
        }
        catch (const InvalidInputException &e)
        {
            std::cerr << e.what();
        }
        catch (const NegativeValueException &e)
        {
            std::cerr << e.what();
        }
        catch (const OutofBoundsException &e)
        {
            std::cerr << e.what();
        }
        catch (const ArrayFullException &e)
        {
            std::cerr << e.what();
        }
        catch (const ArrayEmptyException &e)
        {
            std::cerr << e.what();
        }
        catch (const InvalidPositionException &e)
        {
            std::cerr << e.what();
        }
        catch (...)
        {
            border(width_menu);
            std::cerr << "Unknown error occured";
        }
        if (ch == 7 && !show_adv_opn)
            show_adv_opn = true;
        else
            press_key(); // program paused - getch()

    } while (1); // true
}

/** MENU SCREEN SELECTOR TEMPLATE FUNCTIONS **/

template <typename T>
std::vector<std::string> ArrayHandler<T>::menu_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> menu_to_display;
    size_t i;

    if (arr.max_size())
        menu_to_display.push_back(array_data.at(0));
    else
        menu_to_display.push_back(array_data.at(1));

    for (i = 2; i < array_data.size() - 2; ++i)
    {
        if (!(i == 7 && show_adv_opn))
            menu_to_display.push_back(array_data.at(i));

        if (i == 7 && !show_adv_opn)
            break;
    }

    i = array_data.size() - 2;

    while (i < array_data.size())
        menu_to_display.push_back(array_data.at(i++));

    return menu_to_display;
}

template <>
std::vector<std::string> ArrayHandler<std::string>::menu_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> menu_to_display;
    size_t i;

    if (arr.max_size())
        menu_to_display.push_back(array_data.at(0));
    else
        menu_to_display.push_back(array_data.at(1));

    for (i = 2; i < array_data.size() - 2; ++i)
    {
        if (!(i == 7 && show_adv_opn))
            menu_to_display.push_back(array_data.at(i));

        if ((i == 7 && !show_adv_opn) || (i == 20 && show_adv_opn))
            break;
    }

    i = array_data.size() - 2;

    while (i < array_data.size())
        menu_to_display.push_back(array_data.at(i++));

    return menu_to_display;
}

template <>
std::vector<std::string> ArrayHandler<char>::menu_screen_selector()
{
    // select the correct menu to display as per need

    std::vector<std::string> menu_to_display;
    size_t i;

    if (arr.max_size())
        menu_to_display.push_back(array_data.at(0));
    else
        menu_to_display.push_back(array_data.at(1));

    for (i = 2; i < array_data.size() - 2; ++i)
    {
        if (!(i == 7 && show_adv_opn))
            menu_to_display.push_back(array_data.at(i));

        if ((i == 7 && !show_adv_opn) || (i == 20 && show_adv_opn))
            break;
    }

    i = array_data.size() - 2;

    while (i < array_data.size())
        menu_to_display.push_back(array_data.at(i++));

    return menu_to_display;
}

/** END OF MENU SCREEN SELECTOR TEMPLATE FUNCTIONS **/

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
        break;

    case 8:   // return to Home
    case ESC: // return
        throw Esc();

    case 9: // exit the program
        exit(0);

    default:
        print_message(std::string{"Invalid choice"});
        break;
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

    case 9:
        // merge
        merge_arr();
        break;

    case 10: // shift/Rotation
        shift_rotate_arr();
        break;

    case 11: // reverse the array
        reverse_arr();
        break;

    case 12: // set operations
        set_opn_arr();
        break;

    case 13: // sorting
        sort_opn_arr();
        break;

    case 14: // find missing elements
        find_miss_ele_arr();
        break;

    case 15: // finding duplicates
        find_dup_ele_arr();
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

    case 20:
        // average value
        average();
        break;

    case 21: // sum
        sum();
        break;

    case 22:  // return to Home
    case ESC: // return
        throw Esc();

    case 23: // exit the program
        exit(0);

    default:
        print_message(std::string{"Invalid choice"});
        break;
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

    case 10: // shift/Rotation
        shift_rotate_arr();
        break;

    case 11: // reverse the array
        reverse_arr();
        break;

    case 12: // set operations
        set_opn_arr();
        break;

    case 13: // sorting
        sort_opn_arr();
        break;

    case 14: // find missing elements
        find_miss_ele_arr();
        break;

    case 15: // finding duplicates
        find_dup_ele_arr();
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

    case 20:  // return to Home
    case ESC: // return
        throw Esc();

    case 21: // exit the program
        exit(0);

    default:
        print_message(std::string{"Invalid choice"});
        break;
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

    case 10: // shift/Rotation
        shift_rotate_arr();
        break;

    case 11: // reverse the array
        reverse_arr();
        break;

    case 12: // set operations
        set_opn_arr();
        break;

    case 13: // sorting
        sort_opn_arr();
        break;

    case 14: // find missing elements
        find_miss_ele_arr();
        break;

    case 15: // finding duplicates
        find_dup_ele_arr();
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

    case 20:  // return to Home
    case ESC: // return
        throw Esc();

    case 21: // exit the program
        exit(0);

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }
}

/** END OF ARRAYS CONTROLLER ADVANCED TEMPLATE FUNCTIONS **/

template <typename T>
void ArrayHandler<T>::update_size()
{
    int size;

    title(); // print the title = iCoder

    header(std::string{" ARRAY SIZE "});

    animater(std::string{"Enter size: "});

    sc.scan(size);
    arr.update_size(size);
}

template <typename T>
void ArrayHandler<T>::add_elements()
{
    int len;
    bool isLast;
    T value;

    if (arr.length() == arr.max_size())
        throw ArrayFullException();

    title(); // print the title = iCoder

    header(std::string{" INSERT VALUES "});

    animater(std::string{"Enter size: "});

    sc.scan(len);

    if (len < 0)
        throw NegativeValueException();

    std::cout << std::endl;

    for (int i{0}; i < len; ++i)
    {
        if (isLast && arr.length() == arr.max_size())
            throw ArrayFullException();

        if (arr.length() + 1 == arr.max_size())
            isLast = true;
        else
            isLast = (i == len - 1);

        sc.scan(value, isLast);

        arr.push_back(value);
    }
}

template <typename T>
void ArrayHandler<T>::insert_value()
{
    size_t pos;
    T value;

    title(); // print the title = iCoder

    header(std::string{" INSERT VALUE "});

    animater(std::string{"Enter the value: "});

    sc.scan(value);

    std::cout << std::endl;

    animater(std::string{"Enter the position: "});

    sc.scan(pos);

    arr.insert(value, pos);
}

template <typename T>
void ArrayHandler<T>::remove_multiple_values()
{
    size_t pos, n;
    cod::array<T> values;

    title(); // print the title = iCoder

    header(std::string{" DELETE MULTIPLE VALUES "});

    animater(std::string{"Enter the starting position: "});

    sc.scan(pos);

    std::cout << std::endl;

    animater(std::string{"Enter the number of elements: "});

    sc.scan(n);

    values = arr.remove(pos, n);

    n = values.length();

    if (!n) // if position is invalid return to menu screen
        return;

    border(width_menu);

    std::cout << n;

    (n == 1) ? std::cout << " value: " : std::cout << " values:" << std::endl;

    std::cout << values << " deleted from array";
}

template <typename T>
void ArrayHandler<T>::remove_value()
{
    size_t pos;
    T value;

    title(); // print the title = iCoder

    header(std::string{" DELETE VALUE "});

    animater(std::string{"Enter the position: "});

    sc.scan(pos);

    value = arr.remove(pos);

    std::cout << std::endl
              << value << " is deleted from the array";
}

template <typename T>
void ArrayHandler<T>::display_arr() const
{
    title(); // print the title = iCoder

    header(std::string{" DISPLAY ARRAY "});

    std::cout << "Max size: " << arr.max_size()
              << std::endl
              << "Elements stored: " << arr.length() << std::endl
              << "Array: "
              << arr;
}

template <typename T>
void ArrayHandler<T>::linear_search_arr()
{
    T val;
    size_t pos;

    title(); // print the title = iCoder

    header(std::string{" LINEAR SEARCH "});

    switch (stats)
    {
    case DEFAULT:
        std::cout << "Status: DEFAULT";
        break;

    case EASY:
        std::cout << "Status: TRANSPOSITION";
        break;

    case ADV:
        std::cout << "Status: MOVE-TO-FRONT";
        break;
    }

    border(width_menu);
    animater(std::string{"Enter the value: "});
    sc.scan(val);
    pos = arr.lsearch(val);
    if (pos)
        print_message(std::string{"Found at position "} + std::to_string(pos));
    else
        print_message(std::string{"The value doesn't exists!"});
}

template <typename T>
void ArrayHandler<T>::binary_search_arr()
{
    T val;
    size_t pos;

    if (!arr.isSorted())
    {
        title(); // print the title = iCoder

        header(std::string{" BINARY SEARCH "});

        wait_message(std::string{"Checking array..."});

        if (arr.sort())
        {
            print_message(std::string{"Array Sorted!"});
            press_key();
        }
        else
            return;
    }

    title(); // print the title = iCoder

    header(std::string{" BINARY SEARCH "});

    animater(std::string{"Enter the value: "});
    sc.scan(val);
    pos = arr.bsearch(val);
    if (pos)
        print_message(std::string{"Found at position "} + std::to_string(pos));
    else
        print_message(std::string{"The value doesn't exists!"});
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
    catch (const ArrayFullException &e)
    {
        e.what();
        press_key();
    }

    if (!arr.isSorted())
    {

        title(); // print the title = iCoder

        header(std::string{" MERGE "});

        wait_message(std::string{"Checking array 1..."});

        if (!arr.sort())
            return;
    }

    if (!arrHndlr.arr.isSorted())
    {
        title(); // print the title = iCoder

        header(std::string{" MERGE "});

        wait_message(std::string{"Checking array 2..."});

        if (!arrHndlr.arr.sort())
            return;
    }

    title(); // print the title = iCoder

    header(std::string{" MERGE "});

    cod::array<T> mix_arr = arr.merge(arrHndlr.arr);

    std::cout << "Array merged!" << std::endl
              << "Array: ";

    std::cout << mix_arr;
}

template <typename T>
void ArrayHandler<T>::shift_rotate_arr()
{

    int ch{0};
    int n;

    do
    {
        title(); // print the title = iCoder

        menu(shift_rotate_data, std::string{" SHIFT/ROTATE ARRAY "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1:
            title();
            header(std::string{" LEFT SHIFT "});
            animater(std::string{"Enter the number of shifts: "});
            sc.scan(n);
            arr.shift(LEFT, n);
            return;

        case 2:
            title();
            header(std::string{" RIGHT SHIFT "});
            animater(std::string{"Enter the number of shifts: "});
            sc.scan(n);
            arr.shift(RIGHT, n);
            return;

        case 3:
            title();
            header(std::string{" LEFT ROTATE "});
            animater(std::string{"Enter the number of rotations: "});
            sc.scan(n);
            arr.rotate(LEFT, n);
            return;

        case 4:
            title();
            header(std::string{" RIGHT ROTATE "});
            animater(std::string{"Enter the number of rotations: "});
            sc.scan(n);
            arr.rotate(RIGHT, n);
            return;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            if (press_esc())
                return;
            break;
        }

    } while (1);
}

template <typename T>
void ArrayHandler<T>::reverse_arr()
{

    int ch{0};
    size_t start, end;

    do
    {
        title(); // print the title = iCoder

        menu(reverse_data, std::string{" REVERSE ARRAY "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1:
            arr.reverse(0, arr.length() - 1);
            print_message(std::string{"Array Updated!"});
            return;

        case 2:
            border(width_menu);
            animater(std::string{"Enter the starting position: "});
            sc.scan(start);

            std::cout << std::endl;

            animater(std::string{"Enter the ending position: "});

            sc.scan(end);

            arr.reverse(start - 1, end - 1);
            print_message(std::string{"Array Updated!"});
            return;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            if (press_esc())
                return;
            break;
        }

    } while (1);
}

template <typename T>
void ArrayHandler<T>::set_opn_arr()
{

    int ch{0};
    ArrayHandler arrHndlr;
    cod::array<T> set_arr;

    try
    {
        arrHndlr.update_size();
        arrHndlr.add_elements();
    }
    catch (const ArrayFullException &e)
    {
        e.what();
        press_key();
    }

    do
    {
        title(); // print the title "iCoder"

        menu(set_data, std::string{" SET "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1: // union
            set_arr = arr.Union(arrHndlr.arr);

            print_message(std::string{"Union!"});

            std::cout << std::endl
                      << "Array: ";

            std::cout << set_arr;
            return;

        case 2: // intersection
            set_arr = arr.Intersection(arrHndlr.arr);

            print_message(std::string{"Intersection!"});

            std::cout << std::endl
                      << "Array: ";

            std::cout << set_arr;
            return;

        case 3: // difference
            set_arr = arr.Difference(arrHndlr.arr);

            print_message(std::string{"Difference!"});

            std::cout << std::endl
                      << "Array: ";

            std::cout << set_arr;
            return;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            if (press_esc())
                return;
            break;
        }

    } while (1);
}

template <typename T>
void ArrayHandler<T>::sort_opn_arr()
{
    title(); // print the title = iCoder

    header(std::string{" SORT "});

    if (arr.isSorted())
        print_message(std::string{"Array already Sorted!"});
    else
    {
        wait_message(std::string{"Checking array..."});

        arr.sort();

        print_message(std::string{"Array Sorted!"});
    }
}

template <typename T>
void ArrayHandler<T>::find_miss_ele_arr()
{
    print_message();
}

template <typename T>
void ArrayHandler<T>::find_dup_ele_arr()
{
    print_message();
}

template <typename T>
void ArrayHandler<T>::find_pair_sum_arr()
{
    print_message();
}

template <typename T>
void ArrayHandler<T>::max_min()
{
    T min_val = arr.min();
    T max_val = arr.max();

    title(); // print the title "iCoder"

    header(std::string{" MAX & MIN VALUE "});

    std::cout << "Min Value: " << min_val << std::endl
              << "Max Value: " << max_val;
}

template <typename T>
void ArrayHandler<T>::get_value()
{
    size_t pos;

    title(); // print the title "iCoder"

    header(std::string{" GET VALUE "});

    animater(std::string{"Enter the position: "});
    sc.scan(pos);

    T val = arr[pos - 1];

    border(width_menu);
    std::cout << "Value: " << val;
}

template <typename T>
void ArrayHandler<T>::set_value()
{
    size_t pos;
    T set_val, get_val;

    title(); // print the title "iCoder"

    header(std::string{" SET VALUE "});

    animater(std::string{"Enter the position: "});
    sc.scan(pos);

    std::cout << std::endl;

    animater(std::string{"Enter the value: "});
    sc.scan(set_val);

    get_val = arr[pos - 1];
    arr[pos - 1] = set_val;

    border(width_menu);
    std::cout << "Old Value: " << get_val << std::endl
              << "New Value: " << set_val;
}

template <typename T>
void ArrayHandler<T>::average()
{
    int ch{0};
    size_t pos, n;
    double avg;

    do
    {
        title(); // print the title "iCoder"

        menu(average_data, std::string{" AVERAGE "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1:
            avg = arr.average(0, arr.length());
            print_message(std::string{"Average: "});
            std::cout << std::fixed << std::setprecision(4) << avg;
            return;

        case 2:
            border(width_menu);
            animater(std::string{"Enter the starting position: "});
            sc.scan(pos);

            std::cout << std::endl;

            animater(std::string{"Enter the number of elements: "});

            sc.scan(n);

            avg = arr.average(pos - 1, n);
            print_message(std::string{"Average: "});
            std::cout << std::fixed << std::setprecision(4) << avg;
            return;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            if (press_esc())
                return;
            break;
        }

    } while (1);
}

template <typename T>
void ArrayHandler<T>::sum()
{
    int ch{0};
    size_t pos, n;
    T sum;

    do
    {
        title(); // print the title "iCoder"

        menu(sum_data, std::string{" SUM "});

        sc.scanChoice(ch);

        switch (ch)
        {
        case 1:
            sum = arr.sum(0, arr.length());
            print_message(std::string{"Sum: " + std::to_string(sum)});
            return;

        case 2:
            border(width_menu);
            animater(std::string{"Enter the starting position: "});
            sc.scan(pos);

            std::cout << std::endl;

            animater(std::string{"Enter the number of elements: "});

            sc.scan(n);

            sum = arr.sum(pos - 1, n);
            print_message(std::string{"Sum: " + std::to_string(sum)});
            return;

        case ESC:
            throw EscPressed();

        default:
            print_message(std::string{"Invalid choice"});
            if (press_esc())
                return;
            break;
        }

    } while (1);
}
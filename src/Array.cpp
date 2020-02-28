#include <iostream>
#include <iomanip>
#include <sstream>
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

        if ((i == 7 && !show_adv_opn) || (i == 19 && show_adv_opn))
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

        if ((i == 7 && !show_adv_opn) || (i == 19 && show_adv_opn))
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
        print_message();
        break;

    case 8: // binary search
        print_message();
        break;

    case 9:
        // merge
        print_message();
        break;

    case 10: // shift/Rotation
        print_message();
        break;

    case 11: // reverse the array
        break;

    case 12: // set operations
        break;

    case 13: // find missing elements
        print_message();
        break;

    case 14: // finding duplicates
        print_message();
        break;

    case 15: // find a pair with sum K
        print_message();
        break;

    case 16: // min and max value
        print_message();
        break;

    case 17: // get value
        get_value();
        break;

    case 18: // set value
        set_value();
        break;

    case 19:
        // average value
        average();
        break;

    case 20: // sum
        sum();
        break;

    case 21:  // return to Home
    case ESC: // return
        throw Esc();

    case 22: // exit the program
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
        print_message();
        break;

    case 8: // binary search
        print_message();
        break;

    case 9: // merge
        print_message();
        break;

    case 10: // shift/Rotation
        print_message();
        break;

    case 11: // reverse the array
        print_message();
        break;

    case 12: // set operations
        print_message();
        break;

    case 13: // find missing elements
        print_message();
        break;

    case 14: // finding duplicates
        print_message();
        break;

    case 15: // find a pair with sum K
        print_message();
        break;

    case 16: // min and max value
        print_message();
        break;

    case 17: // get value
        get_value();
        break;

    case 18: // set value
        set_value();
        break;

    case 19:  // return to Home
    case ESC: // return
        throw Esc();

    case 20: // exit the program
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
        print_message();
        break;

    case 8: // binary search
        print_message();
        break;

    case 9: // merge
        print_message();
        break;

    case 10: // shift/Rotation
        print_message();
        break;

    case 11: // reverse the array
        print_message();
        break;

    case 12: // set operations
        print_message();
        break;

    case 13: // find missing elements
        print_message();
        break;

    case 14: // finding duplicates
        print_message();
        break;

    case 15: // find a pair with sum K
        print_message();
        break;

    case 16: // min and max value
        print_message();
        break;

    case 17: // get value
        get_value();
        break;

    case 18: // set value
        set_value();
        break;

    case 19:  // return to Home
    case ESC: // return
        throw Esc();

    case 20: // exit the program
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

    title(); // print the title = iCoder

    header(std::string{" INSERT VALUES "});

    animater(std::string{"Enter size: "});

    sc.scan(len);

    if (len < 0)
        throw NegativeValueException();

    std::cout << std::endl;

    for (int i{0}; i < len; ++i)
    {

        if (arr.length() + 1 == arr.max_size())
            isLast = true;
        else
            isLast = (i == len - 1);

        sc.scan(value, isLast);

        arr.push_back(value);

        if (arr.length() == arr.max_size())
            throw ArrayFullException();
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

    for (size_t i{0}; i < n; ++i)
    {
        if (i < n - 1)
            std::cout << values[i] << ", ";
        else
            std::cout << values[i] << " deleted from array";
    }
}

template <typename T>
void ArrayHandler<T>::display_arr() const
{
    title(); // print the title = iCoder

    header(std::string{" DISPLAY ARRAY "});

    std::cout << arr;
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
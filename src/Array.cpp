#include <iostream>
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
            {
                arrays_controller(ch);

                if (ch == 8 || ch == 9)
                    ch += 11;
            }

            if (ch == ESC || ch == 19)
                return;

            if (ch == 20)
                exit(0);
        }
        catch (const EscPressed &e)
        {
            continue;
        }
        catch (const InvalidInputException &e)
        {
            std::cerr << e.what();
        }
        catch (const NegativeValueException &e)
        {
            std::cerr << e.what();
        }
        catch (const ArrayFullException &e)
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
            std::cerr << "Unknown error occured" << std::endl;
        }
        if (ch == 7 && !show_adv_opn)
            show_adv_opn = true;
        else
            press_key(); // program paused - getch()

    } while (1); // true
}

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

    case 7:   // make show_adb_opn = true at end of while loop
    case 8:   // return to Home
    case 9:   // exit the program
    case ESC: // return
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }
}

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

    case 7:
        print_message();
        break;

    case 8:
        print_message();
        break;

    case 9:
        print_message();
        break;

    case 10:
        print_message();
        break;

    case 11:
        print_message();
        break;

    case 12:
        print_message();
        break;

    case 13:
        print_message();
        break;

    case 14:
        print_message();
        break;

    case 15:
        print_message();
        break;

    case 16:
        print_message();
        break;

    case 17:
        print_message();
        break;

    case 18:
        print_message();
        break;

    case 19:  // return to Homw
    case ESC: // return
    case 20:  // exit the program
        break;

    default:
        print_message(std::string{"Invalid choice"});
        break;
    }
}

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
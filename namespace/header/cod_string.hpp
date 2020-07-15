#ifndef COD_STRING_HPP
#define COD_STRING_HPP

#include <iostream>
#include "cod_scan.hpp"
#include "../../header/FileHandler.hpp" // including both ISaveable & FileHandler

namespace cod
{
    class string : public ISaveable
    {
    public:
        /************************************ ISAVEABLE PURE VIRTUAL FUNCTION ****************************************/

        virtual std::vector<std::pair<std::string, std::string>> save() const override;
        virtual void load(const std::vector<std::pair<std::string, std::string>> &vec) override;
        virtual std::string getPath() const override;

    private:
        /************************************* NON MEMBER FUNCTION OVERLOADS ****************************************/

        friend void swap(string &lhs, string &rhs)
        {
            lhs.swap(rhs); // calls the swap member function
        }

        friend std::ostream &operator<<(std::ostream &os, const string &obj)
        {
            if (obj.size())
                for (size_t i{0}; i < obj._size; i++)
                {
                    os << obj.at(i); // display string to console
                }
            else
                os << "String is empty!";

            return os;
        }

        friend cod::scan &operator>>(cod::scan &sc, string &obj)
        {
            char *buff = new char[1'02'400]; // 100 MB

            sc >> buff; // scan string

            string s = buff;
            obj = s;

            delete[] buff;
            return sc;
        }

        friend cod::scan &getline(cod::scan &sc, cod::string &s);

        friend string operator+(const string &lhs, const string &rhs) //  string
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }
        friend string operator+(string &&lhs, string &&rhs)
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }

        friend string operator+(string &&lhs, const string &rhs)
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }

        friend string operator+(const string &lhs, string &&rhs)
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }

        friend string operator+(const string &lhs, const char *rhs) // c-string
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }
        friend string operator+(string &&lhs, const char *rhs)
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }

        friend string operator+(const char *lhs, const string &rhs)
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }

        friend string operator+(const char *lhs, string &&rhs)
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }
        friend string operator+(const string &lhs, char rhs) // character
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }
        friend string operator+(string &&lhs, char rhs)
        {
            string temp(lhs);
            temp += rhs;
            return temp;
        }

        friend string operator+(char lhs, const string &rhs)
        {
            string temp(1, lhs);
            temp += rhs;
            return temp;
        }

        friend string operator+(char lhs, string &&rhs)
        {
            string temp(1, lhs);
            temp += rhs;
            return temp;
        }

        friend bool operator==(const string &lhs, const string &rhs)
        {
            return (lhs.compare(rhs) == 0);
        }

        friend bool operator==(const char *lhs, const string &rhs)
        {
            return (rhs.compare(lhs) == 0);
        }

        friend bool operator==(const string &lhs, const char *rhs)
        {
            return (lhs.compare(rhs) == 0);
        }

        friend bool operator!=(const string &lhs, const string &rhs)
        {
            return (lhs.compare(rhs) != 0);
        }

        friend bool operator!=(const char *lhs, const string &rhs)
        {
            return (rhs.compare(lhs) != 0);
        }

        friend bool operator!=(const string &lhs, const char *rhs)
        {
            return (lhs.compare(rhs) != 0);
        }

        friend bool operator<(const string &lhs, const string &rhs)
        {
            return (lhs.compare(rhs) < 0);
        }

        friend bool operator<(const char *lhs, const string &rhs)
        {
            return (rhs.compare(lhs) > 0);
        }

        friend bool operator<(const string &lhs, const char *rhs)
        {
            return (lhs.compare(rhs) < 0);
        }

        friend bool operator<=(const string &lhs, const string &rhs)
        {
            return (lhs.compare(rhs) <= 0);
        }

        friend bool operator<=(const char *lhs, const string &rhs)
        {
            return (rhs.compare(lhs) >= 0);
        }

        friend bool operator<=(const string &lhs, const char *rhs)
        {
            return (lhs.compare(rhs) <= 0);
        }

        friend bool operator>(const string &lhs, const string &rhs)
        {
            return (lhs.compare(rhs) > 0);
        }

        friend bool operator>(const char *lhs, const string &rhs)
        {

            return (rhs.compare(lhs) < 0);
        }

        friend bool operator>(const string &lhs, const char *rhs)
        {
            return (lhs.compare(rhs) > 0);
        }

        friend bool operator>=(const string &lhs, const string &rhs)
        {
            return (lhs.compare(rhs) >= 0);
        }

        friend bool operator>=(const char *lhs, const string &rhs)
        {
            return (rhs.compare(lhs) <= 0);
        }

        friend bool operator>=(const string &lhs, const char *rhs)
        {
            return (lhs.compare(rhs) >= 0);
        }

        void capacity_selecter();
        void capacity_updater(size_t n);
        void validate(size_t pos, bool cmpSize = false) const;
        void update_word_vowel_consonant();
        void perm(string &str, size_t l, size_t h);
        void cat(const char *rhs, size_t len = npos);
        void cpy(const char *rhs, size_t len = npos);

        char *str;
        long long index;
        std::string _name;
        size_t _size, _capacity, _maxSize, _words, _vowels, _consonants;

    public:
        static constexpr size_t npos = -1;

        /*************************************************** CONSTRUCTOR *********************************************/
        string();                                                 // no-args
        string(const char *s);                                    // from c-string
        string(const char *s, size_t n);                          // from buffer
        string(size_t n, char c);                                 // fill
        string(const string &rhs);                                // copy
        string(string &&rhs);                                     // move
        string(const std::initializer_list<char> &list);          // initializer list
        string(const string &rhs, size_t pos, size_t len = npos); // substring
        // string(const iterator &first, const iterator &last);   // range

        /************************************************ ASSIGNMENT OPERATOR ****************************************/
        string &operator=(const string &rhs);                       // copy
        string &operator=(string &&rhs);                            // move
        string &operator=(const char *s);                           // c-string
        string &operator=(char c);                                  // character
        string &operator=(const std::initializer_list<char> &list); // initializer list

        /************************************************** STRING ITERATOR ******************************************/
        // iterator begin() const;
        // iterator end() const;
        // const const_iterator cbegin() const;
        // const const_iterator cend() const;

        /****************************************************** CAPACITY *********************************************/
        size_t size(size_t pos = 0, size_t len = npos) const;
        size_t length() const;
        size_t max_size() const;
        std::string name() const;
        size_t words();
        size_t vowels();
        size_t consonants();
        void resize(size_t n, char c = '\0');
        size_t capacity() const;
        void reserve(size_t n = 0);
        void clear();
        bool empty() const;
        void shrink_to_fit();

        /**************************************************** ELEMENT ACCESS *****************************************/
        char &operator[](size_t pos);
        const char &operator[](size_t pos) const;
        char &at(size_t pos);
        const char &at(size_t pos) const;
        char &back();
        const char &back() const;
        char &front();
        const char &front() const;

        /******************************************************* MODIFIERS *******************************************/
        string &operator+=(const string &rhs);                       // string
        string &operator+=(const char *s);                           // c-string
        string &operator+=(char c);                                  // character
        string &operator+=(const std::initializer_list<char> &list); // initilizer list

        string &append(const string &rhs);                                // string
        string &append(const string &rhs, size_t pos, size_t len = npos); // substring
        string &append(const char *s);                                    // c-string
        string &append(const char *s, size_t n);                          // buffer
        string &append(size_t n, char c);                                 // fill
        string &append(const std::initializer_list<char> &list);          // initializer list
        // string &append(const iterator &first, const iterator &last); // range

        void push_back(char c);

        string &assign(const string &rhs);                                // string
        string &assign(const string &rhs, size_t pos, size_t len = npos); // substring
        string &assign(string &&rhs);                                     // move
        string &assign(const char *s);                                    // c-string
        string &assign(const char *s, size_t n);                          // buffer
        string &assign(size_t n, char c);                                 // fill
        string &assign(const std::initializer_list<char> &list);          // initializer list
        // string &assign(const iterator &first, const iterator &last); // range

        string &insert(size_t pos, const string &rhs);                                      // string
        string &insert(size_t pos, const string &rhs, size_t subpos, size_t sublen = npos); // substring
        string &insert(size_t pos, const char *s);                                          // c-string
        string &insert(size_t pos, const char *s, size_t n);                                // buffer
        string &insert(size_t pos, size_t n, char c);                                       // fill
        // iterator insert(const_iterator p, size_t n, char c); // fill iterator
        // iterator insert(const_iterator p, char c);// single character
        // iterator insert(iterator p, InputIterator first, InputIterator last); // range
        // string &insert(const_iterator p, initializer_list<char> il);// initializer list

        string erase(size_t pos = 0, size_t len = npos); // sequence
        // iterator erase(const_iterator p);                          // character
        // iterator erase(const_iterator first, const_iterator last); // range

        string &replace(size_t pos, size_t len, const string &rhs); // string
        // string &replace(const_iterator i1, const_iterator i2, const string &rhs);
        string &replace(size_t pos, size_t len, const string &rhs, size_t subpos, size_t sublen = npos); // substring
        string &replace(size_t pos, size_t len, const char *s);                                          // c-string
        // string& replace (const_iterator i1, const_iterator i2, const char* s);
        string &replace(size_t pos, size_t len, const char *s, size_t n); // buffer
        // string& replace (const_iterator i1, const_iterator i2, const char* s, size_t n);
        string &replace(size_t pos, size_t len, size_t n, char c); // fill
        // string& replace (const_iterator i1, const_iterator i2, size_t n, char c);
        // string &replace(const_iterator i1, const_iterator i2, InputIterator first, InputIterator last); // range
        // string &replace(const_iterator i1, const_iterator i2, std::initializer_list<char> list); // initializer list

        void pop_back();

        /************************************************** ADVANCED OPERATIONS *************************************/

        void swap(string &rhs); // swap string
        void reverse(size_t pos = 0, size_t len = npos) const;
        bool ispalindrome(size_t pos = 0, size_t len = npos) const;
        bool isanagram(size_t pos, size_t len, const string &rhs, size_t subpos = 0, size_t sublen = npos) const;
        void permutation(size_t pos = 0, size_t len = npos);
        std::vector<std::pair<int, char>> find_duplicates(size_t pos = 0, size_t len = npos);
        std::vector<char> find_unique(size_t pos = 0, size_t len = npos);

        /*************************************************** STRING OPERATIONS **************************************/
        const char *c_str() const;
        const char *data() const;
        size_t copy(char *s, size_t len, size_t pos = 0) const;

        size_t find(const string &rhs, size_t pos = 0) const;   // string
        size_t find(const char *s, size_t pos = 0) const;       // c-string
        size_t find(const char *s, size_t pos, size_t n) const; // buffer
        size_t find(char c, size_t pos = 0) const;              // character

        size_t rfind(const string &rhs, size_t pos = npos) const; // string
        size_t rfind(const char *s, size_t pos = npos) const;     // c-string
        size_t rfind(const char *s, size_t pos, size_t n) const;  // buffer
        size_t rfind(char c, size_t pos = npos) const;            // character

        size_t find_first_of(const string &rhs, size_t pos = 0) const;   // string
        size_t find_first_of(const char *s, size_t pos = 0) const;       // c-string
        size_t find_first_of(const char *s, size_t pos, size_t n) const; // buffer
        size_t find_first_of(char c, size_t pos = 0) const;              // character

        size_t find_last_of(const string &rhs, size_t pos = npos) const; // string
        size_t find_last_of(const char *s, size_t pos = npos) const;     // c-string
        size_t find_last_of(const char *s, size_t pos, size_t n) const;  // buffer
        size_t find_last_of(char c, size_t pos = npos) const;            // character

        size_t find_first_not_of(const string &rhs, size_t pos = 0) const;   // string
        size_t find_first_not_of(const char *s, size_t pos = 0) const;       // c-string
        size_t find_first_not_of(const char *s, size_t pos, size_t n) const; // buffer
        size_t find_first_not_of(char c, size_t pos = 0) const;              // character

        size_t find_last_not_of(const string &rhs, size_t pos = npos) const; // string
        size_t find_last_not_of(const char *s, size_t pos = npos) const;     // c-string
        size_t find_last_not_of(const char *s, size_t pos, size_t n) const;  // buffer
        size_t find_last_not_of(char c, size_t pos = npos) const;            // character

        string substr(size_t pos = 0, size_t len = npos) const;

        int compare(const string &rhs) const;                         // string
        int compare(size_t pos, size_t len, const string &rhs) const; // substrings
        int compare(size_t pos, size_t len, const string &rhs, size_t subpos, size_t sublen = npos) const;
        int compare(const char *s) const; // c-string
        int compare(size_t pos, size_t len, const char *s) const;
        int compare(size_t pos, size_t len, const char *s, size_t n) const; // buffer

        virtual ~string();
    };

    cod::scan &getline(cod::scan &sc, cod::string &s);

} // namespace cod

#endif
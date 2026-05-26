#include <string>
#include <iostream>

#include "PhoneBook.hpp"
#include "utils.hpp"

int main()
{
    std::string input;
    PhoneBook   phonebook;

    while (!std::cin.eof())
    {
        std::cout << "Enter ADD to save a new contact, SEARCH to display a contact or EXIT to quit the program." << std::endl;
        std::cout << "phonebook> ";
        std::cin >> input;
        clearFailedExtraction();
        std::cout << std::endl;
        if (input == "ADD")
            phonebook.AddContact();
        else if (input == "SEARCH")
            phonebook.PrintPhoneBook();
        else if (input == "EXIT")
            return (0);
        else
        {
        }
    }
    return (0);
}

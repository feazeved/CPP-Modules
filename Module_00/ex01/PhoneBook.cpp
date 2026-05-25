#include <string>
#include <iostream>
#include <iomanip>
#include <sstream>

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include "utils.hpp"

PhoneBook::PhoneBook()
    : count(0)
{
}

std::string PhoneBook::PromptField(const std::string& field_name)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter " << field_name << ": ";
        std::cin >> input;

        if (!clearFailedExtraction())
            return (input);
    }
}

void  PhoneBook::AddContact()
{
    int index = count % 8;

    contacts[index].SetFirstName(PromptField("the first name"));
    contacts[index].SetLastName(PromptField("the last name"));
    contacts[index].SetNick(PromptField("a nickname"));
    contacts[index].SetNumber(PromptField("a number"));
    contacts[index].SetSecret(PromptField("the darkest secret"));
    std::cout << std::endl;

    count++;
}

void  PhoneBook::PrintPhoneBook()
{
    int to_display;

    if (count <= 8)
        to_display = count;
    else
        to_display = 8;

    if (to_display == 0)
    {
       std::cout << "The phone book is empty! Try adding a contact first with ADD" << std::endl;
       return ;
    }

    std::cout << "---------------------------------------------\n";
    std::cout << "|     index|first name| last name|  nickname|\n";
    std::cout << "---------------------------------------------\n";
    for (int i = 0; i < to_display; i++)
    {
        std::cout << "|" << std::right << std::setw(10) << i << "|";
        std::cout << std::right << std::setw(10) << TruncateString(contacts[i].GetFirstName(), 10) << "|";
        std::cout << std::right << std::setw(10) << TruncateString(contacts[i].GetLastName(), 10) << "|";
        std::cout << std::right << std::setw(10) << TruncateString(contacts[i].GetNick(), 10) << "|\n";
    }
    std::cout << "---------------------------------------------\n\n";

    std::cout << "Please enter an index to display contact info" << std::endl;
    std::cout << "phonebook> ";

    std::string index_input;
    std::cin >> index_input;
    clearFailedExtraction();

    if (index_input[0] == '+')
        index_input.erase(0);
    if (index_input[0] == '-')
    {
        std::cerr << "Index out of range. Please enter a number between 0 and "
                  << (to_display - 1) << "\n" << std::endl;
        return ;
    }


    if (!isdigit(index_input[0]) || index_input.size() != 1)
    {
        std::cerr << "Invalid input: not a valid number\n" << std::endl;
        return ;
    }

    std::istringstream  my_stream(index_input);
    int                 index_int;

    my_stream >> index_int;

    if (index_int >= to_display)
    {
        std::cerr << "Index out of range. Please enter a number between 0 and "
                  << (to_display - 1) << "\n" << std::endl;
        return ;
    }
    contacts[index_int].PrintContact();

}


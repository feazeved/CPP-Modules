#include <string>
#include <iostream>

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

//void  PhoneBook::PrintContact()
//{
//
//}

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
    //TODO Display in table form
    
}

#include "PhoneBook.hpp"
#include "Contact.hpp"
#include <string>
#include <iostream>

PhoneBook::PhoneBook()
    : count(0)
{
}

static bool is_blank(const std::string& str)
{
    for (size_t i = 0; i < str.size(); i++)
    {
        if (!std::isspace(str[i]))
            return (false);
    }
    return (true);
}

std::string PhoneBook::PromptField(const std::string& field_name)
{
    std::string input;

    while (1)
    {
        std::cout << "Enter " << field_name << ": ";
        if (!std::getline(std::cin, input))
        {
            std::cerr << "\nNo input available. Exiting.\n";
            return (std::string());
        }
        if (!is_blank(input))
            return (input);
        std::cout << "Type a non-empty field.\n";
    }
}

void  PhoneBook::AddContact()
{
    int index = count % 8;

    contacts[index].first_name = PromptField("first name");
    contacts[index].last_name = PromptField("last name");
    contacts[index].nickname = PromptField("nickname");
    contacts[index].number = PromptField("number");

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

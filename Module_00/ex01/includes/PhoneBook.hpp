#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

#include "Contact.hpp"
#include <string>

class PhoneBook
{
    public:
        PhoneBook();
        void  AddContact();
        void  PrintPhoneBook();

    private:
        Contact contacts[8];
        int count;

        std::string PromptField(const std::string& field_name);
};

#endif

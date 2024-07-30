#ifndef USER_INPUT_H
#define USER_INPUT_H
#include <string>
#include <iostream>
#include <limits>
#include <sstream>
#include <unordered_set>
#define PASSWORD_MSG "Enter your password"
#define VALID_CHARACTERS "~`!@#$%^&*()-_+={}[]|\\;:\"<>,./?abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
#define SPECIAL_CHARACTERS "~`!@#$%^&*()-_+={}[]|\\;:\"<>,./?"
#define LOWERCASE_CHARACTERS "abcdefghijklmnopqrstuvwxyz"
#define UPPERCASE_CHARACTERS "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define NUMBERS_CHARACTERS "1234567890"

unsigned char isCinValid();
std::string getUserInput(std::string printed_msg, unsigned char check_input);

/*
Reads user input and returns it.
*/
std::string getUserInput(std::string printed_msg, unsigned char check_input)
{
    int run = 1;
    std::string password;

    while (run)
    {
        std::ostringstream print_buffer;

        std::cout << printed_msg << "\n"
                  << std::flush; // Print the wanted message.
        std::cin >> password;    // Get user's input.

        if (!isCinValid())
            continue;

        if (!check_input) // Check if input validation is on.
        {
            run = 0;
            continue;
        }

        int yes_no_run = 1;
        std::string yes_no_buffer;

        while (yes_no_run) // Validate input with the user.
        {
            // TODO: line repeats twice if invalid option is given.
            print_buffer << "You put " << password << "\nIs that correct? (Enter Y/N)\n";
            std::cout << print_buffer.str(); // Print the question.
            std::cin >> yes_no_buffer;
            std::cin.clear();
            if (std::cin.fail())
            {
                std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
                std::cin.clear();
                std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
                continue;
            }

            if (!yes_no_buffer.compare("Y")) // Check if password is correct.
            {
                run = 0;
                yes_no_run = 0;
            }
            else if (!yes_no_buffer.compare("N")) // Check if password is incorrect.
            {
                yes_no_run = 0;
            }
            else
            {
                std::cout << "Invalid option, try again." << std::endl;
                continue;
            }
        }
    }
    return password;
}
unsigned char isCinValid()
{
    if (!std::cin.fail())
        return 1;

    std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return 0;
}

std::string getUserInputPassword()
{
    return getUserInput(PASSWORD_MSG, 1);
}

class InputValidator
{
private:
    std::unordered_set<char> all_set;
    std::unordered_set<char> special_set;
    std::unordered_set<char> lower_set;
    std::unordered_set<char> upper_set;
    std::unordered_set<char> number_set;

public:
    InputValidator() // Constructor
    {
        std::string valid_chars = VALID_CHARACTERS;
        for (int i = 0; i < valid_chars.size(); i++)
        {
            this->all_set.insert(valid_chars[i]);
        }

        valid_chars = SPECIAL_CHARACTERS;
        for (int i = 0; i < valid_chars.size(); i++)
        {
            this->special_set.insert(valid_chars[i]);
        }

        valid_chars = LOWERCASE_CHARACTERS;
        for (int i = 0; i < valid_chars.size(); i++)
        {
            this->lower_set.insert(valid_chars[i]);
        }

        valid_chars = UPPERCASE_CHARACTERS;
        for (int i = 0; i < valid_chars.size(); i++)
        {
            this->upper_set.insert(valid_chars[i]);
        }

        valid_chars = NUMBERS_CHARACTERS;
        for (int i = 0; i < valid_chars.size(); i++)
        {
            this->number_set.insert(valid_chars[i]);
        }
    }
    unsigned char validateInput(std::string input)
    {
        for (int i = 0; i < input.size(); i++)
        {
            if (this->all_set.find(input[i]) != this->all_set.end()) // Check if set contains the current character.
                continue;
            std::cout << "Non-permitted character detected, please retry." << "\n";
            return 0; // Invalid.
        }
        return 1; // Valid.
    }
    unsigned char validatePassword(std::string password)
    {
        return 1;
    }
};

#endif
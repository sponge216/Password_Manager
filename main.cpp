#include <iostream>
#include "headers/userInputHeader.hpp"
#define CHOICES_SIZE 3

int generalMenu(std::string choices[], int choices_size, std::string intro);
std::string getPrimePassword();

int main(int argc, char *argv[])
{
    std::string password = getPrimePassword(); // Confirm user's prime password;

    std::string choices[CHOICES_SIZE] = {"Add password", "Edit password", "Remove password"};
    int choice = generalMenu(choices, CHOICES_SIZE, "Enter one of the following choices' index");
    return 0;
}

int generalMenu(std::string choices[], int choices_size, std::string intro)
{
    if (intro != "")
        std::cout << intro << "\n";

    int choice = -1;
    do
    {
        for (int i = 0; i < choices_size; i++)
        {
            std::cout << choices[i] << " - " << i + 1 << "\n";
        }
        std::cout << "Enter your choice's number here: ";
        std::cin >> choice;
        std::cout << "\n";
    } while (choice < 0 || choice > choices_size);

    return choice;
}

std::string getPrimePassword()
{
    std::string password;
    InputValidator *input_validator = new InputValidator();
    do
    {
        password = getUserInputPassword();
    } while (!input_validator->validateInput(password));
    std::cout << "Password confirmed as: " << password << "\n";
    return password;
}
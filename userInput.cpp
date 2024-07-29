#include <iostream>
#include <limits>
#include <sstream>;

std::string getUserInput(std::string printed_msg)
{
    int run = 1;
    std::string password;

    while (run)
    {
        std::ostringstream print_buffer;
        std::string yes_no_buffer;

        std::cout << printed_msg << std::flush; // Print the wanted message.
        std::cin >> password;                   // Get user's input.

        if (std::cin.fail())
        {
            // TODO: go over this block of code and learn all that's used in it.
            std::cerr << "Sorry, I cannot read that. Please try again." << std::endl;
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
            continue;
        }

        int yes_no_run = 1;
        while (yes_no_run) // Validate input with the user.
        {
            print_buffer << "You put " << password << "\nIs that correct? (Enter Y/N)";
            std::cout << print_buffer.str(); // Print the question.
            std::cin >> yes_no_buffer;
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
            }
            else if (!yes_no_buffer.compare("N")) // Check if password is incorrect.
            {
                yes_no_run = 0;
            }
        }
        return password;
    }
}
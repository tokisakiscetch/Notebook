#include <iostream>
#include <string>
#include <fstream>
#include <cctype>

int main()
{
    std::ofstream file("sketchbook.txt");

    if (!file.is_open())
    {
        std::cerr << "Error opening file.";
        return 1;
    }

    char choice = 'y';
    while (choice == 'y')
    {
        std::cout << "Ready to enter text? y/n(any other answer will be accepted as n) -> ";
        std::cin >> choice;
        std::cin.ignore();

        if (std::tolower(choice) == 'y')
        {
            std::string text;
            std::cout << "Enter any text -> ";
            std::getline(std::cin, text);
            file << text << std::endl;
        }
        else
        {
            std::cout << "The code is ending...";
            file.close();
            return 0;
        }
    }

    file.close();
    return 0;
}
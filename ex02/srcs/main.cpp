#include "../includes/PmergeMe.hpp"

int main(int argc, char **argv)
{
    if (argc < 2)
    {
        std::cout << "Error: wrong number of arguments" << std::endl;
        return (1);
    }
    std::string input = argv[1];
    for (int i = 2; i < argc; i++)
        input += " " + std::string(argv[i]);
    readInput(input);
    return (0);
}
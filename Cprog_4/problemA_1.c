#include <stdio.h>
#include <math.h>
#include <string.h>

int main()
{
 std::cout << "Enter a sequence of characters (press Enter to finish):" << std::endl;

    // Read characters until the Enter key is pressed
    std::string userInput;
    std::getline(std::cin, userInput);

    // Display the entered sequence
    std::cout << "Entered sequence: " << userInput << std::endl;

    return 0;
}

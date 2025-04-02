#include "functions.hpp"

float add(float x, float y)
{
    return x + y;
}

float subtract(float x, float y)
{
    return x - y;
}

float divide(float x, float y)
{
    return x / y;
}

float multiply(float x, float y)
{
    return x * y;
}

float power(float x, float y)
{
    return pow(x,y);
}

void readCommand(std::string command)
{

    std::string firstNum = "";
    std::string secondNum = "";
    char symbol = 'a';

    int length = command.length();

    bool firstNumFound = false;

    for(int i = 0; i < length; i++)
    {
        ///Look for a bad starting character
        if((i < 1) && (command[i] < 48 || command[i] > 57))
        {
            std::cout << "\n";
            std::cout << "Error incorrect formatting! First character should be a number" << std::endl;
            break;
        }

        ///Figure out which operator to use
        if((command[i] == '+' || command[i] == '-' || command[i] == '*' || command[i] == '/' || command[i] == 'p') && (symbol == 'a') && (!firstNumFound))
        {
            symbol = command[i];
            firstNumFound = true;
        }
        else if(firstNumFound == true && (command[i] == '+' || command[i] == '-' || command[i] == '*' || command[i] == '/' || command[i] == 'p'))
        {
            std::cout << "\n";
            std::cout << "Error incorrect formatting! You used a character not allowed in the program" << std::endl;
            break;
        }

        ///Look for firstnumber,secondnumber
        if(((command[i] >= 48 && command[i] <= 57) || (command[i] == '.')) && firstNumFound == false)
        {
            firstNum += command[i];
        }
        else if(((command[i] >= 48 && command[i] <= 57) || (command[i] == '.')) && firstNumFound == true)
        {
            secondNum += command[i];
        }
    }

    switch(symbol)
    {
        case '+':
            std::cout << "Adding " << firstNum << " and " << secondNum << " gives you " << add(stof(firstNum),stof(secondNum)) << std::endl;
            break;

        case '-':
            std::cout << "Subtracting " << firstNum << " from " << secondNum << " gives you " << subtract(stof(firstNum), stof(secondNum)) << std::endl;
            break;

        case '*':
            std::cout << "Multiplying " << firstNum << " by " << secondNum << " gives you " << multiply(stof(firstNum),stof(secondNum)) << std::endl;
            break;

        case '/':
            std::cout << "Dividing " << firstNum << " by " << secondNum << " gives you " << divide(stof(firstNum), stof(secondNum)) << std::endl;
            break;

        case 'p':
            std::cout << firstNum << " to the power of " << secondNum << " is " << power(stof(firstNum),stof(secondNum)) << std::endl;
            break;

        default:
            std::cout << "Error!" << std::endl;
            break;
    }
}
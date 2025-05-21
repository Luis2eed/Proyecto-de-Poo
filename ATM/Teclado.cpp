// Teclado.cpp
#include <iostream>
#include <string>
#include <conio.h>  // Solo para _getch() en Windows
#include "Teclado.h"
using namespace std;

int Teclado::obtenerEntrada() const 
{
    int entrada;
    std::cin >> entrada;
    return entrada;
}

int Teclado::obtenerNIPEnmascarado() const 
{
    std::string input;
    char ch;

    std::cout << "Introduzca su NIP: ";

    while ((ch = _getch()) != '\r') 
    {  
        if (ch >= '0' && ch <= '9') 
        {
            std::cout << '*';
            input += ch;
        }
        else if (ch == '\b' && !input.empty()) 
        {  // Backspace
            std::cout << "\b \b";
            input.pop_back();
        }
    }

    std::cout << std::endl;
    return input.empty() ? 0 : std::stoi(input);
}
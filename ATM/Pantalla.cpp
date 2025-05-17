// Pantalla.cpp
// Definiciones de las funciones miembro para la clase Pantalla.
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Pantalla.h" // Definici�n de la clase Pantalla

// imprime un mensaje sin nueva l�nea
void Pantalla::mostrarMensaje(string mensaje) const
{
	cout << mensaje;
} // fin de la funci�n mostrarMensaje

// imprime un mensaje con una nueva l�nea
void Pantalla::mostrarLineaMensaje(string mensaje) const
{
	 cout << mensaje << endl;
} // fin de la funci�n mostrarLineaMensaje

// imprime un monto en d�lares
void Pantalla::mostrarMontoDolares(double monto) const
{
	 cout << fixed << setprecision(2) << "$" << monto;
} // fin de la funci�n mostrarMontoDolares
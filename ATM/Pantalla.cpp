// Pantalla.cpp
// Definiciones de las funciones miembro para la clase Pantalla.
#include <iostream>
using std::cout;
using std::endl;
using std::fixed;

#include <iomanip>
using std::setprecision;

#include "Pantalla.h" // Definición de la clase Pantalla

// imprime un mensaje sin nueva línea
void Pantalla::mostrarMensaje(string mensaje) const
{
	cout << mensaje;
} // fin de la función mostrarMensaje

// imprime un mensaje con una nueva línea
void Pantalla::mostrarLineaMensaje(string mensaje) const
{
	 cout << mensaje << endl;
} // fin de la función mostrarLineaMensaje

// imprime un monto en dólares
void Pantalla::mostrarMontoDolares(double monto) const
{
	 cout << fixed << setprecision(2) << "$" << monto;
} // fin de la función mostrarMontoDolares
// Pantalla.h
// Definici�n de la clase Pantalla. Representa la pantalla del ATM.
#ifndef PANTALLA_H
#define PANTALLA_H

#include <string>
using std::string;

class Pantalla
{
public:
	 void mostrarMensaje(string) const; // imprime un mensaje en pantalla
	 void mostrarLineaMensaje(string) const; // imprime un mensaje con nueva l�nea
	 void mostrarMontoDolares(double) const; // imrime un monto en d�lares
}; // fin de la clase Pantalla

#endif // PANTALLA_H
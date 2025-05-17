// Retiro.h
// Definici�n de la clase Retiro. Representa una transacci�n de retiro.
#ifndef RETIRO_H
#define RETIRO_H

#include "Transaccion.h" // Definici�n de la clase Transaccion
class Teclado; // declaraci�n anticipada de la clase Teclado
class DispensadorEfectivo; // declaraci�n anticipada de la clase DispensadorEfectivo

class Retiro : public Transaccion
{
public:
	Retiro(int, Pantalla&, BaseDatosBanco&, Teclado&, DispensadorEfectivo&);
	virtual void ejecutar(); // realiza la transacci�n
private:
	int monto; // monto a retirar
	Teclado & teclado; // referencia al teclado del ATM
	DispensadorEfectivo & dispensadorEfectivo; // referencia al dispensador de efectivodel ATM
	int mostrarMenuDeMontos() const; // muestra el men� de retiro
	}; // fin de la clase Retiro

#endif // RETIRO_H
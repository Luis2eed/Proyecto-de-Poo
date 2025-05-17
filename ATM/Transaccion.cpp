// Transaccion.cpp
// Definiciones de las funciones miembro para la clase Transaccion.
#include "Transaccion.h" // Definici�n de la clase Transaccion
#include "Pantalla.h" // Definici�n de la clase Pantalla
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco

// el constructor inicializa las caracter�sticas comunes de todas las Transacciones
Transaccion::Transaccion(int numeroCuentaUsuario, Pantalla & pantallaATM,
BaseDatosBanco & baseDatosBancoATM)
: numeroCuenta(numeroCuentaUsuario),
pantalla(pantallaATM),
baseDatosBanco(baseDatosBancoATM)
{
	// cuerpo vac�o
} // fin del constructor de Transaccion

// devuelve el n�mero de cuenta
int Transaccion::obtenerNumeroCuenta() const
{
	 return numeroCuenta;
} // fin de la funci�n obtenerNumeroCuenta

// devuelve referencia a la pantalla
Pantalla & Transaccion::obtenerPantalla() const
{
	return pantalla;
} // fin de la funci�n obtenerPantalla

// devuelve referencia a la base de datos del banco
BaseDatosBanco & Transaccion::obtenerBaseDatosBanco() const
{
	return baseDatosBanco;
} // fin de la funci�n obtenerBaseDatosBanco
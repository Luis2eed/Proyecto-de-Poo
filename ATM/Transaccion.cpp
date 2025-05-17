// Transaccion.cpp
// Definiciones de las funciones miembro para la clase Transaccion.
#include "Transaccion.h" // Definición de la clase Transaccion
#include "Pantalla.h" // Definición de la clase Pantalla
#include "BaseDatosBanco.h" // Definición de la clase BaseDatosBanco

// el constructor inicializa las características comunes de todas las Transacciones
Transaccion::Transaccion(int numeroCuentaUsuario, Pantalla & pantallaATM,
BaseDatosBanco & baseDatosBancoATM)
: numeroCuenta(numeroCuentaUsuario),
pantalla(pantallaATM),
baseDatosBanco(baseDatosBancoATM)
{
	// cuerpo vacío
} // fin del constructor de Transaccion

// devuelve el número de cuenta
int Transaccion::obtenerNumeroCuenta() const
{
	 return numeroCuenta;
} // fin de la función obtenerNumeroCuenta

// devuelve referencia a la pantalla
Pantalla & Transaccion::obtenerPantalla() const
{
	return pantalla;
} // fin de la función obtenerPantalla

// devuelve referencia a la base de datos del banco
BaseDatosBanco & Transaccion::obtenerBaseDatosBanco() const
{
	return baseDatosBanco;
} // fin de la función obtenerBaseDatosBanco
//Cuenta.cpp
// Definiciones de las funciones miembro de la clase Cuenta.
#include "Cuenta.h" // definici�n de la clase Cuenta

// el constructor de Cuenta inicializa los atributos
Cuenta::Cuenta(int elNumeroDeCuenta, int elNIP,	double elSaldoDisponible, double elSaldoTotal)
	: numeroCuenta(elNumeroDeCuenta),
	nip(elNIP),
	saldoDisponible(elSaldoDisponible),
	saldoTotal(elSaldoTotal)
	{
	// cuerpo vac�o
	} // fin del constructor de Cuenta

// determina si un NIP especificado por el usuario coincide con el NIP en la Cuenta
bool Cuenta::validarNIP(int nipUsuario) const
{
	if (nipUsuario == nip)
		return true;
	else
		return false;
} // fin de la funci�n validarNIP

// devuelve el saldo disponible
double Cuenta::obtenerSaldoDisponible() const
{
	return saldoDisponible;
} // fin de la funci�n obtenerSaldoDisponible

// devuelve el saldo total
double Cuenta::obtenerSaldoTotal() const
{
	return saldoTotal;
} // fin de la funci�n obtenerSaldoTotal

// abona un monto a la cuenta
void Cuenta::abonar(double monto)
{
 saldoTotal += monto; // lo suma al saldo total
} // fin de la funci�n abonar

// carga un monto a la cuenta
void Cuenta::cargar(double monto)
{
	saldoDisponible -= monto; // resta del saldo disponible
	 saldoTotal -= monto; // resta del saldo total
} // fin de la funci�n cargar

// devuelve el n�mero de cuenta
int Cuenta::obtenerNumeroCuenta() const
{
	return numeroCuenta;
} // fin de la funci�n obtenerNumeroCuenta
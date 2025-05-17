 // BaseDatosBanco.h
 // Definición de la clase BaseDatosBanco. Representa la base de datos del banco.
 #ifndef BASEDATOS_BANCO_H
 #define BASEDATOS_BANCO_H

 #include <vector> // la clase utiliza un vector para almacenar objetos Cuenta
 using std::vector;

#include "Cuenta.h" // definición de la clase Cuenta

class BaseDatosBanco
{
public:
BaseDatosBanco(); // el constructor inicializa las cuentas
	
		// determina si el número de cuenta y el NIP coinciden con los de una Cuenta
		bool autenticarUsuario(int, int); // devuelve true si la Cuenta es auténtica
	
	double obtenerSaldoDisponible(int); // obtiene el saldo disponible
	double obtenerSaldoTotal(int); // obtiene el saldo total de una Cuenta
	void abonar(int, double); // suma el monto al saldo de la Cuenta
	void cargar(int, double); // resta el monto del saldo de la Cuenta
private:
 vector< Cuenta > cuentas; // vector de las Cuentas del banco
	
		// función utilitaria privada
		Cuenta * obtenerCuenta(int); // obtiene el apuntador al objeto Cuenta
	}; // fin de la clase BaseDatosBanco

 #endif // BASEDATOS_BANCO_H
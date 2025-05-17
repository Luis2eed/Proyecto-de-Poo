// ATM.cpp
// Definiciones de las funciones miembro para la clase ATM.
#include "ATM.h" // Definici�n de la clase ATM
#include "Transaccion.h" // Definici�n de la clase Transaccion
#include "SolicitudSaldo.h" // Definici�n de la clase SolicitudSaldo
#include "Retiro.h" // Definici�n de la clase Retiro
#include "Deposito.h" // Definici�n de la clase Deposito

// constantes de enumeraci�n que representan las opciones del men� principal
enum OpcionMenu { SOLICITUD_SALDO = 1, RETIRO, DEPOSITO, SALIR };

// el constructor predeterminado del ATM inicializa los miembros de datos
ATM::ATM()
	: usuarioAutenticado(false), // el usuario no est� autenticado para empezar
	numeroCuentaActual(0) // no hay n�mero de cuenta actual para empezar
{
	// cuerpo vac�o
} // fin del constructor predeterminado del ATM

// inicia el ATM
void ATM::ejecutar()
{
	// da la bienvenida y autentica al usuario; realiza transacciones
	while (true)
	{
		// itera mientras el usuario no est� autenticado
		while (!usuarioAutenticado)
		{
			pantalla.mostrarLineaMensaje("\nBienvenido!");
			autenticarUsuario(); // autentica al usuario
		} // fin de while

		realizarTransacciones(); // ahora el usuario es autenticado
		usuarioAutenticado = false; // restablece antes de la siguiene sesi�n del ATM
		numeroCuentaActual = 0; // restablece antes de la siguiente sesi�n del ATM
		pantalla.mostrarLineaMensaje("\nGracias! Hasta luego!");
	} // fin de while
} // fin de la funci�n ejecutar

// intenta autenticar al usuario con la base de datos
void ATM::autenticarUsuario()
{
	pantalla.mostrarMensaje("\nEscriba su numero de cuenta: ");
	int numeroCuenta = teclado.obtenerEntrada(); // introduce el n�mero de cuenta
	pantalla.mostrarMensaje("\nEscriba su NIP: "); // pide el NIP
	int nip = teclado.obtenerNIPEnmascarado();// introduce el NIP

	// establece usuarioAutenticado con el valor bool devuelto por la base de datos
	usuarioAutenticado =
		baseDatosBanco.autenticarUsuario(numeroCuenta, nip);

	// comprueba si la autenticaci�n tuvo �xito
	if (usuarioAutenticado)
	{
		numeroCuentaActual = numeroCuenta; // guarda el # de cuenta del usuario
	} // fin de if
	else
		pantalla.mostrarLineaMensaje(
			"Numero de cuenta o NIP invalido. Intente de nuevo.");
} // fin de la funci�n autenticarUsuario

// muestra el men� principal y realiza las transacciones
void ATM::realizarTransacciones()
{
	// apuntador local para almacenar la transacci�n actual en proceso
	Transaccion* transaccionActualPtr;

	bool usuarioSalio = false; // el usuario no ha elegido salir

	// itera mientras el usuario no haya elegido la opci�n para salir del sistema
	while (!usuarioSalio)
	{
		// muestra el men� principal y obtiene la selecci�n del usuario
		int seleccionMenuPrincipal = mostrarMenuPrincipal();

		// decide c�mo proceder con base en la opci�n del men� elegida por el usuario
		switch (seleccionMenuPrincipal)
		{
			// el usuario eligi� realizar uno de tres tipos de transacciones
		case SOLICITUD_SALDO:
		case RETIRO:
		case DEPOSITO:
			// se inicializa como nuevo objeto del tipo elegido
			transaccionActualPtr =
				crearTransaccion(seleccionMenuPrincipal);

			if (transaccionActualPtr != nullptr)
			{
				transaccionActualPtr->ejecutar(); // ejecuta la transacci�n
				// libera el espacio para la Transaccion asignada en forma din�mica
				delete transaccionActualPtr;
			}
			else
			{
				pantalla.mostrarLineaMensaje(
					"\nError al crear la transacci�n. Intente de nuevo.");
			}
			break;
		case SALIR: // el usuario eligi� terminar la sesi�n
			pantalla.mostrarLineaMensaje("\nSaliendo del sistema...");
			usuarioSalio = true; // esta sesi�n del ATM debe terminar
			break;
		default: // el usuario no introdujo un entero del 1 al 4
			pantalla.mostrarLineaMensaje(
				"\nNo introdujo una seleccion valida. Intente de nuevo.");
			break;
		} // fin de switch
	} // fin de while
}	 // fin de la funci�n realizarTransacciones

// muestra el men� principal y devuelve una selecci�n de entrada
int ATM::mostrarMenuPrincipal() const
{
	pantalla.mostrarLineaMensaje("\nMenu principal:");
	pantalla.mostrarLineaMensaje("1 - Ver mi saldo");
	pantalla.mostrarLineaMensaje("2 - Retirar efectivo");
	pantalla.mostrarLineaMensaje("3 - Depositar fondos");
	pantalla.mostrarLineaMensaje("4 - Salir\n");
	pantalla.mostrarMensaje("Introduzca una opcion: ");
	return teclado.obtenerEntrada(); // devuelve la selecci�n del usuario
} // fin de la funci�n mostrarMenuPrincipal

// devuelve el objeto de la clase derivada de Transaccion especificada
Transaccion* ATM::crearTransaccion(int tipo)
{
	Transaccion* tempPtr = nullptr; // Inicializa a nullptr

	// determina qu� tipo de Transaccion crear
	switch (tipo)
	{
	case SOLICITUD_SALDO: // crea nueva transacci�n SolicitudSaldo
		tempPtr = new SolicitudSaldo(
			numeroCuentaActual, pantalla, baseDatosBanco);
		break;
	case RETIRO: // crea nueva transacci�n Retiro
		tempPtr = new Retiro(numeroCuentaActual, pantalla,
			baseDatosBanco, teclado, dispensadorEfectivo);
		break;
	case DEPOSITO: // crea nueva transacci�n Deposito
		tempPtr = new Deposito(numeroCuentaActual, pantalla,
			baseDatosBanco, teclado, ranuraDeposito);
		break;
	}
	return tempPtr;  // devuelve el objeto reci�n creado o nullptr si no se cre� nada
} // fin de la funci�n crearTransaccion
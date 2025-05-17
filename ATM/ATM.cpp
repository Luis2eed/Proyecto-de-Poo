// ATM.cpp
// Definiciones de las funciones miembro para la clase ATM.
#include "ATM.h" // Definición de la clase ATM
#include "Transaccion.h" // Definición de la clase Transaccion
#include "SolicitudSaldo.h" // Definición de la clase SolicitudSaldo
#include "Retiro.h" // Definición de la clase Retiro
#include "Deposito.h" // Definición de la clase Deposito

// constantes de enumeración que representan las opciones del menú principal
enum OpcionMenu { SOLICITUD_SALDO = 1, RETIRO, DEPOSITO, SALIR };

// el constructor predeterminado del ATM inicializa los miembros de datos
ATM::ATM()
	: usuarioAutenticado(false), // el usuario no está autenticado para empezar
	numeroCuentaActual(0) // no hay número de cuenta actual para empezar
{
	// cuerpo vacío
} // fin del constructor predeterminado del ATM

// inicia el ATM
void ATM::ejecutar()
{
	// da la bienvenida y autentica al usuario; realiza transacciones
	while (true)
	{
		// itera mientras el usuario no esté autenticado
		while (!usuarioAutenticado)
		{
			pantalla.mostrarLineaMensaje("\nBienvenido!");
			autenticarUsuario(); // autentica al usuario
		} // fin de while

		realizarTransacciones(); // ahora el usuario es autenticado
		usuarioAutenticado = false; // restablece antes de la siguiene sesión del ATM
		numeroCuentaActual = 0; // restablece antes de la siguiente sesión del ATM
		pantalla.mostrarLineaMensaje("\nGracias! Hasta luego!");
	} // fin de while
} // fin de la función ejecutar

// intenta autenticar al usuario con la base de datos
void ATM::autenticarUsuario()
{
	pantalla.mostrarMensaje("\nEscriba su numero de cuenta: ");
	int numeroCuenta = teclado.obtenerEntrada(); // introduce el número de cuenta
	pantalla.mostrarMensaje("\nEscriba su NIP: "); // pide el NIP
	int nip = teclado.obtenerNIPEnmascarado();// introduce el NIP

	// establece usuarioAutenticado con el valor bool devuelto por la base de datos
	usuarioAutenticado =
		baseDatosBanco.autenticarUsuario(numeroCuenta, nip);

	// comprueba si la autenticación tuvo éxito
	if (usuarioAutenticado)
	{
		numeroCuentaActual = numeroCuenta; // guarda el # de cuenta del usuario
	} // fin de if
	else
		pantalla.mostrarLineaMensaje(
			"Numero de cuenta o NIP invalido. Intente de nuevo.");
} // fin de la función autenticarUsuario

// muestra el menú principal y realiza las transacciones
void ATM::realizarTransacciones()
{
	// apuntador local para almacenar la transacción actual en proceso
	Transaccion* transaccionActualPtr;

	bool usuarioSalio = false; // el usuario no ha elegido salir

	// itera mientras el usuario no haya elegido la opción para salir del sistema
	while (!usuarioSalio)
	{
		// muestra el menú principal y obtiene la selección del usuario
		int seleccionMenuPrincipal = mostrarMenuPrincipal();

		// decide cómo proceder con base en la opción del menú elegida por el usuario
		switch (seleccionMenuPrincipal)
		{
			// el usuario eligió realizar uno de tres tipos de transacciones
		case SOLICITUD_SALDO:
		case RETIRO:
		case DEPOSITO:
			// se inicializa como nuevo objeto del tipo elegido
			transaccionActualPtr =
				crearTransaccion(seleccionMenuPrincipal);

			if (transaccionActualPtr != nullptr)
			{
				transaccionActualPtr->ejecutar(); // ejecuta la transacción
				// libera el espacio para la Transaccion asignada en forma dinámica
				delete transaccionActualPtr;
			}
			else
			{
				pantalla.mostrarLineaMensaje(
					"\nError al crear la transacción. Intente de nuevo.");
			}
			break;
		case SALIR: // el usuario eligió terminar la sesión
			pantalla.mostrarLineaMensaje("\nSaliendo del sistema...");
			usuarioSalio = true; // esta sesión del ATM debe terminar
			break;
		default: // el usuario no introdujo un entero del 1 al 4
			pantalla.mostrarLineaMensaje(
				"\nNo introdujo una seleccion valida. Intente de nuevo.");
			break;
		} // fin de switch
	} // fin de while
}	 // fin de la función realizarTransacciones

// muestra el menú principal y devuelve una selección de entrada
int ATM::mostrarMenuPrincipal() const
{
	pantalla.mostrarLineaMensaje("\nMenu principal:");
	pantalla.mostrarLineaMensaje("1 - Ver mi saldo");
	pantalla.mostrarLineaMensaje("2 - Retirar efectivo");
	pantalla.mostrarLineaMensaje("3 - Depositar fondos");
	pantalla.mostrarLineaMensaje("4 - Salir\n");
	pantalla.mostrarMensaje("Introduzca una opcion: ");
	return teclado.obtenerEntrada(); // devuelve la selección del usuario
} // fin de la función mostrarMenuPrincipal

// devuelve el objeto de la clase derivada de Transaccion especificada
Transaccion* ATM::crearTransaccion(int tipo)
{
	Transaccion* tempPtr = nullptr; // Inicializa a nullptr

	// determina qué tipo de Transaccion crear
	switch (tipo)
	{
	case SOLICITUD_SALDO: // crea nueva transacción SolicitudSaldo
		tempPtr = new SolicitudSaldo(
			numeroCuentaActual, pantalla, baseDatosBanco);
		break;
	case RETIRO: // crea nueva transacción Retiro
		tempPtr = new Retiro(numeroCuentaActual, pantalla,
			baseDatosBanco, teclado, dispensadorEfectivo);
		break;
	case DEPOSITO: // crea nueva transacción Deposito
		tempPtr = new Deposito(numeroCuentaActual, pantalla,
			baseDatosBanco, teclado, ranuraDeposito);
		break;
	}
	return tempPtr;  // devuelve el objeto recién creado o nullptr si no se creó nada
} // fin de la función crearTransaccion
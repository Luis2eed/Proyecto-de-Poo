// Retiro.cpp
// Definiciones de las funciones miembro para la clase Retiro.
#include "Retiro.h" // Definici�n de la clase Retiro
#include "Pantalla.h" // Definici�n de la clase Pantalla
#include "BaseDatosBanco.h" // Definici�n de la clase BaseDatosBanco
#include "Teclado.h" // Definici�n de la clase Teclado
#include "DispensadorEfectivo.h" // Definici�n de la clase DispensadorEfectivo

// constante global que corresponde a la opci�n del men� para cancelar
const static int CANCELO = 6;

// el constructor de Retiro inicializa los miembros de datos de la clase
Retiro::Retiro(int numeroCuentaUsuario, Pantalla & pantallaATM,
	BaseDatosBanco& baseDatosBancoATM, Teclado& tecladoATM,
DispensadorEfectivo & dispensadorEfectivoATM)
: Transaccion(numeroCuentaUsuario, pantallaATM, baseDatosBancoATM),
	teclado(tecladoATM), dispensadorEfectivo(dispensadorEfectivoATM)
	{
	// cuerpo vac�o
	} // fin del constructor de Retiro

 // realiza una transacci�n; sobrescribe la funci�n virtual pura de Transaccion
 void Retiro::ejecutar()
 {
	bool efectivoDispensado = false; // no se ha dispensado todav�a el efectivo
	bool transaccionCancelada = false; // no se ha cancelado todav�a la transacci�n
	
		// obtiene referencias a la base de datos del banco y la pantalla
		BaseDatosBanco & baseDatosBanco = obtenerBaseDatosBanco();
	Pantalla & pantalla = obtenerPantalla();
	
		// itera hasta que se dispensa el efectivo o hasta que el usuario cancela
	do
	{
		// obtiene el monto de retiro elegido del usuario
		int seleccion = mostrarMenuDeMontos();
		
		// comprueba si el usuario eligi� un monto de retiro o cancel�
		if (seleccion != CANCELO)
		{
		monto = seleccion; // establece monto con el monto en d�lares seleccionado
		
			// obtiene el saldo disponible de la cuenta involucrada
			 double saldoDisponible =
			 baseDatosBanco.obtenerSaldoDisponible(obtenerNumeroCuenta());
			
			// comprueba si el usuario tiene suficiente dinero en la cuenta
		if (monto <= saldoDisponible)
		{
		// comprueba si el dispensador de efectivo tiene suficiente dinero
		if (dispensadorEfectivo.haySuficienteEfectivoDisponible(monto))
		{
		// actualiza la cuenta involucrada para ref lejar el retiro
		baseDatosBanco.cargar(obtenerNumeroCuenta(), monto);
			
		dispensadorEfectivo.dispensarEfectivo(monto); // dispensa el efectivo
		efectivoDispensado = true; // se dispens� el efectivo
					
		// instruye al usuario para que tome el efectivo
		pantalla.mostrarLineaMensaje(
		"\nPor favor tome su efectivo del dispensador de efectivo.");
		} // fin de if
		else // el dispensador de efectivo no tiene suficiente efectivo
		pantalla.mostrarLineaMensaje(
		"\nNo hay suficiente efectivo disponible en el ATM."
			"\n\nElija un monto menor.");
				} // fin de if
			else // no hay suficiente dinero en la cuenta del usuario
				{
				pantalla.mostrarLineaMensaje(
					"\nNo hay suficientes fondos en su cuenta."
					"\n\nElija un monto menor.");
				} // fin de else
			} // fin de if
		else // el usuario eligi� la opci�n del men� para cancelar
			 {
			 pantalla.mostrarLineaMensaje("\nCancelando la transaccion...");
			 transaccionCancelada = true; // el usuario cancel� la transacci�n
		} // fin de else
		
	} while (!efectivoDispensado && !transaccionCancelada); // fin de do...while
	
 } // fin de la funci�n ejecutar
 
	 // muestra un men� de montos de retiro y la opci�n para cancelar;
	 // devuelve el monto elegido o 0 si el usuario opt� por cancelar
	 int Retiro::mostrarMenuDeMontos() const
	 {
	 int opcionUsuario = 0; // variable local para almacenar el valor de retorno
	 
		  Pantalla & pantalla = obtenerPantalla(); // obtiene la referencia a la pantalla
	 
		// arreglo de montos que corresponden a los n�meros del men�
		 int montos[] = { 0, 20, 40, 60, 100, 200 };
	 
		 // itera mientras no se haya seleccionado una opci�n v�lida
		 while (opcionUsuario == 0)
		 {
		 // muestra el men�
		pantalla.mostrarLineaMensaje("\nOpciones de retiro:");
		  pantalla.mostrarLineaMensaje("1 - $20");
		  pantalla.mostrarLineaMensaje("2 - $40");
		  pantalla.mostrarLineaMensaje("3 - $60");
		  pantalla.mostrarLineaMensaje("4 - $100");
		  pantalla.mostrarLineaMensaje("5 - $200");
		  pantalla.mostrarLineaMensaje("6 - Cancelar transaccion");
		  pantalla.mostrarMensaje("\nElija una opcion de retiro (1-6): ");
		 
			 int entrada = teclado.obtenerEntrada(); // obtiene la entrada del usuario a trav�s del teclado
			 
			 // determina c�mo proceder con base en el valor de la entrada;
	switch (entrada)
			 {
			 case 1: // si el usuario eligi� un monto de retiro
			 case 2: // (es decir, si eligi� la opci�n 1, 2, 3, 4 o 5), devuelve
			 case 3: // el monto correspondiente del arreglo montos
			 case 4:
			 case 5:
				 opcionUsuario = montos[entrada]; // guarda la opci�n del usuario
				 break;
			 case CANCELO: // el usuario eligi� cancelar
				 opcionUsuario = CANCELO; // guarda la opci�n del usuario
				 break;
			 default: // el usuario no introdujo un valor entre 1 y 6
				 pantalla.mostrarLineaMensaje(
					 "\nSeleccion invalida. Intente de nuevo.");
				 } // fin de switch
	} // fin de while
	 
	return opcionUsuario; // devuelve monto de retiro o CANCELO
 } // fin de la funci�n mostrarMenuDeMontos
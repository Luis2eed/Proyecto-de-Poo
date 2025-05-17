//solicitudSaldo.h
// Definición de la clase SolicitudSaldo. Representa una solicitud de saldo.
#ifndef SOLICITUD_SALDO_H
#define SOLICITUD_SALDO_H

#include "Transaccion.h" // Definición de la clase Transaccion

class SolicitudSaldo : public Transaccion
{
public:
	SolicitudSaldo(int, Pantalla&, BaseDatosBanco&); // constructor
	virtual void ejecutar(); // realiza la transacción
}; // fin de la clase SolicitudSaldo

#endif // SOLICITUD_SALDO_H
// RanuraDeposito.cpp
// Definición de las funciones miembro de la clase RanuraDeposito.
#include "RanuraDeposito.h" // definición de la clase RanuraDeposito

// indica si se recibió el sobre (siempre devuelve true, ya que ésta
// sólo es una simulación de software de una ranura de depósito real)
bool RanuraDeposito::seRecibioSobre() const
{
 return true; // se recibió el sobre de depósito
} // fin de la función seRecibioSobre
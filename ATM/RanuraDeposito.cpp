// RanuraDeposito.cpp
// Definici�n de las funciones miembro de la clase RanuraDeposito.
#include "RanuraDeposito.h" // definici�n de la clase RanuraDeposito

// indica si se recibi� el sobre (siempre devuelve true, ya que �sta
// s�lo es una simulaci�n de software de una ranura de dep�sito real)
bool RanuraDeposito::seRecibioSobre() const
{
 return true; // se recibi� el sobre de dep�sito
} // fin de la funci�n seRecibioSobre
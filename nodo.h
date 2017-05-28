#ifndef NODO_H
#define NODO_H
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <qstring.h>
#include <qstringlist.h>
#include "archivo.h"


class Nodo
{
public:
    int value;
    int index;
    int dad;
    int right;
    int left;
    Nodo( int value );
    char *toChar();
    void initFromChar( char* data );
    void Guardar( Archivo *archivo );
    void Cargar( int i, Archivo *archivo );
};

#endif // NODO_H

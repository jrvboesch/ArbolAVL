#ifndef AVL_H
#define AVL_H
#include "archivo.h"
#include "nodo.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <qstring.h>
#include <qstringlist.h>

class avl
{
public:
    Archivo *archivo;
    int first_block;
    int block_size;
    avl();
    int getRoot();
    void setRoot(int root);
    int getCount();
    void setCount();
    void format();
    void add( int num );
    void addp( int num , int dad, int me );
    Nodo search( int num );
    Nodo searchp( int num, int me );
    int deep( int n );
    int swapR(Nodo *me );
    int swapL(Nodo *me );
};

#endif // AVL_H

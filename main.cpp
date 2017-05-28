#include <QCoreApplication>
#include "avl.h"
#include "nodo.h"
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    avl *tree = new avl();
    tree->add(5);
//    tree->add(3);

    qDebug() << tree->getCount();
//    add
//    Nodo *n = new Nodo( num );
//    n->index = 0;
//    n->Guardar( this->archivo );
//    this->setRoot( 0 );
//    end add

    Nodo *n = new Nodo(3);
    n->Cargar( tree->getRoot(), tree->archivo );
    qDebug() << n->value;

    return a.exec();
}

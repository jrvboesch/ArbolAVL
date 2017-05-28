#include "nodo.h"

Nodo::Nodo(int value)
{
    this->value = value;
    this->index = -1;
    this->dad = -1;
    this->left = -1;
    this->right = -1;
}

char* Nodo::toChar(){
    int size = ( sizeof( int ) * 5 ) + 4;
    char* data = new char[16];
    QString str;

    sprintf( data,"%d",index);
    str.append(data);
    str.append(",");
    sprintf( data,"%d",value);
    str.append(data);
    str.append(",");
    sprintf( data,"%d",dad);
    str.append(data);
    str.append(",");
    sprintf( data,"%d",left);
    str.append(data);
    str.append(",");
    sprintf( data,"%d",right);
    str.append(data);

    return (char*)str.toStdString().c_str();
}

void Nodo::initFromChar( char* data ){

    QString str( data );
    QStringList token;
    token = str.split(",");

    this->index = token.takeAt(0).toInt();
    this->value = token.takeAt(0).toInt();
    this->dad = token.takeAt(0).toInt();
    this->left = token.takeAt(0).toInt();
    this->right = token.takeAt(0).toInt();

}

void Nodo::Guardar( Archivo * archivo) {
    char* data = new char[ 30 ];
    archivo->Open();

    data = this->toChar();

    archivo->Write( ( this->index * 30 ) + 10, data, 30 );

    archivo->Close();
}

void Nodo::Cargar(int i , Archivo *archivo) {

    char* data = new char[ 30 ];
    archivo->Open();

    data = archivo->Read( ( i * 30 ) + 10, 30 );

    this->initFromChar( data );

    archivo->Close();
}

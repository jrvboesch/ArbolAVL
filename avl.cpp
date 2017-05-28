#include "avl.h"

avl::avl()
{
    this->archivo = new Archivo("arbol.txt");
    this->block_size = 30;
    this->first_block = 11;
    if( !this->archivo->fileExist() ){
        this->archivo->format();
        this->format();
    }
}

void avl::format() {
    int first = -1;
    int count = 0;
    QString str;
    char* data = new char[10];

    sprintf( data, "%d", first );
    str.append( data );
    str.append(",");
    sprintf( data,"%d",count );
    str.append( data );

    this->archivo->Open();

    this->archivo->Write( 0, ( char* )str.toStdString().c_str(), 10 );

    this->archivo->Close();
}

int avl::getRoot() {
    int out;
    char* data = new char[10];
    this->archivo->Open();

    data = this->archivo->Read( 0, 10 );

    QString str( data );
    QStringList token;
    token = str.split(",");

    this->archivo->Close();
    out = token.takeAt(0).toInt();
    return out;
}

void avl::setRoot( int root ) {
    int first = root;
    int count = this->getCount();

    QString str;
    char* data = new char[10];

    sprintf( data, "%d", first );
    str.append( data );
    str.append(",");
    sprintf( data,"%d",count );
    str.append( data );

    this->archivo->Open();

    this->archivo->Write( 0, ( char* )str.toStdString().c_str(), 10 );

    this->archivo->Close();
}

int avl::getCount() {
    int out;
    char* data = new char[10];
    this->archivo->Open();

    data = this->archivo->Read( 0, 10 );

    QString str( data );
    QStringList token;
    token = str.split(",");

    this->archivo->Close();
    out = token.takeAt(1).toInt();
    return out;
}

void avl::setCount() {
    int first = this->getRoot();
    int count = this->getCount() + 1;

    QString str;
    char* data = new char[10];

    sprintf( data, "%d", first );
    str.append( data );
    str.append(",");
    sprintf( data,"%d",count );
    str.append( data );

    this->archivo->Open();

    this->archivo->Write( 0, ( char* )str.toStdString().c_str(), 10 );

    this->archivo->Close();
}

void avl::add( int num ) {
    int root = this->getRoot();

    if( root == -1 ) {
        Nodo *n = new Nodo( num );
        n->index = 0;
        n->Guardar( this->archivo );
        this->setRoot( 0 );
    }else {
        this->addp( num, root, root );
    }
}

void avl::addp( int num , int dad, int me ) {
    if( me == -1 ) {
        Nodo *n = new Nodo( num );
        n->index = this->getCount();
        n->dad = dad;
        n->Guardar( this->archivo );
        this->setCount();
    }else {
        Nodo *n = new Nodo( num );
        n->Cargar( me, this->archivo );
        if( n->value > num ){
            this->addp( num, me, n->left );
        }else{
            this->addp( num, me, n->right );
        }
        int l = this->deep( n->left );
        int r = this->deep( n->right );
        int dif = l - r;

        if( dif > 1 ) {
            this->swapL( n );
        }else if( dif < -1 ){
            this->swapR( n );
        }
    }
}

Nodo avl::search( int num ){
    Nodo *n = new Nodo( num );
    n->Cargar( this->getRoot(), this->archivo );

    if( n->value == num ){
        return n;
    }
    Nodo *l = this->searchp( num, n->left );
    Nodo *r = this->searchp( num, n->right );

    if( l )
        return l;
    if( r )
        return r;

    return NULL;
}

Nodo avl::searchp( int num, int me ){
    Nodo *n = new Nodo( num );
    n->Cargar( me, this->archivo );

    if( n->value == num ){
        return n;
    }
    Nodo *l = this->searchp( num, n->left );
    Nodo *r = this->searchp( num, n->right );

    if( l )
        return l;
    if( r )
        return r;

    return NULL;
}

int avl::deep( int n ){
    if( n == -1 )
        return 0;

    Nodo *n = new Nodo( num );
    n->Cargar( n, this->archivo );

    int l = 1 + this->searchp( num, n->left );
    int r = 1 + this->searchp( num, n->right );

    if( l > r ){
        return l;
    }
    return r;
}

int avl::swapR( Nodo *me ){
    if( me->left == -1 ){
        Nodo *r = new Nodo( -1 );
        Nodo *dad = new Nodo( -1 );
        r->Cargar( me->right, this->archivo );
        dad->Cargar( me->dad, this->archivo );
        if( r->left != -1 ){
            Nodo *l2 = new Nodo( -1 );
            l2->Cargar( r->left, this->archivo );

            l2->right = l2->dad;
            r->dad = r->left;
            me->right = r->left;
            l2->dad = me->index;
            r->left = -1;
        }

        r->left = r->dad;
        me->right = -1;
        dad->right = r->index;
        r->dad = dad->index;
        me->dad = r->index;

    }else{
        Nodo *r = new Nodo( -1 );
        r->Cargar( me->right, this->archivo );
        this->swapR( r );
    }

}

int avl::swapL( Nodo *me ){
    if( me->right == -1 ){
        Nodo *l = new Nodo( -1 );
        Nodo *dad = new Nodo( -1 );
        l->Cargar( me->right, this->archivo );
        dad->Cargar( me->dad, this->archivo );
        if( l->right != -1 ){
            Nodo *r2 = new Nodo( -1 );
            r2->Cargar( l->left, this->archivo );

            r2->left = r2->dad;
            l->dad = r2->index;
            me->left = r2->index;
            r2->dad = me->index;
            l->right = -1;
        }

        l->dad = me->dad;
        me->left = -1;
        l->right = me->index;
        dad->left = l->index;
        me->dad = l->index;

    }else{
        Nodo *l = new Nodo( -1 );
        l->Cargar( me->left, this->archivo );
        this->swapL( l );
    }

}

























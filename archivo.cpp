#include "archivo.h"

Archivo::Archivo( char* file){
    this->path = file;
    this->fp = NULL;
}

void Archivo::Open() {
    if( strlen( this->path ) ){
        this->fp = fopen( this->path, "r+" );
    }
}

void Archivo::Close() {
    if( this->fp ){
        fclose( this->fp );
    }
}

void Archivo::Write( int offset, char* data, int size ) {
    if( this->fp ){
        fseek( this->fp, offset, SEEK_SET );
        fwrite( data, size, 1, this->fp );
    }
}

char* Archivo::Read( int offset, int size ) {
    char* data = new char( size );
    if( this->fp ){
        fseek( this->fp, offset, SEEK_SET );
        fread( data, 1, size, this->fp );
    }
    return data;
}

void Archivo::format() {
    if( strlen( this->path ) ){
        this->fp = fopen( this->path, "w+" );
        fseek( this->fp, 1024*3, SEEK_SET );
        fputc( '\0', this->fp );
        this->Close();
    }
}

bool Archivo::fileExist() {
    FILE* fpe;
    if( (fpe = fopen( this->path, "r" ) ) ){
        fclose( fpe );
        return true;
    }
    return false;
}

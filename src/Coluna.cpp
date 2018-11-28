#include "Coluna.h"
#include <sstream>
#include <string>

Coluna::Coluna(int c, Informacao* info)
{
    this->coluna = c;
    this->infoMat = info;
}

Coluna::~Coluna()
{
}

int Coluna::getColuna()
{
    return this->coluna;
}

Informacao* Coluna::getInfoMat()
{
    return this->infoMat;
}

int Coluna::compareTo(Informacao* info) throw(char*)
{
    if(info == NULL)
        throw("A informa��o n�o pode ser nula");

    Coluna* c = (Coluna*)info;

    if(this->coluna == c->getColuna())
        return 0;
    else
        if(this->coluna < c->getColuna())
            return -1;
    return 1;
}

void Coluna::setInfoMat(Informacao* info) throw(char*)
{
    if(info == NULL)
        throw ("A informacao nao pode ser nula!");

    this->infoMat = info;
}

std::string Coluna::toString()
{
    std::stringstream ss;
    ss << "Coluna";
    ss << this->coluna;
}

Informacao* Coluna::clone()
{
}

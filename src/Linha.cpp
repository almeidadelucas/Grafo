#include "Linha.h"
#include "Coluna.h"
#include <sstream>

Linha::Linha(int l)
{
    this->linha = l;
    this->colunas = new ArvoreAVL();
}

Linha::~Linha()
{
}

int Linha::getLinha()
{
    return this->linha;
}

Informacao* Linha::getInfoMat(int c)
{
    Coluna* col = new Coluna(c, NULL);
    Coluna* retorno = (Coluna*)colunas->tem(col);
    if(retorno == NULL)
        return NULL;
    return retorno->getInfoMat()->clone();
}

void Linha::inserirInfoMat(int c, Informacao* infoMat)
{
    Coluna* col = new Coluna(c, infoMat->clone());
    if(colunas->tem(col) != NULL) // J� tem uma informacao, substitui ela pela nova;
        this->colunas->excluirInfo(col);
    this->colunas->inserirInfo(col);
}

void Linha::excluirInfoMat(int c)
{
    Coluna* col = new Coluna(c, NULL);
    if(colunas->tem(col) != NULL)
        this->colunas->excluirInfo(col);
}

bool Linha::estaVazia()
{
    return colunas == NULL;
}

int Linha::compareTo(Informacao* info) throw(char*)
{
    if(info == NULL)
        throw("A informa��o n�o pode ser nula");

    Linha* l = (Linha*)info;

    if(this->linha == l->getLinha())
        return 0;
    else
        if(this->linha < l->getLinha())
            return -1;
    return 1;
}

bool Linha::temInfoMat(int c)
{
    Coluna* col = new Coluna(c, NULL);
    return colunas->tem(col) != NULL;
}

Informacao* Linha::getMaior()
{
    return this->colunas->getMaior();
}

Informacao* Linha::getMenor()
{
    return this->colunas->getMenor();
}

std::string Linha::toString()
{
    std::stringstream ss;
    ss << "Linha: ";
    ss << getLinha();
    return ss.str();
}

Informacao* Linha::clone()
{
}

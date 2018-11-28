#include "ArvoreAVL.h"
#include "No.h"
#include "Informacao.h"
#include <iostream>
#include <cstring>

using namespace std;

ArvoreAVL::ArvoreAVL()
{
    this->raiz = NULL;
}

ArvoreAVL::~ArvoreAVL()
{
    delete raiz;
}

void ArvoreAVL::inserirInfo(Informacao* i) throw(char*)
{
    if(i == NULL)
        throw("A informa��o n�o pode ser nula!");
    if(tem(this->raiz, i) != NULL)
        throw("A informa��o j� existe!");
    this->raiz = inserir(this->raiz, i);
}

No* ArvoreAVL::inserir(No* no, Informacao* i)
{
    if(no == NULL)
        return new No(i);

    int c = i->compareTo(no->getInformacao());

    if(c < 0)
        no->setPtrEsq(inserir(no->getPtrEsq(), i));
    if(c > 0)
        no->setPtrDir(inserir(no->getPtrDir(), i));

    return this->balancear(no);
}

No* ArvoreAVL::balancear(No* no)
{
    if(no->getEquilibrio() > 1)
    {
        if(no->getPtrDir()->getEquilibrio() < 0)
            return this->giroDuploParaEsq(no);
        else
            return this->giroParaEsq(no);
    }
    else
        if(no->getEquilibrio() < -1)
        {
            if(no->getPtrEsq()->getEquilibrio() > 0)
                return this->giroDuploParaDir(no);
            else
                return this->giroParaDir(no);
        }
    return no;
}

No* ArvoreAVL::giroParaEsq(No* no)
{
    No* novaRaiz = no->getPtrDir();
    no->setPtrDir(novaRaiz->getPtrEsq());
    novaRaiz->setPtrEsq(no);

    return novaRaiz;
}

No* ArvoreAVL::giroParaDir(No* no)
{
    No* novaRaiz = no->getPtrEsq();
    no->setPtrEsq(novaRaiz->getPtrDir());
    novaRaiz->setPtrDir(no);

    return novaRaiz;
}
No* ArvoreAVL::giroDuploParaEsq(No* no)
{
    no->setPtrDir(this->giroParaDir(no->getPtrDir()));
    return giroParaEsq(no);
}
No* ArvoreAVL::giroDuploParaDir(No* no)
{
    no->setPtrEsq(this->giroParaEsq(no->getPtrEsq()));
    return giroParaDir(no);
}

void ArvoreAVL::excluirInfo(Informacao* i) throw(char*)
{
    if(i == NULL)
        throw("A inforam��o n�o pode ser nula");
    if(tem(i) == NULL)
        throw("A informa��o n�o existe na �rvore");
    this->raiz = this->excluir(this->raiz, i);
}

No* ArvoreAVL::excluir(No* no, Informacao* i)
{
    if(no == NULL)
        return NULL;
    int c = i->compareTo(no->getInformacao());
    //---------------------------------------------------------
    // A informa��o a ser exluida � menor que a que est� no n�
    // portanto est� a esquerda do n�
    //---------------------------------------------------------
    if(c < 0)
        no->setPtrEsq(this->excluir(no->getPtrEsq(), i));
    //---------------------------------------------------------
    // A informa��o a ser exluida � maior que a que est� no n�
    // portanto est� a direita do n�
    //---------------------------------------------------------
    else
        if(c > 0)
            no->setPtrDir(this->excluir(no->getPtrDir(), i));
        else
            if(no->getPtrEsq() == NULL)
                return no->getPtrDir();
            else
                if(no->getPtrDir() == NULL)
                    return no->getPtrEsq();
                else
                {
                    // O maior vira o novo n�
                    if(no->getNivel(no->getPtrEsq()) > no->getNivel(no->getPtrDir()))
                    {
                        Informacao* maior = this->encontrarMaior(no->getPtrEsq());
                        no->setInformacao(maior);
                        no->setPtrEsq(this->excluir(no->getPtrEsq(), maior));
                    }
                    // O menor vira o novo n�
                    else
                    {
                        Informacao* menor = this->encontrarMenor(no->getPtrDir());
                        no->setInformacao(menor);
                        no->setPtrDir(this->excluir(no->getPtrDir(), menor));
                    }
                }

    return this->balancear(no);
}

Informacao* ArvoreAVL::encontrarMaior(No* no)
{
    while(no->getPtrDir() != NULL)
        no = no->getPtrDir();
    return no->getInformacao();
}

Informacao* ArvoreAVL::encontrarMenor(No* no)
{
    while(no->getPtrEsq() != NULL)
        no = no->getPtrEsq();
    return no->getInformacao();
}

Informacao* ArvoreAVL::tem(Informacao* i)
{
    return tem(this->raiz, i);
}

Informacao* ArvoreAVL::tem(No* no, Informacao* i)
{
    if(no == NULL)
        return NULL;

    int c = i->compareTo(no->getInformacao());

    if(c < 0)
        return tem(no->getPtrEsq(), i);
    if(c > 0)
        return tem(no->getPtrDir(), i);
    return no->getInformacao();
}

Informacao* ArvoreAVL::getMaior()
{
    if(this->raiz == NULL)
        return NULL;
    return encontrarMaior(this->raiz);
}

Informacao* ArvoreAVL::getMenor()
{
    if(this->raiz == NULL)
        return NULL;
    return encontrarMenor(this->raiz);
}

ostream& operator<<(ostream& os, const ArvoreAVL& ar)
{
    if(ar.raiz == NULL)
        os << "()";
    else
        ar.raiz->printar(os);

    return os;
}

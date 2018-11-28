#ifndef ARVOREAVL_H
#define ARVOREAVL_H
#include "No.h"
#include "Informacao.h"
#include <iostream>

using namespace std;

class ArvoreAVL
{
    public:
        ArvoreAVL();
        virtual ~ArvoreAVL();
        void inserirInfo(Informacao*) throw(char*);
        void excluirInfo(Informacao*) throw(char*);
        Informacao* tem(Informacao*);
        Informacao* getMaior();
        Informacao* getMenor();
        friend ostream& operator<<(ostream&, const ArvoreAVL&);
    private:
        No* raiz;
        No* balancear(No*);
        No* giroParaEsq(No*);
        No* giroParaDir(No*);
        No* giroDuploParaEsq(No*);
        No* giroDuploParaDir(No*);
        No* inserir(No*,Informacao*);
        No* excluir(No*,Informacao*);
        Informacao* tem(No*, Informacao*);
        Informacao* encontrarMaior(No*);
        Informacao* encontrarMenor(No*);
};

#endif // ARVOREAVL_H

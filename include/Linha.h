#ifndef LINHA_H
#define LINHA_H
#include "ArvoreAVL.h"
#include "Informacao.h"
#include "Coluna.h"
#include <string>

class Linha : public Informacao
{
    public:
        Linha(int);
        virtual ~Linha();
        int getLinha();
        Informacao* getInfoMat(int); // pegar Informacao dessa linha em alguma coluna
        void inserirInfoMat(int, Informacao*);
        void excluirInfoMat(int);
        bool estaVazia();
        bool temInfoMat(int);
        int compareTo(Informacao*) throw(char*);
        Informacao* getMaior();
        Informacao* getMenor();
        std::string toString();
        Informacao* clone();
    private:
        int linha;
        ArvoreAVL* colunas;
};

#endif // LINHA_H

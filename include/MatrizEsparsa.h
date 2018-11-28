#ifndef MATRIZESPARSA_H
#define MATRIZESPARSA_H
#include "ArvoreAVL.h"
#include "Informacao.h"

class MatrizEsparsa
{
    public:
        MatrizEsparsa(Informacao* infoPadrao);
        virtual ~MatrizEsparsa();
        bool temInfo(int, int) throw(char*);
        Informacao* getInfo(int, int) throw(char*);
        void inserirInfo(int, int, Informacao*) throw(char*);
        void excluirInfo(int, int) throw(char*);
        friend ostream& operator<<(ostream&, const MatrizEsparsa&);
    private:
        ArvoreAVL* matriz;
        Informacao* infoPadrao;
};

#endif // MATRIZESPARSA_H

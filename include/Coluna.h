#ifndef COLUNA_H
#define COLUNA_H
#include "Informacao.h"
#include <string>

class Coluna : public Informacao
{
    public:
        Coluna(int, Informacao*);
        virtual ~Coluna();
        int getColuna();
        int compareTo(Informacao*) throw(char*);
        void setInfoMat(Informacao*) throw(char*);
        Informacao* getInfoMat();
        std::string toString();
        Informacao* clone();
    private:
        int coluna;
        Informacao* infoMat;
};

#endif // COLUNA_H

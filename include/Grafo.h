#ifndef GRAFO_H
#define GRAFO_H
#include "MatrizEsparsa.h"
#include "tipoOrientacao.h"

using namespace std;

class Grafo
{
    public:
        Grafo(int, tipoOrientacao);
        virtual ~Grafo();
        void addVertice(char*);
        void delVertice(char*);
        void addAresta(char*, char*, int);
        friend ostream& operator<< (ostream&, const Grafo&);
    private:
        int maxVertice;
        int qtsVertices;
        char** nomeVertice;
        MatrizEsparsa* aresta;
        tipoOrientacao tipo;
        bool temVertice(char*);
};

#endif // GRAFO_H

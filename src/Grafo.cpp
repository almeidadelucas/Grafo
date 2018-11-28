#include "Grafo.h"
#include "MinhaInformacao.h"
#include <iostream>
#include <stdexcept>

Grafo::Grafo(int maxVer, tipoOrientacao tip)
{
    this->tipo = tip;
    this->maxVertice = maxVer;
    this->qtsVertices = 0;
    this->aresta = new MatrizEsparsa(new MinhaInformacao(-1));
    this->nomeVertice = new char*[maxVertice];
    for(int i = 0; i < this->maxVertice; i++)
        this->nomeVertice[i] = NULL;
}

Grafo::~Grafo()
{
}

void Grafo::addVertice(char* nome)
{
    if(this->qtsVertices == this->maxVertice)
        throw invalid_argument("Numero maximo de vertices atingido");
    if(nome == NULL)
        throw invalid_argument("O nome nao pode ser nulo");

    for(int i = 0; i < this->maxVertice; i++)
        if(this->nomeVertice[i] == NULL)
        {
            this->nomeVertice[i] = nome;
            this->qtsVertices++;
            break;
        }
}

void Grafo::delVertice(char* nome)
{
    int i, j;
    if(this->qtsVertices == 0)
        throw invalid_argument("Vertice nao existe!");

    for(i = 0; i < this->qtsVertices; i++)
        if(this->nomeVertice[i] == nome)
            break;

    for(j = 0; j < this->qtsVertices; j++)
        if(this->aresta->getInfo(i, j) != NULL || this->aresta->getInfo(j, i) != NULL)
            throw invalid_argument("O vertice possui ligacoes e nao pode ser excluido");

    this->nomeVertice[i] = NULL;
    this->qtsVertices--;
}

void Grafo::addAresta(char* saida, char* destino, int peso)
{
    if(!temVertice(saida) || !temVertice(destino))
        throw invalid_argument("Um dos vertices nao existe");

    int l, c; // linha e coluna
    for(int i = 0; i < this->qtsVertices; i++)
    {
        if(this->nomeVertice[i] == saida)
            l = i;
        else
        if(this->nomeVertice[i] == destino)
            c = i;
    }

    this->aresta->inserirInfo(l, c, new MinhaInformacao(peso));
    if(tipo == naoDirigido)
        this->aresta->inserirInfo(c, l, new MinhaInformacao(peso));
}

bool Grafo::temVertice(char* nome)
{
    for(int i = 0; i < this->maxVertice; i++)
        if(this->nomeVertice[i] == nome)
            return true;
    return false;
}

ostream& operator<< (ostream& os, const Grafo& grafo)
{
    if(grafo.qtsVertices == 0)
        os << "()";
    else
    {
        for(int i = 0; i < grafo.maxVertice; i++)
            if(grafo.nomeVertice[i] != NULL)
            {
                for(int j = 0; j < grafo.maxVertice; j++)
                    if(   grafo.nomeVertice[j] != NULL
                       && grafo.nomeVertice[j] != grafo.nomeVertice[i]
                       && grafo.aresta->getInfo(i, j)->compareTo(new MinhaInformacao(-1)) != 0)
                        os << grafo.nomeVertice[i] << " - " << grafo.nomeVertice[j] << " " << grafo.aresta->getInfo(i, j)->toString() << "\n";
            }
    }
}

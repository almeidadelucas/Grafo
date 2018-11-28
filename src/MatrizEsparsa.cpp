#include "MatrizEsparsa.h"
#include "Linha.h"

MatrizEsparsa::MatrizEsparsa(Informacao* padrao)
{
    infoPadrao = padrao;
    this->matriz = new ArvoreAVL();;
}

MatrizEsparsa::~MatrizEsparsa()
{
}

bool MatrizEsparsa::temInfo(int l, int c) throw(char*)
{
    if(l < 0 || c < 0)
        throw("Posicao invalida!");
    Linha* linha = (Linha*)matriz->tem(new Linha(l));
    if(linha == NULL)
        return false;

    return linha->temInfoMat(c);
}

Informacao* MatrizEsparsa::getInfo(int l, int c) throw(char*)
{
    if(l < 0 || c < 0)
        throw("Posicao invalida!");

    Linha* linha = (Linha*)matriz->tem(new Linha(l));
    if(linha == NULL)
        return this->infoPadrao->clone();

    Informacao* retorno = linha->getInfoMat(c);
    if(retorno == NULL)
        return this->infoPadrao->clone();

    return linha->getInfoMat(c)->clone();
}

void MatrizEsparsa::inserirInfo(int l, int c, Informacao* i) throw(char*)
{
    if(l < 0 || c < 0)
        throw("Posicao invalida!");

    if(i->compareTo(this->infoPadrao) != 0)
    {
        Linha* linha = (Linha*)matriz->tem(new Linha(l));

        if(linha != NULL)
            matriz->excluirInfo(linha);
        else
            linha = new Linha(l);

        linha->inserirInfoMat(c, i);
        matriz->inserirInfo(linha);
    }
}

void MatrizEsparsa::excluirInfo(int l, int c) throw(char*)
{
    if(l < 0 || c < 0)
        throw("Posicao invalida!");

    Linha* linha = (Linha*)matriz->tem(new Linha(l));

    if(linha != NULL)
    {
        matriz->excluirInfo(linha);

        linha->excluirInfoMat(c);
        if(!linha->estaVazia())
            matriz->inserirInfo(linha);
    }
}

ostream& operator<<(ostream& os, const MatrizEsparsa& mat)
{
    Linha* maiorLinha = (Linha*)mat.matriz->getMaior();
    Linha* menorLinha = (Linha*)mat.matriz->getMenor();
    Linha* linhaAux = NULL;

    Coluna* maiorColuna = NULL;
    Coluna* colunaAux = NULL;

    Informacao* aux = NULL;

    int i, j;

    if(maiorLinha == NULL && menorLinha == NULL)
        os << "1";
    else
    {
        for(i = menorLinha->getLinha(); i <= maiorLinha->getLinha(); i++) // pegar maior coluna
        {
            linhaAux = (Linha*)mat.matriz->tem(new Linha(i));
            if(linhaAux != NULL)
            {
                colunaAux = (Coluna*)linhaAux->getMaior();
                if(maiorColuna == NULL || colunaAux->compareTo(maiorColuna) > 0)
                    maiorColuna = colunaAux;
            }
        }

        os << "      " << 0 << " ";
        for(i = 1; i <= maiorColuna->getColuna(); i++)
            os << " " << i << " ";
        os << "\n";

        for(i = 0; i <= maiorLinha->getLinha(); i++) // pegar maior coluna
        {
            if (i >= 10)
                os << " " << i << "- ";
            else
                os << " " << i << " - ";

            for(j = 0; j <= maiorColuna->getColuna(); j++)
            {
                linhaAux = (Linha*)mat.matriz->tem(new Linha(i));
                if(linhaAux != NULL)
                {
                    aux = linhaAux->getInfoMat(j);
                    if(aux != NULL)
                    {
                        if(aux->toString().length() == 2)
                            os << " " << aux->toString();
                        else
                        if(aux->toString().length() == 3)
                            os << aux->toString();
                        else
                            os << " " << aux->toString() << " ";
                    }
                    else
                        os << " " << mat.infoPadrao->toString() << " ";
                }
                else
                    os << " " << mat.infoPadrao->toString() << " ";
            }
            os << "\n";
        }
    }
}

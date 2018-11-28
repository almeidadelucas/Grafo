#include "No.h"
#include "Informacao.h"
#include <sstream>

No::No(Informacao* i)
{
    this->ptrDir    = NULL;
    this->ptrEsq    = NULL;
    this->info      = i;
}

No::~No()
{
    delete ptrDir;
    delete ptrEsq;
}

Informacao* No::getInformacao()
{
    return this->info;
}

void No::setInformacao(Informacao* i)
{
    this->info = i;
}

No* No::getPtrEsq()
{
    return this->ptrEsq;
}

No* No::getPtrDir()
{
    return this->ptrDir;
}

int No::getEquilibrio()
{
    int i = this->getNivel(this->ptrDir) - this->getNivel(this->getPtrEsq());
    return i;
}

int No::getNivel(No* no)
{
    if(no == NULL)
        return -1;

    int nEsq = this->getNivel(no->ptrEsq);
    int nDir = this->getNivel(no->ptrDir);

    if(nEsq > nDir)
        return ++nEsq;

    return ++nDir;
}

void No::setPtrEsq(No* no)
{
    this->ptrEsq = no;
}

void No::setPtrDir(No* no)
{
    this->ptrDir = no;
}

void No::printar(ostream& os)
{
    os << "(";

    if(this->ptrEsq != NULL)
        this->ptrEsq->printar(os);

    os << this->info->toString();

    if(this->ptrDir != NULL)
        this->ptrDir->printar(os);

    os << ")";
}

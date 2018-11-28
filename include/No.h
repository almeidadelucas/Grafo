#ifndef NO_H
#define NO_H
#include "Informacao.h"
#include <iostream>

using namespace std;

class No
{
    public:
        No(Informacao*);
        virtual ~No();
        Informacao* getInformacao();
        No*         getPtrEsq();
        No*         getPtrDir();
        int         getEquilibrio();
        int         getNivel(No*);
        void        setPtrEsq(No*);
        void        setPtrDir(No*);
        void        setInformacao(Informacao*);
        void        printar(ostream&);
    private:
        Informacao* info;
        No*         ptrEsq;
        No*         ptrDir;
};

#endif // NO_H

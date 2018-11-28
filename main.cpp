#include <iostream>
#include <stdexcept>
#include "Grafo.h"
#include "tipoOrientacao.h"

using namespace std;

int main()
{
    try
    {
        Grafo grafo(10, dirigido);
        grafo.addVertice("A");
        grafo.addVertice("B");
        grafo.addVertice("C");
        grafo.addAresta("A", "B", 5);
        grafo.addAresta("A", "C", 11);
        grafo.addAresta("B", "C", 7);
        grafo.addVertice("D");
        grafo.addAresta("B", "D", 10);
        cout << grafo;

    }
    catch(std::invalid_argument e)
    {
        cerr << "\n" << e.what() << "\n";
    }
    return 0;
}

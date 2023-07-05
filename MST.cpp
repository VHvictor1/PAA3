#include <bits/stdc++.h>

using namespace std;

struct Aresta
{
    long long int origem, destino, peso;
};

struct Subconjunto
{
    long long int paiDoConjunto;
    long long int classificacao;
};

long long int encontrarPai(long long int i, vector<Subconjunto> &subconjuntos)
{
    if (subconjuntos[i].paiDoConjunto != i)
        subconjuntos[i].paiDoConjunto = encontrarPai(subconjuntos[i].paiDoConjunto, subconjuntos);
    return subconjuntos[i].paiDoConjunto;
}

void unirConjuntos(long long int x, long long int y, vector<Subconjunto> &subconjuntos)
{
    long long int raizX = encontrarPai(x, subconjuntos);
    long long int raizY = encontrarPai(y, subconjuntos);

    if (subconjuntos[raizX].classificacao > subconjuntos[raizY].classificacao)
        subconjuntos[raizY].paiDoConjunto = raizX;
    else if (subconjuntos[raizX].classificacao < subconjuntos[raizY].classificacao)
        subconjuntos[raizX].paiDoConjunto = raizY;
    else
    {
        subconjuntos[raizY].paiDoConjunto = raizX;
        subconjuntos[raizX].classificacao++;
    }
}

bool compararArestas(const Aresta &a, const Aresta &b)
{
    return a.peso < b.peso;
}

void ordenarArestas(vector<Aresta> &arestas)
{
    for (int i = 0; i < arestas.size(); ++i)
    {
        for (int j = i + 1; j < arestas.size(); ++j)
        {
            if (arestas[i].peso > arestas[j].peso)
            {
                swap(arestas[i], arestas[j]);
            }
        }
    }
}

long long int kruskal(const vector<Aresta> &arestas, int numVertices, int numArestas)
{
    vector<Subconjunto> subconjuntos(numArestas);
    for (int i = 0; i < numArestas; ++i)
        subconjuntos[i] = {i, 0};

    long long int custoTotal = 0;
    for (int i = 0; i < numArestas; ++i)
    {
        if (encontrarPai(arestas[i].origem, subconjuntos) != encontrarPai(arestas[i].destino, subconjuntos))
        {
            unirConjuntos(arestas[i].origem, arestas[i].destino, subconjuntos);
            custoTotal += arestas[i].peso;
        }
    }

    return custoTotal;
}

int main()
{
    int numVertices, numArestas;
    cin >> numVertices;
    cin >> numArestas;

    vector<Aresta> arestas(numArestas);
    for (int i = 0; i < numArestas; ++i)
    {
        long long int origem, destino;
        cin >> origem >> destino >> arestas[i].peso;
        arestas[i].origem = origem - 1;
        arestas[i].destino = destino - 1;
    }

    ordenarArestas(arestas);
    long long int custoMinimo = kruskal(arestas, numVertices, numArestas);

    cout << custoMinimo;

    return 0;
}
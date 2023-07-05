#include <bits/stdc++.h>

using namespace std;

int resolver(int posicao, int restante, const vector<int> &tamanhos, const vector<int> &valores, vector<vector<int>> &dp)
{
    if (posicao <= 0 || restante == 0)
        return 0;

    int &resultado = dp[posicao][restante];
    if (resultado != -1)
        return resultado;

    resultado = resolver(posicao - 1, restante, tamanhos, valores, dp);
    if (restante >= tamanhos[posicao])
        resultado = max(resultado, valores[posicao] + resolver(posicao - 1, restante - tamanhos[posicao], tamanhos, valores, dp));

    return resultado;
}

int main()
{
    int tamanhoDisponivel, numItens;
    cin >> tamanhoDisponivel >> numItens;

    vector<int> tamanhos(numItens + 1);
    vector<int> valores(numItens + 1);

    for (int i = 1; i <= numItens; i++)
    {
        cin >> tamanhos[i] >> valores[i];
    }

    vector<vector<int>> dp(numItens + 1, vector<int>(tamanhoDisponivel + 1, -1));

    int resultado = resolver(numItens, tamanhoDisponivel, tamanhos, valores, dp);
    cout << resultado << endl;

    return 0;
}

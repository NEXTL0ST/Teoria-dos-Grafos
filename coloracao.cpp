#include <bits/stdc++.h>

using namespace std;

void leituraGrafo(vector<vector<int>> &, int);
void escritaGrafo(vector<vector<int>> &);
void colorirGrafo(vector<vector<int>> &);

int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> Grafo;
    Grafo.assign(n, vector<int>());
    leituraGrafo(Grafo, m);
    colorirGrafo(Grafo);
    escritaGrafo(Grafo);
    cout << "Total Vértices: " << n << endl;
    cout << "Total Arestas: " << m << endl;
    return 0;
}

void leituraGrafo(vector<vector<int>> &G, int m)
{
    int a, b;
    while (m--)
    {
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
}

void escritaGrafo(vector<vector<int>> &G)
{
    int n = G.size();
    cout << "Lista de Adjacência:" << endl;
    for (int u = 0; u < n; u++)
    {
        cout << u << ": ";
        for (auto v : G[u])
        {
            cout << v << " ";
        }
        cout << endl;
    }
}

void colorirGrafo(vector<vector<int>> &G)
{
    int n = G.size();
    vector<int> cores(n, -1);
    vector<int> grau(n, 0);

    for (int i = 0; i < n; i++)
        grau[i] = G[i].size();

    vector<pair<int, int>> ordem;
    for (int i = 0; i < n; i++)
        ordem.push_back({grau[i], i});
    sort(ordem.rbegin(), ordem.rend());

    for (auto &it : ordem)
    {
        int u = it.second;
        vector<bool> usado(n, false);
        for (auto &i : G[u])
            if (cores[i] != -1)
                usado[cores[i]] = true;

        int cr;
        for (cr = 0; cr < n; cr++)
            if (!usado[cr])
                break;

        cores[u] = cr;
    }

    for (int u = 0; u < n; u++)
        cout << "Vértice " << u << " tem cor " << cores[u] << endl;
}
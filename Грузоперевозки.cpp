#include <stdio.h>
#include <iostream>
#include <vector>
#define INTMAX 2147483647

using namespace std;

void FloydWarshall(vector<vector<int>> &graph, int n){
    for (int k = 0; k < n; ++k){
        for (int i = 0; i < n; ++i){
            for (int j = 0; j < n; ++j){
                if (graph[i][k] < INTMAX && graph[k][j] < INTMAX)
                    graph[i][j] = min(graph[i][j],graph[i][k] + graph[k][j]);
            }
        }
    }
}

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n, m, q, s1, s2, w;
    cin >> n >> m;
    vector<vector<int>> graph;

    graph.resize(n);
    for (int i = 0; i < n; i++){
        graph[i].resize(n);
        for (int j = 0; j < n; j++)
            graph[i][j] = INTMAX;
        graph[i][i] = 0;
    }

    for (int i = 0; i < m; i++){
        cin >> s1 >> s2 >> w;
        graph[--s1][--s2] = w;
    }
    cin >> q;

    FloydWarshall(graph, n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if ((graph[i][j] != INTMAX) && (graph[j][i] != INTMAX)){
                graph[i][j] = 0;
                graph[j][i] = 0;
            }

    FloydWarshall(graph, n);

    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            if (graph[i][j] == INTMAX)
                graph[i][j] = -1;

    for (int i = 0; i < q; ++i){
        cin >> s1 >> s2;
        cout << graph[--s1][--s2] << '\n';
    }
}
#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int to, weigth;
};

vector< vector<edge> > graph;
vector<int> currShortPath;
vector<bool> visited;

void dijkstra();

int n, m, s;
int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    cin >> n >> m >> s;
    s--;
    graph.resize(n);
    visited.resize(n);
    currShortPath.resize(n);
    for (int i = 0; i < n; i++){
        i == s ? currShortPath[i] = 0 : currShortPath[i] = INT_MAX;
    }
    edge temp;
    int from;
    for (int i = 0; i < m; i++){
        cin >> from >> temp.to >> temp.weigth;
        temp.to--;
        graph[--from].push_back(temp);
    }
    dijkstra();
    for (int i = 0; i < currShortPath.size(); i++){
        currShortPath[i] == INT_MAX ? cout << -1 << " " : cout << currShortPath[i] << " ";
    }
}

void dijkstra(){
    for (int i = 0; i < n; ++i) {
        int v = -1;
        for (int j = 0; j < n; j++)
            if (!visited[j] && (v == -1 || currShortPath[j] < currShortPath[v]))
                v = j;
        if (currShortPath[v] == INT_MAX)
            break;
        visited[v] = true;
        for (int j = 0; j < graph[v].size(); j++) {
            if (currShortPath[v] + graph[v][j].weigth < currShortPath[graph[v][j].to]) {
                currShortPath[graph[v][j].to] = currShortPath[v] + graph[v][j].weigth;
            }
        }
    }
}
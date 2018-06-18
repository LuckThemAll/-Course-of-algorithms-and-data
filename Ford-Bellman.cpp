#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct edge {
    int a, b, weigth;
};
vector<edge> edges;
vector<int> d;

int relax(int num){
    return min(d[edges[num].b], d[edges[num].a] + edges[num].weigth);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, s;
    edge t;
    cin >> n >> m >> s;
    d.resize(n + 1);
    for (int i = 0; i < d.size(); i++)
        d[i] = INT_MAX;
    d[s] = 0;
    for (int i = 0; i < m; i++){
        cin >> t.a >> t.b >> t.weigth;
        edges.push_back(t);
    }
    for (int f = 0; f < n - 1; f++)
        for (int i = 0; i < m; i++)
            if (d[edges[i].a] != INT_MAX)
                d[edges[i].b] = relax(i);
    for (int i = 0; i <= n ; i++)
        if (d[i] != INT_MAX)
            cout << d[i] << ' ';
        else
            cout << ' ' << ' ';
}
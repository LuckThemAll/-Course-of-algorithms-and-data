#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> graph;
int n;
//white: 0;
//black: 1;

vector<int> bfs(int start){
    vector<int> result, status, d;
    queue<int> q;

    d.resize(n);
    status.resize(n);
    for (int i = 0; i < n; i++) {
        status[i] = 0;
        d[i] = 0;
    }

    q.push(start);
    result.push_back(start + 1);
    status[start] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < graph[v].size(); ++i)
        {
            if (status[graph[v][i]] == 0)
            {
                status[graph[v][i]] = 1;
                q.push(graph[v][i]);
                result.push_back(graph[v][i] + 1);
            }
        }
    }
    return result;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int m, a, b, s;
    cin >> n >> m >> s;
    vector<int> ans;

    graph.resize(n);
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[a - 1].push_back(b - 1);
        graph[b - 1].push_back(a - 1);
    }

    ans = bfs(s - 1);
    if (ans.size() != n)
        cout << -1;
    else {
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
    }
}
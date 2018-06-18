#include <iostream>
#include <vector>

using namespace std;

vector<int> ans;
vector<vector<int>> graph;
vector<int> status;
bool circle;
//white: 0
//gray: 1
//black: 2

void dfs(int num){
    if (circle || (status[num] == 2)) return;

    if (status[num] == 1){
        circle = true;
        return;
    }

    status[num] = 1;
    for (int i = 0; i < graph[num].size(); i++)
        dfs(graph[num][i]);
    status[num] = 2;
    ans.push_back(num + 1);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m, a, b;
    circle = false;
    cin >> n >> m;

    status.resize(n);
    for (int i = 0; i < n; i++)
        status[i] = 0;

    graph.resize(n);
    for (int i = 0; i < m; i++){
        cin >> a >> b;
        graph[b - 1].push_back(a - 1);
    }

    for (int i = 0; i < n; i++)
        dfs(i);

    if (circle)
        cout << -1;
    else
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
}
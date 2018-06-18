#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<vector<int>> graph;

bool checkForEulerPath(int n){
    for (int i = 0; i < n; i++)
        if (graph[i].size() % 2 == 1)
            return false;
    return true;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int n, m;
    vector<int> ans;
    stack<int> stack;
    cin >> n >> m;
    graph.resize(n);
    int v1, v2;
    for (int i = 0; i < m; i++) {
        cin >> v1 >> v2;
        graph[v2 - 1].push_back(v1 - 1);
        graph[v1 - 1].push_back(v2 - 1);
    }

    if (not checkForEulerPath(n))
        cout << -1;
    else{
        stack.push(0);
        while (!stack.empty()) {
            int v = stack.top();
            if (graph[v].size() == 0) {
                ans.push_back(v + 1);
                stack.pop();
            }
            else {
                int t;
                t = graph[v][graph[v].size() - 1];
                for (int i = 0; i < graph[t].size(); i++)
                    if (graph[t][i] == v) {
                        swap(graph[t][i], graph[t][graph[t].size() - 1]);
                        graph[t].pop_back();
                        break;
                    }
                graph[v].pop_back();
                stack.push(t);
            }
        }
        for (int i = 0; i < ans.size(); i++)
            cout << ans[i] << ' ';
    }
}
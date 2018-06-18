#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int e, f, n, m;
    cin >> e >> f >> n;
    m = f - e;
    vector<int> cost, weight, minCost;
    int temp;
    cost.push_back(0);
    weight.push_back(0);
    minCost.push_back(0);
    for (int i = 1; i <= n; i++){
        cin >> temp;
        cost.push_back(temp);
        cin >> temp;
        weight.push_back(temp);
    }
    for (int i = 1; i <= m; i++)
        minCost.push_back(INT_MAX);
    for (int i = 0; i <= m; i++){
        for (int j = 1; j <= n; j++){
            if ((weight[j] + i) <= m)
                if ((minCost[i] != INT_MAX) && (minCost[weight[j] + i] > (cost[j] + minCost[i])))
                    minCost[weight[j] + i] = cost[j]+ minCost[i];
        }
    }
    (minCost[minCost.size() - 1] == INT_MAX) ? (cout << -1) : (cout << minCost[m]);
}
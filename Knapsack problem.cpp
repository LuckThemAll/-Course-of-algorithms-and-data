#include <iostream>
#include <vector>

using namespace std;

vector<int> ans, w;
vector<vector<int>> a;

void findAns(int &n, int &maxW){
    int shift = 0;
    for (int i = n - 1; i > 0; i--) {
        if (a[i][maxW - shift] != a[i - 1][maxW - shift]) {
            ans[i] = 1;
            shift += w[i];
        }
    }
    if (a[0][maxW - shift] != 0)
        ans[0] = 1;
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, maxW, temp;
    cin >> n >> maxW;
    a.resize(n);
    ans.resize(n);
    for (int i = 0; i < n; i++)
        a[i].resize(maxW + 1);
    for (int i = 0; i < n; i++) {
        cin >> temp;
        w.push_back(temp);
    }
    for (int k = 0; k < n; k++)
        for (int s = 0; s <= maxW; s++){
            if (k == 0) {
                if (w[k] <= s)
                    a[k][s] = w[k];
            }
            else
                a[k][s] = s >= w[k] ? max(a[k - 1][s], a[k - 1][s - w[k]] + w[k]) : a[k - 1][s];
        }
    if (a[n - 1][maxW] == maxW){
        findAns(n , maxW);
        for (int i = 0; i < n; i++)
            cout << ans[i] << ' ';
    }
    else
        cout << -1;
}
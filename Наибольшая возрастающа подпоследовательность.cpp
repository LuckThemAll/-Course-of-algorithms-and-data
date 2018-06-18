#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, t, length = 0;
    vector<int> d, a, pos, ans, previous;
    cin >> n;
    pos.push_back(-1);
    d.push_back(INT_MIN);
    for (int i = 0; i < n; i++) {
        cin >> t;
        a.push_back(t);
        pos.push_back(-1);
        previous.push_back(-1);
        d.push_back(INT_MAX);
    }
    for (int i = 0; i < n; ++i) {
        int j = int(upper_bound(d.begin(), d.end(), a[i]) - d.begin());
        if (d[j - 1] < a[i] && a[i] < d[j]) {
            d[j] = a[i];
            pos[j] = i;
            previous[i] = pos[j - 1];
            length = max(length, j);
        }
    }
    cout << length << '\n';
    t = pos[length];
    while (t != -1) {
        ans.push_back(t + 1);
        t = previous[t];
    }
    for (int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << ' ';
    }
}
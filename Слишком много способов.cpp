#include <iostream>
#include <vector>

using namespace std;

long long GCD(long long a,long long b) {
    return (b == 0) ? a : GCD(b, a % b);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int x1, y1, z1, x2, y2, z2;

    cin >> x1; cin >> y1; cin >> z1;
    cin >> x2; cin >> y2; cin >> z2;

    int x = abs(x1 - x2);
    int y = abs(y1 - y2);
    int z = abs(z1 - z2);

    vector<long long> c;
    vector<long long> a;

    for (int i = 1; i <= (x + y + z); ++i)
        a.push_back(i);

    for (int i = 1; i <= x; ++i)
        c.push_back(i);

    for (int i = 1; i <= y; ++i)
        c.push_back(i);

    for (int i = 1; i <= z; ++i)
        c.push_back(i);

    long long temp;
    for (int i = 0; i < (x + y + z); ++i) {
        for (int j = 0; j < (x + y + z); ++j) {
            temp = GCD(a[i], c[j]);
            if (temp != 0) {
                a[i] /=  temp;
                c[j] /=  temp;
            }
        }
    }

    long long ans = 1;
    for (int i = 0; i < (x + y + z); ++i)
        ans = (ans * (a[i] % 1000000007)) % 1000000007;

    cout << ans;
}
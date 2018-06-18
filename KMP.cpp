#include <vector>
#include <iostream>
#include <string>

using namespace std;

vector<int> prefixFunction(string &s);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    string a, b, s;
    getline(cin, a); getline(cin, b);
    vector<int> pi;
    s = b + "#" + a;
    pi = prefixFunction(s);
    for (int i = 0; i < a.length(); i++)
        if (pi[b.length() + 1 + i] == b.length()) {
            cout << i + 2 - b.length();
            return 0;
        }
    cout << -1;
}

vector<int> prefixFunction(string &s){
    vector<int> res;
    res.resize(s.length());
    int m;
    for (int i = 1; i < s.length(); i++) {
        m = res[i - 1];
        while (m > 0 && s[i] != s[m])
            m = res[m - 1];
        if (s[i] == s[m])
            m++;
        res[i] = m;
    }
    return res;
}
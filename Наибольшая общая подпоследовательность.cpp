#include <iostream>
#include <cstdio>
#include <vector>

using namespace std;

string GetLCS(string &a, string &b){
    vector<vector<int> > matrixOfLength;
    matrixOfLength.resize(a.size() + 1);
    for (int i = 0; i <= a.size(); i++)
        matrixOfLength[i].resize(b.size() + 1);
    for (int  i = (a.size() - 1); i >= 0; i--){
        for (int j = (b.size() - 1); j >= 0; j--){
            if (a[i] == b[j]){
                matrixOfLength[i][j] = matrixOfLength[i + 1][j + 1] + 1;
            }
            else{
                matrixOfLength[i][j] = max(matrixOfLength[i + 1][j], matrixOfLength[i][j+1]);
            }
        }
    }
    string result;
    for (int i = 0, j = 0; matrixOfLength[i][j] != 0 && i < a.size() && j < b.size(); ){
        if (a[i] == b[j]){
            result.push_back(a[i]);
            i++; j++;
        }
        else{
            if (matrixOfLength[i][j] == matrixOfLength[i + 1][j])
                i++;
            else
                j++;
        }
    }
    return result;
};

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    string a, b;
    cin >> a;
    cin >> b;

    cout << GetLCS(a, b);

}
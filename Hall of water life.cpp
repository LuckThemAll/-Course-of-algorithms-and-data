#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n,m, maxi = 1000000001, temp;
    cin >> n >> m;
    int dist[400][400];
    int a[400];
    for (int i = 0; i < n; i++){
        cin >> temp;
        a[i] = temp;
    }
    for (int i = 1; i <= m; i++){
        dist[0][i] = maxi;
    }
    for (int i = 1; i < n; ++i){
        for (int j = 0; j <= m; j++){
            dist[i][j] = maxi;
            for (int k = 0; k <= min(i-1,j); k++){
                dist[i][j] = min(dist[i][j], max(dist[i-1-k][j-k],a[i]-a[i-1-k]));
            }
        }
    }
    cout << dist[n-1][m];
    return 0;

}
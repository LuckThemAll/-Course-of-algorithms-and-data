#include <iostream>
#include <vector>

using namespace std;

vector<int> a;

void quickSort(int l, int r){
    int x = a[l + (r - l) / 2];
    int i = l;
    int j = r;
    while(i <= j){
        while(a[i] < x) i++;
        while(a[j] > x) j--;
        if(i <= j){
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (i<r) quickSort(i, r);
    if (l<j) quickSort(l, j);
}

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);

    int numCount;
    cin >> numCount;

    int temp;
    for (int i = 0; i < numCount; i++) {
        cin >> temp;
        a.push_back(temp);
    }

    quickSort(0, numCount - 1);

    for (int i = 0; i < numCount; i++)
        cout << a[i] << ' ';
}
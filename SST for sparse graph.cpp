#include <iostream>
#include <vector>

using namespace std;

struct edge {
    int a, b, weigth;
};

struct DSU {
    int root;
};

vector<edge> edges, ans;
bool used[100000];
vector<int> vertices;
vector<DSU> trees;

void makeSet(int a);
void unite(int a, int b);
void quickSort(int l, int r);
int find(int a);

int main() {
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int n, m, cost = 0;
    edge t1;
    cin >> n >> m;
    for (int i = 1; i <= n; i++){
        vertices.push_back(i);
        makeSet(i);
    }

    for (int i = 0; i < m; i++) {
        cin >> t1.a >> t1.b >> t1.weigth;
        edges.push_back(t1);
    }

    quickSort(0, edges.size() - 1);

    for (int i = 0; i < m; i++){
        if (find(edges[i].a) != find(edges[i].b)) {
            ans.push_back(edges[i]);
            unite(edges[i].a, edges[i].b);
        }
    }
    int lengthOfTheSST = 0;
    if ((ans.size() + 1) < n)
        cout << -1;
    else{
        for (int i = 0; i < ans.size(); i++){
            lengthOfTheSST+=ans[i].weigth;
        }
        cout << lengthOfTheSST;
    }

}

void quickSort(int l, int r) {
    int x = edges[l + (r - l) / 2].weigth;
    int i = l;
    int j = r;
    while(i <= j) {
        while(edges[i].weigth < x) i++;
        while(edges[j].weigth > x) j--;
        if(i <= j) {
            swap(edges[i], edges[j]);
            i++;
            j--;
        }
    }
    if (i<r)
        quickSort(i, r);
    if (l<j)
        quickSort(l, j);
}

void makeSet(int a) {
    DSU temp;
    temp.root = a;
    trees.push_back(temp);
};

void unite(int a, int b) {
    a = find(a);
    b = find(b);
    trees[a - 1].root = b;
};

int find(int a) {
    int temp = trees[a - 1].root;
    if (temp == a) {
        return a;
    }
    return trees[a - 1].root = find(trees[a - 1].root);
    return a;
};
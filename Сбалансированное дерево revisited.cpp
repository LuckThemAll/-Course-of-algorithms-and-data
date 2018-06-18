#include <iostream>
#include <vector>

using namespace std;

vector<int>  numbers[1000000];

int getKey(int value) {
    return (value % 9941);
}

int compare(const void * a, const void * b)
{
    return (*(int*)a - *(int*)b);
}

int serchEl(int value, int key) {
    int ans = -1;
    for (int i = 0; i < numbers[key].size(); i++)
        if (numbers[key][i] == value)
            ans = i;
    return ans;
}

void push(int value) {
    int key = getKey(value);
    if (serchEl(value, key) == -1) {
        numbers[key].push_back(value);
    }
}

void deleteEl(int value) {
    int key = getKey(value);
    int a = serchEl(value, key);
    if (a != -1) {
        numbers[key].erase(numbers[key].begin() + a);
    }
}

int main()
{
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    int a = 1;
    while (a != 0)
    {
        cin >> a;
        if (a > 0) {
            push(a);
        }
        else {
            deleteEl(-a);
        }
    }
    vector<int> sorted;
    for (int i = 0; i < 1000000; i++) {
        for (int j = 0; j < numbers[i].size(); j++) {
            sorted.push_back(numbers[i][j]);
        }
    }
    qsort(&sorted[0], sorted.size(), sizeof(int), compare);
    for (int i = 0; i < sorted.size(); i++) {
        cout << sorted[i] << ' ';
    }
    return 0;
}
#include <bits/stdc++.h>

using namespace std;

typedef vector<vector<int>> matrix;

matrix matriz;
int p = 1; // peça

void triminos(int n, int x, int y){
    int cx = x/n * n;
    int cy = y/n * n;
    n >>= 1; // n/=2
    cx += n;
    cy += n;
    bool bx = x & n;
    bool by = y & n;
    matriz[cx-bx][cy-!by] = matriz[cx-bx][cy-by] = matriz[cx-!bx][cy-by] = ++p;
    if(n >= 2) {
        triminos(n, x, y);
        triminos(n, cx-bx, cy-!by);
        triminos(n, cx-bx, cy-by);
        triminos(n, cx-!bx, cy-by);
    }
}

void printMatriz(int n){
    int t = log10(n*n-1/3);
    for(int y = 0; y < n; y++) {
        cout << "\b\n";
        for(int x = 0; x < n; x++) {
            cout << matriz[x][y] << "\t";
        }
        cout << "\n\n";
    }
}

int main() {
    int n, x, y;
    cin >> n >> x >> y;
    matriz = matrix(n, vector<int>(n, 0));
    matriz[x][y] = p;
    triminos(n, x, y);

    printMatriz(n);

    return 0;
}
#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef vector<ll> vll;

int main() {
    int n;
    cin >> n;
    vll v = {0, 0};
    bool b = 0;
    ll k = 1;
    for(int i = 0; i < n; ++i){
        bool in;
        cin >> in;
        if(in){
            v[b] += k;
            k = 0;
            b = !b;
        }
        k++;
    }
    v[b] += k;
    cout << v[0] * v[1] << '\n';
    return 0;
}
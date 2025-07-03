#include <bits/stdc++.h>

using namespace std;

void solve(){
    int n;
    cin >> n;
    int a[n+1];
    for(int i = 0; i < n; i++){
        cin >> a[i];
    }
    a[n] = 0;
    int best = a[n-1];
    for(int i = n-2; i >= 0; i--){
        a[i] += a[min(i + a[i], n)];
        best = max(best, a[i]);
    }
    cout << best << "\n";
}

int main(){
    ios_base::sync_with_stdio(0);
	cin.tie(0);
	int t = 1;
	cin >> t;
    for(int c = 1; c <= t; c++){
        solve();
    }
    return 0;
}
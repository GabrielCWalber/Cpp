/*
  Competitive Programming Problem: Odd-Parity Subsequences
  
  Given a binary string, count how many contiguous subsequences contain an 
  odd number of 1s.
  
  Solution:
  - Convert binary string into gaps between 1s (including before first and 
    after last 1)
  - Each odd-parity subsequence spans from one gap at an even position to 
    another at an odd position
  - Total count = (sum of even-position gaps) × (sum of odd-position gaps)
  - Uses distributive property to avoid O(n²) pairwise multiplications
  
  Personal favorite - elegant mathematical solution.
  
  Time complexity: O(n)
  Space complexity: O(1)
*/

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

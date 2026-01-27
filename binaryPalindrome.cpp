/*
  Competitive Programming Problem: Largest Binary Palindrome
  
  Given a number x, find the largest number ≤ x whose binary representation 
  is a palindrome.
  
  Approach:
  - First attempt: mirror the left half of x's bits to the right half
  - If result > x: reduce to the previous binary palindrome by decrementing
    the middle section and mirroring again
  
  Time complexity: O(log x)
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll x, y;
    cin >> x;

    y = x;
    int b = 0;
    while(y > 0){
        b++;
        y >>= 1;
    }
    y = x;
    
    bitset<100> a(y);
    for(int i = 0; i < (b>>1); ++i) {
        a[i] = a[b-1-i];
    }
    y = a.to_ullong();

    if(y <= x){
        cout << y << '\n';
        return 0;
    }
    
    y = x -(1<<(b>>1));
    a = y;

    if((y & (1<<b-1)) == 0){
        y = (1<<b-1)-1;

        cout << y << '\n';
        return 0;
    }

    for(int i = 0; i < (b>>1); ++i) {
        a[i] = a[b-1-i];
    }
    y = a.to_ullong();

    cout << y << '\n';
    return 0;

}

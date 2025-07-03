#include <bits/stdc++.h>
using namespace std;

#define vs vector<string>

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    const bool sortV = false;
    const bool check = true;

    vs a = {"element0", "element1"};

    vs b = {"element1", "element2"};
    
    vs ab;

    if(sortV) {
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
    } else if(check) {
        for (int i = 1; i < a.size(); ++i){
            if(a[i-1] >= a[i]) {
                cout << "Error in a: \"" << a[i-1] << "\" >= \"" << a[i] << "\"\n";
                return 1;
            }
        }
        for (int i = 1; i < b.size(); ++i){
            if(b[i-1] >= b[i]) {
                cout << "Error in b: \"" << b[i-1] << "\" >= \"" << b[i] << "\"\n";
                return 1;
            }
        }
    }

    int i = 0;
    int j = 0;

    while(i < a.size() && j < b.size()) {
        if(a[i] == b[j]) {
            ab.push_back(a[i]);
            ++i;
            ++j;
        } else {
            bool o = a[i] < b[j];
            i += o;
            j += !o;
        }
    }

    if(ab.empty()) {
        cout << "\n∅\n\n";
        return 0;
    }

    cout << "\n{\"" << ab[0];
    for(int i = 1; i < ab.size(); ++i) {
        cout << "\", \"" << ab[i];
    }
    cout << "\"}\n\n";

    return 0;
}
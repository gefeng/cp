#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    string S;
    string T;
    cin >> S >> T;

    int n = S.size();
    int m = T.size();
    if(S[0] == T[0]) {
        cout << "YES" << '\n';
        cout << S.substr(0, 1) + "*" << '\n';
        return;
    }

    if(S[n - 1] == T[m - 1]) {
        cout << "YES" << '\n';
        cout << "*" + S.substr(n - 1, 1) << '\n';
        return;
    }

    for(int i = 0; i < n - 1; i++) {
        string s = S.substr(i, 2);
        
        if(T.find(s) != string::npos) {
            cout << "YES" << '\n';
            cout << "*" + s + "*" << '\n';
            return;
        }
    }

    cout << "NO" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}

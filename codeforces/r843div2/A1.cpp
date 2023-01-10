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
    cin >> S;

    int n = S.length();
    int j = -1;
    for(int i = 1; i < n - 1; i++) {
        if(S[i] == 'a') {
            j = i; 
            break;
        }
    }

    if(j == -1) {
        cout << S.substr(0, 1) << ' ' << S.substr(1, n - 2) << ' ' << S.substr(n - 1, 1) << '\n';
    } else {
        cout << S.substr(0, j) << ' ' << S.substr(j, 1) << ' ' << S.substr(j + 1, n - j - 1) << '\n';
    }
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

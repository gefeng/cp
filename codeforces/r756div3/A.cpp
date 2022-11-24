#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    if(N % 2 == 0) {
        cout << 0 << '\n';
        return;
    }

    string s = to_string(N);
    int n = s.length();
    if((s[0] - '0') % 2 == 0) {
        cout << 1 << '\n';
        return;
    }

    for(int i = 0; i < n; i++) {
        if((s[i] - '0') % 2 == 0) {
            cout << 2 << '\n';
            return;
        }        
    }

    cout << -1 << '\n';
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

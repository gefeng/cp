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

    string S;
    cin >> S;

    bool has_r = false;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'R') {
            has_r = true;
        } else {
            if(has_r) {
                cout << 0 << '\n';
                return;
            }
        }
    }

    for(int i = 0; i < N - 1; i++) {
        if(S[i] == 'L' && S[i + 1] == 'R') {
            cout << i + 1 << '\n';
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

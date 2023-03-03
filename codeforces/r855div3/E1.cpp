#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;

    string S, T;
    cin >> S >> T;

    string s = S;
    string t = T;
    sort(s.begin(), s.end());
    sort(t.begin(), t.end());
    if(s != t) {
        cout << "NO" << '\n';
        return;
    }

    for(int i = 0; i < N; i++) {
        if(S[i] == T[i]) {
            continue;
        }

        if(i + K >= N && i - K < 0) {
            cout << "NO" << '\n';
            return;
        }
    }

    cout << "YES" << '\n';
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

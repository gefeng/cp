#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int M, S;
    cin >> M >> S;

    vector<int> B(M);
    for(int i = 0; i < M; i++) {
        cin >> B[i];
    }

    sort(B.begin(), B.end());
    
    int cur = 1;
    for(int i = 0; i < M; i++) {
        while(cur != B[i]) {
            S -= cur;
            cur += 1;
        }
        cur += 1;
    }

    while(S > 0) {
        S -= cur;
        cur += 1;
    }

    cout << (S == 0 ? "YES" : "NO") << '\n';
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

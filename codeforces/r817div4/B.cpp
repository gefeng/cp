#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    array<string, 2> A;
    cin >> A[0] >> A[1];

    bool ans = true;
    for(int i = 0; i < N; i++) {
        if((A[0][i] == 'R' || A[1][i] == 'R') && (A[0][i] != A[1][i])) {
            ans = false;
            break;
        }
    }

    cout << (ans ? "YES" : "NO") << '\n';
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

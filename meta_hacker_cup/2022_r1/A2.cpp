#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void run_case(int T) {
    int N, K;
    cin >> N >> K;

    vector<int> A(2 * N, 0);
    vector<int> B(N, 0);
    unordered_set<int> unique;
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i + N] = A[i];
        unique.insert(A[i]); 
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    bool ok = true;
    vector<int> dp(N, 0);
    for(int i = 0, j = 1; j < N; j++) {
        if(B[i] == B[j]) {
            dp[j] = ++i;
        } else {
            if(i > 0) {
                i = dp[i - 1];
                j--;
            }
        }
    }

    int d = -1;
    for(int i = 0, j = 0; i < 2 * N; i++) {
        if(A[i] == B[j]) {
            j++;
            if(j == N) {
                d = i - j + 1;
                break;
            }
        } else {
            if(j > 0) {
                j = dp[j - 1];
                i--;
            }
        }
    }

    ok = d != -1;

    if(ok) {
        if(unique.size() > 1) {
            if(N == 2) {
                ok = d % 2 == K % 2;
            } else {
                if(d == 0) {
                    ok = K != 1;
                } else {
                    ok = K > 0;
                } 
            }
        }
    }

    cout << "Case #" << T << ": " << (ok ? "YES" : "NO") << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}

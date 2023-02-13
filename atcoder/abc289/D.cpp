#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int M;
    cin >> M;
    set<int> T;
    for(int i = 0; i < M; i++) {
        int P;
        cin >> P;
        T.insert(P);
    }

    int X;
    cin >> X;

    vector<bool> dp(X + 1, false);
    dp[0] = true;
    for(int i = 1; i <= X; i++) {
        for(int j = 0; j < N; j++) {
            if(i - A[j] >= 0 && T.find(i) == T.end() && dp[i - A[j]]) {
                dp[i] = true; 
            }
        }
    }

    cout << (dp[X] ? "Yes" : "No") << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

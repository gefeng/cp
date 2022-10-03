#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using LL = long long;

LL to_key(vector<int>& c) {
    LL k = 0LL;
    for(int x : c) {
        k = (k << 2) | x;
    }
    return k;
}

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<vector<int>> A(N, vector<int>(K, 0));
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < K; j++) {
            cin >> A[i][j];
        }
    }

    unordered_map<LL, int> cnt;
    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            vector<int> c(K, 0);
            for(int k = 0; k < K; k++) {
                if(A[i][k] == A[j][k]) {
                    c[k] = A[i][k];         
                } else {
                    c[k] = 3 - A[i][k] - A[j][k];
                }
            }
            cnt[to_key(c)]++;
        }
    }

    LL ans = 0LL;
    for(vector<int>& c : A) {
        LL key = to_key(c);
        if(cnt.find(key) != cnt.end()) {
            int f = cnt[key];
            ans += f * (f - 1) / 2;
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}

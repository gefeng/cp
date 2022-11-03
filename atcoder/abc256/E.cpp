#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;
using LL = long long;

int dfs(vector<int>& A, vector<int>& state, int cur) {
    if(state[cur] == 1) {
        return cur;
    }
    if(state[cur] == 2) {
        return -1;
    }

    state[cur] = 1;

    int res = dfs(A, state, A[cur]); 

    state[cur] = 2;
    return res;
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    vector<int> B(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
        A[i] -= 1;
    }

    for(int i = 0; i < N; i++) {
        cin >> B[i];
    }

    LL ans = 0LL;
    vector<int> state(N, 0);
    for(int i = 0; i < N; i++) {
        if(state[i] == 0) {
            int res = dfs(A, state, i);
            if(res != -1) {
                int min_v = (int)1e9;
                for(int j = res; ; ) {
                    min_v = min(min_v, B[j]);
                    j = A[j];
                    if(j == res) {
                        break;
                    }
                }
                ans += min_v;
            }
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

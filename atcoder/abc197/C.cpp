#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

int ans = (int)2e9;

void dfs(vector<int>& A, int cur, int sum_or, int sum_xor) {
    if(cur == A.size()) {
        if(sum_or != -1) {
            ans = min(ans, sum_xor ^ sum_or);
        } else {
            ans = min(ans, sum_xor);
        }
        return;
    }

    if(sum_or == -1) {
        dfs(A, cur + 1, A[cur], sum_xor);
    } else {
        dfs(A, cur + 1, sum_or | A[cur], sum_xor); 
        dfs(A, cur + 1, A[cur], sum_xor ^ sum_or);
    }
}

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    dfs(A, 0, -1, 0); 

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

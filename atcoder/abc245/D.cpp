#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;

    vector<int> A(N + 1, 0);
    vector<int> C(M + N + 1, 0);
    
    for(int i = 0; i < N + 1; i++) {
        cin >> A[i];
    }

    for(int i = 0; i < M + N + 1; i++) {
        cin >> C[i];
    }

    vector<int> ans;
    for(int i = M + N; i >= 0; i--) {
        int x = C[i] / A[N];
        ans.push_back(x);
        for(int j = N, k = i; j >= 0; j--, k--) {
            C[k] -= x * A[j]; 
        }
    }
   
    reverse(ans.begin(), ans.begin() + M + 1);
    for(int i = 0; i < M + 1; i++) {
        cout << ans[i] << " \n"[i == M];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

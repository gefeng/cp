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
    
    vector<string> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<string> ans(K);
    for(int i = 0; i < K; i++) {
        ans[i] = A[i];
    }

    sort(ans.begin(), ans.end());

    for(int i = 0; i < K; i++) {
        cout << ans[i] << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

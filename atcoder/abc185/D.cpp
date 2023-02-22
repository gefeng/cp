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

    vector<int> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int pre = 1;
    int k = N;
    for(int i = 0; i < M; i++) {
        int len = A[i] - pre;
        if(len > 0) {
            k = min(k, len);
        }
        pre = A[i] + 1;
    } 

    if(N + 1 - pre > 0) {
        k = min(k, N + 1 - pre);
    }

    int ans = 0;
    pre = 1;
    for(int i = 0; i < M; i++) {
        int len = A[i] - pre; 

        ans += (len + k - 1) / k;

        pre = A[i] + 1;
    }

    if(N + 1 - pre > 0) {
        ans += (N + 1 - pre + k - 1) / k;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

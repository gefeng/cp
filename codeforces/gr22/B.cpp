#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case() {
    int N, K;
    cin >> N >> K;
    
    vector<LL> A(K, 0);
    for(int i = 0; i < K; i++) {
        cin >> A[i];
    }

    LL pre = 0;
    int pre_len = N - K + 1;
    if(pre_len == 1) {
        pre = A[0];
    } else {
        if(A[0] < 0) {
            pre = A[0] / pre_len;
        } else {
            pre = A[0] / pre_len + (A[0] % pre_len == 0 ? 0 : 1);
        }
    }

    for(int i = 1; i < K; i++) {
        LL cur = A[i] - A[i - 1];
        if(cur < pre) {
            cout << "NO" << '\n';
            return;
        }

        pre = cur;
    }

    cout << "YES" << '\n';
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

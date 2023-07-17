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
    int N, M, K;
    cin >> N >> M >> K;

    vector<int> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i];
    }
    
    if(K > M) {
        cout << "NO" << '\n';
        return;
    }

    LL sum = 0LL;
    LL max_f = 0LL;
    for(int i = 0; i < M; i++) {
        sum += A[i]; 
        max_f = max(max_f, (LL)A[i]);
    }

    if((max_f - 1LL) * (K - 1) > sum - max_f) {
        cout << "NO" << '\n';
    } else {
        cout << "YES" << '\n';
    }
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

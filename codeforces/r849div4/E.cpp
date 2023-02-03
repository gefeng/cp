#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int INF = 2e9;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int cnt = 0;
    for(int i = 0; i < N; i++) {
        if(A[i] < 0) {
            cnt += 1;
        }
    }

    LL ans = 0LL;
    for(int i = 0; i < N; i++) {
        ans += abs(A[i]); 
    }

    if(cnt & 1) {
        int min_v = INF;
        for(int i = 0; i < N; i++) {
            min_v = min(min_v, abs(A[i])); 
        }
        ans -= 2 * min_v;
    }
    
    cout << ans << '\n';
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

#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    int max_v = 1LL;
    while(max_v <= N) {
        max_v *= 2;
    }

    LL ans =(1LL + N) * N / 2LL; 

    vector<int> cnt(max_v + 1, 0); 
    cnt[0] = 1;
    int sum = 0;
    for(int i = 0; i < N; i++) {
        sum ^= A[i]; 
        for(int f = 0; f * f <= max_v; f++) {
            if((sum ^ (f * f)) <= max_v) {
                ans -= cnt[sum ^ (f * f)];
            }
        }
        cnt[sum] += 1;
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

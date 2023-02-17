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
    LL N;
    cin >> N;

    vector<LL> fact;
    for(LL f = 2; f * f <= N; f++) {
        while(N % f == 0LL) {
            fact.push_back(f);
            N /= f;
        }
    }
    if(N > 1LL) {
        fact.push_back(N);
    }

    LL ans = 0LL;
    int n = fact.size();
    vector<LL> group(n, 1LL);
    for(int i = 0; i < n; ) {
        int j = i;
        while(i < n && fact[i] == fact[j]) {
            i += 1;
        }

        for(int k = 0; k < i - j; k++) {
            group[k] *= fact[j + k];
        }
    } 

    for(int i = 0; i < n; i++) {
        if(group[i] != 1LL) {
            ans += group[i];
        }
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

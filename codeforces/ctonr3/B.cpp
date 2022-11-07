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
    int N;
    cin >> N;
    
    string S;
    cin >> S;

    LL cnt = 0LL;
    for(int i = 0; i < N; i++) {
        cnt += S[i] - '0'; 
    }

    LL ans = cnt * (1LL * N - cnt);

    for(int i = 0; i < N; ) {
        int j = i;
        while(i < N && S[i] == S[j]) {
            i += 1;
        }

        ans = max(ans, 1LL * (i - j) * (i - j));
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

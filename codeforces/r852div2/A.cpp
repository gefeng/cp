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
    LL A, B, N, M;
    cin >> A >> B >> N >> M;
    
    LL ans = B * N;
    LL buy = N / (M + 1LL) * M;
    LL left = N - buy - N / (M + 1LL);
    ans = min(ans, A * buy + A * left);
    ans = min(ans, A * buy + B * left);
 
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

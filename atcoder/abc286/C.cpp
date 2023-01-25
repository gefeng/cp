#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL INF = (LL)2e18;

string rotate(string s, int x) {
    string t = s.substr(x) + s.substr(0, x);
    return t;
}

void run_case() {
    int N, A, B;
    cin >> N >> A >> B;

    string S;
    cin >> S;

    LL ans = INF;
    for(int i = 0; i < N; i++) {
        string t = rotate(S, i);

        LL sum = 1LL * A * i;
        for(int l = 0, r = N - 1; l < r; l++, r--) {
            if(t[l] != t[r]) {
                sum += B;
            }
        }

        ans = min(ans, sum);
    }

    cout << ans << '\n';    
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

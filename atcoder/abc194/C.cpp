#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0LL;
    for(int d = 0; d <= 400; d++) {
        LL cnt = 0LL;
        vector<int> v(405, 0);
        
        //cur - pre = d
        //cur - pre = -d
        for(int i = 0; i < N; i++) {
            int x = A[i] - d + 200;
            int y = A[i] + d + 200;
            if(x >= 0 && x <= 400) {
                cnt += v[x];
            }
            if(y >= 0 && y <= 400) {
                cnt += v[y];
            }
            v[A[i] + 200] += 1;
        }

        ans += cnt * d * d;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

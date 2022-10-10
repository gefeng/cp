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
    
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    LL ans = 0LL;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int can = min(i + 1, A[i]);
        if(can > cnt) {
            cnt++;
        } else {
            cnt = can;
        }
        ans += cnt;
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

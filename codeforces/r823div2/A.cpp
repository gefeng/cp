#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, C;
    cin >> N >> C;

    array<int, 101> cnt{0}; 
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        cnt[X]++;
    }

    int ans = 0;
    for(int i = 0; i <= 100; i++) {
        if(cnt[i]) {
            ans += cnt[i] > C ? C : cnt[i];
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

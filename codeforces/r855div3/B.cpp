#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, K;
    cin >> N >> K;
    
    string S;
    cin >> S;

    array<int, 26> cnt1{0};
    array<int, 26> cnt2{0};
    for(char c : S) {
        if(c >= 'A' && c <= 'Z') {
            cnt2[c - 'A'] += 1;
        } else {
            cnt1[c - 'a'] += 1;
        }
    }

    int ans = 0;
    for(int i = 0; i < 26; i++) {
        int d = min(cnt1[i], cnt2[i]);         
        cnt1[i] -= d;
        cnt2[i] -= d;
        ans += d;
    }

    for(int i = 0; i < 26; i++) {
        int d = min(K, max(cnt1[i] / 2, cnt2[i] / 2));
        K -= d;
        ans += d;
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

#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = static_cast<int>(2e9);

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int cnt_a = 0;
    int cnt_b = 0;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') {
            cnt_a += 1;
        } else {
            cnt_b += 1;
        }
    }

    if(cnt_a == cnt_b) {
        std::cout << 0 << '\n';
        return;
    }
    
    std::vector<int> a(N);
    if(cnt_a > cnt_b) {
        for(int i = 0; i < N; i++) {
            a[i] = S[i] == 'a' ? 1 : -1;
        }
    } else {
        for(int i = 0; i < N; i++) {
            a[i] = S[i] == 'b' ? 1 : -1;
        }
    }

    std::map<int, int> m;
    m[0] = -1;
    
    int ans = INF;
    int sum = 0;
    int t = std::abs(cnt_a - cnt_b);
    for(int i = 0; i < N; i++) {
        sum += a[i]; 
        if(m.find(sum - t) != m.end()) {
            ans = std::min(ans, i - m[sum - t]);
        }
        m[sum] = i;
    }

    std::cout << (ans == N ? -1 : ans) << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    int T;
    std::cin >> T;
    while(T--) {
        run_case();
    }
}

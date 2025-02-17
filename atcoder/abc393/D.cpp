#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;

    int tot = 0;
    std::queue<int> q;
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            tot += 1;
            q.push(i);
        }
    }

    if(tot == 1) {
        std::cout << 0 << '\n';
        return;
    }

    int64_t ans = 0;
    for(int i = 0, j = 0; i < N; i++) {
        if(S[i] == '1') {
            ans += i - j;
            j += 1;
        } 
    }

    int64_t sum = ans;
    for(int l = 1, r = 1; r < N; r++) {
        if(r - l + 1 > tot) {
            l += 1;
        }
        if(r - l + 1 == tot) {
            while(!q.empty() && tot - q.size() + l > q.front()) {
                q.pop();
            }
            sum -= q.size();
            sum += tot - q.size();
            ans = std::min(ans, sum);
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

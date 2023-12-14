#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::string S;
    std::cin >> S;

    int lo = 0;
    int hi = N;
    int ans = 0;
    while(lo <= hi) {
        int mid = (lo + hi) >> 1;

        int x = M;
        int y = mid;
        bool ok = true;
        for(int i = 0; i < N; i++) {
            if(S[i] == '0') {
                x = M;
                y = mid;
            } else if(S[i] == '1') {
                if(x) {
                    x -= 1;
                } else if(y) {
                    y -= 1;
                } else {
                    ok = false;
                    break;
                }
            } else {
                if(y == 0) {
                    ok = false;
                    break;
                }
                y -= 1;
            }
        }

        if(ok) {
            ans = mid;
            hi = mid - 1;
        } else {
            lo = mid + 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

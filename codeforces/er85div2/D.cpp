#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int64_t N, L, R;
    std::cin >> N >> L >> R;

    if(L == N * (N - 1) + 1) {
        std::cout << 1 << '\n';
        return;
    }
    
    int64_t now = 0;
    int p = 0;
    int offset = 0;
    for(int64_t i = N - 1; i >= 1; i--) {
        if(L > now + i * 2) {
            now += i * 2;
            continue;
        }
        p = N - i;
        offset = L - now - 1;
        break;
    }

    std::vector<int> seg;
    for(int i = 0, j = p + 1; i < (N - p) * 2; i += 2, j++) {
        seg.push_back(p);
        seg.push_back(j);
    }

    std::vector<int> ans;
    int64_t len = R - L + 1;
    for(int i = offset; i < seg.size(); i++) {
        if(ans.size() != len) {
            ans.push_back(seg[i]);
        } else {
            break;
        }
    }

    while(ans.size() != len && p + 1 != N) {
        p += 1;
        for(int i = 0, j = p + 1; i < (N - p) * 2; i += 2, j++) {
            if(ans.size() != len) {
                ans.push_back(p);
            } else {
                break;
            }
            if(ans.size() != len) {
                ans.push_back(j);
            } else {
                break;
            }
        }
    } 

    if(ans.size() != len) {
        ans.push_back(1);
    }

    for(int i = 0; i < len; i++) {
        std::cout << ans[i] << " \n"[i == len - 1];
    }
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

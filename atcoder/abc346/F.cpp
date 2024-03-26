#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int64_t MAX = (int64_t)3e18;

void run_case() {
    int64_t N;
    std::cin >> N;

    std::string S, T;
    std::cin >> S >> T;
    
    std::array<int, 26> f = {};
    int n = S.size();
    int m = T.size();
    std::vector<std::array<int, 26>> cnt(n);
    std::vector<std::map<int, int>> p(26);
    for(int i = n - 1; i >= 0; i--) {
        f[S[i] - 'a'] += 1;
        if(i < n - 1) {
            for(int j = 0; j < 26; j++) {
                cnt[i][j] = cnt[i + 1][j];
            }
        }

        cnt[i][S[i] - 'a'] += 1;
    }

    for(int c = 0; c < 26; c++) {
        int x = 0;
        for(int i = 0; i < n; i++) {
            if(S[i] - 'a' == c) {
                x += 1;
                p[c][x] = i;
            }
        }
    }

    auto is_ok = [&](int64_t k) {
        int64_t seg = 0;
        int pos = -1;
        for(int i = 0; i < m; i++) {
            int c = T[i] - 'a';
            int x = f[c];

            if(x == 0) {
                return false;
            }              

            pos += 1;
            if(pos == n) {
                if(++seg >= N) {
                    return false;
                }
                pos = 0;
            }

            int left = cnt[pos][c];
            if(k <= left) {
                pos = p[c][cnt[0][c] - (left - k)];  
            } else {
                if(++seg >= N) {
                    return false;
                }
                
                int64_t d = (k - left) / cnt[0][c] - 1;
                int64_t r = (k - left) % cnt[0][c];

                if(r) {
                    d += 1;
                }

                if(d + seg >= N) {
                    return false;
                }

                seg += d;
                pos = p[c][r == 0 ? x : r];
            }
        } 

        return true;
    };

    int64_t lo = 1;
    int64_t hi = MAX;
    int64_t ans = 0;
    while(lo <= hi) {
        int64_t mid = (lo + hi) >> 1;

        if(is_ok(mid)) {
            ans = mid;
            lo = mid + 1;
        } else {
            hi = mid - 1;
        }
    }

    std::cout << ans << '\n';
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N;
    std::cin >> N;
    
    auto query = [&](int t, int i, int j, int x) {
        std::cout << "? " << t << ' ' << i + 1 << ' ' << j + 1 << ' ' << x << std::endl;
        int Q;
        std::cin >> Q;
        return Q;
    };

    int p = -1;
    for(int i = 0; i < N; ) {
        if(i + 1 < N) {
            int res = query(1, i, i + 1, N - 1);
            if(res < N - 1) {
                i += 2;
            } else {
                if(res == N) {
                    p = i + 1;
                    break;
                }

                if(i == 0) {
                    res = query(1, i + 2, i, N - 1);
                    if(res == N) {
                        p = i;
                        break;
                    }
                } else {
                    res = query(1, 0, i, N - 1);
                    if(res == N) {
                        p = i;
                        break;
                    }
                }
                i += 2;
            }
        } else {
            p = N - 1;
            i += 1;
        }
    }

    assert(p != -1);
    
    std::vector<int> ans(N);
    ans[p] = N;
    for(int i = 0; i < N; i++) {
        if(i != p) {
            ans[i] = query(2, i, p, 1);
        }
    }

    std::cout << "! ";
    for(int i = 0; i < N; i++) {
        std::cout << ans[i] << ' ';
    }
    std::cout << std::endl;
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

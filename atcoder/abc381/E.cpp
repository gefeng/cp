#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    int N, Q;
    std::cin >> N >> Q;
    
    std::string S;
    std::cin >> S;

    std::vector<int> pos_1;
    std::vector<int> pos_2;
    std::vector<int> pos_3;
    
    for(int i = 0; i < N; i++) {
        if(S[i] == '1') {
            pos_1.push_back(i);
        } else if(S[i] == '2') {
            pos_2.push_back(i);
        } else {
            pos_3.push_back(i);
        }
    }

    auto validate = [&](int L, int R) {
        int res = 0;
        int lo = 1;
        int hi = (R - L + 1) / 2;
        while(lo <= hi) {
            int mid = (lo + hi) >> 1;

            bool ok = false;
            auto it_1 = std::lower_bound(pos_1.begin(), pos_1.end(), L);
            auto it_2 = std::upper_bound(pos_1.begin(), pos_1.end(), R); 
            if(it_1 != pos_1.end() && it_2 != pos_1.begin()) {
                it_2--;
                int l = it_1 - pos_1.begin();
                int r = it_2 - pos_1.begin();
                if(l <= r && l + mid - 1 <= r) {
                    int p_1 = pos_1[l + mid - 1];
                    auto it = std::upper_bound(pos_3.begin(), pos_3.end(), p_1);
                    if(it != pos_3.end() && *it <= R) {
                        int p_3 = *it; 
                        it_1 = std::lower_bound(pos_2.begin(), pos_2.end(), p_3);
                        it_2 = std::upper_bound(pos_2.begin(), pos_2.end(), R);
                        int len = int(it_2 - pos_2.begin()) - int(it_1 - pos_2.begin());
                        if(it_1 != pos_2.end() && *it_1 <= R && len >= mid) {
                            ok = true; 
                        }
                    }
                }
            }

            if(ok) {
                res = mid * 2 + 1;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }

        if(res == 0) {
            auto it = std::lower_bound(pos_3.begin(), pos_3.end(), L);
            if(it != pos_3.end() && *it <= R) {
                res = 1;
            }
        }
        
        return res;
    };

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;

        int res = validate(L, R);

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

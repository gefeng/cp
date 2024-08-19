#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

constexpr int INF = int(2e9);

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<std::string> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    std::map<std::string, std::vector<int>> m;
    for(int i = 0; i < N; i++) {
        m[A[i]].push_back(i);
    } 
    
    std::array<std::string, 6> all = {"BG", "BR", "BY", "GR", "GY", "RY"};

    auto is_good = [](std::string& s1, std::string& s2) {
        for(int i = 0; i < 2; i++) {
            for(int j = 0; j < 2; j++) {
                if(s1[i] == s2[j]) {
                    return true;
                }
            }
        } 
        return false;
    };

    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        if(L > R) {
            std::swap(L, R);
        }

        std::string s1 = A[L];
        std::string s2 = A[R];
        
        int res = INF;
        if(is_good(s1, s2)) {
            res = R - L;
        } else {
            for(std::string t : all) {
                if(is_good(s1, t) && is_good(s2, t)) {
                    std::vector<int>& pos = m[t]; 
                    auto it = std::upper_bound(pos.begin(), pos.end(), L);
                    
                    if(it != pos.end()) {
                        int p = *it;
                        if(p < R) {
                            res = R - L;
                            break;
                        }
                        
                        res = std::min(res, (p - R) * 2 + R - L);
                    }

                    if(it != pos.begin()) {
                        auto pre = std::prev(it);
                        int p = *pre;
                        res = std::min(res, (L - p) * 2 + R - L);
                    }
                }
            } 
        }
        std::cout << (res == INF ? -1 : res) << '\n';
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

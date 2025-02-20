#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

void run_case() {
    std::string S;
    std::cin >> S;

    int A, B, AB, BA;
    std::cin >> A >> B >> AB >> BA;

    int n = S.size();
    
    if(n == 1) {
        if(S[0] == 'A' && A) {
            std::cout << "Yes" << '\n';
            return;
        }
        if(S[0] == 'B' && B) {
            std::cout << "Yes" << '\n';
            return;
        }
        std::cout << "No" << '\n';
        return;
    }

    std::vector<std::pair<int, int>> seg_ab;
    std::vector<std::pair<int, int>> seg_ba;
    std::vector<std::pair<int, int>> seg;
    int pre = 0;
    for(int i = 1; i < n; i++) {
        if(S[i] == S[i - 1]) {
            if(pre == i - 1) {
                if(S[i - 1] == 'A') {
                    if(--A < 0) {
                        std::cout << "No" << '\n';
                        return;
                    }
                } else {
                    if(--B < 0) {
                        std::cout << "No" << '\n';
                        return;
                    }
                }
            } else {
                if((i - pre) % 2 == 0) {
                    if(S[pre] == 'A') {
                        seg_ab.emplace_back(pre, i - 1);
                    } else {
                        seg_ba.emplace_back(pre, i - 1);
                    }
                } else {
                    seg.emplace_back(pre, i - 1);
                }
            }
            pre = i;
        } 
    }

    if(pre == n - 1) {
        if(S[n - 1] == 'A') {
            if(--A < 0) {
                std::cout << "No" << '\n';
                return;
            }
        } else {
            if(--B < 0) {
                std::cout << "No" << '\n';
                return;
            }
        }
    } else {
        if((n - pre) % 2 == 0) {
            if(S[pre] == 'A') {
                seg_ab.emplace_back(pre, n - 1);
            } else {
                seg_ba.emplace_back(pre, n - 1);
            }
        } else {
            seg.emplace_back(pre, n - 1);
        }
    }

    auto cmp = [](const auto& x, const auto& y) {
        return x.second - x.first > y.second - y.first;
    };

    std::sort(seg_ab.begin(), seg_ab.end(), cmp);
    std::sort(seg_ba.begin(), seg_ba.end(), cmp);
    
    while(!seg_ab.empty()) {
        auto [l, r] = seg_ab.back();
        seg_ab.pop_back();
        if((r - l + 1) / 2 > AB) {
            seg.emplace_back(l, r - AB * 2); 
            AB = 0;
        } else {
            AB -= (r - l + 1) / 2;
        }
    }
    
    while(!seg_ba.empty()) {
        auto [l, r] = seg_ba.back();
        seg_ba.pop_back();
        if((r - l + 1) / 2 > BA) {
            seg.emplace_back(l, r - BA * 2); 
            BA = 0;
        } else {
            BA -= (r - l + 1) / 2;
        }
    }

    int sum = AB + BA;
    for(auto [l, r] : seg) {
        if((r - l + 1) % 2 == 1) {
            int have = (r - l) / 2;
            int x = std::min(sum, have);
            sum -= x;
            have -= x;
            
            int a = have + (S[l] == 'A' ? 1 : 0);
            int b = have + (S[l] == 'B' ? 1 : 0);
            
            A -= a;
            B -= b;
            
            if(A < 0 || B < 0) {
                std::cout << "No" << '\n';
                return;
            }
        } else {
            int have = (r - l - 1) / 2;
            int x = std::min(sum, have);
            sum -= x;
            have -= x;
            
            int a = have + 1;
            int b = have + 1;
            A -= a;
            B -= b;
            
            if(A < 0 || B < 0) {
                std::cout << "No" << '\n';
                return;
            }
        }
    }

    std::cout << "Yes" << '\n';
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

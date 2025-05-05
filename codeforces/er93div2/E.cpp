#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

void run_case() {
    int N;
    std::cin >> N;
    
    int cnt_l = 0;
    int64_t sum_dup = 0;
    int64_t sum_single = 0;
    std::set<int> dup;
    std::set<int> single;
    std::set<int> l;

    auto add_to_dup = [&](int x) {
        sum_dup += x;
        dup.insert(x);
    };

    auto add_to_single = [&](int x) {
        sum_single += x;
        single.insert(x);
    };

    auto remove_from_dup = [&]() {
        int x = *dup.begin();
        dup.erase(x);
        sum_dup -= x;
    };

    auto remove_from_dup_x = [&](int x) {
        dup.erase(x);
        sum_dup -= x;
    };

    auto remove_from_single = [&]() {
        int x = *single.rbegin();
        single.erase(x);  
        sum_single -= x;
    };

    auto remove_from_single_x = [&](int x) {
        single.erase(x);  
        sum_single -= x;
    };
    
    for(int i = 0; i < N; i++) {
        int T, X;
        std::cin >> T >> X;

        if(T == 0) {
            if(X < 0) {
                X *= -1;
                if(dup.find(X) != dup.end()) {
                    remove_from_dup_x(X);
                } else {
                    remove_from_single_x(X);
                }
            } else {
                if(dup.size() < cnt_l) {
                    add_to_dup(X);
                } else {
                    add_to_single(X);
                }
            }
        } else {
            if(X < 0) {
                X *= -1;
                if(dup.find(X) != dup.end()) {
                    remove_from_dup_x(X);
                } else {
                    remove_from_single_x(X);
                }
                l.erase(X);
                cnt_l -= 1;
            } else {
                if(dup.size() < cnt_l) {
                    add_to_dup(X);
                } else {
                    add_to_single(X);
                }
                l.insert(X);
                cnt_l += 1;
            }
        }

        while(dup.size() < cnt_l) {
            add_to_dup(*single.rbegin());
            remove_from_single();
        }

        while(dup.size() > cnt_l) {
            add_to_single(*dup.begin());
            remove_from_dup();
        }

        while(!dup.empty() && !single.empty() && *dup.begin() < *single.rbegin()) {
            add_to_dup(*single.rbegin()); 
            add_to_single(*dup.begin());
            remove_from_dup();
            remove_from_single();
        }

        int64_t res = sum_dup * 2 + sum_single;
        if(!l.empty() && dup.find(*l.begin()) != dup.end()) {
            res -= *l.begin();
            res += single.empty() ? 0 : *single.rbegin();
        }

        std::cout << res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}

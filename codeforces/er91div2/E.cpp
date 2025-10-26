#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>
#include <map>

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<std::set<int>> towers(M);
    std::vector<int> cnt_seg(M, 0);
    
    for(int i = 0; i < N; i++) {
        int T;
        std::cin >> T;
        towers[T - 1].insert(i + 1);
    }
    
    int ans = 0;
    for(int i = 0; i < M; i++) {
        int pre = -1;
        int cnt = 1;
        for(int x : towers[i]) {
            if(x - 1 != pre && pre != -1) {
                cnt += 1;
            }
            pre = x;
        }
        ans += cnt; 
        cnt_seg[i] = cnt;
    }

    std::cout << ans - 1 << '\n';

    for(int i = 0; i < M - 1; i++) {
        int A, B;
        std::cin >> A >> B;

        A -= 1;
        B -= 1;

        if(towers[A].size() < towers[B].size()) {
            std::swap(towers[A], towers[B]);
            std::swap(cnt_seg[A], cnt_seg[B]);
        }
        
        ans -= cnt_seg[A];
        ans -= cnt_seg[B];

        for(int x : towers[B]) {
            auto it = towers[A].upper_bound(x);
            if(it != towers[A].end() && it != towers[A].begin()) {
                int pre = *std::prev(it);
                int nxt = *it;
                if(x != pre + 1 && x != nxt - 1) {
                    cnt_seg[A] += 1;
                } else if(x == pre + 1 && x == nxt - 1) {
                    cnt_seg[A] -= 1;
                }
            } else if(it != towers[A].end()) {
                int nxt = *it;
                if(nxt - 1 != x) {
                    cnt_seg[A] += 1;
                }
            } else if(it != towers[A].begin()) {
                int pre = *std::prev(it);
                if(x != pre + 1) {
                    cnt_seg[A] += 1;
                }
            }
            towers[A].insert(x);
        }
        towers[B].clear();

        ans += cnt_seg[A];
        std::cout << ans - 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}

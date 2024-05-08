#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int INF = (int)1e9;

void run_case() {
    int N;
    std::cin >> N;

    std::string S;
    std::cin >> S;
    
    int first_a = -1;
    int last_c = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') {
            first_a = first_a == -1 ? i : first_a;
        } 
        if(S[i] == 'c') {
            last_c = i;
        }
    }

    if(first_a == -1 || last_c == -1 || first_a > last_c) {
        std::cout << 0 << '\n';
        return;
    }

    std::vector<int> nxt_b(N, -1);
    std::vector<int> cnt_c(N, 0);
    int cnt = 0;
    int pos = -1;
    for(int i = N - 1; i >= 0; i--) {
        if(S[i] == 'c') {
            cnt += 1;
        } 
        if(S[i] == 'b') {
            pos = i;
        }
        nxt_b[i] = pos;
        cnt_c[i] = cnt;
    }

    std::vector<int> pre_b(N, -1);
    std::vector<int> cnt_a(N, 0);
    cnt = 0;
    pos = -1;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'a') {
            cnt += 1;
        }
        if(S[i] == 'b') {
            pos = i;
        }
        pre_b[i] = pos;
        cnt_a[i] = cnt;
    }

    int ans = INF;
    int remove_a = 0;
    int remove_c = 0;
    for(int i = first_a; i < last_c; i++) {
        if(S[i] == 'a') {
            int b = nxt_b[i];
            if(b < last_c) {
                ans = std::min(ans, cnt_c[b] + remove_a);
            }
            remove_a += 1;
        }
    }
    
    for(int i = last_c; i > first_a; i--) {
        if(S[i] == 'c') {
            int b = pre_b[i];
            if(b > first_a) {
                ans = std::min(ans, cnt_a[b] + remove_c);
            }
            remove_c += 1;
        }
    }

    std::cout << (ans == INF ? 0 : ans) << '\n';
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

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
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N * 2);
    for(int i = 0; i < N * 2; i++) {
        std::cin >> A[i];
    }

    std::set<int> sa;
    std::set<int> sb;
    for(int i = 0; i < N; i++) {
        sa.insert(A[i]);
    }

    for(int i = 0; i < N; i++) {
        sb.insert(A[i + N]);
    }

    std::vector<int> l;
    std::vector<int> r;
    std::vector<int> lr;
    for(int i = 1; i <= N; i++) {
        if(sa.find(i) != sa.end() && sb.find(i) != sb.end()) {
            lr.push_back(i);
        } else if(sa.find(i) != sa.end()) {
            l.push_back(i);
        } else {
            r.push_back(i);
        }
    }

    std::vector<int> ans_l;
    std::vector<int> ans_r;
    while(ans_l.size() < K * 2 - 1) {
        if(!l.empty() && !r.empty()) {
            ans_l.push_back(l.back());
            ans_l.push_back(l.back());
            l.pop_back();

            ans_r.push_back(r.back());
            ans_r.push_back(r.back());
            r.pop_back();
        } else {
            break;
        }
    }

    while(ans_l.size() != 2 * K) {
        ans_l.push_back(lr.back());
        ans_r.push_back(lr.back());
        lr.pop_back();
    }

    for(int i = 0; i < 2 * K; i++) {
        std::cout << ans_l[i] << " \n"[i == K * 2 - 1];
    }

    for(int i = 0; i < 2 * K; i++) {
        std::cout << ans_r[i] << " \n"[i == K * 2 - 1];
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

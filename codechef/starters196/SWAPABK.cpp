#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

struct fenwick_tree {
    int n_;
    std::vector<int64_t> ft_;
    
    fenwick_tree(int n) : n_(n + 1), ft_(n + 1, 0LL) {} 

    void update(int i, int64_t v) {
        for(++i; i < n_; i += i & -i) {
            ft_[i] += v;
        }
    }

    int64_t query(int i) {
        int64_t res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft_[i];
        }
        return res;
    }

    int64_t query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int N, K;
    std::cin >> N >> K;

    std::vector<int> A(N);
    std::vector<int> B(N);

    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    for(int i = 0; i < N; i++) {
        std::cin >> B[i];
    }

    fenwick_tree ft_1(N);
    fenwick_tree ft_2(N);
    std::set<int> key_p;
    int64_t score = 0;

    for(int i = 0, t = 0; i < N; i++) {
        if(std::abs(A[i] - B[i]) > K) {
            key_p.insert(i);
            if(A[i] + K < B[i]) {
                t = 1;
            } else {
                t = 0;
            }
        }
        ft_1.update(i, A[i]);
        ft_2.update(i, B[i]);
        score += t == 0 ? A[i] : B[i];
    }

    int Q;
    std::cin >> Q;
    for(int i = 0; i < Q; i++) {
        int T, P, X;;
        std::cin >> T >> P >> X;
        P -= 1;
        
        int pre = 0;
        int nxt = 0;
        auto it = key_p.lower_bound(P);
        pre = it == key_p.begin() ? -1 : *std::prev(it);
        
        it = key_p.upper_bound(P);
        nxt = it == key_p.end() ? N : *it;
        
        if(key_p.find(P) != key_p.end()) {
            score -= pre == -1 || B[pre] + K < A[pre] ? ft_1.query(pre + 1, P - 1) : ft_2.query(pre + 1, P - 1); 
            score -= A[P] + K < B[P] ? ft_2.query(P, nxt - 1) : ft_1.query(P, nxt - 1);
            key_p.erase(P);
        } else {
            score -= pre == -1 || B[pre] + K < A[pre] ? ft_1.query(pre + 1, nxt - 1) : ft_2.query(pre + 1, nxt - 1);
        }

        if(T == 1) {
            ft_1.update(P, X - A[P]);
            A[P] = X;
        } else {
            ft_2.update(P, X - B[P]);
            B[P] = X;
        }

        if(std::abs(A[P] - B[P]) > K) {
            key_p.insert(P);
            score += pre == -1 || B[pre] + K < A[pre] ? ft_1.query(pre + 1, P - 1) : ft_2.query(pre + 1, P - 1); 
            score += A[P] + K < B[P] ? ft_2.query(P, nxt - 1) : ft_1.query(P, nxt - 1);
        } else {
            score += pre == -1 || B[pre] + K < A[pre] ? ft_1.query(pre + 1, nxt - 1) : ft_2.query(pre + 1, nxt - 1);
        }

        std::cout << score << '\n';
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

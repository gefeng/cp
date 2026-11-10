#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <queue>
#include <set>

template<class T>
struct fenwick_tree {
    int n;
    int log;
    std::vector<T> ft;

    fenwick_tree(int _n) : n(_n + 1), log(0) {
        ft.resize(n, static_cast<T>(0));
        while((1 << (log + 1)) < n) {
            log++;
        }
    }

    void update(int i, T v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }

    T query(int i) {
        T res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }

    T query(int l, int r) {
        return query(r) - query(l - 1);
    }

    // smallest index i such that prefix sum >= k
    int kth(T k) {
        int now = 0;
        for(int pw = 1 << log; pw > 0; pw >>= 1) {
            if(now + pw < n && ft[now + pw] < k) {
                now += pw;
                k -= ft[now];
            }
        }
        return now + 1;
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<std::pair<int, int>> A(N);    
    A[0] = {N, N}; 
    for(int i = 1; i < N; i++) {
        int L, R;
        std::cin >> L >> R;
        L--;
        R--;
        A[i] = {L, R};
    }

    std::set<int> s;
    std::vector<int> min_v(N, N); // minimum vertex reachable from v
    for(int i = 0; i < N; i++) {
        s.insert(i);
    }

    for(int i = 1; i < N; i++) {
        auto [l, r] = A[i];
        while(true) {
            auto it = s.lower_bound(l);
            if(it != s.end() && *it <= r) {
                min_v[*it] = i;
                s.erase(it);
            } else {
                break;
            }
        }
    }

    std::ranges::sort(A, [](const auto& x, const auto& y) {
                return x.second < y.second;
            });

    std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>, std::greater<std::pair<int, int>>> pq;
    fenwick_tree<int> ft(N);
    
    int64_t ans = 0;
    int pre = -1;
    for(int i = 0; i < N - 1; i++) {
        auto [l, r] = A[i];
        ans += r - l + 1;
        
        for(int x = pre + 1; x <= r; x++) {
            pq.emplace(min_v[x], x);
        }

        while(!pq.empty() && pq.top().first <= r) {
            ft.update(pq.top().second, 1);
            pq.pop();
        }

        ans -= ft.query(l, r);
        pre = r;
    }

    std::cout << ans << '\n';
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

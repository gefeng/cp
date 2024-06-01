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

struct fenwick_tree {
    int n;
    std::vector<int> ft;
    fenwick_tree(int _n) : n(_n + 1), ft(n, 0) {
    }
    void update(int i, int v) {
        for(++i; i < n; i += i & -i) {
            ft[i] += v;
        }
    }
    int query(int i) {
        int res = 0;
        for(++i; i > 0; i -= i & -i) {
            res += ft[i];
        }
        return res;
    }
    int query(int l, int r) {
        return query(r) - query(l - 1);
    }
};

void run_case() {
    int Q;
    int64_t K;
    std::cin >> Q >> K;
    
    std::set<int64_t> s;
    std::map<int64_t, int64_t> m_range;

    auto insert = [&](int64_t x) {
        int64_t pre = -1;
        int64_t nxt = -1;
        auto it = s.upper_bound(x);
        if(it != s.end() && *it - x <= K) {
            nxt = *it;
        }
        if(it != s.begin()) {
            it--;
            if(x - *it <= K) {
                pre = *it;
            }
        }
        if(pre == -1 && nxt == -1) {
            m_range[x] = x;
        } else if(pre == -1) {
            int64_t r = m_range[nxt];
            m_range.erase(nxt);
            m_range[x] = r;
        } else if(nxt == -1) {
            auto it1 = m_range.upper_bound(pre);
            it1--;
            it1->second = x;
        } else {
            if(nxt - pre > K) {
                auto it1 = m_range.upper_bound(x);
                int64_t r = it1->second;
                it1--;
                it1->second = r;
                m_range.erase(nxt);
            }
        }
        s.insert(x);
    };

    auto remove = [&](int64_t x) {
        int64_t pre = -1;
        int64_t nxt = -1;
        auto it = s.upper_bound(x);
        if(it != s.end() && *it - x <= K) {
            nxt = *it;
        }
        it--;
        if(it != s.begin()) {
            it--;
            if(x - *it <= K) {
                pre = *it;
            }
        }

        if(pre != -1 && nxt != -1) {
            if(nxt - pre > K) {
                auto it1 = m_range.upper_bound(x);
                it1--;
                auto [l, r] = *it1;
                m_range.erase(it1);
                m_range[l] = pre;
                m_range[nxt] = r;
            }
        } else if(pre != -1) {
            auto it1 = m_range.upper_bound(x);
            it1--;
            it1->second = pre;
        } else if(nxt != -1) {
            int64_t r = m_range[x];
            m_range.erase(x);
            m_range[nxt] = r;
        } else {
            m_range.erase(x);
        }
        
        s.erase(x);
    };

    std::vector<std::pair<int, int64_t>> A(Q);
    std::map<int64_t, int> m_id;
    for(int i = 0; i < Q; i++) {
        std::cin >> A[i].first >> A[i].second;
        m_id[A[i].second] = 0; 
    }
    
    int id = 0;
    for(auto& [_, v] : m_id) {
        v = id++;
    }

    fenwick_tree ft(id);
    for(auto [t, x] : A) {
        if(t == 1) {
            if(s.find(x) == s.end()) {
                insert(x);
                ft.update(m_id[x], 1);
            } else {
                remove(x);
                ft.update(m_id[x], -1);
            }
        } else {
            auto it = m_range.upper_bound(x);
            it--;
            auto [l, r] = *it;
            std::cout << ft.query(m_id[l], m_id[r]) << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

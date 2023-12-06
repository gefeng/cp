#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

constexpr int64_t B = 5;
const std::array<int64_t, B> MOD = {998244353, 1000000007, 1000000009, 1000000021, 1000000033};
const std::array<int64_t, B> BASE = {31, 123, 77, 293, 314};
constexpr int MAX = (int)1e6;

std::vector<std::vector<int64_t>> pw(B);

struct seg_tree {
    int N, M, H;
    std::vector<std::array<int64_t, B>> st1;
    std::vector<std::array<int64_t, B>> st2;
    std::vector<int> len;

    seg_tree(int n) {
        build(n);
    }

    seg_tree(std::vector<int64_t>& v) {
        build(v);
    }

    int highest_one_bit(unsigned int i) {
        i |= (i >>  1);
        i |= (i >>  2);
        i |= (i >>  4);
        i |= (i >>  8);
        i |= (i >> 16);
        return i - (i >> 1); 
    }
    
    std::array<int64_t, B> hashify1(std::array<int64_t, B>& h1, std::array<int64_t, B>& h2, int len) {
        std::array<int64_t, B> h;
        for(int i = 0; i < B; i++) {
            h[i] = ((h1[i] * pw[i][len] % MOD[i]) + h2[i]) % MOD[i];
        }
        return h;
    }

    std::array<int64_t, B> hashify2(std::array<int64_t, B>& h1, std::array<int64_t, B>& h2, int len) {
        std::array<int64_t, B> h;
        for(int i = 0; i < B; i++) {
            h[i] = (h1[i] + (h2[i] * pw[i][len] % MOD[i])) % MOD[i];
        }
        return h;
    }

    void propagate(int i) {
        st1[i] = hashify1(st1[2 * i], st1[2 * i + 1], len[2 * i + 1]);
        st2[i] = hashify2(st2[2 * i], st2[2 * i + 1], len[2 * i]);
        len[i] = len[2 * i] + len[2 * i + 1];
    }

    void build(int n) {
        N = n;
        M = highest_one_bit(std::max(1, N - 1)) << 2; 
        H = M / 2;
        st1.resize(M, {0});
        st2.resize(M, {0});
        len.resize(M, {0});
    }

    void build(std::vector<int64_t>& v) {
        build(v.size());
        
        for(int i = 0; i < N; i++) {
            for(int j = 0; j < 5; j++) {
                st1[i + H][j] = v[i];
                st2[i + H][j] = v[i];
            }
            len[i + H] = 1;
        }
        
        for(int i = H - 1; i > 0; i--) {
            propagate(i);
        }
    }

    void set(int i, int64_t v) {
        for(int j = 0; j < B; j++) {
            st1[i + H][j] = v;
            st2[i + H][j] = v;
        }
        for(int j = (i + H) >> 1; j > 0; j >>= 1) {
            propagate(j);
        }
    }

    int64_t query(int l, int r) {
        return query1(1, 0, H - 1, l, r).first == query2(1, 0, H - 1, l, r).first;
    }

    std::pair<std::array<int64_t, B>, int> query1(int v, int lo, int hi, int l, int r) {
        if(l <= lo && r >= hi) {
            return {st1[v], len[v]};
        } 
        if(r < lo || l > hi) {
            return {{0}, 0};
        }

        int mid = (lo + hi) >> 1;
        auto [x, len1] = query1(v * 2, lo, mid, l, r);
        auto [y, len2] = query1(v * 2 + 1, mid + 1, hi, l, r);
        
        return {hashify1(x, y, len2), len1 + len2};
    }

    std::pair<std::array<int64_t, B>, int> query2(int v, int lo, int hi, int l, int r) {
        if(l <= lo && r >= hi) {
            return {st2[v], len[v]};
        } 
        if(r < lo || l > hi) {
            return {{0}, 0};
        }

        int mid = (lo + hi) >> 1;
        auto [x, len1] = query2(v * 2, lo, mid, l, r);
        auto [y, len2] = query2(v * 2 + 1, mid + 1, hi, l, r);
        
        return {hashify2(x, y, len1), len1 + len2};
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::string S;
    std::cin >> S;

    for(int i = 0; i < B; i++) {
        pw[i].resize(MAX + 1, 1);
        for(int j = 1; j <= MAX; j++) {
            pw[i][j] = pw[i][j - 1] * BASE[i] % MOD[i];
        }
    }

    std::vector<int64_t> a(N);
    for(int i = 0; i < N; i++) {
        a[i] = S[i] - 'a' + 1;
    }

    seg_tree st(a);

    for(int i = 0; i < Q; i++) {
        int T;
        std::cin >> T;

        if(T == 1) {
            int P;
            char C;
            std::cin >> P >> C;
            P -= 1;
            st.set(P, C - 'a' + 1);
        } else {
            int L, R;
            std::cin >> L >> R;
            L -= 1;
            R -= 1;
            std::cout << (st.query(L, R) ? "Yes" : "No") << '\n';
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

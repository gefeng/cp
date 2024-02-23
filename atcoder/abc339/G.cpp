#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

struct merge_sort_tree {
    int n, m, h;
    std::vector<std::vector<int>> mst;
    std::vector<std::vector<int64_t>> mst_sum;
    
    merge_sort_tree(std::vector<int>& a) {
        m = a.size();
        n = 1;
        while(n < m) {
            n <<= 1;
        }
        h = n;
        n <<= 1;

        mst.resize(n);
        mst_sum.resize(n);
        for(int i = 0; i < m; i++) {
            mst[i + h].push_back(a[i]);
            mst_sum[i + h].push_back(0);
            mst_sum[i + h].push_back(a[i]);
        }

        for(int i = h - 1; i > 0; i--) {
            mst[i] = merge(mst[i * 2], mst[i * 2 + 1]); 

            int sz = mst[i].size();
            mst_sum[i].resize(sz + 1, 0);
            for(int j = 1; j <= sz; j++) {
                mst_sum[i][j] = mst_sum[i][j - 1] + mst[i][j - 1];
            }
        }
    }

    std::vector<int> merge(std::vector<int>& a, std::vector<int>& b) {
        int sz1 = a.size();
        int sz2 = b.size();
        std::vector<int> res;
        res.reserve(sz1 + sz2);
        for(int i = 0, j = 0; i < sz1 || j < sz2; ) {
            if(i == sz1) {
                res.push_back(b[j++]);
            } else if(j == sz2) {
                res.push_back(a[i++]);
            } else {
                if(a[i] < b[j]) {
                    res.push_back(a[i++]);
                } else {
                    res.push_back(b[j++]);
                }
            }
        }
        return res;
    }

    int64_t query(int l, int r, int x) {
        return query(l, r, 1, 0, h - 1, x);
    }

    int64_t query(int l, int r, int v, int tl, int tr, int x) {
        if(tl > r || tr < l) {
            return 0;
        } 
        
        if(tl >= l && tr <= r) {
            auto it = std::upper_bound(mst[v].begin(), mst[v].end(), x);
            if(it != mst[v].begin()) {
                it--;
                int p = it - mst[v].begin();
                return mst_sum[v][p + 1];
            } else {
                return 0;
            }
        }

        int tm = (tl + tr) >> 1;
        return query(l, r, v * 2, tl, tm, x) + query(l, r, v * 2 + 1, tm + 1, tr, x);
    }
};

void run_case() {
    int N;
    std::cin >> N;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    merge_sort_tree mst(A);

    int Q;
    std::cin >> Q;
    int64_t pre_res = 0;
    for(int i = 0; i < Q; i++) {
        int64_t L, R, X;
        std::cin >> L >> R >> X;
        
        L ^= pre_res;
        R ^= pre_res;
        X ^= pre_res;
        L -= 1;
        R -= 1;
        
        pre_res = mst.query((int)L, (int)R, X);
        std::cout << pre_res << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

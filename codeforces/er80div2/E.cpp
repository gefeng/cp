#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

class fenwick_tree {
public:    
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

private:
    int n;
    std::vector<int> ft;
};

void run_case() {
    int N, M;
    std::cin >> N >> M;

    std::vector<int> A(M);
    for(int i = 0; i < M; i++) {
        std::cin >> A[i];
        A[i] -= 1;
    }

    std::vector<int> pre(N, -1);
    fenwick_tree ft_1(N);
    fenwick_tree ft_2(M);
    
    std::vector<std::pair<int, int>> ans(N, {-1, -1});
    for(int i = 0; i < M; i++) {
        if(pre[A[i]] == -1) {
            int cnt = ft_1.query(A[i] + 1, N - 1);
            ans[A[i]].second = std::max(ans[A[i]].second, cnt + A[i]);
        } else {
            int l = pre[A[i]];
            int cnt = ft_2.query(l + 1, i - 1);
            ans[A[i]].second = std::max(ans[A[i]].second, cnt); 
        }
        if(ft_1.query(A[i], A[i]) == 0) {
            ft_1.update(A[i], 1);
        }
        if(pre[A[i]] != -1) {
            ft_2.update(pre[A[i]], -1);
        }
        ft_2.update(i, 1);
        pre[A[i]] = i;
    }

    for(int i = 0; i < N; i++) {
        ans[i].second = std::max(ans[i].second, i);
        if(pre[i] == -1) {
            ans[i].first = i;
            ans[i].second = std::max(ans[i].second, ft_1.query(i + 1, N - 1) + i);
        } else {
            ans[i].first = 0;
            ans[i].second = std::max(ans[i].second, ft_2.query(pre[i] + 1, M - 1));
        }
    }

    for(int i = 0; i < N; i++) {
        std::cout << ans[i].first + 1 << ' ' << ans[i].second + 1 << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(0);
    
    run_case();
}

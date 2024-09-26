#include <iostream>
#include <utility>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

int block_size;

struct Q {
    int l;
    int r;
    int idx;
    Q(int _l, int _r, int _idx) : l(_l), r(_r), idx(_idx) {}
    bool operator< (const Q rhs) const {
        int x = l / block_size;
        int y = rhs.l / block_size;
        if(x == y) {
            return r < rhs.r;
        }
        return x < y;
    }
};

std::vector<bool> mo(std::vector<int>& data, std::vector<Q>& queries) {
    int n = queries.size();
    std::vector<bool> ans(n);

    std::sort(queries.begin(), queries.end());

    int l = 0;
    int r = 0;
    int cnt = 0;
    std::vector<int> freq(data.size(), 0);

    auto modify = [&](int i) {
        freq[data[i]] ^= 1;
        cnt += freq[data[i]] == 1 ? 1 : -1;
    };

    modify(0);
    for(const Q& q : queries) {
        while(q.l < l) {
            l--;
            modify(l);
        }
        while(q.l > l) {
            modify(l);
            l++;
        }
        while(q.r < r) {
            modify(r);
            r--;
        }
        while(q.r > r) {
            r++;
            modify(r);
        }

        ans[q.idx] = cnt == 0;
    }

    return ans;
}

void run_case() {
    int N, M;
    std::cin >> N >> M;
    
    std::vector<int> A(N);
    std::map<int, int> m;
    int id = 0;
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
        m[A[i]] = 0;
    }

    block_size = int(sqrt(N));
    
    for(auto& [_, v] : m) {
        v = id++;
    }

    for(int i = 0; i < N; i++) {
        A[i] = m[A[i]];
    }

    std::vector<Q> queries;
    for(int i = 0; i < M; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        queries.emplace_back(L, R, i);
    } 
    
    std::vector<bool> ans = mo(A, queries);
    
    for(int i = 0; i < M; i++) {
        std::cout << (ans[i] ? "YES" : "NO") << '\n';
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

#include <iostream>
#include <vector>

struct sparse_table {
    const int LOG = 17;
    const int E = (int)1e9;

    int n;
    std::vector<std::vector<int>> st;

    sparse_table(int n) : n(n) {
        st = std::vector<std::vector<int>>(n, std::vector<int>(LOG, E));
    }
    
    sparse_table(std::vector<int>& a) : sparse_table(a.size()) {
        for(int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
    
        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i + (1 << k) - 1 < n; i++) {
                st[i][k] = std::min(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    int get(int l, int r) {
        int k = 0;
        while((k + 1) < LOG && (1 << (k + 1)) < r - l + 1) {
            k += 1;
        }
        return std::min(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

void run_case() {
    int N, Q;
    std::cin >> N >> Q;

    std::vector<int> A(N);
    for(int i = 0; i < N; i++) {
        std::cin >> A[i];
    }

    sparse_table st(A);
    
    for(int i = 0; i < Q; i++) {
        int L, R;
        std::cin >> L >> R;
        L -= 1;
        R -= 1;
        std::cout << st.get(L, R) << '\n';
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    run_case();
}

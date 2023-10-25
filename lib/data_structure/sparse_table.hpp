#ifndef CP_SPARSE_TABLE_HPP
#define CP_SPARSE_TABLE_HPP

#include <vector>

template<class T, T (*op)(T, T)>
struct sparse_table {
    const int LOG = 20;

    int n;
    std::vector<std::vector<T>> st;
    std::vector<int> log;

    sparse_table(int n) : n(n) {
        st = std::vector<std::vector<T>>(n, std::vector<T>(LOG, 0));

        log = std::vector<int>(n + 1, 0);
        for(int i = 2, k = 0; i <= n; i++) {
            if(k + 1 < LOG && (1 << (k + 1)) < i) {
                k += 1; 
            } 
            log[i] = k;
        }
    }
    
    sparse_table(std::vector<T>& a) : sparse_table(a.size()) {
        for(int i = 0; i < n; i++) {
            st[i][0] = a[i];
        }
    
        for(int k = 1; k < LOG; k++) {
            for(int i = 0; i + (1 << k) - 1 < n; i++) {
                st[i][k] = op(st[i][k - 1], st[i + (1 << (k - 1))][k - 1]);
            }
        }
    }

    T get(int l, int r) {
        int k = log[r - l + 1];
        return op(st[l][k], st[r - (1 << k) + 1][k]);
    }
};

#endif

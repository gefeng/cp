#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

const int64_t MOD = (int64_t)1e9 + 7;    
    
struct mat {
    int n, m;
    std::vector<std::vector<int64_t>> a;
    mat(int n, int m) : n(n), m(m) {
        a = std::vector<std::vector<int64_t>>(n, std::vector<int64_t>(m, 0));
    }

    mat operator *(const mat& o) const {
        mat res(n, o.m);
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < o.m; j++) {
                for(int k = 0; k < m; k++) {
                    res.a[i][j] += a[i][k] * o.a[k][j] % MOD;
                    res.a[i][j] %= MOD;
                }
            }
        }
        return res;
    }
};

mat q_pow(mat x, int64_t y) {
    mat res(x.n, x.n);
    for(int i = 0; i < x.n; i++) {
        res.a[i][i] = 1;
    }

    while(y) {
        if(y & 1) {
            res = res * x;
        }
        x = x * x;
        y >>= 1;
    }
    return res;
}

std::vector<int> prefix_function(std::string s) {
    int n = (int)s.length();
    std::vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

class Solution {
public:
    int numberOfWays(std::string s, std::string t, long long k) {
        int n = s.length();
        std::string ss = t + "*" + s + s;
        std::vector<int> prefix = prefix_function(ss);
        
        int c = 0;
        for(int i = 0; i < n; i++) {
            if(prefix[i + 2 * n] >= n) {
                c += 1;
            }
        }
        
        if(c == 0) {
            return 0;
        }
        
        mat m1(2, 2);
        mat m2(2, 1);
        //mat m1;
        m1.a[0][0] = c - 1;
        m1.a[0][1] = c;
        m1.a[1][0] = n - c;
        m1.a[1][1] = n - c - 1;
        m1 = q_pow(m1, k);
        
        if(s == t) {
            m2.a[0][0] = 1;
            m2.a[1][0] = 0;
        } else {
            m2.a[0][0] = 0;
            m2.a[1][0] = 1;
        }
        
        mat m3 = m1 * m2;
        return m3.a[0][0];
    }
};

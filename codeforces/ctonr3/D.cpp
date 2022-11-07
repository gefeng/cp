#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = 998244353LL;

void factorization(int x, vector<int>& res) {
    for(int f = 2; f * f <= x; f += 1) {
        while(x % f == 0) {
            res.push_back(f);
            x /= f;
        }
    }
    if(x > 1) {
        res.push_back(x);
    }
}

void inclusion_exclusion(vector<int>& p_factors, int x, LL& res) {
    vector<int> unique;
    
    for(int i = 0; i < p_factors.size(); i++) {
        if(i == 0 || p_factors[i] != p_factors[i - 1]) {
            unique.push_back(p_factors[i]);
        }
    }

    int n = unique.size();
    for(int i = 1; i < (1 << n); i++) {
        int cnt = 0;
        int prod = 1;
        for(int j = 0; j < n; j++) {
            if(i & (1 << j)) {
                prod *= unique[j];
                cnt += 1;
            }
        }

        int tot = x / prod;

        if(cnt & 1) {
            res -= tot;
            res += MOD;
            res %= MOD;
        } else {
            res += tot;
            res %= MOD;
        }
    }
}

void trim(vector<int>& a, vector<int>& b) {
    vector<int> c;
    int i = 0;
    int j = 0;
    int n = a.size();
    int m = b.size();
    while(i < n) {
        if(j == m) {
            c.push_back(a[i++]);
        } else {
            if(a[i] == b[j]) {
                i += 1;
                j += 1;
            } else {
                c.push_back(a[i++]);
            }
        }
    }
    swap(c, a);
}

void run_case() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
    
    for(int i = 1; i < N; i++) {
        if(A[i - 1] % A[i] != 0) {
            cout << 0 << '\n';
            return;
        }
    }

    vector<int> p_factors;
    factorization(A[0], p_factors);

    LL ans = 1LL;
    for(int i = 1; i < N; i++) {
        if(A[i] == A[i - 1]) {
            ans *= M / A[i];
            ans %= MOD;
        } else {
            vector<int> factors;
            factorization(A[i], factors);
            trim(p_factors, factors); 

            LL tot = M / A[i];
            inclusion_exclusion(p_factors, M / A[i], tot);
            ans *= tot;
            ans %= MOD;

            swap(p_factors, factors);
        }
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    int T;
    cin >> T;
    while(T--) {
        run_case();
    }
}

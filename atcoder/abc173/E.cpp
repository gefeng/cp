#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const LL MOD = (LL)1e9 + 7LL;

void run_case() {
    int N, K;
    cin >> N >> K;

    vector<int> pos;
    vector<int> neg;
    int cnt = 0;
    for(int i = 0; i < N; i++) {
        int X;
        cin >> X;
        if(X > 0) {
            pos.push_back(X); 
        } else if(X < 0) {
            neg.push_back(X);
        } else {
            cnt += 1;
        }
    }

    int n = pos.size();
    int m = neg.size();
    if(m + n < K) {
        cout << 0 << '\n';
        return;
    }

    LL ans = 1LL;
    if(m + n == K) {
        if(m % 2 == 1 && cnt) {
            cout << 0 << '\n';
            return;
        }

        for(int x : pos) {
            ans *= x;
            ans %= MOD;
        }

        for(int x : neg) {
            ans *= -x;
            ans %= MOD;
        }

        if(m % 2 == 1) {
            ans *= -1;
            ans += MOD;
            ans %= MOD;
        }
        cout << ans << '\n';
        return;
    }

    if(n == 0) {
        sort(neg.begin(), neg.end());
        if(K % 2 == 1) {
            if(cnt) {
                cout << 0 << '\n';
                return;
            }

            for(int i = m - 1; K; i--, K--) {
                ans *= -neg[i];
                ans %= MOD;
            } 
            
            ans *= -1;
            ans += MOD;
            ans %= MOD;
        } else {
            for(int i = 0; K; i++, K--) {
                ans *= -neg[i];
                ans %= MOD;
            } 
        }

        cout << ans << '\n';
        return;
    }

    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());

    int i = 0;
    int j = 0;
    while((i < n || j < m) && K) {
        if(i == n) {
            j += 1;
        } else if(j == m) {
            i += 1;
        } else {
            if(pos[i] >= -neg[j]) {
                i += 1;
            } else {
                j += 1;
            }
        }
        K -= 1;
    }

    if(j % 2 == 1) {
        if(i == n) {
            i -= 1;             
            j += 1;
        } else if(j == m || i == 0) {
            j -= 1;
            i += 1;
        } else {
            LL x = 1LL * pos[i] * pos[i - 1];
            LL y = 1LL * neg[j] * neg[j - 1];
            if(x >= y) {
                i += 1;
                j -= 1;
            } else {
                j += 1;
                i -= 1;
            }
        }
    }
    
    while(--i >= 0) {
        ans *= pos[i];
        ans %= MOD;
    } 
    while(--j >= 0) {
        ans *= -neg[j];
        ans %= MOD;
    }

    cout << ans << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

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
const LL BASE = 26LL;

void rolling_has() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    vector<LL> save(N + 1, 0LL);
    
    LL h = 0LL;
    LL d = 1LL;
    for(int l = 2 * N - 1, r = 2 * N - 1; l >= 0; l--) {
        h = (h * BASE % MOD) + S[l] - 'a' + 1LL;
        h %= MOD;

        if(r - l + 1 > N) {
            h = h - ((S[r] - 'a' + 1LL) * d % MOD) + MOD;
            h %= MOD;
            r -= 1;
        } else {
            d *= BASE;
            d %= MOD;
        }

        if(r - l + 1 == N) {
            save[l] = h;
        }
    }

    vector<LL> prefix(N + 1, 0LL);
    vector<LL> suffix(N + 1, 0LL); 

    h = 0LL;
    d = 1LL;
    for(int i = 1; i <= N; i++) {
        h = (h * BASE % MOD) + S[i - 1] - 'a' + 1LL; 
        h %= MOD;
        d *= BASE;
        d %= MOD;
        prefix[i] = h;
    }

    d = 1LL;
    for(int i = N; i >= 1; i--) {
        prefix[i] = prefix[i] * d % MOD;
        d *= BASE;
        d %= MOD;
    }

    h = 0LL;
    d = 1LL;
    for(int i = 1; i <= N; i++) {
        h += (S[2 * N - i] - 'a' + 1LL) * d % MOD;
        h %= MOD;
        d *= BASE;
        d %= MOD;
        suffix[i] = h;
    }

    for(int i = 0; i <= N; i++) {
        LL x = (prefix[i] + suffix[N - i]) % MOD;
        LL y = save[i];
        //cout << i << ' ' << x << ' ' << y << '\n';
        if(x == y) {
            string ans = S.substr(i, N);
            reverse(ans.begin(), ans.end());
            cout << ans << '\n' << i << '\n';
            return;
        }
    }

    cout << -1 << '\n';
}

vector<int> z_algorithm(string& s) {
    int n = s.length();
    vector<int> z(n, 0);

    int l = 0, r = 0;
    for(int i = 1; i < n; i++) {
        z[i] = max(0, min(z[i - l], r - i + 1));
        while(i + z[i] < n && s[i + z[i]] == s[z[i]]) {
            l = i;
            r = i + z[i];
            z[i] += 1;
        }
    } 

    return z;
}

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    string l = S.substr(0, N);
    string r = S.substr(N);
    reverse(r.begin(), r.end());
    string s = l + r;
    

    reverse(r.begin(), r.end());
    reverse(l.begin(), l.end());
    string t = l + r;

    vector<int> zs = z_algorithm(s);
    vector<int> zt = z_algorithm(t);

    for(int i = N; i < 2 * N; i++) {
        if(zs[i] + i == 2 * N && (N + zs[i] == 2 * N || zt[N + zs[i]] + N + zs[i] == 2 * N)) {
            cout << S.substr(0, zs[i]) + S.substr(2 * N - (N - zs[i])) << '\n';
            cout << zs[i] << '\n';
            return;
        }
    }
    
    cout << -1 << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

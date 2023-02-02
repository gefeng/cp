#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;
using LL = long long;

void dfs(vector<char>& s, int n, vector<string>& subset, string& cur, int i) {
    if(i == s.size()) {
        if(cur.size() == n) {
            subset.push_back(cur);
        }
        return;
    }
    
    dfs(s, n, subset, cur, i + 1);

    cur.push_back(s[i]);
    dfs(s, n, subset, cur, i + 1);
    cur.pop_back();
}

void run_case() {
    int N, K;
    cin >> N >> K;

    string S, T;
    cin >> S >> T;

    set<char> seen;
    for(int i = 0; i < N; i++) {
        seen.insert(S[i]);
    }

    vector<char> char_set;
    for(char c : seen) {
        char_set.push_back(c);
    }

    int unique = seen.size();
    vector<string> subset;

    int n = unique > K ? K : unique;
    
    string cur = "";
    dfs(char_set, n, subset, cur, 0);

    LL ans = 0LL;
    for(string s : subset) {
        array<bool, 26> has{false};
        for(char c : s) {
            has[c - 'a'] = true;
        }

        LL tot = 0LL;
        for(int l = 0, r = 0; r < N; r++) {
            while(r < N && (S[r] == T[r] || has[S[r] - 'a'])) {
                r += 1;
            }
            
            LL x = r - l;
            tot += (1LL + x) * x / 2LL;
            l = r + 1;
        }
        ans = max(ans, tot);
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

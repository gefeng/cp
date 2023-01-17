#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <set>

using namespace std;

pair<int, string> solve(string& s, int tot) {
    int n = s.length();

    if(n % tot) {
        return {n + 1, ""};
    }

    int freq = n / tot;

    vector<pair<int, int>> v(26, {0, 0});
    for(int i = 0; i < 26; i++) {
        v[i].second = i;
    }

    for(char c : s) {
        v[c - 'a'].first += 1;
    }

    sort(v.begin(), v.end(), greater<pair<int, int>>());

    int cnt = 0;
    for(int i = 0; i < tot; i++) {
        if(v[i].first > freq) {
            for(int j = i + 1; j < tot; j++) {
                if(v[j].first < freq) {
                    int d = min(v[i].first - freq, freq - v[j].first);
                    v[i].first -= d;
                    v[j].first += d;
                    cnt += d;
                }
            }
            //cnt += abs(v[i].first - freq); 
        } else if(v[i].first < freq) {
            cnt += freq - v[i].first;
        }
        v[i].first = freq;
    } 

    string ans(n, '*');
    for(int i = 0; i < tot; i++) {
        for(int j = 0; j < n; j++) {
            if(s[j] - 'a' == v[i].second && v[i].first) {
                ans[j] = s[j];
                v[i].first -= 1;
            }
        }
    }

    for(int i = 0; i < tot; i++) {
        for(int j = 0; j < n; j++) {
            if(ans[j] == '*' && v[i].first) {
                ans[j] = char(v[i].second + 'a');
                v[i].first -= 1;
            }
        }
    }
    return {cnt, ans};
}

void run_case() {
    int N;
    cin >> N;

    string S;
    cin >> S;

    int min_v = N + 1;
    string ans = "";
    for(int i = 1; i <= min(26, N); i++) {
        pair<int, string> res = solve(S, i);
        if(res.first < min_v) {
            min_v = res.first;
            ans = res.second;
        }
    } 

    cout << min_v << '\n' << ans << '\n';
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

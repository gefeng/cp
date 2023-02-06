#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

LL ans_a, ans_b, ans_c = 0LL;

LL to_num(string& S, array<int, 26>& map) {
    LL res = 0LL;
    for(char c : S) {
        res *= 10LL;
        res += map[c - 'a'];
    }
    return res;
}

bool is_ok(string& S1, string& S2, string& S3, array<int, 26>& map) {
    if(map[S1[0] - 'a'] == 0 || map[S2[0] - 'a'] == 0 || map[S3[0] - 'a'] == 0) {
        return false;
    }

    LL x = to_num(S1, map);
    LL y = to_num(S2, map); 
    LL z = to_num(S3, map);
    if(x + y == z) {
        ans_a = x;
        ans_b = y;
        ans_c = z;
        return true;
    }
    return false;
}

bool dfs(string& S1, string& S2, string& S3, vector<int>& v, int cur, array<int, 26>& m1, array<int, 10>& m2) {
    if(cur == v.size()) {
        return is_ok(S1, S2, S3, m1);
    } 

    int c = v[cur];
    for(int i = 0; i < 10; i++) {
        if(m2[i] == 0) {
            m1[c] = i;
            m2[i] = 1;
            if(dfs(S1, S2, S3, v, cur + 1, m1, m2)) {
                return true;
            }
            m1[c] = -1;
            m2[i] = 0;
        }
    } 
    return false;
}

void run_case() {
    string S1, S2, S3;    
    cin >> S1 >> S2 >> S3;

    array<int, 26> freq{0}; 
    for(char c : S1) {
        freq[c - 'a'] += 1;
    }
    for(char c : S2) {
        freq[c - 'a'] += 1;
    }
    for(char c : S3) {
        freq[c - 'a'] += 1;
    }

    int cnt = 0;
    for(int i = 0; i < 26; i++) {
        cnt += freq[i] ? 1 : 0; 
    }

    if(cnt > 10) {
        cout << "UNSOLVABLE" << '\n';
        return;
    }

    vector<int> v;
    for(int i = 0; i < 26; i++) {
        if(freq[i]) {
            v.push_back(i);
        }
    }
    
    array<int, 26> m1;
    array<int, 10> m2;
    m1.fill(-1);
    m2.fill(0);

    if(dfs(S1, S2, S3, v, 0, m1, m2)) {
        cout << ans_a << '\n';
        cout << ans_b << '\n';
        cout << ans_c << '\n';
    } else {
        cout << "UNSOLVABLE" << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

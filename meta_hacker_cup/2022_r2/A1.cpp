#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

void run_case(int T) {
    string S;
    cin >> S;
    int Q;
    cin >> Q;

    vector<pair<int, int>> A(Q, {0, 0});
    for(int i = 0; i < Q; i++) {
        cin >> A[i].first >> A[i].second;
    }

    int n = S.length();
    vector<array<int, 26>> v(n + 1, {0});

    for(int i = 1; i <= n; i++) {
        v[i] = v[i - 1];
        v[i][S[i - 1] - 'a']++;
    }

    int ans = 0;
    for(pair<int, int>& q : A) {
        int l = q.first;
        int r = q.second;
        l--;
        r--;
        
        if((r - l + 1) % 2 == 0) {
            continue;
        }

        bool ok = true;

        int sz_1 = (r - l + 1) / 2;
        //int sz_2 = sz_1 + 1;
        array<int, 26> cnt_1{0};
        array<int, 26> cnt_2{0};
        for(int i = 0; i < 26; i++) {
            cnt_1[i] = v[l + sz_1][i] - v[l][i];
            cnt_2[i] = v[r + 1][i] - v[l + sz_1][i];
        } 

        int cnt_dif = 0;
        for(int i = 0; i < 26; i++) {
            if(cnt_2[i] != cnt_1[i]) {
                if(cnt_1[i] > cnt_2[i] || cnt_2[i] - cnt_1[i] > 1) {
                    ok = false;
                    break;
                }
                cnt_dif++;
            }
        }

        if(ok && cnt_dif == 1) {
            ans++;
            continue;
        }

        ok = true;
        cnt_dif = 0;
        cnt_2[S[l + sz_1] - 'a']--;
        cnt_1[S[l + sz_1] - 'a']++;
        for(int i = 0; i < 26; i++) {
            if(cnt_1[i] != cnt_2[i]) {
                if(cnt_2[i] > cnt_1[i] || cnt_1[i] - cnt_2[i] > 1) {
                    ok = false;
                    break;
                } 
                cnt_dif++;
            }
        }

        if(ok && cnt_dif == 1) {
            ans++;
        }
    }

    cout << "Case #" << T << ": " << ans << '\n';
}

int main() {
    int T;
    cin >> T;
    for(int t = 1; t <= T; t++) {
        run_case(t);
    }
}

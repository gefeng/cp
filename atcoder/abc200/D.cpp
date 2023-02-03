#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N;
    cin >> N;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<vector<bool>> dp(N + 1, vector<bool>(200, 0));
    vector<vector<vector<int>>> pre(N + 1, vector<vector<int>>(200));
    dp[0][0] = true;

    for(int i = 1; i <= N; i++) {
        int r = A[i - 1] % 200;
        for(int j = 0; j < 200; j++) {
            for(int k = 0; k < i; k++) {
                if(dp[k][j]) {
                    dp[i][(j + r) % 200] = true;
                    pre[i][(j + r) % 200].push_back(k);
                }
            }
        }
    }

    for(int r = 0; r < 200; r++) {
        int first = -1;
        int second = -1;
        for(int i = 1; i <= N; i++) {
            if(dp[i][r]) {
                if(first == -1) {
                    first = i;
                } else if(second == -1) {
                    second = i;
                } 
            }
        }

        if(first != -1 && second != -1) {
            cout << "Yes" << '\n';

            vector<int> s1;
            vector<int> s2;

            int cur = first;
            int rem = r;
            while(cur != 0) {
                s1.push_back(cur);

                int nrem = (rem - (A[cur - 1] % 200) + 200) % 200;
                int nxt = pre[cur][rem].empty() ? 0 : pre[cur][rem][0]; 

                rem = nrem;
                cur = nxt;
            }

            cur = second;
            rem = r;
            while(cur != 0) {
                s2.push_back(cur);

                int nrem = (rem - (A[cur - 1] % 200) + 200) % 200;
                int nxt = pre[cur][rem].empty() ? 0 : pre[cur][rem][0]; 

                rem = nrem;
                cur = nxt;
            }

            reverse(s1.begin(), s1.end());
            reverse(s2.begin(), s2.end());

            int m = s1.size();
            int n = s2.size();
            cout << m << ' ';
            for(int i = 0; i < m; i++) {
                cout << s1[i] << " \n"[i == m - 1];
            }

            cout << n << ' ';
            for(int i = 0; i < n; i++) {
                cout << s2[i] << " \n"[i == n - 1];
            }
            return;
        } else if(first != -1) {
            int cur = first;
            int rem = r;
            bool ok = false;
            vector<int> s1;
            vector<int> s2;
            while(cur != 0) {
                s1.push_back(cur);
                s2.push_back(cur);
                if(pre[cur][rem].size() > 1) {
                    ok = true;
                    break;
                }
                int nrem = (rem - (A[cur - 1] % 200) + 200) % 200;
                int nxt = pre[cur][rem].empty() ? 0 : pre[cur][rem][0]; 
                rem = nrem;
                cur = nxt;
            }

            if(ok) {
                int p1 = pre[cur][rem][0];
                int p2 = pre[cur][rem][1];
                int r1 = (rem - (A[cur - 1] % 200) + 200) % 200;
                int r2 = (rem - (A[cur - 1] % 200) + 200) % 200;
                while(p1 != 0) {
                    s1.push_back(p1);
                    int nr1 = (r1 - (A[p1 - 1] % 200) + 200) % 200;
                    int np1 = pre[p1][r1].empty() ? 0 : pre[p1][r1][0];
                    r1 = nr1;
                    p1 = np1;
                }
                while(p2 != 0) {
                    s2.push_back(p2);
                    int nr2 = (r2 - (A[p2 - 1] % 200) + 200) % 200;
                    int np2 = pre[p2][r2].empty() ? 0 : pre[p2][r2][0];
                    r2 = nr2;
                    p2 = np2;
                }

                reverse(s1.begin(), s1.end());
                reverse(s2.begin(), s2.end());

                cout << "Yes" << '\n';

                int m = s1.size();
                int n = s2.size();
                cout << m << ' ';
                for(int i = 0; i < m; i++) {
                    cout << s1[i] << " \n"[i == m - 1];
                }

                cout << n << ' ';
                for(int i = 0; i < n; i++) {
                    cout << s2[i] << " \n"[i == n - 1];
                }

                return;
            }

        }
    } 

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

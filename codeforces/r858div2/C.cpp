#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;
using LL = long long;

const int SIZE = 12;

void gen(vector<int>& v, int cur, vector<vector<int>>& res, vector<int>& seq) {
    if(cur == SIZE) {
        res.push_back(seq); 
        return;
    }

    for(int x : v) {
        seq.push_back(x);
        gen(v, cur + 1, res, seq);
        seq.pop_back();
    }
}

void test() {
    //vector<int> v = {-4, -1, 0, 1, 4};
    vector<int> v = {-6, -1, 0, 6};
    
    vector<vector<int>> res;
    vector<int> seq;
    gen(v, 0, res, seq);

    for(vector<int>& s : res) {
        bool ok = true;
        for(int i = 0; i < (1 << SIZE); i++) {
            int cnt = __builtin_popcount(i);
            if(cnt != SIZE / 2) {
                continue;
            }

            int sum1 = 0;
            int prod1 = 1;
            int sum2 = 0;
            int prod2 = 1;
            for(int j = 0; j < SIZE; j++) {
                if(i & (1 << j)) {
                    sum1 += s[j];
                    prod2 *= s[j];
                } else {
                    sum2 += s[j];
                    prod1 *= s[j];
                }
            }

            if(sum1 != prod1 || sum2 != prod2) {
                ok = false;
                break;
            }
        }

        if(ok) {
            for(int i = 0; i < SIZE; i++) {
                cout << s[i] << ' ';
            }
            cout << '\n';
        }
    }
}

void run_case() {
    //test();
    
    int N;
    cin >> N;

    int n2 = N * 2;
    vector<int> A(n2);
    for(int i = 0; i < n2; i++) {
        cin >> A[i];
    }

    if(N == 1) {
        cout << abs(A[0] - A[1]) << '\n';
    } else {
        LL ans = 0LL;
        for(int x : A) {
            ans += abs(x);
        }

        if(N == 2) {
            LL d = 0LL;
            for(int x : A) {
                d += abs(x - 2);
            }
            ans = min(ans, d);
        }

        if(N % 2 == 0) {
            LL d = 0LL;
            for(int x : A) {
                d += abs(x + 1);
            }

            for(int x : A) {
                ans = min(ans, d - abs(x + 1) + abs(x - N));
            }
        }

        cout << ans << '\n';
    }
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

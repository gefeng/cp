#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<pair<int, int>> B(Q);
    for(int i = 0; i < Q; i++) {
        cin >> B[i].first >> B[i].second;
    }

    vector<int> xor_sum(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        xor_sum[i] = xor_sum[i - 1] ^ A[i - 1];
    }

    vector<int> cnt_zero(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cnt_zero[i] = cnt_zero[i - 1] + (A[i - 1] == 0 ? 1 : 0);
    }

    unordered_map<int, vector<int>> eve_map;
    unordered_map<int, vector<int>> odd_map;
    for(int i = 1; i <= N; i++) {
        if(i & 1) {
            odd_map[xor_sum[i]].push_back(i - 1);
        } else {
            eve_map[xor_sum[i]].push_back(i - 1);
        }
    }

    for(auto& p : B) {
        int l = p.first;
        int r = p.second;
        l--;
        r--;

        int len = r - l + 1;
        int zero = cnt_zero[r + 1] - cnt_zero[l];
        if(zero == len) {
            cout << 0 << '\n';
            continue;
        } 

        if((xor_sum[r + 1] ^ xor_sum[l]) != 0 || len == 2) {
            cout << -1 << '\n';
            continue;
        }

        if(len & 1) {
            cout << 1 << '\n';
            continue;
        }

        if(A[l] == 0 || A[r] == 0) {
            cout << 1 << '\n';
            continue;
        }

        int t = xor_sum[l];
        if(l & 1) {
            vector<int>& v = eve_map[t];
            auto it = lower_bound(v.begin(), v.end(), l);
            if(it != v.end() && *it <= r) {
                cout << 2 << '\n';
            } else {
                cout << -1 << '\n';
            }
        } else {
            vector<int>& v = odd_map[t]; 
            auto it = lower_bound(v.begin(), v.end(), l);
            if(it != v.end() && *it <= r) {
                cout << 2 << '\n';
            } else {
                cout << -1 << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    
    run_case();
}

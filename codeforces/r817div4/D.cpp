#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <vector>
#include <string>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    cin >> N;
    string S;
    cin >> S;

    LL sum = 0LL;
    for(int i = 0; i < N; i++) {
        if(S[i] == 'L') {
            sum += i;
        } else {
            sum += N - 1 - i;
        }
    }
    
    vector<int> v;
    for(int i = 0; i < N / 2; i++) {
        if(S[i] == 'L') {
            v.emplace_back(i);
        }
    }

    for(int i = (N + 1) / 2; i < N; i++) {
        if(S[i] == 'R') {
            v.emplace_back(N - 1 - i);
        }
    }

    sort(v.begin(), v.end());

    LL cur = sum;
    for(int i = 0, k = 1; k <= N; k++, i++) {
        if(i < v.size()) {
            cur -= v[i];
            cur += N - 1 - v[i];
        } 

        cout << cur << " \n"[k == N];
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

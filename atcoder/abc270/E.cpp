#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;
using LL = long long;

void run_case() {
    int N;
    LL K;
    cin >> N >> K;

    vector<LL> A(N, 0LL);
    
    map<LL, LL> cnt_map;
    LL left = 0LL;
    for(int i = 0; i < N; i++) {
        cin >> A[i];

        if(A[i]) {
            left++;
            cnt_map[A[i]]++;
        }
    }

    LL round = 0;
    LL rem = 0;
    while(K && !cnt_map.empty()) {
        LL min_v = cnt_map.begin()->first; 
        LL tot = (min_v - round) * left; 

        if(K >= tot) {
            K -= tot;
            round = min_v;
            left -= cnt_map[min_v];

            cnt_map.erase(min_v);
        } else {
            LL can = K / left;
            rem = K % left;

            round += can;
            K = 0; 
        }
    }

    for(int i = 0; i < N; i++) {
        A[i] = max(0LL, A[i] - round);
    }

    for(int i = 0; i < N; i++) {
        if(rem && A[i]) {
            A[i]--; 
            rem--;
        }
    }

    for(int i = 0; i < N; i++) {
        cout << A[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

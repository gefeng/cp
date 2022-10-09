#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, M;
    cin >> N >> M;
    
    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }
 
    vector<vector<int>> turn(M + 1);
    for(int i = 0; i < N; i++) {
        if(A[i] >= N) {
            continue;
        }

        int l = 0;
        int r = 0;
        if(A[i] < 0) {
            l = -A[i] / (i + 1) + (-A[i] % (i + 1) == 0 ? 0 : 1);   
            r = (-A[i] + N) / (i + 1) + ((-A[i] + N) % (i + 1) == 0 ? 0 : 1);
        } else {
            l = 1;
            r = (N - A[i]) / (i + 1) + ((N - A[i]) % (i + 1) == 0 ? 0 : 1);
        }

        if(l > M) {
            continue;
        }
        r = min(M + 1, r);
        for(int j = l; j < r; j++) {
            turn[j].push_back(A[i] + (i + 1) * j);
        }
    }

    for(int i = 1; i <= M; i++) {
        vector<int>& v = turn[i];
        vector<bool> seen(v.size(), false);

        for(int x : v) {
            if(x < v.size()) {
                seen[x] = true;
            }
        }

        int mex = v.size();
        for(int j = 0; j < v.size(); j++) {
            if(!seen[j]) {
                mex = j; 
                break;
            }
        }

        cout << mex << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

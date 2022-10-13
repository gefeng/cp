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

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> ans;
    vector<bool> taken(N, false);

    ans.reserve(N);
    int sum = 0;
    for(int i = 0; i < 32; i++) {
        int max = 0;
        int pick = -1;
        for(int j = 0; j < N; j++) {
            if(!taken[j] && (sum | A[j]) > max) {
                max = sum | A[j];
                pick = j;
            } 
        }

        if(pick == -1) {
            break;
        }

        taken[pick] = true;
        sum = max;
        ans.push_back(A[pick]);
    }

    for(int i = 0; i < N; i++) {
        if(!taken[i]) {
            ans.push_back(A[i]);
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
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

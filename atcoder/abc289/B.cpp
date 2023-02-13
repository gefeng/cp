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

    vector<int> A(M);
    for(int i = 0; i < M; i++) {
        cin >> A[i]; 
    } 

    vector<int> ans;
    for(int i = 1, j = 0; i <= N; i++) {
        int l = i;
        while(j < M && i == A[j]) {
            j += 1;
            i += 1;
        }

        if(i == l) {
            ans.push_back(i);
        } else {
            for(int k = i; k >= l; k--) {
                ans.push_back(k);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        cout << ans[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

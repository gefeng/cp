#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

void run_case() {
    int N, W;
    cin >> N >> W;
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    unordered_set<int> ans;
    ans.reserve(10 * N);
    for(int i = 0; i < N; i++) {
        if(A[i] <= W) {
            ans.insert(A[i]);
        } 
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            if(A[i] + A[j] <= W) {
                ans.insert(A[i] + A[j]);
            }
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = i + 1; j < N; j++) {
            for(int k = j + 1; k < N; k++) {
                if(A[i] + A[j] + A[k] <= W) {
                    ans.insert(A[i] + A[j] + A[k]);
                }
            }
        }
    }

    cout << ans.size() << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

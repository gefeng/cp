#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>

using namespace std;

void run_case() {
    int N, X;
    cin >> N >> X;

    vector<int> A(N);
    
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    vector<int> ans;
    for(int i = 0; i < N; i++) {
        if(A[i] != X) {
            ans.push_back(A[i]);
        }
    }

    int sz = ans.size();
    for(int i = 0; i < sz; i++) {
        cout << ans[i] << " \n"[i == sz - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

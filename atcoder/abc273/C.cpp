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
    int N;
    cin >> N;

    vector<int> A(N, 0);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    for(int i = 0, j = N - 1; i < N; i++) {
        if(j < 0) {
            cout << 0 << '\n';
            continue;
        }
        int k = j;
        while(j >= 0 && A[j] == A[k]) {
            j--;
        }

        cout << k - j << '\n'; 
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

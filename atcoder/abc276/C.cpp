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
    
    vector<int> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int p = N - 1;
    while(A[p] > A[p - 1]) {
        p -= 1;
    }

    for(int i = N - 1; i >= p; i--) {
        if(A[i] < A[p - 1]) {
            swap(A[i], A[p - 1]);
            break;
        }
    }

    reverse(A.begin() + p, A.end());
    
    for(int i = 0; i < N; i++) {
        cout << A[i] << " \n"[i == N - 1];
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

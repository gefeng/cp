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

    if(A[0] != 1) {
        cout << "No" << '\n';
        return;
    }

    for(int i = 2; i <= N; i++) {
        int p = 0;
        for(int j = 0; j < N; j++) {
            if(A[j] == i) {
                p = j;
                break;
            }
        }

        if(A[i - 1] < i) {
            cout << "No" << '\n';
            return;
        }

        swap(A[i - 1], A[p]);
    }

    cout << "Yes" << '\n';
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

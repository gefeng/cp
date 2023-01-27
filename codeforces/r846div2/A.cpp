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

    vector<int> odd;
    for(int i = 0; i < N; i++) {
        if(A[i] & 1) {
            odd.push_back(i + 1);
        }
    }

    if(odd.empty()) {
        cout << "No" << '\n';
        return;
    }
    if(odd.size() == 2 && N == 3) {
        cout << "No" << '\n';
        return;
    }

    cout << "Yes" << '\n';
    if(odd.size() > 2) {
        for(int i = 0; i < 3; i++) {
            cout << odd[i] << " \n"[i == 2];
        } 
    } else {
        for(int i = 0, j = 0; i < N && j < 2; i++) {
            if(A[i] % 2 == 0) {
                cout << i + 1 << ' ';
                j += 1;
            }
        }

        cout << odd[0] << '\n';
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

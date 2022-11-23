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
    cin >> N;

    vector<LL> A(N);
    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    int Q;
    cin >> Q;

    int last_i = -1;
    int last_x = -1;
    map<int, int> m;

    for(int i = 0; i < Q; i++) {
        int T;
        cin >> T;
        
        if(T == 1) {
            LL X;
            cin >> X;
            last_i = i;
            last_x = X;
        }
        if(T == 2) {
            int I;
            LL X;
            cin >> I >> X;

            I -= 1;

            if(last_i == -1) {
                A[I] += X;
            } else {
                if(m.find(I) == m.end()) {
                    A[I] = last_x + X;
                } else {
                    int pre = m[I];
                    if(pre < last_i) {
                        A[I] = last_x + X;
                    } else {
                        A[I] += X;
                    }
                }
            }

            m[I] = i;
        }
        if(T == 3) {
            int I;
            cin >> I;

            I -= 1;
            
            if(last_i == -1) {
                cout << A[I] << '\n';
            } else {
                if(m.find(I) == m.end()) {
                    A[I] = last_x;
                } else {
                    int pre = m[I];
                    if(pre < last_i) {
                        A[I] = last_x;
                    }
                }

                m[I] = i;
                cout << A[I] << '\n';
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

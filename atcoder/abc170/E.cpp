#include <iostream>
#include <cassert>
#include <algorithm>
#include <cmath>
#include <array>
#include <string>
#include <vector>
#include <map>

using namespace std;

const int MAX = (int)2e5;

void run_case() {
    int N, Q;
    cin >> N >> Q;

    vector<map<int, int>> A(MAX + 1);
    vector<map<int, int>> B(MAX + 1);
    map<int, int> im; 
    map<int, int> em;
    
    for(int i = 0; i < N; i++) {
        int X, Y;
        cin >> X >> Y;

        A[Y][i + 1] = X;
        B[Y][X] += 1;
        im[i + 1] = Y;
    }

    for(int i = 1; i <= MAX; i++) {
        if(B[i].empty()) {
            continue;
        }

        em[B[i].rbegin()->first] += 1;
    }

    for(int i = 0; i < Q; i++) {
        int C, D;
        cin >> C >> D;

        int old_k = im[C];
        int r = A[old_k][C];

        im.erase(C);
        A[old_k].erase(C);

        if(--B[old_k][r] == 0) {
            B[old_k].erase(r);

            if(B[old_k].empty() || B[old_k].rbegin()->first < r) {
                if(--em[r] == 0) {
                    em.erase(r);
                }

                if(!B[old_k].empty()) {
                    em[B[old_k].rbegin()->first] += 1;
                }
            }
        }

        im[C] = D;
        A[D][C] = r;

        //cout << old_r << '\n';
        if(B[D].empty()) {
            em[r] += 1;
        } else if(B[D].rbegin()->first < r) {
            int old_r = B[D].rbegin()->first;
            if(--em[old_r] == 0) {
                em.erase(old_r);
            }
            
            em[r] += 1;
        }
        B[D][r] += 1;

        cout << em.begin()->first << '\n';
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

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

    int sum = 0;
    for(int x : A) {
        sum += x;
    }

    if(sum == 0) {
        cout << N << '\n';
        for(int i = 1; i <= N; i++) {
            cout << i << ' ' << i << '\n';
        }
    } else {
        vector<pair<int, int>> flip;
        vector<pair<int, int>> ans;
        flip.reserve(N);
        ans.reserve(N);

        if(sum < 0) {
            for(int i = 1; i < N; i++) {
                if((A[i] == -1 && A[i - 1] == -1) || (A[i] == -1 && A[i - 1] == 0)) {
                    if(sum < 0) {
                        flip.emplace_back(i, i + 1);
                        sum += 2;
                        i++;
                    } else {
                        break;
                    }
                }
            }         
        } else {
            for(int i = 1; i < N; i++) {
                if((A[i] == 1 && A[i - 1] == 1) || (A[i] == 1 && A[i - 1] == 0)) {
                    if(sum > 0) {
                        flip.emplace_back(i, i + 1);
                        sum -= 2;
                        i++;
                    } else {
                        break;
                    }
                }
            }
        }

        if(sum != 0) {
            cout << -1 << '\n';
            return;
        }

        int last = 0;
        for(auto& p : flip) {
            int l = p.first;
            int r = p.second;

            for(int i = last + 1; i < l; i++) {
                ans.emplace_back(i, i);
            }

            ans.emplace_back(l, r);
            last = r;
        }

        for(int i = last + 1; i <= N; i++) {
            ans.emplace_back(i, i);
        }

        int m = ans.size();
        cout << m << '\n';
        for(auto& p : ans) {
            cout << p.first << ' ' << p.second << '\n';
        }
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

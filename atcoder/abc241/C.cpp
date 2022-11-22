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

    vector<string> G(N);
    for(int i = 0; i < N; i++) {
        cin >> G[i];
    }

    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int l = 0, r = 0; r < N; r++) {
            if(G[i][r] == '#') {
                cnt += 1;
            }

            if(r - l + 1 > 6) {
                if(G[i][l] == '#') {
                    cnt -= 1;
                }
                l += 1;
            }

            if(r - l + 1 == 6 && cnt >= 4) {
                cout << "Yes" << '\n';
                return;
            }
        } 
    }

    for(int i = 0; i < N; i++) {
        int cnt = 0;
        for(int l = 0, r = 0; r < N; r++) {
            if(G[r][i] == '#') {
                cnt += 1;
            }
            
            if(r - l + 1 > 6) {
                if(G[l][i] == '#') {
                    cnt -= 1;
                }
                l += 1;
            }

            if(r - l + 1 == 6 && cnt >= 4) {
                cout << "Yes" << '\n';
                return;
            }
        }
    }

    for(int i = 0; i < N; i++) {
        int cnt = 0;
        int len = 0;
        int r = 0;
        int c = i;
        while(r >= 0 && c >= 0 && r < N && c < N) {
            len += 1;
            cnt += G[r][c] == '#' ? 1 : 0;

            if(len > 6) {
                cnt -= G[r - 6][c - 6] == '#' ? 1 : 0;
                len -= 1;
            }
            
            if(len == 6 && cnt >= 4) {
                cout << "Yes" << '\n';
                return;
            }

            r += 1;
            c += 1;
        }
    }
    
    for(int i = 1; i < N; i++) {
        int cnt = 0;
        int len = 0;
        int r = i;
        int c = 0;
        while(r >= 0 && c >= 0 && r < N && c < N) {
            len += 1;
            cnt += G[r][c] == '#' ? 1 : 0;

            if(len > 6) {
                cnt -= G[r - 6][c - 6] == '#' ? 1 : 0;
                len -= 1;
            }
            
            if(len == 6 && cnt >= 4) {
                cout << "Yes" << '\n';
                return;
            }

            r += 1;
            c += 1;
        }
    }


    for(int i = N - 1; i >= 0; i--) {
        int cnt = 0;
        int len = 0;
        int r = 0;
        int c = i;
        while(r >= 0 && c >= 0 && r < N && c < N) {
            len += 1;
            cnt += G[r][c] == '#' ? 1 : 0;

            if(len > 6) {
                cnt -= G[r - 6][c + 6] == '#' ? 1 : 0;
                len -= 1;
            }
            
            if(len == 6 && cnt >= 4) {
                cout << "Yes" << '\n';
                return;
            }

            r += 1;
            c -= 1;
        }
    }


    for(int i = 1; i < N; i++) {
        int cnt = 0;
        int len = 0;
        int r = i;
        int c = N - 1;
        while(r >= 0 && c >= 0 && r < N && c < N) {
            len += 1;
            cnt += G[r][c] == '#' ? 1 : 0;

            if(len > 6) {
                cnt -= G[r - 6][c + 6] == '#' ? 1 : 0;
                len -= 1;
            }
            
            if(len == 6 && cnt >= 4) {
                cout << "Yes" << '\n';
                return;
            }

            r += 1;
            c -= 1;
        }
    }

    cout << "No" << '\n';
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    run_case();
}

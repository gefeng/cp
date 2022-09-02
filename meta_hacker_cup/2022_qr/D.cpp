#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_set>
#include <unordered_map>

using namespace std;
using LL = long long;

//ifstream in;
//ofstream out;

void run_case(int T) {
    int N, M, Q;
    cin >> N >> M >> Q;
    
    vector<unordered_set<int>> G(N + 1);
    unordered_map<int, unordered_map<int, int>> W; 

    for(int i = 0; i < M; i++) {
        int A, B, C;
        cin >> A >> B >> C;

        G[A].insert(B);
        G[B].insert(A);
        W[A][B] = C;
        W[B][A] = C;
    } 

    auto hash = [](const int& x, const int& y) {
        return x * 200005 + y;
    };

    cout << "Case #" << T << ": ";
    unordered_map<int, LL> save;
    for(int i = 0; i < Q; i++) {
        int X, Y;
        cin >> X >> Y;

        if(G[X].size() > G[Y].size()) {
            swap(X, Y);
        } 

        LL tot = 0;
        int key = hash(X, Y);
        if(save.find(key) != save.end()) {
            tot = save[key];
        } else {
            if(G[X].find(Y) != G[X].end()) {
                tot += (LL)W[X][Y] * 2LL;
            }
      
            for(int nei : G[X]) {
                if(G[nei].find(Y) != G[nei].end()) {
                    tot += min(W[X][nei], W[nei][Y]);
                }
            }

            save[key] = tot;
        }
         
        cout << tot << " \n"[i == Q - 1];
    }
}

int main() {
    //in.open("input.txt");
    //out.open("output.txt");

    int T;
    cin >> T;
    for(int i = 1; i <= T; i++) {
        run_case(i);
    }

    //in.close();
    //out.close();
}

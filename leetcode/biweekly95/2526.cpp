#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>
#include <queue>

using namespace std;

class DataStream {
    queue<int> q;
    map<int, int> m;
    int v;
    int k;
public:
    DataStream(int value, int k) {
        this->v = value;
        this->k = k;
    }
    
    bool consec(int num) {
        q.push(num);
        m[num] += 1;
        
        if(q.size() > k) {
            int x = q.front();
            q.pop();
            if(--m[x] == 0) {
                m.erase(x);
            }
        }
        
        if(q.size() < k || m.size() > 1 || m.begin()->first != v) {
            return false;
        }
        
        return true;
    }
};

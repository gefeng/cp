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
#include <tuple>

class Router {
public:
    std::queue<std::tuple<int, int, int>> q;
    std::set<std::tuple<int, int, int>> s;
    std::map<int, std::vector<int>> m;
    std::map<int, int> m_st;
    
    int capacity;
    Router(int memoryLimit) {
        capacity = memoryLimit;
    }
    
    bool addPacket(int source, int destination, int timestamp) {
        if(s.find({source, destination, timestamp}) != s.end()) {
            return false;
        }
        
        q.emplace(source, destination, timestamp);
        s.emplace(source, destination, timestamp);
        m[destination].push_back(timestamp);
        if(m[destination].size() == 0) {
            m_st[destination] = 0;
        }
    
        if(q.size() > capacity) {
            forwardPacket();
        }
    
        return true;
    }
    
    std::vector<int> forwardPacket() {
        std::vector<int> p;
        if(q.empty()) {
            return p;
        }
        auto [x, y, t] = q.front();
        q.pop();
        p.push_back(x);
        p.push_back(y);
        p.push_back(t);
        
        s.erase({x, y, t});
        m_st[y] += 1;
        
        return p;
    }
    
    int getCount(int destination, int startTime, int endTime) {
        int cnt = 0;
        if(m.find(destination) == m.end()) {
            return 0;
        }
        
        std::vector<int>& t = m[destination];
        int st = m_st[destination];
        cnt = std::upper_bound(t.begin() + st, t.end(), endTime) - std::lower_bound(t.begin() + st, t.end(), startTime);
        return cnt;
    }
};

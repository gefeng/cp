#include <algorithm>
#include <array>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <set>
#include <string>
#include <vector>

class TaskManager {
public:
    std::map<int, std::set<int>> m_1;
    std::map<int, std::pair<int, int>> m_2;
    std::map<int, std::set<int>> m_3;
    
    TaskManager(std::vector<std::vector<int>>& tasks) {
        for(auto& t : tasks) {
            m_1[t[0]].insert(t[1]);
            m_2[t[1]] = {t[0], t[2]};
            m_3[t[2]].insert(t[1]);
        }    
    }
    
    void add(int userId, int taskId, int priority) {
        m_1[userId].insert(taskId);
        m_2[taskId] = {userId, priority};
        m_3[priority].insert(taskId);
    }
    
    void edit(int taskId, int newPriority) {
        int old = m_2[taskId].second;
        
        m_3[old].erase(taskId);
        if(m_3[old].empty()) {
            m_3.erase(old);
        }
        
        m_3[newPriority].insert(taskId);
        m_2[taskId].second = newPriority;
    }
    
    void rmv(int taskId) {
        auto [u_id, p] = m_2[taskId];
        
        m_1[u_id].erase(taskId);
        if(m_1[u_id].empty()) {
            m_1.erase(u_id);
        }
        
        m_2.erase(taskId);
        
        m_3[p].erase(taskId);
        if(m_3[p].empty()) {
            m_3.erase(p);
        }
    }
    
    int execTop() {
        if(m_3.empty()) {
            return -1;
        }
        int task = *(m_3.rbegin()->second.rbegin());
        int u_id = m_2[task].first;
        rmv(task);
        return u_id;
    }
};

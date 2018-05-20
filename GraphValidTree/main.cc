/*
 * Given n nodes labeled from 0 to n-1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
 * 
 * Example 1:
 * 
 * Input: n = 5, and edges = [[0,1], [0,2], [0,3], [1,4]]
 * Output: true
 * Example 2:
 * 
 * Input: n = 5, and edges = [[0,1], [1,2], [2,3], [1,3], [1,4]]
 * Output: false
 * Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0,1] is the same as [1,0] and thus will not appear together in edges.
 *
 * https://leetcode.com/problems/graph-valid-tree/description/
 *
 */

class Solution {
public:
    
    bool isGraphCyclic(const vector<vector<int>>& adj, int v, vector<bool>& visited, int parent) {
        
        visited[v] = true;
        
        for (auto it = adj[v].begin(); it != adj[v].end(); it++) {
            if (!visited[*it]) {
                if (isGraphCyclic(adj, *it, visited, v)) {
                    return true;
                }
            }
            else if (*it != parent) {
                return true;
            }
        }
        
        return false;
    }
    
    void isGraphConnected(const vector<vector<int>>& adj, int s, vector<bool>& connected) {
        
        connected[s] = true;
        
        for (auto it = adj[s].begin(); it != adj[s].end(); it++) {
            if (!connected[*it]) {
                isGraphConnected(adj, *it, connected);
            }
        }
    }
    
    bool validTree(int n, vector<pair<int, int>>& edges) {
        vector<vector<int>> adj(n);
        
        for (auto e: edges) {
            adj[e.first].emplace_back(e.second);
            adj[e.second].emplace_back(e.first);
        }
        vector<bool> connected(n, false);
        
        isGraphConnected(adj, 0, connected);
        
        for (int i = 0; i < n; i++) {
            if (!connected[i]) {
                return false;
            }
        }
        
        vector<bool> visited(n, false);
        
        //for (int i = 0; i < n; i++) {
        //    if (!visited[i]) {
                if (isGraphCyclic(adj, 0, visited, -1)) {
                    return false;
                }
        //    }
        //}
        
        return true;
    }
};
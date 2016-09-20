//
//  main.cpp
//  BFS
//
//  Created by Vaibhav Chakki on 8/25/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class Graph
{
public:
    Graph(int v) {
        vertices_ = v;
        adj_ = new list<int>[vertices_];
    }
    
    void AddEdge(int v, int edge) {
        adj_[v].push_back(edge);
    }
    
    void BFS(int s);
    
private:
    int vertices_;
    list<int>* adj_;
    
};

void Graph::BFS(int s)
{
    if (s > vertices_) {
        return;
    }
    
    bool *visited = new bool[vertices_];
    
    for(int i = 0; i < vertices_; i++) {
        visited[i] = false;
    }
    
    list<int> queue;
    list<int>::iterator i;
    
    visited[s] = true;
    queue.push_back(s);
    
    while (!queue.empty()) {
        int n = queue.front();
        cout << n << "\t" << endl;
        queue.pop_front();
        
        for (i = adj_[n].begin(); i != adj_[n].end(); i++) {
            if (visited[*i] == false) {
                visited[*i] = true;
                queue.push_back(*i);
            }
        }
        
    }
}





int main(int argc, const char * argv[]) {
    

    Graph g(4);
    
    g.AddEdge(0, 1);
    g.AddEdge(0, 2);
    g.AddEdge(1, 2);
    g.AddEdge(2, 0);
    g.AddEdge(2, 3);
    g.AddEdge(3, 3);
    
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n";
    g.BFS(2);
    return 0;
}

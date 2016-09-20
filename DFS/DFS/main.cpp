//
//  main.cpp
//  DFS
//
//  Created by Vaibhav Chakki on 8/26/16.
//  Copyright © 2016 Vaibhav Chakki. All rights reserved.
//

#include <iostream>
#include <list>

using namespace std;

class Graph {
public:
    Graph(int V) {
        vertices_ = V;
        adj_ = new list<int>[V];
    }
    
    void addEdge(int v, int e)
    {
        adj_[v].push_back(e);
    }
    
    void DFS();
    
private:
    int vertices_;
    list<int> *adj_;
    
    void DFSUtil(int s, bool* visited);
};

void Graph::DFSUtil(int s, bool* visited)
{
    cout << s << "\t" << endl;
    visited[s] = true;
    
    for (auto i = adj_[s].begin(); i != adj_[s].end(); i++) {
        if (visited[*i] == false) {
            visited[*i] = true;
            DFSUtil(*i, visited);
        }
    }
}

void Graph::DFS()
{
    
    bool *visited = new bool[vertices_];
    
    for (int i = 0; i < vertices_; i++) {
        visited[i] = false;
    }
    
    for (int i = 0; i < vertices_; i++) {
        if (visited[i] == false) {
            DFSUtil(i, visited);
        }
    }
    
}

int main(int argc, const char * argv[]) {
    Graph g(4);
    g.addEdge(0, 1);
    g.addEdge(0, 2);
    g.addEdge(1, 2);
    g.addEdge(2, 0);
    g.addEdge(2, 3);
    g.addEdge(3, 3);
    
    cout << "Following is the DFS \n";
    g.DFS();
    
}

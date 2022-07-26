/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

//BFS

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        queue<Node*> q;
        q.push(node);
        Node* copy = new Node(node->val);
        clone[node] = copy;
        
        while(!q.empty()){
            Node* curr = q.front();
            q.pop();
            
            for(auto &it:curr->neighbors){
                if(clone.find(it)==clone.end()){
                    clone[it] = new Node(it->val);                  
                    q.push(it);
                }
                clone[curr]->neighbors.push_back(clone[it]);
            }
        }
        
        return copy;
    }
    
    private:
    unordered_map<Node*,Node*> clone;
};

//DFS

class Solution {
public:
    void dfs(Node *node){
        for(auto it:node->neighbors){
            if(clone.find(it)==clone.end()){
                clone[it] = new Node(it->val);
                dfs(it);
            }
            clone[node]->neighbors.push_back(clone[it]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* copy = new Node(node->val);
        clone[node] = copy;
        dfs(node);
        return copy;
    }
    
    private:
    unordered_map<Node*,Node*> clone;
};

// DFS Optimized according to constraints
class Solution {
public:
    void dfs(Node *node){
        for(auto it:node->neighbors){
            if(!visited[it->val]){
                visited[it->val] = new Node(it->val);
                dfs(it);
            }
            visited[node->val]->neighbors.push_back(visited[it->val]);
        }
    }
    Node* cloneGraph(Node* node) {
        if(!node) return NULL;
        Node* copy = new Node(node->val);
        visited[node->val] = copy;
        dfs(node);
        return copy;
    }
    
    private:
        Node* visited[101];
};

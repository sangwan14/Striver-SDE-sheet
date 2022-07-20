/*    BFS - right to left

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return nullptr;
        queue<Node*> q;
        q.push(root);        
        while(size(q)) {
            Node* rightNode = nullptr;                   
            for(int i = size(q); i; i--) {               
                auto cur = q.front(); q.pop();            
                cur -> next = rightNode;                 
                rightNode = cur;                          
                if(cur -> right)                          
                    q.push(cur -> right),                 
                    q.push(cur -> left);                  
            }
        }
        return root;
    }
};

*/

/*  BFS - left to right 

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        
        queue<Node*> q;
        q.push(root);
        
        Node* prev = NULL;
        
        while(q.size()){
            int size = q.size();
            for(int i=0;i<size;i++){
                Node* curr = q.front();
                q.pop();
                
                if(prev) prev->next = curr;
                prev = curr;
                
                if(curr->left) {
                 q.push(curr->left);
                 q.push(curr->right);
                } 
            }
            prev = NULL;
        }
        
        return root;
    }
};

*/

/* DFS

class Solution {
public:
    Node* prev = NULL;
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(root->left) { 
            root->left->next = root->right;
            if(root->next) root->right->next = root->next->left;
        }
        connect(root->left);
        connect(root->right);
        return root;
    }
};

*/

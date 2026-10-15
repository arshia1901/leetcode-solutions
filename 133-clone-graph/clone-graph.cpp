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

class Solution {
private: 
    Node* dfs(Node* node, unordered_map<Node*, Node*>& clones){
        //create clone of this node first 
        if(clones.count(node)){
            return clones[node]; 
        }
        Node* clone = new Node(node->val); 
        clones[node]=clone; 
        for(auto neighbor : node->neighbors){
            clone->neighbors.push_back(dfs(neighbor, clones)); 
        }
        return clone; 
    }
public:
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> clones; 
        if(node==nullptr){
            return node; 
        }
        return dfs(node, clones); 
    }
};
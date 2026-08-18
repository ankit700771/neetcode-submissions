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
public:
    Node* cloneGraph(Node* node) {

        if(!node) 
            return NULL;

        unordered_map<Node*, Node*> mp;
        queue<pair<Node*, Node*>> q;
        Node* clone_node = new Node(node->val);
        mp[node] = clone_node;
        q.push({node, clone_node});

        while(!q.empty()) {
            auto [temp, newNode] = q.front();
            q.pop();

            for(auto n: temp->neighbors) {
                if(mp.find(n) == mp.end()) {
                    Node* clone = new Node(n->val);
                    mp[n] = clone;
                    newNode->neighbors.push_back(clone);
                    q.push({n, clone});
                } else {
                    newNode->neighbors.push_back(mp[n]);
                }
            }

        }

        return clone_node;

    }
};

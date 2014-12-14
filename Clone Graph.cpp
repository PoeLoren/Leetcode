/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        if(m.find(node->label) != m.end())
            return m[node->label];
        UndirectedGraphNode* root = new UndirectedGraphNode(node->label);
        m[node->label] = root;
        for(int i = 0; i < node->neighbors.size(); i++)
        {
            UndirectedGraphNode* newNode = cloneGraph(node->neighbors[i]);
            root->neighbors.push_back(newNode);
        }
        return root;
    }
private:
    unordered_map<int, UndirectedGraphNode*> m;
};
// DFS traversal with vector<node*> vis to know if a node is visited
// if it is not visited create a clone node , add it to neighbor of parent node , add it to vis array and call dfs on it and original node
// video link : https://www.youtube.com/watch?v=f2EfGComRKM&t=141s
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

void dfs(Node * node,Node * cl,vector<Node*> &vis){

 //Node * cl = Node(node->val);
    // if(vis[cl->val]==NULL)
    //     vis[cl->val]=clone;

        for(auto it : node->neighbors){
            if(vis[it->val]==NULL){
                Node * cp = new Node(it->val);
                (cl->neighbors).push_back(cp);
                vis[it->val]=cp;
                dfs(it,cp,vis);
            }

            else{
                 (cl->neighbors).push_back(vis[it->val]);
            }
        }
}
    Node* cloneGraph(Node* node) {
        
        vector<Node*> vis(1000,NULL);

        if(node==NULL)
        return NULL;

        Node * clone = new Node(node->val);

        if(vis[clone->val]==NULL)
        vis[clone->val]=clone;

        // for(auto it : node->neighbors){
        //     if(vis[it->val]==NULL){
        //         Node * cl = new Node(it->val);
        //         (clone->neighbors).push_back(cl);
        //         vis[it->val]=cl;
        //         dfs(it,cl,vis);
        //     }

        //     else{
        //          (clone->neighbors).push_back(vis[it->val]);
        //     }
        // } // this also works

        dfs(node,clone,vis);

        return clone;
    }
};

// similar approach but instead of vis array we use hashmap   and video reference is Neetcode
class Solution {
    public:
    Node* dfs(Node* cur,unordered_map<Node*,Node*>& mp)
    {
        vector<Node*> neighbour;
        Node* clone=new Node(cur->val);
        mp[cur]=clone;
            for(auto it:cur->neighbors)
            {
                if(mp.find(it)!=mp.end())   //already clone and stored in map
                {
                    neighbour.push_back(mp[it]);    //directly push back the clone node from map to neigh
                }
                else
                    neighbour.push_back(dfs(it,mp));
            }
            clone->neighbors=neighbour;
            return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(node==NULL)
            return NULL;
        if(node->neighbors.size()==0)   //if only one node present no neighbors
        {
            Node* clone= new Node(node->val);
            return clone; 
        }
        return dfs(node,mp);
    }
};

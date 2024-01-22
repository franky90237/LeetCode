//2024-01-22
//time  : O(n)
//space : O(n)
class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string res;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty())
        {
            TreeNode* cur=q.front();
            q.pop();                        
            
            if(cur)
            {
                res += to_string(cur->val) + ","; 
                q.push(cur->left);
                q.push(cur->right);
            }
            else
            {
                res += "N,";
            }
        }
        
        return res;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        vector<int> nodes;
        string cur;
        for(int i=0; i<data.size(); ++i)
        {            
            if(data[i] == ',')
            {
                nodes.push_back(stoi(cur));
                cur="";
                continue;
            }
            
            if(data[i] == 'N') cur = "99999";
            else cur += data[i];
        }
        
        if(nodes[0] == 99999) return NULL;
        
        TreeNode* root=new TreeNode(nodes[0]);
        queue<TreeNode*> q;
        q.push(root);
        int idx=1;        
        while(idx < nodes.size())
        {
            TreeNode* cur=q.front();
            q.pop();

            if(nodes[idx] != 99999) 
            {
                cur->left=new TreeNode(nodes[idx]);
                q.push(cur->left);
            }
            ++idx;

            if(idx >= nodes.size()) break;
            if(nodes[idx] != 99999) 
            {
                cur->right=new TreeNode(nodes[idx]);
                q.push(cur->right);
            }
            ++idx;
        }
        
        return root;
    }
};

//2024-01-22
//time  : O(n)
//space : O(n)
class Codec 
{
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) 
    {
        string res;
        dfs(root, res);
        return res;
    }
    
    void dfs(TreeNode* root, string& res)
    {
        if(!root)
        {
            res += "N,";
            return;
        }
        
        res += to_string(root->val) + ",";
        dfs(root->left, res);
        dfs(root->right, res);
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) 
    {
        deque<string> nodes;
        string cur;
        for(int i=0; i<data.size(); ++i)
        {            
            if(data[i] == ',')
            {
                nodes.emplace_back(cur);
                cur="";
                continue;
            }
            
            if(data[i] == 'N') cur = "N";
            else cur.push_back(data[i]);
        }                
        
        return buildTree(nodes);
    }
    
    TreeNode* buildTree(deque<string>& nodes)
    {
        if(nodes.front() == "N") 
        {
            nodes.pop_front();
            return NULL;
        }
        
        TreeNode* cur=new TreeNode(stoi(nodes.front()));
        nodes.pop_front();
        cur->left = buildTree(nodes);
        cur->right = buildTree(nodes);
        
        return cur;
    }
};

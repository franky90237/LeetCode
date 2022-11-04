//2022-10-30
//TLE
//time  : O(n*n)
//space : O(n)
class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries)
    {
        vector<int> ans;
        unordered_map<int, int> dp; 
        for(int i=0; i<queries.size(); ++i)
        {
            if(dp.find(queries[i]) != dp.end())
            {
                ans.push_back(dp[queries[i]]);
                continue;
            }
            
            int depth=dfs(root, queries[i])-1;
            //cout<<depth<<endl;
            
            ans.push_back(depth);
            dp[queries[i]]=depth;
        }
        
        return ans;
    }
    
    int dfs(TreeNode* root, int val)
    {
        if(!root) return 0;
        if(root->val == val) return 0;                
        
        return 1 + max(dfs(root->left, val), dfs(root->right, val));
    }
};


//2022-11-03
//TLE
//time  : O(nlog(n))
//space : O(n)
struct item
{   
    int p;
    int l;
    int r;
    int h;
    
    item()
    {
        
    }
    
    item(int _p, int _l, int _r, int _h)
    {
        p=_p;
        l=_l;
        r=_r;
        h=_h;
    }    
};

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        unordered_map<int, item> table;
        dfs(NULL, root, table);
        
        unordered_map<int, int> visited;
        vector<int> ans;
        for(int num: queries)
        {
            if(visited.find(num) == visited.end())
            {
                int height=getTrimHeight(root->val, num, table);
                ans.push_back(height);
            }
            else
            {
                ans.push_back(visited[num]);
            }
        }
        
        return ans;
    }
    
    int dfs(TreeNode* parent, TreeNode* root, unordered_map<int, item>& table)
    {
        if(!root) return -1;
        
        int lLen=dfs(root, root->left, table);
        int rLen=dfs(root, root->right, table);
        
        int pVal = (parent) ? parent->val : -1;
        int lVal = (root->left) ? root->left->val : -1;
        int rVal = (root->right) ? root->right->val : -1;
        int height = max(lLen, rLen)+1;
        item tmp(pVal, lVal, rVal, height);
        table[root->val]=tmp;
        
        return height;
    }
    
    int getTrimHeight(int root, int cur, unordered_map<int, item>& table)
    {   
        int height=-1;
        while(cur != root)
        {
            int parent = table[cur].p;
            int sibling = (table[parent].l != cur) ? table[parent].l : table[parent].r; 
            height=max(height, table[sibling].h)+1;
            cur=parent;
        }
        
        return height;
    }
};

//2022-11-04
//TLE
//time  : O(nlog(n))
//space : O(n)
struct Item
{   
    int level;
    int height;
    
    Item()
    {
        
    }
    
    Item(int l, int h)
    {
        level=l;
        height=h;
    }    
};

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        unordered_map<int, Item> table;
        vector<vector<int>> hierarchy;
        dfs(0, root, table, hierarchy);
        
        unordered_map<int, int> visited;
        vector<int> ans;
        for(int num: queries)
        {
            if(visited.find(num) == visited.end())
            {
                int height=getTrimHeight(root->val, num, table, hierarchy);
                ans.push_back(height);
                visited[num]=height;
            }
            else
            {
                ans.push_back(visited[num]);
            }
        }
        
        return ans;
    }
    
    int dfs(int level, TreeNode* root, unordered_map<int, Item>& table, vector<vector<int>>& hierarchy)
    {
        if(!root) return -1;
        
        if(level == hierarchy.size()) hierarchy.push_back({});
        hierarchy[level].push_back(root->val);
        
        int lLen=dfs(level+1, root->left, table, hierarchy);
        int rLen=dfs(level+1, root->right, table, hierarchy);                
        int height = max(lLen, rLen)+1;
        Item tmp(level, height);
        table[root->val]=tmp;
        
        return height;
    }
    
    int getTrimHeight(int root, int cur, unordered_map<int, Item>& table, vector<vector<int>>& hierarchy)
    {
        int level=table[cur].level;
        int height=level-1;
        for(int sibling: hierarchy[level])
        {
            if(sibling == cur) continue;
            height=max(height, table[sibling].level+table[sibling].height);
        }
                
        return height;
    }
};

//2022-11-04
//time  : O(nlog(n))
//space : O(n)
struct Item
{
    int parent;
    int left;
    int right;
    int level;
    int height;
    
    Item()
    {
        
    }
    
    Item(int p, int _left, int r, int _level, int h)
    {
        parent=p;
        left=_left;
        right=r;
        level=_level;
        height=h;
    }    
};

class Solution {
public:
    vector<int> treeQueries(TreeNode* root, vector<int>& queries) 
    {
        unordered_map<int, Item> table;
        vector<vector<int>> hierarchy;
        dfs(0, NULL, root, table, hierarchy);
        
        unordered_map<int, int> visited;
        vector<int> ans;
        for(int num: queries)
        {
            if(visited.find(num) == visited.end())
            {
                int level=table[num].level;
                int horizen=hierarchy[level].size();
                int vertical=level;
                
                int height;
                if(horizen < vertical) height=getHeightHorizental(root->val, num, table, hierarchy);
                else height=getHeightVertical(root->val, num, table);
                
                ans.push_back(height);
                visited[num]=height;
            }
            else
            {
                ans.push_back(visited[num]);
            }
        }
        
        return ans;
    }
    
    int dfs(int level, TreeNode* parent, TreeNode* root, unordered_map<int, Item>& table, vector<vector<int>>& hierarchy)
    {
        if(!root) return -1;
        
        if(level == hierarchy.size()) hierarchy.push_back({});
        hierarchy[level].push_back(root->val);
        
        int lLen=dfs(level+1, root, root->left, table, hierarchy);
        int rLen=dfs(level+1, root, root->right, table, hierarchy);
        int pVal = (parent) ? parent->val : -1;
        int lVal = (root->left) ? root->left->val : -1;
        int rVal = (root->right) ? root->right->val : -1;        
        int height = max(lLen, rLen)+1;
        
        Item tmp(pVal, lVal, rVal, level, height);
        table[root->val]=tmp;
        
        return height;
    }
    
    int getHeightHorizental(int root, int cur, unordered_map<int, Item>& table, vector<vector<int>>& hierarchy)
    {
        int level=table[cur].level;
        int height=level-1;
        for(int sibling: hierarchy[level])
        {
            if(sibling == cur) continue;
            height=max(height, table[sibling].level+table[sibling].height);
        }
                
        return height;
    }
    
    int getHeightVertical(int root, int cur, unordered_map<int, Item>& table)
    {   
        int height=-1;
        while(cur != root)
        {
            int parent = table[cur].parent;
            int sibling = (table[parent].left != cur) ? table[parent].left : table[parent].right; 
            height=max(height, table[sibling].height)+1;
            cur=parent;
        }
           
        return height;
    }
};

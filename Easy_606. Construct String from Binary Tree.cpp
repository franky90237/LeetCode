/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */

//2022-09-07
//time  : O(n)
//space : O(height of the tree)
class Solution {
public:
    string tree2str(TreeNode* root)
    {
        /*
        1 -> 1
        1,2 -> 1(2)
        1,2,3 ->  1(2)(3)
        */
        
        if(!root) return "";
        
        string left=tree2str(root->left);
        string right=tree2str(root->right);
        //cout<<root->val<<" "<<left<<" "<<right<<endl;
        
        if(left=="" && right=="")
        {
            return to_string(root->val);
        }
        else if(left=="" && right!="")
        {
            return to_string(root->val) + "()" +"(" + right + ")";
        }
        else if(left!="" && right=="")
        {
            return to_string(root->val) + "(" + left + ")";
        } 
        else
        {
            return to_string(root->val) + "(" + left + ")" + "(" + right + ")";
        }
    }
};

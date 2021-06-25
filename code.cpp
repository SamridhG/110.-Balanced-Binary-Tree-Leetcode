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
class Solution {
public:
    int max(int a,int b)
    {
        return a>b?a:b;
    }
    int height(TreeNode* root)
    {
        if(root==NULL)
        {
            return -1;
        }
        else
        {
            return (max(height(root->left),height(root->right))+1);
        }
    }
    bool isBalanced(TreeNode* root) {
        if(root==NULL)
        {
            return true;
        }
        queue<TreeNode *>A;
        A.push(root);
        while(!A.empty())
        {
            TreeNode *check=A.front();
            A.pop();
            if(abs(height(check->left)-height(check->right))>1)return false;
            if(check->left){A.push(check->left);}
            if(check->right){A.push(check->right);}
            
        }
        return true;
    }
};

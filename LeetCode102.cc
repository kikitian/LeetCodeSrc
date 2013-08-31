/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    
private:
    void dfs(TreeNode*& root, int left, int right, vector<int>& arr){
        if(left > right) return ;
        root = new TreeNode(arr[(left+right)/2]);
        dfs(root->left,left,(left+right)/2-1,arr);
        dfs(root->right,(left+right)/2+1,right,arr);
        return ;
    }
public:
    TreeNode *sortedArrayToBST(vector<int> &arr) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        
        if(arr.size()==0) return NULL;
        int size = arr.size();
        TreeNode* ret = new TreeNode(arr[size/2]);
        dfs(ret->left,0,size/2-1,arr);
        dfs(ret->right,size/2+1,size-1,arr);
        
        return ret;
    }

};
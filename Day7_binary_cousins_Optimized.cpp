/**
Cousins in Binary Tree

In a binary tree, the root node is at depth 0, and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, but have different parents.

We are given the root of a binary tree with unique values, and the values x and y of two different nodes in the tree.

Return true if and only if the nodes corresponding to the values x and y are cousins.

 

Example 1:

Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:

Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:

Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false

 

Note:

    The number of nodes in the tree will be between 2 and 100.
    Each node has a unique integer value from 1 to 100.

 

 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int depth1 = 0, depth2 = 0, p1 = 0, p2 = 0;

void get_x(struct TreeNode* root, int data, int depth, int prev)
{
    if(root==NULL) return;
    
    if(root->val==data) {
        depth1=depth;
        p1=prev;
        return;
    }
    
    depth++;
    get_x(root->left,data,depth,root->val);
    get_x(root->right,data,depth,root->val);
}

void get_y(struct TreeNode* root, int data, int depth, int prev)
{
    if(root==NULL) return;
    
    if(root->val==data) {
        depth2=depth;
        p2=prev;
        return;
    }
    
    depth++;
    get_y(root->left,data,depth,root->val);
    get_y(root->right,data,depth,root->val);
}

bool isCousins(struct TreeNode* root, int x, int y)
{
    depth1 = 0;
    depth2 = 0;
    p1 = 0;
    p2 = 0;
    
    if(root == NULL)
    {
        return false;
    }
    get_x(root,x,0,root->val);
    get_y(root,y,0,root->val);
       
    if(depth1 != depth2) return false;
    if(p1 == p2) return false;
    
    return true;
}

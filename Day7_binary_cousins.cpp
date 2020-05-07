/*Cousins in Binary Tree

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
*/
 
#include<stdio.h>
#include<stdlib.h>
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

int getdepth(struct TreeNode *node, int data, int depth) 
{ 
    if (node == NULL) 
        return 0; 
  
    if (node->val == data) 
        return depth; 
  
    int nextlevel = getdepth(node->left, data, depth+1); 
    if (nextlevel != 0) 
        return nextlevel; 
  
    nextlevel = getdepth(node->right, data, depth+1); 
    return nextlevel; 
} 

struct TreeNode* getParent(struct TreeNode* currnode, struct TreeNode* prevNode, int data)
{
    if (currnode == NULL) 
        return NULL; 
  
    // If current node is the required node 
    if (currnode->val == data) 
    { 
        return prevNode; 
    } 
    else if(getParent(currnode->left, currnode, data)==NULL)
    {
        return getParent(currnode->right, currnode, data); 
    } 
    else
    {
        return getParent(currnode->left, currnode, data);
    }
    
}

bool isCousins(struct TreeNode* root, int x, int y){
       
    struct TreeNode* p1;
    p1 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    struct TreeNode* p2;
    p2 = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    
    int depth1, depth2;
    
    p1 = getParent(root, NULL, x);
    p2 = getParent(root, NULL, y);
    
    depth1 = getdepth(root, x, 0);
    depth2 = getdepth(root, y, 0);
    
    if(p1 != p2 && depth1 == depth2)
    {
        return true;
    }
    else
    {
        return false;
    }
}
int main()
{
	return(0);
}

#include <bits/stdc++.h> 
/*
Structure of the Node of the BST is :

struct Node
{
    int data;
    Node *left;
    Node *right;

    Node(int val) 
    {
        data = val;
        left = right = NULL;
    }
};
*/

int findPrice(Node* root)
{
    Node* temp = root;
    int val = INT_MAX;

    while(temp != NULL){
        val = min(val,temp->data);
        if(temp -> left != NULL){
            temp = temp -> left;
        } 
        else{
            temp = temp -> right;
        } 
    }

    return val;
}

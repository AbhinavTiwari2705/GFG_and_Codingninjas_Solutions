/*****************************************************

    Following is the Binary Tree node structure:
    
    class BinaryTreeNode {
        public : 
        T data;
        BinaryTreeNode<T> *left;
        BinaryTreeNode<T> *right;

        BinaryTreeNode(T data) {
            this -> data = data;
            left = NULL;
            right = NULL;
        }
        
        ~BinaryTreeNode() {
            if(left) 
                delete left;
            if(right) 
                delete right;
        }
    };

******************************************************/
bool mirror(BinaryTreeNode<int>* root1,BinaryTreeNode<int>* root2)

{

    if(!root1 && !root2)

    {

        return true;

    }

    if(!root1||!root2)

    {

        return false;

    }

    if(root1->data!=root2->data)

    {

        return false;

    }

    return mirror(root1->left,root2->right) && mirror(root1->right,root2->left);

}

bool isSymmetric(BinaryTreeNode<int>* root)

{

    if (!root) {

        return true;

    }

 

    BinaryTreeNode<int>* root1=root->left;

    BinaryTreeNode<int>* root2=root->right;

 

    return mirror(root1,root2);

       

}

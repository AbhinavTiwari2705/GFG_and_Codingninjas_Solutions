//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};

// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N')
        return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;)
        ip.push_back(str);

    // Create the root of the tree.....
    Node* root = new Node(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size())
            break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = new Node(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


// } Driver Code Ends
/*
struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};
*/
class Solution {
  private:
  void inorderTraversal(Node* root, vector<int>& res) {
      if (!root) return;
      inorderTraversal(root->left, res);
      res.push_back(root->data);
      inorderTraversal(root->right, res);
  }

  vector<int> mergeSortedVectors(vector<int>& list1, vector<int>& list2) {
      vector<int> mergedList;
      int i = 0, j = 0;
      
      while (i < list1.size() && j < list2.size()) {
          if (list1[i] < list2[j]) {
              mergedList.push_back(list1[i]);
              i++;
          } else {
              mergedList.push_back(list2[j]);
              j++;
          }
      }
      
      while (i < list1.size()) {
          mergedList.push_back(list1[i]);
          i++;
      }
      
      while (j < list2.size()) {
          mergedList.push_back(list2[j]);
          j++;
      }
      
      return mergedList;
  }

  public:
    vector<int> merge(Node *root1, Node *root2) {
        vector<int> list1, list2;
        
        inorderTraversal(root1, list1);
        inorderTraversal(root2, list2);
        
        return mergeSortedVectors(list1, list2);
    }
};


//{ Driver Code Starts.
int main() {

    int t;
    string tc;
    getline(cin, tc);
    t = stoi(tc);
    while (t--) {
        string s;
        getline(cin, s);
        Node* root1 = buildTree(s);

        getline(cin, s);
        Node* root2 = buildTree(s);

        // getline(cin, s);
        Solution obj;
        vector<int> vec = obj.merge(root1, root2);
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i] << " ";
        cout << endl;
        /// cout<<"~"<<endl;
    }
    return 0;
}
// } Driver Code Ends

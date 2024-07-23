class Solution
{
public:
    // Function to return a list of nodes visible from the top view
    // from left to right in Binary Tree.
    vector<int> topView(Node *root)
    {
        if (!root) return {};

        // Map to store the top view nodes with horizontal distance as the key
        map<int, int> lines;
        // Queue to store nodes along with their horizontal distance
        queue<pair<Node*, int>> q;

        q.push({root, 0});
        vector<int> ans;

        while (!q.empty()) {
            auto node = q.front().first;
            int line = q.front().second;

            q.pop();

            // If this horizontal distance is being encountered for the first time
            if (lines.find(line) == lines.end()) {
                lines[line] = node->data;
            }

            // Push the left child with horizontal distance -1
            if (node->left) {
                q.push({node->left, line - 1});
            }

            // Push the right child with horizontal distance +1
            if (node->right) {
                q.push({node->right, line + 1});
            }
        }

        // Traverse the map to get the top view nodes
        for (auto i : lines) {
            ans.push_back(i.second);
        }

        return ans;
    }
};

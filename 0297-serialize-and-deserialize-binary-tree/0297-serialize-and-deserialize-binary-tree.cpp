class Codec {
public:

    // Serialize tree into a string
    string serialize(TreeNode* root) {
        if (root == NULL) {
            return "";
        }

        queue<TreeNode*> q;
        q.push(root);

        string result = "";

        while (!q.empty()) {
            TreeNode* node = q.front();
            q.pop();

            if (node == NULL) {
                result += "null,";
            } 
            else {
                result += to_string(node->val) + ",";

                q.push(node->left);
                q.push(node->right);
            }
        }

        return result;
    }


    // Deserialize string into a tree
    TreeNode* deserialize(string data) {
        if (data.empty()) {
            return NULL;
        }

        vector<string> nodes;
        string temp = "";

        // Split the string using commas
        for (char ch : data) {
            if (ch == ',') {
                nodes.push_back(temp);
                temp = "";
            } 
            else {
                temp += ch;
            }
        }

        TreeNode* root = new TreeNode(stoi(nodes[0]));

        queue<TreeNode*> q;
        q.push(root);

        int i = 1;

        while (!q.empty() && i < nodes.size()) {
            TreeNode* parent = q.front();
            q.pop();

            // Left child
            if (nodes[i] != "null") {
                TreeNode* leftNode = new TreeNode(stoi(nodes[i]));
                parent->left = leftNode;
                q.push(leftNode);
            }
            i++;

            // Right child
            if (i < nodes.size() && nodes[i] != "null") {
                TreeNode* rightNode = new TreeNode(stoi(nodes[i]));
                parent->right = rightNode;
                q.push(rightNode);
            }
            i++;
        }

        return root;
    }
};
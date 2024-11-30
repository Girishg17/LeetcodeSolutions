using namespace std;

struct Node {
    int arr[1][2]; // Single pair of [start, end]
    Node* left;
    Node* right;
};

// Function to create a new node
Node* createNode(int first, int second) {
    Node* newNode = new Node();
    newNode->arr[0][0] = first;
    newNode->arr[0][1] = second;
    newNode->left = nullptr;
    newNode->right = nullptr;
    return newNode;
}

class Solution {
public:
    // Insert a new pair into the tree
    void insert(int first, int second, Node*& root) {
        if (root == nullptr) {
            root = createNode(first, second);
            return;
        }

        if (first < root->arr[0][0]) { // Insert into the left subtree
            insert(first, second, root->left);
        } else { // Insert into the right subtree
            insert(first, second, root->right);
        }
    }

    // In-order traversal to collect the pairs in sorted order
    void inOrderTraversal(Node* root, vector<vector<int>>& result) {
        if (root == nullptr) return;
        inOrderTraversal(root->left, result);
        result.push_back({root->arr[0][0], root->arr[0][1]});
        inOrderTraversal(root->right, result);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // Build the adjacency list
        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        for (const auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

        // Find the start node for Eulerian Path
        int startNode = pairs[0][0]; // Default start node
        for (const auto& [node, degree] : outDegree) {
            if (outDegree[node] > inDegree[node]) {
                startNode = node;
                break;
            }
        }

        // Use Hierholzer's Algorithm to find Eulerian Path
        vector<vector<int>> result;
        stack<int> stk;
        stk.push(startNode);

        while (!stk.empty()) {
            int current = stk.top();
            if (!graph[current].empty()) {
                int next = graph[current].back();
                graph[current].pop_back();
                stk.push(next);
            } else {
                stk.pop();
                if (!stk.empty()) {
                    result.push_back({stk.top(), current});
                }
            }
        }

        // Reverse the result to get the correct order
        reverse(result.begin(), result.end());
        return result;
    }
};
struct Node {
    int arr[1][2]; 
    Node* left;
    Node* right;
};

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
    void insert(int first, int second, Node*& root) {
        if (root == nullptr) {
            root = createNode(first, second);
            return;
        }

        if (first < root->arr[0][0]) { 
            insert(first, second, root->left);
        } else { 
            insert(first, second, root->right);
        }
    }

 
    void inOrderTraversal(Node* root, vector<vector<int>>& result) {
        if (root == nullptr) return;
        inOrderTraversal(root->left, result);
        result.push_back({root->arr[0][0], root->arr[0][1]});
        inOrderTraversal(root->right, result);
    }

    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {

        unordered_map<int, vector<int>> graph;
        unordered_map<int, int> outDegree, inDegree;

        for (const auto& pair : pairs) {
            graph[pair[0]].push_back(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }

  
        int startNode = pairs[0][0]; 
        for (const auto& [node, degree] : outDegree) {
            if (outDegree[node] > inDegree[node]) {
                startNode = node;
                break;
            }
        }

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

        
        reverse(result.begin(), result.end());
        return result;
    }
};
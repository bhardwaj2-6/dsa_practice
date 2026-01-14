// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> postOrder(Node* node) {
        // code here
        stack<Node*> s1;
        stack<int> s2;
        s1.push(node);
        vector<int> ans;
        while(!s1.empty()){
            Node* temp=s1.top();
            s1.pop();
            s2.push(temp->data);
            if(temp->left) s1.push(temp->left);
            if(temp->right) s1.push(temp->right);
        }
        while(!s2.empty()){
            ans.push_back(s2.top());
            s2.pop();
        }
        return ans;
    }
};
// User function Template for C++

/* Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};*/
class Solution {
  public:
    vector<int> inOrder(Node* root) {
        // code here
        stack<Node*> s;
        stack<bool> visited;
        s.push(root);
        visited.push(0);
        vector<int> ans;
        while(!s.empty()){
            Node* temp=s.top();
            s.pop();
            bool flag=visited.top();
            visited.pop();
            if(flag==0){
                if(temp->right){
                    s.push(temp->right);
                    visited.push(0);
                }
                s.push(temp);
                visited.push(1);
                if(temp->left){
                    s.push(temp->left);
                    visited.push(0);
                }
            }else{
                ans.push_back(temp->data);
            }
        }
        return ans;
    }
};
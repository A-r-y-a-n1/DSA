#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    public:
    int val;
    TreeNode* left = NULL;
    TreeNode* right = NULL;

    TreeNode(int n){
        this -> val = n;
        this -> left = NULL;
        this -> right = NULL;
    }

};

int solveDFS(TreeNode* a , int value , int& m){
    if(!a) return 0;
    if(value >= m) return 0;
    if(a -> left == NULL && a -> right == NULL){
        value += (a -> val == 0);
        if(value < m) return 1;
        else return 0;
    }
    if(a -> val == 0){
        return solveDFS(a -> left , value+1 , m) + solveDFS(a -> right , value+1 , m);
    }
    else{
        return solveDFS(a -> left , 0 , m) + solveDFS(a -> right , 0 , m);
    }
}

int solveBFS(TreeNode* root, int m) {
    if (!root || m <= 0) return 0;
    
    queue<pair<TreeNode*, int>> q; // {node, current_consec_zeros}
    q.push({root, 0});
    int count = 0;

    while (!q.empty()) {
        auto a = q.front();
        TreeNode* node = a.first;
        int consec = a.second;
        q.pop();
        int current_consec = (node->val == 0) ? consec + 1 : 0;
        if (current_consec >= m) continue;
        if (!node->left && !node->right) {
            count++;
            continue;
        }
        if (node->left) q.push({node->left, current_consec});
        if (node->right) q.push({node->right, current_consec});
    }
    
    return count;
}

int main(){
    cout <<"MAKING TREE" << endl;
    TreeNode* root = new TreeNode(0);
    root -> left = new TreeNode(0);
    root -> right = new TreeNode(1);
    root -> left -> left = new TreeNode(0);
    root -> left -> right = new TreeNode(1);
    root -> right -> left = new TreeNode(0);
    root -> right -> right = new TreeNode(1);
    int m = 3;
    int ans = solveBFS(root , m);
    cout <<"ans is " << ans <<" ";
}
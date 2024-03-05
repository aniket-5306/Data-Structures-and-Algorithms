#include<iostream>
#include<queue>
using namespace std;

class Node{

    public:
    int data;
    Node *left;
    Node *right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }

};

Node* buildingBinaryTree(Node* root){

    queue<Node*> q;

    int data;
    cin >> data;
    if(data != -1){
        root = new Node(data);
        q.push(root);
    }

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();

        if(temp != NULL){

            int leftData;
            cin >> leftData;
            if(leftData != -1){
                temp -> left = new Node(leftData);
                q.push(temp -> left);
            }

            int rightData;
            cin >> rightData;
            if(rightData != -1){
                temp -> right = new Node(rightData);
                q.push(temp -> right);
            }

        }
    }

    return root;

}

int heightOfBinaryTree(Node* root){

    if(root == NULL)
        return 0;

    int left = heightOfBinaryTree(root -> left);
    int right = heightOfBinaryTree(root -> right);

    int ans = max(left, right) + 1;

    return ans;

}

pair<bool,int> checkBalancedBinaryTree(Node* root){

    if(root == NULL){
        pair<bool,int> p(true,0);
        return p;
    }

    pair<bool,int> checkLeft = checkBalancedBinaryTree(root -> left);
    pair<bool,int> checkRight = checkBalancedBinaryTree(root -> right);    

    int leftHeight = checkLeft.second;
    int rightHeight = checkRight.second;

    bool checkBalanced = abs(leftHeight - rightHeight) <= 1;
    int height = max(leftHeight,rightHeight) + 1;

    if(checkLeft.first && checkRight.first && checkBalanced){
        pair<bool,int> p(true,height);
        return p;
    }

    pair<bool,int> p(false,height);
    return p;        

}

void levelOrderTraversal(Node* root){

    queue<Node*> q;

    if(root != NULL){
        q.push(root);
        q.push(NULL);
    }

    while(!q.empty()){

        Node* temp = q.front();
        q.pop();

        if(temp == NULL){
            cout << endl;
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout << temp -> data << " ";
            if(temp -> left)
                q.push(temp -> left);
            if(temp -> right)
                q.push(temp -> right);
        }
    }
}


int main(){

    Node *root = NULL;

    cout << "Enter data :";
    root = buildingBinaryTree(root);

    levelOrderTraversal(root);

    if(checkBalancedBinaryTree(root).first){
        cout << "It is balanced" << endl;
    }
    else{
        cout << "It is not balanced" << endl;
    }

}
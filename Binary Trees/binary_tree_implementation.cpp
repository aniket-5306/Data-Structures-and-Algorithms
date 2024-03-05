#include<iostream>
#include<queue>
using namespace std;

class Node{
    public:
    int data;
    Node* left;
    Node* right;

    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
    }
};

Node* binaryTreeCreation(Node* root){

    int data;
    cin >> data;

    if(data == -1)
        return NULL;

    root = new Node(data);    

    // cout << "Insert a node to the left of " << data << " :";
    root -> left = binaryTreeCreation(root -> left);
    // cout << "Insert a node to the right of " << data << " :";
    root -> right = binaryTreeCreation(root -> right);    

    return root;

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

void inorder(Node* root){

    if(root == NULL)
        return;

    // inorder -> (LNR)
    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);

}

void preorder(Node* root){

    if(root == NULL)
        return;

    // preorder -> (NLR)
    cout << root -> data << " ";
    preorder(root -> left);
    preorder(root -> right);

}

void postorder(Node* root){

    if(root == NULL)
        return;

    // postorder -> (LRN)
    postorder(root -> left);
    postorder(root -> right);
    cout << root -> data << " ";

}

int main(){

    Node* root = NULL;
    cout << "Enter data:";
    root = binaryTreeCreation(root);
    // 1 5 9 -1 -1 3 -1 -1 10 5 -1 -1 7 -1 -1

    levelOrderTraversal(root);

    // cout << "Inorder ->";
    // inorder(root); 
    // cout << endl;

    // cout << "Preorder ->";
    // preorder(root); 
    // cout << endl;

    // cout << "Postorder ->";
    // postorder(root); 
    // cout << endl;

}
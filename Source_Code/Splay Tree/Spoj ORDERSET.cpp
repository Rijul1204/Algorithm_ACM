/*
Author : Rashedul Hasan Rijul (Silent_Coder).
Algo   : Splay Tree.
Problem Name: ORDERSET.
OJ     : Spoj.
implementation help : Moshiur vai . (problem solving blog)
*/

#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
using namespace std;


//  Splay tree ........................

#define sp_tree splay_tree
#define key_type int
#define KEY_TYPE key_type
#define INF (1<<30)

// Node  represents a Single node in a tree.......
class Node{

public:
    int cnt; //  size of subtree rooted frome this node.

    Node *left,*right,*parent;


    key_type key;

    Node();
    Node(key_type _key);

    ~Node();

    int calcTreeSize(); // calculate the size of tree rooted at this node.
    bool isLeftChild();
    bool isRightChild();
    bool isRoot();
    Node* FindNearest(const KEY_TYPE _key);

    KEY_TYPE getKeyVal();
    int      getCnt();

    Node* Insert(key_type _key);
    Node* Insert(Node* newNode);
    Node* Delete();
    Node* Delete(KEY_TYPE _key);

    void Rotate();
    void Zig();
    void ZigZig();
    void ZigZag();

    Node* Splay();
    Node* SplayUntil(Node* until);

    void PrintInOrder();
    void PrintPreOrder();

};

Node::Node()
{
    key     = 0;
    cnt     = 0;
    left    = NULL;
    right   = NULL;
    parent  = NULL;
}

Node::Node(const key_type _key)
{
    key     = _key;
    cnt     = 1;
    left    = NULL;
    right   = NULL;
    parent  = NULL;
}
Node::~Node()
{

}

int Node::calcTreeSize()
{
    return 1 + (this->left?this->left->cnt:0) + (this->right?this->right->cnt:0);
}
bool Node::isLeftChild()
{
    return (this->parent!=NULL && this->parent->left == this);
}
bool Node::isRightChild()
{
    return (this->parent!=NULL && this->parent->right == this);
}
bool Node::isRoot()
{
    return this->parent == NULL;
}

Node* Node::FindNearest(const KEY_TYPE _key)
{
    Node *ret = this;

    while(true)
    {

        if(ret->key < _key)
        {
            if(ret->right)
            {
                ret = ret->right;
            }
            else
                break;
        }
        else if(ret->key > _key)
        {
            if(ret->left)
            {
                ret = ret->left;
            }
            else
                break;
        }
        else
        {
            break;
        }
    }

    return ret;
}



Node* Node::Insert(key_type _key)
{
    return this->Insert(new Node(_key));
}
Node* Node::Insert(Node* newNode)
{
    if(newNode == NULL)
        return this;
    Node* curNode = this;
    bool alreadyThere = false;

    while(true)
    {
        if(newNode->key > curNode->key)
        {
            if(curNode->right)
            {
                curNode = curNode->right;
            }
            else
            {
                curNode->right = newNode;
                newNode->parent = curNode;
                break;
            }
        }
        else if(newNode->key < curNode->key)
        {
            if(curNode->left)
            {
                curNode = curNode->left;
            }
            else
            {
                curNode->left = newNode;
                newNode->parent = curNode;
                break;
            }
        }
        else
        {
            return this;
        }
    }

    Node* temp = newNode->parent;

    while(temp){
        temp->cnt = temp->calcTreeSize();
        temp = temp->parent;
    }

    return newNode->Splay();
}

Node* Node::Delete()
{
    Node *ROOT=this->Splay();

    if(this->left)
    {
        Node* maxNode = this->left->FindNearest(INF);
        maxNode->SplayUntil(this->left);

        this->left->right = this->right;

        if(this->right)
            this->right->parent = this->left;

        ROOT = this->left;
        ROOT->parent = NULL;
        ROOT->cnt = ROOT->calcTreeSize();
    }
    else if(this->right)
    {
        Node* minNode = this->right->FindNearest(-INF);
        minNode->SplayUntil(this->right);

        this->right->left = this->left;

        if(this->left)
            this->left->parent = this->right;

        ROOT = this->right;
        ROOT->parent = NULL;
        ROOT->cnt = ROOT->calcTreeSize();
    }
    else
    {
        ROOT = NULL;
    }

    return ROOT;
}

Node* Node::Delete(KEY_TYPE _key)
{
    Node* ROOT=this;
    Node* forDelete = ROOT;
    ROOT=ROOT->Delete();
    delete forDelete;
    forDelete = NULL;
    return ROOT;
}


void Node::Rotate()
{
    if(isLeftChild())
    {
        bool parWasLeftChild = this->parent?this->parent->isLeftChild():false;

        parent->left = this->right;

        if(this->right)
            this->right->parent = this->parent;

        Node* newParent = this->parent->parent;

        this->right = this->parent;

        if(this->right)
            this->right->parent = this;

        this->parent = newParent;

        if(this->parent != NULL)
        {
            if(parWasLeftChild)
                this->parent->left = this;
            else
                this->parent->right = this;
        }

        this->right->cnt = this->right->calcTreeSize();
        this->cnt = this->calcTreeSize();
    }
    else if(isRightChild())
    {
        bool parWasLeftChild = this->parent?this->parent->isLeftChild():false;

        parent->right = this->left;

        if(this->left)
            this->left->parent = parent;

        Node* newParent = this->parent->parent;

        this->left = this->parent;

        if(this->left)
            this->left->parent = this;

        this->parent = newParent;

        if(this->parent != NULL)
        {
            if(parWasLeftChild)
                this->parent->left = this;
            else
                this->parent->right = this;
        }

        this->left->cnt = this->left->calcTreeSize();
        this->cnt = this->calcTreeSize();
    }
}

void Node::Zig()
{
    Rotate();
}

void Node::ZigZig()
{
    this->parent->Rotate();
    this->Rotate();
}

void Node::ZigZag()
{
    this->Rotate();
    this->Rotate();
}

Node* Node::Splay()
{
    while( !this->isRoot() )
    {
        if(this->parent->isRoot()) // Zig
        {
            this->Zig();
        }
        else if(this->isLeftChild() == this->parent->isLeftChild()) // ZigZig
        {
            this->ZigZig();
        }
        else // ZigZag
        {
            this->ZigZag();
        }
    }

    return this;
}

Node* Node::SplayUntil(Node* until)
{
    Node* grandParent = until->parent;

    while(this->parent != grandParent)
    {
        if(this->parent == until) // zig
        {
            this->Zig();
        }
        else if(this->isLeftChild() == this->parent->isLeftChild()) // zigzig
        {
            this->ZigZig();
        }
        else
            this->ZigZag();
    }
    return this;
}



void Node::PrintInOrder() // For Debug print tree in-order
{
    if(this->left)
        this->left->PrintInOrder();

    cout<<this->getKeyVal()<<" ";

    if(this->right)
        this->right->PrintInOrder();
}

void Node::PrintPreOrder() // For Debug print tree pre-order
{
    cout<<"["<<this->getKeyVal()<<":"<<this->cnt<<"]";

    printf("(");
    if(this->left)
        this->left->PrintPreOrder();
    printf(")");

    printf("(");
    if(this->right)
        this->right->PrintPreOrder();
    printf(")");
}

KEY_TYPE Node::getKeyVal()
{
    return this->key;
}

int Node::getCnt()
{
    return this->cnt;
}

//  Splay_ tree  Structure........

struct splay_tree{

    key_type key;
    Node *root;

    void init(){
        root=NULL;
    }
    bool exist(key_type key){
        if(!root) return 0;
        Node *temp = root->FindNearest(key);
        root = temp->Splay();
        return root->key==key;
    }
    void insert(key_type key){
        if(root){
            root=root->Insert(key);
        }
        else root=new Node(key);
    }
    void del(key_type key){
        if(root){
            if(this->exist(key)){
                root=root->Delete(key);
            }
        }

    }
    void print(){
        root->PrintPreOrder();
        //root->PrintInOrder();
        puts("");
    }
    int kth(int k){
        if(this->root==NULL) return -INF;
        Node* temp = this->root;
        if(temp->cnt < k) return -INF;

        while(true)
        {
            int c = (temp->left?temp->left->cnt:0) + 1;
            if(c == k)
            break;

            if(c < k)
            {
                k -= c;
                temp = temp->right;
            }
            else
            {
                temp = temp->left;
            }
        }

        this->root=temp->Splay();
        return root->key;
    }
    int count_smaller(KEY_TYPE _key){

        if(this->root==NULL) return 0;

        Node* temp = this->root;
        int ret = 0;

        while(true)
        {
            if(temp->key < _key)
            {
                int c = (temp->left?temp->left->cnt:0)+1;
                ret += c;
                if(temp->right){
                    temp = temp->right;
                }
                else{
                    break;
                }
            }
            else if(temp->key > _key)
            {
                if(temp->left){
                    temp = temp->left;
                }
                else
                    break;
            }
            else
            {
                ret += (temp->left?temp->left->cnt:0);
                break;
            }
        }
        this->root=temp->Splay();

        return ret;
    }

};

// Splay tree   finish...............

int q;
sp_tree tree;

int main(){

    int i,j,k,l,test,t=1;

    //freopen("in.txt","r",stdin);
    //freopen("out1.txt","w",stdout);

    while(scanf("%d",&q)==1){

        tree.init();

        for(i=1;i<=q;i++){
            char s[5]; int piv;
            scanf("%s %d",s,&piv);

            if(s[0]=='I'){
                tree.insert(piv);
            }
            if(s[0]=='D'){
                tree.del(piv);
            }
            if(s[0]=='K'){
                int val=tree.kth(piv);
                if(val==-INF) printf("invalid\n");
                else      printf("%d\n",val);
            }
            if(s[0]=='C'){
                int val=tree.count_smaller(piv);
                printf("%d\n",val);
            }
			//tree.print();
        }


    }

    return 0;
}

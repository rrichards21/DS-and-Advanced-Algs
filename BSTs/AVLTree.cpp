#include <bits/stdc++.h>
#include "AVLTree.h"
#define Right true
#define Left false
using namespace std;

AVLTree::AVLTree(){
	node *_root = NULL;
	fixed = false;
	_size=0;
}

AVLTree::~AVLTree(){
	inorder(_root);
}

void AVLTree::insert(int val){	
	//cout<<"Insertando: "<<val<<endl;
	node *n =(node*)malloc(sizeof(node));
	n->num=val;
	n->height = 1;
	n->left = NULL;
	n->right = NULL;
	n->parent = NULL;
	_size++;
	if(_root==NULL){
		_root=n;
	}
	else{
		stack<node*> st;
		stack<bool> child;
		node *aux=_root;
		while(1){
			st.push(aux);
			if(aux->num==val){
				_size--;
				free(n);
				return;
			}
			if(aux->num>val){
				child.push(false);
				if(aux->left!=NULL) aux=aux->left;
				else{
					aux->left=n;
					n->parent = aux;
					break;
				}
			}
			else{
				child.push(true);
				if(aux->right!=NULL) aux=aux->right;
				else{
					aux->right=n;
					n->parent = aux;
					break;
				}
			}
		}
		while(!st.empty()){
			//cout<<"Checking: "<<st.top()->num<<endl;
			_root = checkRotations(st.top(), val);
			st.pop();
		}
		//cout<<"juera"<<endl;
	}
}
int AVLTree::height(node *n){
	if(n == NULL){
		return 0;
	}
	return n->height;
}

node* AVLTree::checkRotations(node *n, int val){
	n->height = 1 + max(height(n->left),height(n->right));
	int balance = height(n->left) - height(n->right);
	//cout<<"Checking: "<<n->num<<" "<<n->height<<endl;
	if(balance > 1 && val < n->left->num){
		//cout<<"1if"<<endl;
		//cout<<"RR: "<<n->num<<" "<<n->height<<endl;
		return rightRotate(n);
	}

	if (balance < -1 && val > n->right->num){
		//cout<<"LR: "<<n->num<<" "<<n->height<<endl;
		return leftRotate(n);
	}

    if (balance > 1 && val > n->left->num)  
    {  
		//cout<<"LRR: "<<n->num<<" "<<n->height<<endl;
        n->left = leftRotate(n->left);
		return rightRotate(n); 
    }

    if (balance < -1 && val < n->right->num)  
    {  
		//cout<<"RLR: "<<n->num<<" "<<n->height<<endl;
        n->right = rightRotate(n->right);
        return leftRotate(n);;
    }
	return n;
}


node* AVLTree::rightRotate(node *n){
    node *x = n->left;
    n->left = x->right;  
    x->right = n;
	if(n->parent == NULL){
		x->parent = n->parent;
		n->parent = x;
	}
	else if(n->parent->left == n){
		x->parent = n->parent;
		n->parent->left = x;
		n->parent = x;
	}
	else if(n->parent->right == n){
		x->parent = n->parent;
		n->parent->right = x;
		n->parent = x;
	}
    n->height = max(height(n->left),height(n->right)) + 1;  
    x->height = max(height(x->left),height(x->right)) + 1;
	return x;
}

node* AVLTree::leftRotate(node *n){
	node *y = n->right;
	n->right = y->left;
	y->left = n;
	if(n->parent == NULL){
		y->parent = n->parent;
		n->parent = y;
	}
	else if(n->parent->left == n){
		y->parent = n->parent;
		n->parent->left = y;
		n->parent = y;
	}
	else if(n->parent->right == n){
		y->parent = n->parent;
		//cout<<n->parent->num<<endl;
		n->parent->right = y;
		//cout<<"nuevo hijo: "<<n->parent->right->num<<endl;
		n->parent = y;
	}
	n->height = 1 + max(height(n->left),height(n->right));
	y->height = 1 + max(height(y->left),height(y->right));
	return y;
}

node* AVLTree::search(int val){
	node *aux=_root;
	while(aux!=NULL){
		if(aux->num==val){
			return aux;
		}
		if(aux->num<val) aux=aux->right;
		else aux=aux->left;
	}
	return NULL;
}

int AVLTree::size(){
	return _size;
}

void AVLTree::inorder(node *n){
	if(n==NULL) return;
	inorder(n->left);
	cout<<n->num<<endl;
	inorder(n->right);
}

node* AVLTree::getRoot(){
	return _root;
}
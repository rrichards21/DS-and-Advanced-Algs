#include <bits/stdc++.h>
#include "BinarySearchTree.h"

using namespace std;

BinarySearchTree::BinarySearchTree(){
	node *_root = NULL;
	_size=0;
}

BinarySearchTree::~BinarySearchTree(){
	inorder(_root);
}

void BinarySearchTree::insert(int val){	
	node *n =(node*)malloc(sizeof(node));
	n->num=val;
	n->left = NULL;
	n->right = NULL;
	_size++;
	if(_root==NULL){
		_root=n;
	}
	else{
		node *aux=_root;
		while(1){
			if(aux->num==val){
				_size--;
				free(n);
				return;
			}
			if(aux->num>val){
				if(aux->left!=NULL) aux=aux->left;
				else{
					aux->left=n;
					return;
				}
			}
			else{
				if(aux->right!=NULL) aux=aux->right;
				else{
					aux->right=n;
					return;
				}
			}
		}
	}
}

node* BinarySearchTree::search(int val){
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

int BinarySearchTree::size(){
	return _size;
}

void BinarySearchTree::inorder(node *n){
	if(n==NULL) return;
	inorder(n->left);
	inorder(n->right);
	free(n);
}
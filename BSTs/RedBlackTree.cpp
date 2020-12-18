#include <bits/stdc++.h>
#include "RedBlackTree.h"

using namespace std;

RedBlackTree::RedBlackTree(){
	_nulo =(node*)malloc(sizeof(node));
	_nulo->num = INT_MIN;
	_nulo->isRed = false;
	_nulo->left = NULL;
	_nulo->right = NULL;
	_nulo->parent = NULL;
	_size=0;
	_root = _nulo;

}

RedBlackTree::~RedBlackTree(){
	inorder(_root);
}

void RedBlackTree::insert(int val){	
	node *n =(node*)malloc(sizeof(node));

	n->num=val;
	n->isRed = true;
	n->left = _nulo;
	n->right = _nulo;
	n->parent = _nulo;

	_size++;

	if(_root==_nulo){
		_root=n;
		n->isRed=false;
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
				if(aux->left!=_nulo) aux=aux->left;
				else{
					aux->left=n;
					n->parent=aux;
					VerificarInsercion(n); 			
					return;
				}
			}
			
			else{
				if(aux->right!=_nulo) aux=aux->right;
				else{
					aux->right=n;
					n->parent=aux;
					VerificarInsercion(n);
					return;
				}
			}
		}

	}
}

node* RedBlackTree::search(int val){
	node *aux=_root;
	while(aux!=_nulo){
		if(aux->num==val){
			return aux;
		}
		if(aux->num<val) aux=aux->right;
		else aux=aux->left;
	}
	return NULL;
}

int RedBlackTree::size(){
	//inorder(_root);
	return _size;
}

void RedBlackTree::inorder(node *n){
	if(n==_nulo) return;
	if(n == NULL) n = _root;
	inorder(n->left);
	if(n->isRed)printf("%d\tRed\n",n->num );
	else printf("%d\tBlack\n",n->num );
	inorder(n->right);
	
}

void RedBlackTree::VerificarInsercion(node *n){
	while(n->parent->isRed){
		if (n->parent==n->parent->parent->left){
			node* aux = n->parent->parent->right;
			if (aux->isRed){
				n->parent->isRed = false;
				aux->isRed = false;
				n->parent->parent->isRed = true;
				n = n->parent->parent;
			}
			else {
				
				if (n == n->parent->right){
					n = n->parent;
					RotarIzquierda(n);				
				}
				n->parent->isRed = false;
				n->parent->parent->isRed = true;
				RotarDerecha(n->parent->parent);
			}
		}
		else{
			node* aux = n->parent->parent->left;//
			if (aux->isRed){
				n->parent->isRed = false;
				aux->isRed = false;
				n->parent->parent->isRed = true;
				n = n->parent->parent;
			}
			else {
				
				if (n == n->parent->left){//
					n = n->parent;
					RotarDerecha(n);
						
				}

				n->parent->isRed = false;
				n->parent->parent->isRed = true;

				RotarIzquierda(n->parent->parent);
				
			}

		}
	}
	//while(n->parent != _nulo) n=n->parent;
	//_root=n;
	_root->isRed = false;
}

void RedBlackTree::RotarDerecha(node *n){
	node *aux = n->left;//
	n->left = aux->right;//
	if (aux->right != _nulo){//
	 	aux->right->parent = n; //
	}
	aux->parent = n->parent;
	if (n->parent == _nulo){
		_root = aux;

	}else{
		if (n == n->parent->right){//
			n->parent->right = aux;//
		}else n->parent->left = aux;//
	}
	aux->right = n;//
	n->parent = aux;//

}

void RedBlackTree::RotarIzquierda(node *n){
	//printf("\nse rota en %d\n",n->num );
	node *aux = n->right;
	n->right = aux->left;
	if (aux->left != _nulo){
	 	aux->left->parent = n; 
	}
	aux->parent = n->parent;
	if (n->parent == _nulo){
		_root = aux;
	}else{
		if (n == n->parent->left){
			n->parent->left = aux;
		}else n->parent->right = aux;
	}
	aux->left = n;
	n->parent = aux;
}

node* RedBlackTree::getRoot(){
	return _root;
}
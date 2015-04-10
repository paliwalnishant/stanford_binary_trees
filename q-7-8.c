#include <stdio.h>
#include <stdlib.h>
 

struct node
{
    int data;
    struct node* left;
    struct node* right;
};
 
void viewline(int [], int);
void viewpath1(struct node*, int [], int);
struct node* newNode(int );
void printPaths(struct node*);
 
 
void printPaths(struct node* node) 
{
  int path[1000];
  viewpath1(node, path, 0);
}
 

void viewpath1(struct node* node, int path[], int pathLen) 
{
  if (node==NULL) return;
 
 
  path[pathLen] = node->data;
  pathLen++;
 
 
  if (node->left==NULL && node->right==NULL) 
  {
    viewline(path, pathLen);
  }
  else
  {
 
    viewpath1(node->left, path, pathLen);
    viewpath1(node->right, path, pathLen);
  }
}
 

struct node* newNode(int data)
{
  struct node* node = (struct node*)
                       malloc(sizeof(struct node));
  node->data = data;
  node->left = NULL;
  node->right = NULL;
 
  return(node);
}
 

void viewline(int ints[], int len)
{
  int i;
  for (i=0; i<len; i++) {
    printf("%d ", ints[i]);
  }
  printf("\n");
} 
 

int main()
{
  struct node *root = newNode(1);
  root->left        = newNode(2);
  root->right       = newNode(3);
  root->left->left  = newNode(4);
  root->left->right = newNode(5); 
 
 
  printPaths(root);
 
  getchar();
  return 0;
}

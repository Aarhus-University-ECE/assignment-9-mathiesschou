/*
 * Search an expression using DFS.
 */

#include <stdio.h>		/* scanf, printf */
#include <stdlib.h>		/* abort */
#include <stdbool.h>		/* bool, true, false */
#include "dfs.h"


void DFT (node * root)
{
	// Implement DFS
	// Hint: You can use print_node, print_tree and/or print_stack.

  stack s;

  s.node = root;
  s.next = NULL;

  while(!isEmpty(&root->num))
  {
    if (root->lchild != NULL && root->rchild != NULL)
    {
      print_node (root);
      pop(&s);
      push(&s,root->rchild);
      push(&s,root->lchild);
    }

    else if (root->lchild == NULL && root->rchild != NULL)
    {
      print_node (root);
      pop(&s);
      push(&s, root->rchild);
    }

    else if (root->lchild != NULL && root->rchild == NULL)
    {
      print_node (root);
      pop(&s);
      push(&s, root->lchild);
    }

    else
    {
      print_node (root);
      pop(&s);
    }
  }
}

node *make_node (int num, node * left, node * right)
{
	return 0;
}

void free_node (node * p)
{
	
}


void print_node (node * p)
{

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("%d", p->num);
}


void print_tree (node * p, int depth)
{
  for (int i = 0; i < depth; i = i + 1)
    printf (" ");
  printf ("| ");

  if (p == NULL)
    printf ("NULL\n");
  else
    printf ("[%d]\n", p->num);


  if (p->lchild)
    {
      print_tree (p->lchild, depth + 1);
    }

  if (p->rchild)
    print_tree (p->rchild, depth + 1);
}

stack *push (stack * topp, node * node)
{

  stack *new_top = topp;
  stack *s = malloc(sizeof(stack));
  s->node = node;
  s->next = new_top;
  topp->next = new_top;

}

bool isEmpty (stack * topp)
{
  if(topp == NULL)
  {
    return true;
  }
  else 
  return false;
}

node *top (stack * topp)
{
	return 0;
}

// Utility function to pop top  
// element from the stack 

stack *pop (stack * topp)
{
	stack *freeing = topp;
  int popped_top = topp->node->num;
  topp = topp->next;

  free(freeing);
  return popped_top;
}

void print_stack (stack * topp)
{
  struct stack *temp = topp;

  while (temp != NULL)
    {

      print_node (temp->node);
      printf ("\n");

      temp = temp->next;
    }

  printf ("====\n");

  return;
}

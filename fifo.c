#include <stdio.h>
#include <stdlib.h>

typedef struct NODE
{
  char name[10];
  int x;
  int y;
  struct NODE * next;
} node;


node* create( int x, int y )
{
  struct NODE * _tmp = malloc( sizeof( node ));
  _tmp->x = x;
  _tmp->y = y;
  _tmp->next = NULL;
  printf( "[cr8] (%i,%i)\n", x, y );
  return _tmp;
}

int len( node* n )
{
  int l=0;
  node* head = n;
  while( head != NULL )
    {
      l++; 
      head=head->next;
    }
  return l+1;
}

node* popfirst(node* head)
{
  node* prev = NULL;

  while( head->next != NULL )
    {
      prev=head;
      head=head->next;
    }
  prev->next=NULL;
  
  //printf( "[pop the first one in] (%i,%i)\t\tL:%i\n", head->x, head->y, len( head )-1);
  return head;
}

void display( node* n )
{
  printf( "(%i,%i) -> %x\n", n->x, n->y, n->next );
  return;
}

node* delfirst(node* head)
{
  /* deletes the first node that was put into the list */
  node* ll=head;
  node* prev = NULL;
  while( head->next != NULL )
    {
      prev=head;
      head=head->next;
    }
  prev->next=NULL;
  
  printf( "[del the first one in] (%i,%i)\n", head->x, head->y );
  free( head );
  return ll;
}

node* poplast( node* head )
{
  node* _tmp=head;
  head->next=NULL;
  
}

node* dellast(node* head)
{
  /* deletes the last node that was put into the list */
  node* new_head = head->next;
  printf( "[del the last one in] (%i,%i)\n", head->x, head->y );
  
  free( head );
  return new_head;
}


void dump(node* n)
{
  node* head = n;
  int i=1;
  while( head != NULL )
    {
      printf( "%i) (%i,%i)\n", i++, head->x, head->y );
      head=head->next;
    }
  printf( "\n\n" );
}

node* push(int x, int y, node* z)
{
  node* _tmp = create( x, y );
  _tmp->next = z;
  return _tmp;
}

node* pushNode( node* n, node* l)
{
  node* _tmp = n;
  n->next = l;
  return n;
}


node* copy( node* n )
{
  return create( n->x, n->y );
}

node* getcopylast( node* ll )
{
  /* get a copy of the last in while keeping it in the list */
  return copy( ll );
}

node* getcopyfirst( node* ll )
{
  node * _tmp;
  /* get a copy of the first in while keeping it in the list */
  while( ll->next != NULL )
    {
      _tmp=ll;
      ll=ll->next;
    }
  _tmp = copy( ll );
  return _tmp;
}

int main()
{
  #ifdef DEBUG
  printf( "*** DEBUG MODE ***\n" );
  #endif

  node* ll=NULL;

  // fill a linked list
  for( int i=0; i<10; i++ )
    {
      //struct node * _tmp=xy1;
      ll=push( i, 3, ll );
    }
  dump( ll );

  ll=delfirst( ll );
  dump( ll );
  ll=dellast( ll );
  dump( ll );

  node* w=getcopyfirst( ll );
  node* y=getcopylast( ll );
  display( w );
  display( y );

  free( w );
  free( y );
  dump( ll );
  return 0;
  /* ================= */
  node * n = popfirst(ll);
  printf( "[popped the first one in] (%i,%i)\n", n->x, n->y );
  dump( ll );
  free( n ); 

  dump( ll );
  n = popfirst(ll);
  printf( "[popped the first one in] (%i,%i)\n", n->x, n->y );
  dump( ll );

  node* m = copy( n );
  free( n );
  printf( "(%i,%i)\n", m->x, m->y );
  free( m );
  /* ================= */
  /* ================= */

  /* an array of 3 node pointers */
  node* x[3];

  x[0]=create( 1, 1 );
  x[1]=create( 2, 2 );
  x[2]=create( 3, 3 );

  display( x[0] );
  display( x[1] );
  display( x[2] );
  
  free( x[0] );
  free( x[1] );
  free( x[2] );
  /* ================= */
  /* ================= */

  dump( ll );
  ll=pushNode( create(5, 7), ll );
  ll=pushNode( create(-6, -9), ll );
  dump( ll );
  n=popfirst( ll );
  dump(ll);
  free( n );
  n=poplast( ll );
  dump( ll );
  free( n );
  /* ================= */
  /* ================= */
  
  return 0;
}



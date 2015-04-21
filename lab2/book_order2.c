#include <stdio.h>
#include "book_order.h"
#define NEWLINE "\n"

int main(int argc, char * argv[],char * envp[])
{
  int offset = 0;
  struct BOOK_ORDER order;
  struct BOOK_ORDER orders[]={
          {"007-6092024712",22,"Linux Programming", 143800000,"Robbins",43.34,0},
          {"978-1449397227",30,"JQuery Pocket Ref", 143900400,"Flanagan",14.50,'Y'},
          {"978-1430210436",40,"Portable Shell Scripts",14402900,"Seebach",39.95,'Y'}} ;

  fprintf(stdout,"isbn: %d bytes Offset at: %d\n",sizeof(order.isbn), offset);
  fprintf(stdout,"copiesOnOrder: %d bytes Offset at: %d\n",sizeof(order.copiesOnOrder), offset);
  fprintf(stdout,"title: %d bytes Offset at: %d\n",sizeof(order.title), offset);
  fprintf(stdout,"dateExpected: %d bytes Offset at: %d\n",sizeof(order.dateExpected), offset);
  fprintf(stdout,"author: %d bytes Offset at: %d\n",sizeof(order.author), offset);
  fprintf(stdout,"price: %d bytes Offset at: %d\n",sizeof(order.price), offset);
  fprintf(stdout,"prepaid: %d bytes Offset at: %d\n",sizeof(order.prepaid), offset);
  fprintf(stdout,"Total size of BOOK_ORDER: %d bytes Offset at: %d\n",sizeof(order), offset);

  return 0;
  }

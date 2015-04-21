/*
   File: book_order.h
   Course: CENG251
   Author: Prof. Leon King,J230,x4200
   Date: Sunday Jan 18, 2015   21:54 PM
   Purpose:  Data Structure to describe a book order from a book store
*/


#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <time.h>

struct BOOK_ORDER
{
    char    isbn[15];
    int     copiesOnOrder;
    char    title[23]; 
    time_t  dateExpected;
    char    author[11];
    double  price;   
    bool    prepaid;
   
};

void displayOrder(int recordNo,struct BOOK_ORDER order)
{
  fprintf(stdout,"recordNo: %d isbn: %s copies: %d  author: %s  " "title: %s price: %lf  prepaid: %c   dateExpected: %s \n", 
		recordNo,order.isbn, order.copiesOnOrder,order.author,
                order.title, order.price, order.prepaid ? 'Y' : 'N',
                ctime(&order.dateExpected));
                  // , order.prepaid ? 'Y' : 'N'
  }
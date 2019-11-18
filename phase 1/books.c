#include "books.h"
#include "stdio.h"
#include "stdlib.h"


static 	char * zone[]={(char*)"KIDS",
	(char*)"HIGHSCHOOL",
	(char*)"ADULT",
	(char*)"COMICS",
	(char*)"DOCUMENTARY"};
static char *erro[]={(char*)"E_OK",
	(char*)"E_ISBORROWED",
	(char*)"E_ALREADY_IN_LIBRARY"};
char * get_zone_name(Zone z)
{
	return zone[z]; 
}
char * get_error_name(ErrorCode z)
{
	return erro[z]; 
}
void print_Book(Book * b1)
{
	printf("the name is: %s \n",b1->name);
	printf("the internal number is: %ld \n" ,b1->internal_num);
	printf("the promotion is %d \n",b1->promotion);
	printf("the zone is %s \n" ,get_zone_name(b1->z));
	printf("*************");
}
void print_copy(BookCopy *b1)
	
{
	printf("the internal number is: %ld \n" ,b1->internal_num);
	printf("the serial number is: %ld \n" ,b1->serial_num);
	printf("is borrowed: %d \n" ,b1->is_borrowed);
	printf("*************");
}
ErrorCode error=E_OK;
ErrorCode borrow_copy(BookCopy *b1,bool is_borrowing)
{
	error=E_OK;
	if(is_borrowing==true)
	{
		if(b1->is_borrowed==true)
		{
			error=E_ISBORROWED;
			return error;
		}
		else
		{
			b1->is_borrowed=true;
		}
	}
	else
	{
		if(b1->is_borrowed==true)
		{
			b1->is_borrowed=false;
		}
		else
		{
			error=E_ALREADY_IN_LIBRARY;
			return error;
		}	
	}
	return error;	
}

void init_copy(BookCopy *b1,size_t internal)
{
	static size_t serial=10000; 
	b1->internal_num=internal;
	b1->serial_num=serial;
	serial++;
	b1->is_borrowed=false;
	
}

#include "books.h"
#include "inttypes.h"
#include "stdlib.h"
#define COVER 1
#define INDEX COVER<<1
#define MISS_PAGES COVER<<2
#define BAR_CODE COVER<<3
#define SPINE COVER<<4
#define STAINED_PAGES COVER<<5
static 	char * zone[]={(char*)"KIDS",
	(char*)"HIGHSCHOOL",
	(char*)"ADULT",
	(char*)"COMICS",
	(char*)"DOCUMENTARY"};
static char *erro[]={(char*)"E_OK",
	(char*)"E_IS_BORROWED",
	(char*)"E_ALREADY_IN_LIBRARY",(char*)"E_BAD_INDEX",(char*)"E_THIS_BOOK_DIDNT_FOUND"};
static char *problems[]={"COVER","INDEX","MISS_PAGES","BAR_CODE","SPINE","STAINED_PAGES"};
static char *boolen[]={"false","true"};
char * get_zone_name(Zone z)
{
	return zone[z]; 
}
char * get_error_name(ErrorCode z)
{
	return erro[z]; 
}
char * get_boolen(bool r)
{
	return boolen[r];
}

void print_Book(Book * b1)
{
	printf("the name is: %s \n",b1->name);
	printf("the internal number is: %ld \n" ,b1->internal_num);
	printf("the promotion is %d \n",b1->promotion);
	printf("the zone is %s \n" ,get_zone_name(b1->z));
	printf("************* \n");
}

void print_copy(BookCopy *b1)
	
{
	int i;
	printf("the internal number is: %ld \n" ,b1->internal_num);
	printf("the serial number is: %ld \n" ,b1->serial_num);
	printf("is borrowed: %d \n" ,b1->is_borrowed);
	printf("borrowing_times: %ld \n" ,b1->borrowing_times);
	for(i=0;i<6;i++)
	{
		if(((b1->problem)&(1<<i))!=0)
			printf("%s \n", problems[i]);
			
	}
	printf("************* \n");
}
ErrorCode error=E_OK;
ErrorCode borrow_copy(BookCopy *b1,bool is_borrowing)
{
	error=E_OK;
	if(is_borrowing==true)
	{
		if(b1->is_borrowed==true)
		{
			error=E_IS_BORROWED;
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
	b1->borrowing_times++;
	return error;	
}

void init_copy(BookCopy *b1,size_t internal)
{
	static size_t serial=10000; 
	b1->internal_num=internal;
	b1->serial_num=serial;
	serial++;
	b1->is_borrowed=false;
	b1->borrowing_times=0;
	b1->problem=1;
	
}
bool is_librarian_required(BookCopy *b1)
{
	if ((((b1->problem) & (COVER))!=0) || ((INDEX) & (b1->problem))!=0 || ((BAR_CODE) & (b1->problem))!=0)
	{
		return true;
	}
	return false;	
}
bool is_bookbinder_required(BookCopy *b1)
{
	if ((((MISS_PAGES )&(b1->problem))!=0) || ((STAINED_PAGES) & (b1->problem))!=0 || ((SPINE) & (b1->problem))!=0)
	{
		return true;
	}
	return false;
}
bool is_ok(BookCopy *b1)
{
	if (b1->problem!=0)
	{
		return false;
	}
	return true;
}
bool is_unless(BookCopy *b1)
{
	int i,count=0;
	for(i=0;i<6;i++)
	{
		if(((1<<i) & b1->problem)!=0)
		{
			count++;
		}
		if(count==4)
			return true;
			
	}
	return false;
}
bool are_in_same_condition(BookCopy *b1,BookCopy *b2)
{
	if(b1->problem==b2->problem)
		return true;
	return false;
}
BookCopy * create_copy(size_t internal)
{
	BookCopy * new_ptr;
	new_ptr=malloc(sizeof(BookCopy));
	init_copy(new_ptr,internal);
	return new_ptr;	
}


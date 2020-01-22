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
	(char*)"E_ALREADY_IN_LIBRARY",(char*)"E_BAD_INDEX",(char*)"E_THIS_BOOK_DIDNT_FOUND",(char*)"E_NULL_PTR",
	(char*)"E_ALLOCATION_ERROR"};
static char *problems[]={"COVER","INDEX","MISS_PAGES","BAR_CODE","SPINE","STAINED_PAGES"};
static char *boolen[]={"false","true"};
static ErrorCode error=E_OK;
static void print_thriller(genre_prop f)
{
	printf("the genre of the book is thriller \n ");
	printf("thrillinig factor: %d \n", f.thrilling_factor);
}
static void print_comedia(genre_prop f)
{
	printf("the genre of the book is comedia \n");
	printf("homur_quality: %d homur_type: %d \n", f.homur.homur_quality,f.homur.homur_type);
}
static void print_drama(genre_prop f)
{
	printf("the genre of the book is drama \n");
	printf("text_quality: %d plot_quality: %d \n", f.drama.text_quality,f.drama.plot_quality);
}
static void print_non_fiction(genre_prop f)
{
	printf("the genre of the book is non fiction \n");
	printf("non_fiction: %d \n", f.non_fiction);
}
typedef void (*funcptr)(genre_prop);
funcptr arr[4]={print_drama,print_thriller, print_comedia,print_non_fiction};
const char * get_zone_name(Zone z)
{
	return zone[z]; 
}
const char * get_error_name(ErrorCode z)
{
	return erro[z]; 
}
const char * get_boolen(bool r)
{
	return boolen[r];
}

void print_Book(Book * b1)
{
	printf("the name is: %s \n",b1->name);
	printf("the internal number is: %d \n" ,b1->internal_num);
	printf("the promotion is %d \n",(int)b1->promotion);
	printf("the zone is %s \n" ,get_zone_name(b1->z));
	arr[b1->g](b1->gp);
	printf("************* \n");
	
}

void print_copy(BookCopy *b1)
	
{
	int i;
	printf("the internal number is: %d \n" ,b1->internal_num);
	printf("the serial number is: %d \n" ,b1->serial_num);
	printf("is borrowed: %d \n" ,b1->is_borrowed);
	printf("borrowing_times: %ld \n" ,b1->borrowing_times);
	for(i=0;i<6;i++)
	{
		if(((b1->problem)&(1<<i))!=0)
			printf("%s \n", problems[i]);
			
	}
	printf("************* \n");
}

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

ErrorCode init_copy(BookCopy *b1,unsigned short internal)
{
	static unsigned int serial=10000;
	error=E_OK;
	if(b1==NULL)
	{
		error=E_NULL_PTR;
	}
	if(serial>1000000000)
	{
		error=E_OVER_MEMBER;
	} 
	b1->internal_num=internal;
	b1->serial_num=serial;
	serial++;
	b1->is_borrowed=false;
	b1->borrowing_times=0;
	b1->problem=1;
	return error;
	
}
bool is_librarian_required(BookCopy *b1)
{
	if (b1==NULL)
	{
		return true;
	}
	if ((((b1->problem) & (COVER))!=0) || ((INDEX) & (b1->problem))!=0 || ((BAR_CODE) & (b1->problem))!=0)
	{
		return true;
	}
	return false;	
}
bool is_bookbinder_required(BookCopy *b1)
{
	if (b1==NULL)
	{
		return false;
	}
	if ((((MISS_PAGES )&(b1->problem))!=0) || ((STAINED_PAGES) & (b1->problem))!=0 || ((SPINE) & (b1->problem))!=0)
	{
		return true;
	}
	return false;
}
bool is_ok(BookCopy *b1)
{
	if (b1==NULL)
	{
		return false;
	}
	if (b1->problem!=0)
	{
		return false;
	}
	return true;
}
bool is_unless(BookCopy *b1)
{
	int i,count=0;
	if (b1==NULL)
	{
		return false;
	}
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
	if (b1==NULL)
	{
		return false;
	}
	if(b1->problem==b2->problem)
		return true;
	return false;
}
BookCopy * create_copy(unsigned short internal)
{
	BookCopy * new_ptr;
	ErrorCode w;
	new_ptr=malloc(sizeof(BookCopy));
	if(new_ptr==NULL)
	{
		return NULL;
	}
	w=init_copy(new_ptr,internal);
	if(w==E_OK)
	{
		return new_ptr;
	}
	return NULL;	
}


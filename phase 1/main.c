#include "local_library.h"
#include "stdlib.h"
#define NUMCOPIES 2
ErrorCode error;
int main()
{
	BookCopy book_copies[NUMCOPIES];
	int flag=0;
	size_t i,k;
	size_t internal;
	size_t j=num_books();
	int n;

	/*print the name of the books of the library*/
	for(i=0;i<j;i++)
	{
		print_Book(&(books[i]));
	}
	/*put copies in the array of the book-copies;*/
	for(i=0;i<NUMCOPIES;i++)
	{
		flag=0;
		scanf("%lu",&internal);
		for(k=0;k<j;k++)
		{
			if(books[k].internal_num==internal)
			{
				
				flag=1;
				
				init_copy(&book_copies[i],internal);
				
			}
		}
		if(flag==0)
		{
			printf("there is a error with the input please try again");
			i--;	
		}
			
	}
	for(i=0;i<NUMCOPIES;i++)
	{
		print_copy(&book_copies[i]);
	}
	
	/*borrowing books in the library*/
	
	printf("menu:\nfor borrow a book-copy press 1\n for return a book-copy press 2\n for exit prees 9\n");
	scanf("%d",&n);
	if(n==9)
	{
		printf("goodby");
		return 1;
	}
	if(n!=1&&n!=2)
	{
		printf("bad_index");
	}
	else
	{
		printf("enter internal number");
		scanf("%lu",&internal);
		for(i=0;i<=NUMCOPIES;i++)
		{
			if(book_copies[i].internal_num==internal)
			{
				if(n==1)
				{
					printf("%s \n",get_error_name(borrow_copy(&book_copies[i],true)));
				}
				else
				{
					printf("%s \n",get_error_name(borrow_copy(&book_copies[i],false)));
				}
			}
		}
	}
	/**********/
	for(i=0;i<NUMCOPIES;i++)
		print_copy(&book_copies[i]);
	return 1;
	
}


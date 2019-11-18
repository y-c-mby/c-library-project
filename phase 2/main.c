
#include "local_library.h"
#include "stdlib.h"
#include "test.h"
#define NUMCOPIES 2
ErrorCode error;
int main()
{
	
	
	
	size_t i;
	size_t internal;
	size_t j=num_books();
	int n;
	size_t numofcopies;
	bool flag=false;
	BookCopy **book_copies;
	test_is_librarian_required();
	test_is_bookbinder_required();
	test_are_in_same_condition();
	test_is_ok();
	test_is_unless();
	/*print the name of the books of the library*/
	for(i=0;i<j;i++)
	{
		print_Book(&(books[i]));
	}
	/*put copies in the array of the book-copies;*/
	printf("enter number of copies:");
	scanf("%lu \n",&numofcopies);
	book_copies=malloc(sizeof(BookCopy*)*numofcopies);
	for(i=0;i<numofcopies;i++)
	{
		scanf("%lu",&internal);
		*(book_copies+i)=create_copy(internal);
	}
	for(i=0;i<numofcopies;i++)
	{
		print_copy(book_copies[i]);
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
		printf("%s \n",get_error_name(E_BAD_INDEX));
	}
	else
	{
		printf("enter internal number \n");
		scanf("%lu",&internal);
		for(i=0;i<numofcopies;i++)
		{
			if(book_copies[i]->internal_num==internal)
			{
				if(n==1)
				{
					printf("%s \n",get_error_name(borrow_copy(book_copies[i],true)));
				}
				else
				{
					printf("%s \n",get_error_name(borrow_copy(book_copies[i],false)));
				}
				flag=true;	
			}
		}
		if(!flag)
		{
			printf("%s \n",get_error_name(E_THIS_BOOK_DIDNT_FOUND));
		}
	}
	/*for(i=0;i<numofcopies;i++)
	{
		print_copy(book_copies[i]);
	}*/
	/*free the allocation memory*/
	for(i=0;i<numofcopies;i++)
	{
		free(book_copies[i]);
	}
	free(book_copies);
	book_copies=NULL;
	return 1;
	
}


#include<stdio.h>
#include "espl_lib.h"

#include<ctype.h>
int main()
{
	int i;
	char* s;
	printf("please give me a number: \n");
	if(!scanf("%u",&i))
		{printf("this is not a number, try again later\n");
			return 0;}

	s = num_to_words(i);
	printf("output string is %s\n",s);
	printf("another try?\nexit with any char\n");
	
		
	while(!scanf("%u",&i))
	{
		s = num_to_words(i);
		printf("output string is %s\n",s);
		printf("another try?\nexit with any char \n");
		if(!scanf("%u",&i))
			{printf("this is not a number, try again later\n");
				break;}
	
	}	
	printf("game over\n");
	return 0;
	
	
}

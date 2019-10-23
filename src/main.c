#include<stdio.h>
#include "espl_lib.h"
#include<string.h>
void main()
{
	unsigned int i;
	char* s;
	printf("please give me a number: \n");
	scanf("%d",i);
	s = num_to_words(i);
	printf("output string is %s\n",s);
	printf("another try?\nexit with input char 'q' \n");
	scanf("%d",i);
	while(i!='q')
	{
		s = num_to_words(i);
		printf("output string is %s\n",s);
		printf("another try?\nexit with input char 'q' \n");
		scanf("%d",i);

	}	
	printf("game over");
	
	
}

#include "header.h"
#include<string.h>

void remove_spaces(char* str)
{
	char blank[300];
	int c=0, d=0, e=0;
	while(str[c]!='\0')
	{
		if(!(str[c] == ' '))
		{
			blank[d] = str[c];
			d++;
		}
		c++;
	}
	blank[d] = '\0';
	for(e=0; e<strlen(str); e++)
	{
		str[e] = blank[e];
	}
	str[e]='\0';
}

void allupper(char* str)
{
	int i;
	for(i=0; i<strlen(str)-1; i++)
        {
                str[i] = toupper(str[i]);
        }
}


#include<stdio.h>
#include "images.h"
#define SIZE 14000
#define FILENAME "test"

void main()
{
	int i, no_files=1, len=0;
	FILE *fp = NULL;

	for(i=0;i<no_files;i++)
	{
		fp = fopen(FILENAME, "w+");
		if(fp==NULL)
		{
			printf("Unable to open file\n");
		}
		len = fwrite(img, 1, SIZE, fp);
		printf("size:%d\n", len);	
	}
	fclose(fp);	
}

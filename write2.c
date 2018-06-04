#include <stdio.h>
#include <string.h>
#define FILENAME "punisher"

void main () 
{
	int i, j, len, no_files=1;
	FILE *fp, *fp1;
	unsigned char ch, buff[2];

	fp = fopen("images.h","w");				// Creating an header file which will have data of an image
	//fputs("Reading an image...\n", fp);
	
	for(j = 0;j < no_files; j++)				// Writing Image data into images.h
	{
		fputs("unsigned char img[] =	{",fp);
		fp1 = fopen(FILENAME, "r");			// Reading image
		if(fp1==NULL)
		{
			printf("Unable to open file\n");
		}
		fseek(fp1,0,SEEK_END);
		len = ftell(fp1);
		printf("size:%d\n",len);			// Getting size of image
		fseek(fp1,0,SEEK_SET);

		for(i=0;i< len;i++)
		{
			ch = fgetc(fp1);			// Taking single char at a time
			sprintf(buff,"%d",ch);
			fputs(buff,fp);				// 1 buff = 1 pixel
			if(i!=len-1)
				fputs(", ",fp);
			if((i % 20 == 0) && (i != 0))
				fputs("\n	",fp);
		}
		fputs(" };\n\n",fp);
		fclose(fp1);
	}
/////////////////////////////////////Done/////////////////////////////////////
	fclose(fp);
}



#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#define MAXLINE 800
#define MAXRECORDS 10


struct user
{
    char navn;
    int antal;
};
struct info{
      char name[100];
      char number[12];
      char address[100];
      char city[20];
      char state[2];
      int zip;
    };

/*struct user
{
    char navn[9];
    int antal;
    int blodtryk[10];
    float gnsTryk;
    int puls[10];
    float gnsPuls;
};*/

int main()
{

  DIR *p;
  struct dirent *pp;
  p = opendir ("./");

  if (p != NULL)
  {
    while ((pp = readdir (p))!=NULL) {
      int length = strlen(pp->d_name);
      if (strncmp(pp->d_name + length - 4, ".txt", 4) == 0) {
          //puts (pp->d_name);
          printf("%.*s; ",length-4,pp->d_name);
      }
    }

    closedir (p);
  }


/*    FILE *pToFile = fopen("database1.txt","w+");

	int line = 0;
	int arr[5];

	char input[512];

	char *token ="&";
	while (pToFile!=EOF)
    {
        while (pToFile!=token)
            {
                fgets(input,6,pToFile);
                printf("%s",input);
            }
    }

    char person1;
    char person2;
    char person3;
    char person4;

	while( fgets( input, 512, pToFile )) {
		line++;
		printf("Line:%d -> %s",line,input);
		scanf(input,"%c",&person1);
	}

    fscanf(pToFile, "%s %s %s %d", &person1, &person2, &person3, &person4);
	fclose(pToFile);
	printf("\n\nEnd Of Program\n");
    printf("\n %c",person1);

	return 0;

char str1[10], str2[10], str3[10];
   int year;
   FILE * fp;

   fp = fopen ("database1.txt", "r+");
   fscanf(fp, "%s %s %s %d", str1, str2, str3, &year);

   fclose(fp);*/
/*
    int nrecs = 0;
    char line[MAXLINE];
    struct info input_records[MAXRECORDS];
    int test[3];
    FILE *inputf;
    inputf=fopen("database1.txt","r");
    while (!feof (inputf))
        {
            if (fgets(line, sizeof (line), inputf))
                {
                    printf("next line= %s\n", line);
                    test[nrecs]=line;
                    nrecs++;
                }
        }
    /*    while (fgets(line, sizeof(line), inputf)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
       // printf("%s", line);
   // }
   // fclose(inputf);

    //return(0);
/*    int floatValue[10];

    int i;
    for (i=0;i<10;i++)
    {
        floatValue[i]=i;
        fprintf(fPointer,"%d",floatValue[i]);
    }*/

  // fwrite(floatValue, sizeof floatValue, 9, fPointer);

    /*
    fseek(fPointer, 7, SEEK_SET);
    fseek(fPointer, -7, SEEK_END);
    */

/*    char singleLine[150];

    while(!feof(fPointer))
    {
        fgets(singleLine,150,fPointer);
        puts(singleLine);
    }
    fclose(fPointer);

    return 0;*/
}

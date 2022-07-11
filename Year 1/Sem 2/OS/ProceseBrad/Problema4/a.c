//Write 2 programs, A and B. A will create 2 prcesses p1 and p2. p1 will
//have provided (by any means (necessary)) a file containing random text
//then it will read from the standard input (keyboard) a number (n).
//p1 will send the nth character from the file to p2 via pipe.
//p2 will write on the standard output (the console) the nature of that
//character (letter, digit, other) and will send it to B via fifo.
//B will display on the standard output the ascii code of that character.
//The source file must be compiled using gcc with -Wall -g options WITHOUT WARNINGS OR SYNTAX ERRORS!!!
//Memory leacks and zombie processes are not allowed.
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
int main()
{
	int p[2];
	pipe(p);
	if(fork()==0)
		{
		char nume_fisier[101];
		printf("Introduceti numele unui fisier existent: ");
		scanf("%s",nume_fisier);
		FILE* f;
		f=fopen(nume_fisier,"r");
		int i,n;
		printf("Introduceti un numar n: ");
		scanf("%d",&n);	
		char caracter;
		for(i=0; i<n; i++)
		caracter=fgetc(f);      //f in loc de nume_fisier!!!
		write(p[1],&caracter,sizeof(char));
		close(p[1]);
		fclose(f);
		exit(0);
	}
	wait(0);
	if(fork()==0)
	{	
		char *myfifo="/tmp/fifo1";
		mkfifo(myfifo,0666);
		char caracter;
		read(p[0],&caracter,sizeof(char));
		printf("%c\n",caracter);
		if(caracter>='0' && caracter<='9')
			printf("Caracterul este cifra.\n");
		else if ((caracter>='a' && caracter <='z') || (caracter>='A' && caracter<='Z'))
			printf("Caracterul este litera.\n");
		else printf("Caracterul e altceva\n.");
		int fd=open(myfifo,O_WRONLY);
		write(fd,&caracter,sizeof(char));
		close(fd);
		close(p[0]);
		exit(0);
	}
	wait(0);
	close(p[0]);
	close(p[1]);
	return 0;
}

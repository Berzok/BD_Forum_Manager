#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <termios.h>

#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED


char getch()
	{
	char buf=0;
	struct termios old={0};
	fflush(stdout);
	if(tcgetattr(0, &old)<0)
		perror("tcsetattr()");
	old.c_lflag&=~ICANON;
	old.c_lflag&=~ECHO;
	old.c_cc[VMIN]=1;
	old.c_cc[VTIME]=0;
	if(tcsetattr(0, TCSANOW, &old)<0)
		perror("tcsetattr ICANON");
	if(read(0,&buf,1)<0)
		perror("read()");
	old.c_lflag|=ICANON;
	old.c_lflag|=ECHO;
	if(tcsetattr(0, TCSADRAIN, &old)<0)
		perror ("tcsetattr ~ICANON");
	return buf;
	}


void connexion()
	{
	char pseudo;
	char password = "";
	char pwd;
	char pwd1[1];
	int i = 0;
	int taille = 0;
	printf("Nom d'utilisateur: ");
	pseudo = scanf("%c", &pseudo);
	fflush(stdin);
	printf("Mot de passe: ");
	while(2+2==4)
		{
		pwd = getch();
		fflush(stdin);
		if(pwd == '\n')
			break;
		printf("*");
		password = password + pwd;
		i++;
		taille++;
		}
	printf("\n");
	}














#endif // SOURCE_H_INCLUDED

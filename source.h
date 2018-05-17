#ifndef SOURCE_H_INCLUDED
#define SOURCE_H_INCLUDED

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
	while(pwd != 13)
		{
		pwd = getch();
		fflush(stdin);
		if(pwd == 13)
            break;
		printf("*");
		password = password + pwd;
		i++;
		taille++;
		}
	}


#endif // SOURCE_H_INCLUDED

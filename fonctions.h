#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

void connexion(){
	printf("Entrez votre login\n");
	char login;
	login = scanf("%c", &login);
	printf("Entrez votre mot de passe\n");
	char mdp;
	fflush(stdin);

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
	system("cls");
	menu(login);
	//return 0;
}

void menu(char login){
	char log = login;
	printf("Bienvenue %c \n", log);
	printf("Choisissez une action :\n	-Choisir un groupe :\t groupe\n	-Rechercher un message : \t message\n	-Afficher le top 20 : \t top");
	char action[10];
	scanf("%s", action);
	reconnaissance(action);
}

reconnaissance(char action){
	char act[10];
	if (act == "groupe"){
		listeGroupe();
	}
	if (act == "message"){
		recherche();
	}
	if (act == "top"){
		top20();
	}
	else{
		printf("Erreur, veuillez selectionner une autre entrée");
	}
}

listeGroupe(){
	
	
	
}

recherche(){
	
	
	
}

top20(){
	
	
	
}











#endif // FONCTIONS_H_INCLUDED

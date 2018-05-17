#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED

int connexion(){
	printf("Entrez votre login\n");
	char login;
	login = scanf("%c", &login);
	printf("Entrez votre mot de passe\n");
	char mdp;
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

void reconnaissance(char action){
	char act[10];
	if (act == "groupe"){
		listeGroupes();
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

void listeGroupes(){
	EXEC SQL BEGIN DECLARE SECTION;
	char nomGroupe[];
	int nbGroupes;
	int idGroupe;
	EXEC SQL END DECLARE SECTION;
	EXEC SQL SELECT COUNT(*) INTO :nbGroupes FROM NEWSGROUPS.groupe;
	printf("%d groupes\n", nbGroupes);
	EXEC SQL DECLARE C1G CURSOR FOR SELECT * FROM NEWSGROUPS.groupe;
	EXEC SQL OPEN C1G;
	EXEC SQL FETCH C1G INTO :idGroupe, :nomGroupe;
	int i = 0;
	int entree;
	printf("id du groupe \t Nom du groupe");
		for(i = 0 ; i < 20 ; i++){
			while(sql.sqlcode != 1403){
			printf("%d \t %s", idGroupe, nomGroupe);
			EXEC SQL FETCH C1G INTO :idGroupe, :nomGroupe;
			printf("Suite ? 0 \t Selection d'un groupe ? id");
			scanf("%d", entree);
			if (entree == 0)
				i = 0
			else
				
		}
	}
	EXEC SQL CLOSE C1G
	
}

void recherche(){
	EXEC SQL BEGIN DECLARE SECTION;
	int idM;
	varchar titreM[50];
	times tamp dateM;
	char nomAuteur [10];
	char texteM[100];
	int idG;
	int idMPere;
	EXEC SQL END DECLARE SECTION;
	char entree1[5];
	printf("Oui ou non avez-vous le pseudo de l'auteur du message ?");
	scanf("%s", entree1)
	if (entree1 == "non")
		
	if (entree1 == "oui")
		printf("Entrez le pseudo");
		scanf("%d", &nomAuteur);
		EXEC SQL DECLARE C1R CURSOR FOR SELECT * FROM NEWSGROUPS.message WHERE NEWSGROUPS.message.auteur LIKE "&nomAuteur";
		EXEC SQL OPEN C1R;
		EXEC SQL FETCH C1R INTO :idM, :titreM, :dateM, :nomAuteur, :texteM, :idG, :idMPere;
		int i = 0;
		int entree;
		printf("id groupe\t titre\t message\t date\t message\t Auteur\t Texte\t id Groupe\t Message Pere\n");
			for(i = 0 ; i < 20 ; i++){
				while(sql.sqlcode != 1403){
				printf("%d \t %s", idGroupe, nomGroupe);
				EXEC SQL FETCH C1R INTO :idM, :titreM, :dateM, :nomAuteur, :texteM, :idG, :idMPere;
				printf("Suite ? 0 \t Selection d'un message ? id");
				scanf("%d", entree);
				if (entree == 0)
					i = 0
				else
					
			}
	}
	EXEC SQL CLOSE C1G
		
	else
		printf("Je n'ai pas compris...")
		recherche();



}

void top20(){
	
	
	
}

//void affichage(char requete[2]){
//	char debutR = requete[0];
//	char forR = requete[1];
//	char whereR = requete[2]
//	EXEC SQL DECLARE C CURSOR FOR debutR FROM forR whereR;
//	EXEC SQL OPEN C;
//	EXEC SQL FETCH C INTO
//}











#endif // FONCTIONS_H_INCLUDED

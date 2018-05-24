#include <stdio.h>
#include <stdlib.h>
#include"fonctions.h"
//#include<sqlca.h>

int main()
	{
	char tamere;
	menu(connexion());
	return 0;
	}
	
	
	
#ifndef FONCTIONS_H_INCLUDED
#define FONCTIONS_H_INCLUDED
#define pass (void)0


//void affichage(char requete[2]){
//	char debutR = requete[0];
//	char forR = requete[1];
//	char whereR = requete[2]
//	EXEC SQL DECLARE C CURSOR FOR debutR FROM forR whereR;
//	EXEC SQL OPEN C;
//	EXEC SQL FETCH C INTO


//}









#endif // FONCTIONS_H_INCLUDED

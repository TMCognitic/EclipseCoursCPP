
#include "PointersAndReferences.h"

//Méthode recevant une référence
void Increment(int& x)
{
	x++;
}

void Decrement(int* x)
{
	(*x)--;
	//*x--;// poserait un problème car cette ligne décrémenterait l'adresse avant d'aller chercher la valeur
}

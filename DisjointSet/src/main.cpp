//============================================================================
// Name        : DisjointSet.cpp
// Author      : c.totaro
// Version     : 1
// Copyright   : 2021
// Description : Programma d'esempio sull'utilizzo del disjoint set
//============================================================================

#include <iostream>
#include "disjointSet.h"
using namespace std;

/**
 * \mainpage Pagina principale del programma di esempio dell'implementazione del disjoint set.
 * \details Questo programma dimostra le potenzialità di un disjoint set realizzato mediante un vettore dinamico.
 * \brief La funzione main si trova nel file main.cpp \n
 * \warning Se ne consiglia l'uso solamente a scopo educativo, versioni migliori potrebbero essere rilasciate successivamente.
 * \version 1.0
 * \copyright 2021
 * \date 11/05/2021
 * \author Christian Totaro
 */

/**
 * Funzione main di test del disjoint set. \n
 * In particolare vengono svolte le seguenti operazioni: \n
 * 1) Inizializzazione di un array d'esempio contenente 10 interi \n
 * 2) Chiamata della funzione MakeSet e relativo salvataggio del disjoint set ottenuto \n
 * 3) Stampa del disjoint set ottenuto \n
 * 4) Serie di Unioni per costruire logicamente degli alberi \n
 * 5) Stampa del disjoint set dopo le unioni
 * \return Valore di ritorno della funzione main
 */
int main() {
	int arr[] = {1,6,5,4,7,3,8,9,10,2};
	int* x = arr;
	DS ds = MakeSet(x,10);
	if(ds.max_elem>0){
		Print(ds);
		//Serie di unioni per costruire un albero con rappresentante 5
		Union(ds,1,3);
		Union(ds,1,7);
		Union(ds,1,5);
		Union(ds,5,4);
		Union(ds,5,6);
		//Serie di unioni per costruire un albero con rappresentante 2
		Union(ds,2,9);
		Union(ds,2,8);
		Union(ds,8,10);
		//Stampa della foresta composta da due alberi
		Print(ds);
		//Unione dei due alberi
		Union(ds,1,2);
		//Stampa dell'albero completo
		Print(ds);
	}

	return 0;
}

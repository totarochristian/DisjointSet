//============================================================================
// Name        : DisjointSet.cpp
// Author      : c.totaro
// Version     : 1
// Copyright   : 2021
// Description : Source file della struttura dati "disjoint set"
//============================================================================

#include<iostream>
#include "disjointSet.h"
using namespace std;

/**
 * Funzione che dato un array di interi contenente tutti gli id dei nodi e la dimensione di questo array, restituisce il disjoint set. \n
 * Nel caso in cui ci siano degli indici il cui valore non è presente in x, queasti avranno come nodo padre 0.
 * \param x Puntatore al primo elemento di un array di interi.
 * \param dim Dimensione dell'array x passato come parametro.
 * \return Disjoint set generato a partire da x.
 */
DS MakeSet(ds_array x, int dim){
	int max = 0;
	//Trova valore massimo di x
	for(int i=0;i<dim;i++){
		if(*(x+i)>max)
			max = *(x+i);
	}
	if(max!=0){
		//Definisco il DS come un array che ha come dimensione
		//il valore massimo di x.
		DS ds;
		ds.max_elem = max;
		ds.arr = new int[max+1];
		//inizializzo il mio ds con tutti i valori a 0
		for(int i=0;i<=max;i++)
			*(ds.arr+i) = 0;
		//riempo le varie posizioni del mio ds con dei singoletti
		for(int i=0;i<dim;i++){
			*(ds.arr+*(x+i)) = *(x+i);
		}
		return ds;
	}else{
		DS ds;
		ds.max_elem = 0;
		ds.arr = NULL;
		return ds;
	}
}

/**
 * Funzione che dato il disjoint set e un id di un nodo, restituisce il rappresentante dell'albero in cui è contenuto il nodo specificato.
 * \param ds Disjoint set nel quale cercare il nodo con id x.
 * \param x Id del nodo da cercare nel disjoint set.
 * \return Id del nodo rappresentante dell'albero nel quale è contenuto il nodo con id x.
 */
int FindSet(DS ds,int x){
	//Se ho trovato un rappresentante (quindi un self-loop)
	if(*(ds.arr+x)==x)
		return x;//lo ritorno
	else
		return FindSet(ds,*(ds.arr+x));//altrimenti richiamo find set con il padre dell'elemento passato
}

/**
 * Procedura che dato un disjoint set e due id di nodi, modifica il disjoint set unendo gli alberi dei due nodi, se contenuti in alberi diversi.
 * \param ds Disjoint set nel quale sono contenuti i nodi con id x ed y e che dopo l'operazione conterrà l'unione dei due.
 * \param x Id del primo nodo del disjoint set utilizzato per l'operazione di unione con il nodo con id y.
 * \param y Id del secondo nodo del disjoint set utilizzato per l'operazione di unione con il nodo con id x.
 */
void Union(DS ds,int x,int y){
	cout<<"Unione di "<<x<<" e "<<y<<endl;
	//Se i padri dei due elementi sonouguali, fanno già parte dello stesso albero
	//Altrimenti devo unire i due alberi
	if(FindSet(ds,x)!=FindSet(ds,y)){
		//Se l'altezza di x è > di quella di y
		if(Level(ds,x)>=Level(ds,y))
			*(ds.arr+y) = x;
		else
			*(ds.arr+x) = y;
	}
}

/**
 * Funzione che dato un disjoint set e l'id di un nodo, restitusice il livello dell'albero in cui il nodo stesso si trova memorizzato.
 * \param ds Disjoint set nel quale cercare il livello del nodo con id x.
 * \param x Id del nodo di cui cercare il livello nel disjoint set.
 * \return Livello dell'albero nel quale si trova il nodo con id x
 */
int Level(DS ds,int x){
	if(FindSet(ds,x)==x)//Caso base, x è il rappresentante
		return 0;
	else
		return 1+Level(ds,*(ds.arr+x));//Altrimenti richiamo level sommando ogni volta 1
}

/**
 * Procedura che si occupa della stampa di un disjoint set.
 * \param ds Disjoint set da stampare su stdout.
 */
void Print(DS ds){
	cout<<"DS memorizzato: "<<endl;
	//Disegna la linea degli indici
	cout<<"indice: ";
	for(int i=1; i<=ds.max_elem;i++)
			cout<<i<<" ";
	cout<<endl;
	//Disegna la linea con i padri
	cout<<"valore: ";
	for(int i=1; i<=ds.max_elem;i++)
		cout<<*(ds.arr+i)<<" ";
	cout<<endl;
}

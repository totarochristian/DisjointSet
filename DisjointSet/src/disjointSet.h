//============================================================================
// Name        : DisjointSet.cpp
// Author      : c.totaro
// Version     : 1
// Copyright   : 2021
// Description : Header file della struttura dati "disjoint set"
//============================================================================

#ifndef DISJOINTSET_H_
#define DISJOINTSET_H_

/**
 * Definizione del tipo ds_array come puntatore ad intero.
 */
typedef int* ds_array;

/**
 * Struttura dati astratta disjoint set. \n
 * Dal punto di vista teorico questa struttura dati è composta da un array il cui indice rappresenta l'id del nodo, mentre il contenuto dell'array rappresenta l'id del nodo padre del nodo nella posizione in questione.
 * \param arr Puntatore alla prima posizione di un array di interi che conterrà l'indice del nodo padre.
 * \param max_elem Dimensione massima dell'array di interi.
 */
struct DS{
	ds_array arr;
	int max_elem;
};

/**
 * Funzione che dato un array di interi contenente tutti gli id dei nodi e la dimensione di questo array, restituisce il disjoint set.
 */
DS MakeSet(ds_array,int);

/**
 * Funzione che dato il disjoint set e un id di un nodo, restituisce il rappresentante dell'albero in cui è contenuto il nodo specificato.
 */
int FindSet(DS,int);

/**
 * Procedura che dato un disjoint set e due id di nodi, modifica il disjoint set unendo gli alberi dei due nodi, se contenuti in alberi diversi.
 */
void Union(DS,int,int);

/**
 * Funzione che dato un disjoint set e l'id di un nodo, restitusice il livello dell'albero in cui il nodo stesso si trova memorizzato.
 */
int Level(DS,int);

/**
 * Procedura che si occupa della stampa di un disjoint set.
 */
void Print(DS);

#endif /* DISJOINTSET_H_ */

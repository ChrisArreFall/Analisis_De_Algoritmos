//
// Created by Chris on 9/15/17.
//

#ifndef ANALISIS_DE_ALGORITMOS_LINKEDLIST_H
#define ANALISIS_DE_ALGORITMOS_LINKEDLIST_H


#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
/*
 * Node Declaration
 */
struct node
{
    int info;
    struct node *next;
}*start;

/*
 * Class Declaration
 */
class LinkedList {
public:

    LinkedList() {
        start = NULL;
    }

    node *createNode(int value);

    void insertBegin();

    void insertPos();

    void insertLast();

    void deletePos();

    void sort();

    void search();

    void display();


};




#endif //ANALISIS_DE_ALGORITMOS_LINKEDLIST_H

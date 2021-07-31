/*
    utest example : Unit test examples.
    Copyright (C) <2018>  <Mauricio Davila>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef __LINKEDLIST
#define __LINKEDLIST
struct Node
{
    void* pElement;                 //puntero al elemento (persona, empleado, etc.)
    struct Node* pNextNode;         //puntero al prox nodo
}typedef Node;

struct LinkedList
{
    Node* pFirstNode;
    int size;                       //cada vez que agrego o elimino un elemento size++/--
}typedef LinkedList;
#endif



//Publicas
LinkedList* ll_newLinkedList(void);//usado
int ll_len(LinkedList* this);//usado                                       //devuelve el valor del campo int size
Node* test_getNode(LinkedList* this, int nodeIndex);//no hace falta
int test_addNode(LinkedList* this, int nodeIndex,void* pElement);//no hace falta
int ll_add(LinkedList* this, void* pElement);//usado
void* ll_get(LinkedList* this, int index);//usado
int ll_set(LinkedList* this, int index,void* pElement);//usado
int ll_remove(LinkedList* this,int index);//usado
int ll_clear(LinkedList* this);//usado
int ll_deleteLinkedList(LinkedList* this);//usado
int ll_indexOf(LinkedList* this, void* pElement);//usado
int ll_isEmpty(LinkedList* this);//usado
int ll_push(LinkedList* this, int index, void* pElement);//usado
void* ll_pop(LinkedList* this,int index); //usado                          //elimina un elemento (los enlaces a ese elemento) y devuelve un puntero a ese elemento
int ll_contains(LinkedList* this, void* pElement);//usado
int ll_containsAll(LinkedList* this,LinkedList* this2);//usado
LinkedList* ll_subList(LinkedList* this,int from,int to);//usado
LinkedList* ll_clone(LinkedList* this);
int ll_sort(LinkedList* this, int (*pFunc)(void* ,void*), int order);//usado

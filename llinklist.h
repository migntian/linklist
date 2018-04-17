#pragma once
#define HEADER printf("\n--------------%s---------------\n",__FUNCTION__)
#include<stdio.h>
#include<stdlib.h>
#include<stddef.h>
typedef char linktype;
typedef struct linklist
{
	linktype data;
	struct linklist *next;

}linklist;
typedef struct complexnode
{
    linktype data;
    struct complexnode *next;
    struct complexnode *random;
}complexnode;
linklist *head;
void linklist_init(linklist **head);
linklist* creat(linktype value);

void linklist_print(linklist *head);
void linklist_pushback(linklist **head,linktype value);
void linklist_popback(linklist **head);
void linklist_pushfront(linklist **head,linktype value);
void linklist_popfront(linklist **head);
linklist *linklist_find(linklist *head,linktype value);
void linklist_pushhighleft(linklist **head,linklist *pos,linktype value);
void linklist_pushhighright(linklist **head,linklist *pos,linktype value);
void linklist_pop1(linklist **head,linklist *pos);
void linklist_pop2(linklist **head,linktype value);
void linklist_pop2plus(linklist **head,linktype value);
void linklist_nizhi(linklist *head);
void linklist_pushhighleftp(linklist **head,linklist *pos,linktype value);
void linklist_pushhighleft1(linklist **head,linklist *pos,linktype value);
linklist *linklist_reverse(linklist **head);
linklist *linklist_merge(linklist *head1,linklist *head2);
linklist *linklist_findlastknode(linklist *head,size_t k);
int linklist_size(linklist *head);
void linklist_eraselastknode(linklist **head,size_t k);
int linklist_iscycle(linklist *head);
int linklist_getcyclelen(linklist *head);
linklist *linklist_getcycleenter(linklist *head);
linklist *linklist_iscross(linklist *head1,linklist *head2);
void linklist_bubblesort(linklist *head);
linklist * linklist_iscrossplus(linklist *head1,linklist *head2);
linklist *linklist_union(linklist *head1,linklist *head2);


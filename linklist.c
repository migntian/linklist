#include<stdio.h>
#include<stdlib.h>
#include"llinklist.h"

void linklist_init(linklist **head)
{
	if(head==NULL)
	{
		return;
	}
	else
	{
		*head=NULL;
	}
}
void linklist_print(linklist *head)
{
	if(head==NULL)
	{
		return;//空链表
	}
	else{
	linklist *cur=head;
	while(cur!=NULL)
	{
		printf("[%c|%p] ",cur->data,cur);
		cur=cur->next;
	}
	//printf("\n");
	}
	printf("\n");
}
linklist *creat(linktype value)
{
	linklist *newnode=(linklist*)malloc(sizeof(linklist));
	if(newnode==NULL)
	{
		printf("申请失败");
		return NULL;
	}
	else
	{
		newnode->data=value;
		newnode->next=NULL;
		return newnode;
	}

}
void linklist_pushback(linklist **head,linktype value)
{
	if(head==NULL)
	{
		return;//非法输入
	}
	if(*head==NULL)
	{
		*head=creat(value);
		return;

	}
	else
	{
		linklist *cur=*head;
		while(cur->next!=NULL)
		{
			cur=cur->next;
		}
		cur->next=creat(value);
	}
}

void linklist_popback(linklist **head)
{
	if(head==NULL)
	{
		return;//feifa
	}
	if(*head==NULL)
	{
		return;//空链表不能删
	}
	else
	{
		linklist *cur=*head;
		while(cur->next->next)
		{
			cur=cur->next;
		}
		free(cur->next);
		cur->next=NULL;
	}
}
void linklist_pushfront(linklist **head,linktype value)
{
	if(head==NULL)
	{
		return;//非法输入
	}
	if(*head==NULL)
	{
		*head=creat(value);
	}
	else
	{
		linklist *newnode=creat(value);
		newnode->next=*head;
		*head=newnode;

	}
}
void linklist_popfront(linklist **head)
{
	if(head==NULL)
	{
		return;//非法输入

	}
	if(*head==NULL)
	{
		return;//空链表，删不了
	}
	else
	{
		linklist *cur=*head;
		*head=(*head)->next;//*的优先级低于->
		free(cur);
		cur=NULL;
	}
}
linklist *linklist_find(linklist *head,linktype value)
{
	if(head==NULL)
	{
		return;//空链表
	}
	else
	{
		linklist *cur=head;
		while(cur!=NULL){
		if(cur->data!=value)
		{
			cur=cur->next;
		//	if(cur->data==value)
		//	{
		//		//printf("hehe");
		//		return cur;
		//		//printf("haha");
		//	}
		//	else
		//	{
		//		cur=cur->next;
		//	}
		}
		else{
		return cur;}
		}
		printf("没找到\n");
		return NULL;
	}
}
void linklist_pushhighleft(linklist **head,linklist *pos,linktype value)
{
	if(head==NULL)
	{
		return;//非法输入

	}
	if(*head==NULL)
	{
		*head=creat(value);
	}
	if(pos==*head)
	{
		linklist *newnode=creat(value);
		newnode->next=*head;
		*head=newnode;

	}
	else
	{
		linklist *cur=*head;
		while((cur->next)!=pos)
		{
			cur=cur->next;
		}
		linklist *newnode=creat(value);
		newnode->next=pos;
		cur->next=newnode;
	
	}

}
void linklist_pushhighright(linklist **head,linklist *pos,linktype value)
{
	if(head==NULL)
	{
		return;

	}
	if(*head==NULL)
	{
		*head=creat(value);
	}
	else
	//{
	//linklist *cur=*head;
	//while(cur==pos)
	{
		linklist *newnode=creat(value);
		newnode->next=pos->next;
		pos->next=newnode;

	}
	//cur=cur->next;
	//}
}
void linklist_pop1(linklist **head,linklist *pos)
{
	if(head==NULL)
	{
		return;//非法输入
	}
	if(*head==NULL)
	{
		return;//空链表删不了
	}
	if(*head==pos)
	{
		*head=pos->next;
		free(pos);
	//	printf("hehe");
	}
	else
	{
	//	printf("haha");
		linklist *cur=*head;
		while(cur->next!=pos)
		{
			cur=cur->next;
		}
		cur->next=pos->next;
		free(pos);
		pos=NULL;
	}


}
void linklist_pop2(linklist **head,linktype value)
{
	if(head==NULL)
	{
		return;//非法输入
	}
	if(*head==NULL)
	{
		return;//空链表删不了

	}
	else
	{
		linklist *pos=linklist_find(*head,value);
		linklist_pop1(head,pos);
//		linklist *cur=*head;
//		while((cur->next->data)!=value)
//		{
//			cur=cur->next;
//
//		}
//		linklist *pos=linklist_find(*head,value);
//		cur->next=pos->next;
//		free(pos);
//		pos=NULL;
//
	}
}
void linklist_pop2plus(linklist **head,linktype value)
{
	if(head==NULL)
	{
		return;//非法输入
	}
	if(*head==NULL)
	{
		return;//空链表没有可删的元素
	}
	//else
	//{
	//	linklist *cur=*head;
	//	while(cur)
	//	{
	//		linklist_pop1(head,linklist_find(*head,value));
	//		cur=cur->next;
	//	}
	//}
	//{

	//	linklist *p=*head;
	//	*head=p->next;
	//	free(p);
	//	p=NULL;
	//}
else
{
	linklist *cur=*head;
	while(cur)
	{
		if((cur->data)!=value)
		{
			cur=cur->next;
	//		continue;
		}
		else
		{
			linklist *p=cur;
			cur=cur->next;
			linklist_pop1(head,p);
		}
	}
}
}
void linklist_nizhi(linklist *head)
{
	if(head==NULL)
	{
		return;//空链表
	}
	linklist_nizhi(head->next);
	printf("[%c|%p] ",head->data,head);
	//printf("\n");
}
//void linklist_pushhighleftp(linklist **head,linklist *pos,linktype value)
//{
//	if(head==NULL)
//	{
//		return;//非法输入
//	}
//	if(*head==NULL)
//	{
//		*head=creat(value);
//	}
//	else
//	{
//		linklist *newnode=pos;
//		pos->data=creat(value)->data;
//		creat(value)->next=pos;
//	}
//
//
//
//}
void swap(linktype *a,linktype *b)
{
	linktype t=*a;
	*a=*b;
	*b=t;
}
void linklist_pushhighleft1(linklist **head,linklist *pos,linktype value)
{
	if(head==NULL)
	{
		return;
	}
	if(*head==NULL)
	{
		*head=creat(value);
	}
	else
	{
		linklist *newnode=creat(value);
		newnode->next=pos->next;
		pos->next=newnode;
		swap(&(pos->data),&(newnode->data));
	}
}
linklist *linklist_merge(linklist *head1,linklist *head2)
{
	linklist *newhead = NULL;
	linklist *tail = NULL;
	if(head1==NULL)
	{
		return head2;
	}
	if(head2==NULL)
	{
		return head1;
	}
	else
	{
		linklist *cur1 = head1;
		linklist *cur2 = head2;
		//确定头指针
		if((cur1->data)<(cur2->data))
		{
			newhead = tail = cur1;
			cur1 = cur1->next;
		}
		else
		{
			newhead = tail = cur2;
			cur2 = cur2->next;
		}
		while(cur1!=NULL && cur2!=NULL)
		{
			if((cur1->data)<=(cur2->data))
			{
				tail->next=cur1;
				tail=tail->next;
				cur1=cur1->next;
			}
			else
			{
				tail->next=cur2;
				tail=tail->next;
				cur2=cur2->next;
			}
		}
		if(cur1==NULL)
		{
			tail->next=cur2;

		}
		else
		{
			tail->next=cur1;
		}
	}
	return newhead;

}

linklist* linklist_reverse(linklist **head)
{
	if(head==NULL)
	{
		return;//非法输入
	}
	if(*head==NULL)
	{
		return;//空链表
	}
	if((*head)->next==NULL)
	{
		return *head;
	}
	else
	{
		linklist *cur=*head;
		while(cur->next)
		{
			linktype value = cur->next->data;
			linklist_pop1(head,cur->next);
			linklist_pushfront(head,value);
		}
		return *head;
	}
}

int linklist_size(linklist *head)
{
	if(head==NULL)
	{
		return 0;//空链表
	}
	else
	{
		int count=0;
		linklist *cur=head;
		while(cur!=NULL)
		{
			count++;
			cur=cur->next;
		}
		return count;
	}

}
linklist *linklist_findlastknode(linklist *head,size_t k)
{
	if(head==NULL)
	{
		return;//空链表
	}
	if(k>linklist_size(head))
	{
		return;//超过了范围
	}
	else
	{
		size_t i=linklist_size(head)-k;
		linklist *cur=head;
		for(;i>0;i--)
		{
			cur=cur->next;


		}
		return cur;
	}
}
void linklist_erase(linklist **head,size_t k)
{
	if(head==NULL)
	{
		return;//非法
	}
	if(*head==NULL)
	{
		return;//空链表
	}
	if(k==linklist_size(*head))
	{
		linklist_popfront(head);
	}
	else
	{
		linklist *pos=linklist_findlastknode(*head,k);
		linklist_pop1(head,pos);

	}
}
int linklist_iscycle(linklist *head)
{
	if(head==NULL)
	{
		return -1;//空链表
	}
	if(head->next==NULL)
	{
		return 0;//只有一个元素
	}
	else
	{
		linklist *fast=head;
		linklist *slow=head;
		while(fast && fast->next)
		{
			fast=fast->next->next;
			slow=slow->next;
			if(fast==slow)
			{
				return 1;
			}
		}
		return 0;

	}


}
int linklist_getcyclelen(linklist *head)
{
	if(head==NULL)
	{
		return 0;//
	}
	else
	{
		linklist *fast=head;
		linklist *slow=head;
		while(fast && fast->next)
		{
			fast=fast->next->next;
			slow=slow->next;
			if(fast==slow)
			{
				linklist *pos=fast;
				int count = 1;
				while(pos->next!=fast)
				{
					pos=pos->next;
					count++;
			
				}
				return count;
			}
		}

	}

}
linklist *linklist_getcycleenter(linklist *head)
{
	if(head==NULL)
	{
		return NULL;
	}
	else
	{
		linklist *fast=head;
		linklist *slow=head;
		while(fast && fast->next)
		{
			fast=fast->next->next;
			slow=slow->next;
			if(fast==slow)
			{
				linklist *meet=fast;
				linklist *cur=head;
				while(cur!=meet)
				{
					cur=cur->next;
					meet=meet->next;
				}
				return cur;
			}
            
        }
        return NULL;
    }
}
void linklist_bubblesort(linklist *head)
{
    if(head == NULL)
    {
        return;//空链表
    }
    else
    {
        linklist *count = head;
        linklist *tail = NULL;
        linklist *cur2 = head;
        for(;count->next!=NULL;count=count->next)
        {
            for(cur2=head;cur2->next!=tail;cur2 = cur2->next)
            {
                if(cur2->data > cur2->next->data)
                {
                    swap(&(cur2->data),&(cur2->next->data));
                }
            }
            tail=cur2;

        }
    }
}
linklist *linklist_iscross(linklist *head1,linklist *head2)
{
	if(head1==NULL || head2==NULL)
	{
		return NULL;
	}
	else
	{
		linklist *cur1=head1;
		linklist *cur2=head2;
		while(cur1->next!=NULL)
		{
			cur1=cur1->next;
			//cur2=cur2->next;
		}
		while(cur2->next!=NULL)
		{
			cur2=cur2->next;
		}
		if(cur1==cur2)
		{
			int i=linklist_size(head1);
			int j=linklist_size(head2);
			int set=i>j ? i-j : j-i;
			linklist *pos1=head1;
			linklist *pos2=head2;
			if(set==i-j)
			{
				for(;set>0;set--)
				{
					pos1=pos1->next;
				}
				while(pos1 != pos2)
				{
					pos1=pos1->next;
					pos2=pos2->next;
				}
				return pos1;
			}
			else
			{
				for(;set>0;set--)
				{
					pos2=pos2->next;
				}
				while(pos1 != pos2)
				{
					pos1=pos1->next;
					pos2=pos2->next;
				}
				return pos1;
			}


		}
		else
		{
			return NULL;
		}

	}
}

linklist *linklist_iscrossplus(linklist *head1,linklist *head2)
{
    if(head1==NULL)
    {
        return NULL;
    }
    else if(head2==NULL)
    {
        return NULL;
    }
    else
    {
        linklist *set1=linklist_getcycleenter(head1);
        linklist *set2=linklist_getcycleenter(head2);
        if((set1==NULL)&&(set2==NULL))
        {
            linklist_iscross(head1,head2);
        }
        else if(set1 == NULL || set2 == NULL)
        {
            return NULL;
        }
        else
        {
            if(set1->data==set2->data)
            {
                //相交点在环外
                size_t len1=0;
                size_t len2=0;

                linklist *cur1=head1;
                linklist *cur2=head2;

                while(cur1 != set1)
                {
                    cur1=cur1->next;
                    len1++;
                }
                while(cur2!=set1)
                {
                    cur2=cur2->next;
                    len2++;
                }

                cur1 = head1;
                cur2 = head2;

                int offset=0;

                if(len1>len2)
                {
                    offset=len1-len2;
                    for(;offset>0;offset--)
                    {
                        cur1=cur1->next;
                    }
                    while(cur1->data!=cur2->data)
                    {
                        cur1=cur1->next;
                        cur2=cur2->next;
                    }
                    return cur1;
                }
                else
                {
                    offset=len2-len1;
                    for(;offset>0;offset--)
                    {
                        cur2=cur2->next;
                    }
                    while(cur1->data!=cur2->data)
                    {
                        cur1=cur1->next;
                        cur2=cur2->next;
                    }
                    return cur1;
                }
            }
            else
            {
                linklist *tmp1=set1;
                while(tmp1!=set2)
                {
                    if(tmp1->next=tmp1)
                    {
                        return NULL;
                    }
                    tmp1=tmp1->next;
                }
                return tmp1;
            }
        }
    }
}
linklist *linklist_union(linklist *head1,linklist *head2)
{
    if(head1==NULL)
    {
        return NULL;
    }
    if(head2==NULL)
    {
        return NULL;
    }
    else
    {
        linklist *newhead=NULL;
        linklist *newtail=NULL;
        linklist *cur1=head1;
        linklist *cur2=head2;
        for(;cur1!=NULL;cur1=cur1->next)
        {
            for(cur2=head2;cur2!=NULL;cur2=cur2->next)
            {
                //if(cur1->data>cur2->data)
                //{
                //    cur2=cur2->next;
                //}
                //else if(cur1->data<cur2->data)
                //{
                //    cur1=cur1->next;
                //}
                
                if(cur2->data==cur1->data)
                {
                    if(newtail==NULL)
                    {
                        newhead=newtail=cur2;
                    }
                    else
                    {
                        newtail->next=cur2;
                        newtail=newtail->next;
                    }
                }

            }
        }
         return newhead;
    }
}
complexnode *creat1(linktype value)
{
    complexnode *new_node=(complexnode *)malloc(sizeof(complexnode));
    if(new_node==NULL)
    {
        return NULL;
    }
    new_node->data=value;
    new_node->next=NULL;
    new_node->random=NULL;
    return new_node;
}
void complexprint(complexnode *head)
{
    if(head==NULL)
    {
        return;
    }
    else
    {
        complexnode *cur=head;
        for(;cur!=NULL;cur=cur->next)
        {
            printf("[%c]",cur->data);
        }
        printf("\n");
        cur=head;
        for(;cur!=NULL;cur=cur->next)
        {
            if(cur->random==NULL)
            {
                printf("[%c]->[%p]",cur->data,cur->random);
                continue;
            }
            printf("[%c]->[%c]",cur->data,cur->random->data);
        }

    }
    printf("\n");
}
complexnode *copycomplex(complexnode *head)
{
    if(head==NULL)
    {
        printf("haha");
        return;//空链表
    }
    else
    {
        printf("haha");
        complexnode *cur=head;
        while(cur!=NULL)
        {
            complexnode *newnode=creat1(cur->data);
            newnode->next=cur->next;
            cur->next=newnode;
            cur=cur->next->next;
        }
        cur=head;
        complexnode *pos=head;
        complexnode *pos1=head->next;
        complexnode *newhead=NULL;
        complexnode *newtail=NULL;
        while(pos1!=NULL)
        {
            pos1->random=pos->random->next;
            if(newhead=newtail=NULL)
            {
                newhead=newtail=pos1;
            }
            else
            {
                newtail->next=pos1;
                newtail=newtail->next;
            }
            pos=pos->next->next;
            pos1=pos->next;

        }
        return newhead;

    }
}

//////////////////////////////////////
//测试代码
/////////////////////////////////////
void test_linklist_print()
{
	linklist *head; 
	linklist_init(&head);
	linklist_print(head);
//	linklist_distory(head);
}
void test_linklist_pushback()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	printf("在空链表中插入一个元素a\n");
	linklist_pushback(&head,'a');
	linklist_print(head);
	printf("继续插入元素'b','c','d'\n");
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_print(head);
//	linklist_pushback(&head,'a');
//	linklist_print(head);
//	linklist_distory(head);
}
void test_linklist_popback()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("删除最后一个元素\n");
	linklist_popback(&head);
	linklist_print(head);

}
void test_linklist_pushfront()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("头插一个元素x\n");
	linklist_pushfront(&head,'x');
	linklist_print(head);

}
void test_linklist_popfront()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("头删\n");
	linklist_popfront(&head);
	linklist_print(head);
}
void test_linklist_find()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("查找元素b的地址\n");
	printf("%p   %c\n",(linklist_find(head,'b')),(linklist_find(head,'b'))->data);
	//lnklist* ret = linklist_find(head,'b');
	//l( ret == NULL)
	//l
	//l  printf("meizhaodao");	
	//l
	//lse
	//l
	//			
	//}

}
void test_linklist_pushhighleft()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("在第2个元素前面插一个x\n");
	linklist_pushhighleft(&head,linklist_find(head,'b'),'x');
	linklist_print(head);

}
void test_linklist_pushhighright()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("在第2个元素后面插一个x\n");
	linklist_pushhighright(&head,linklist_find(head,'b'),'x');
	linklist_print(head);

}
void test_linklist_pop1()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'x');
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("删除第三个位置的元素\n");
	linklist_pop1(&head,linklist_find(head,'b'));
	linklist_print(head);


}
void test_linklist_pop2()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'x');
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("删除元素a的节点");
	linklist_pop2(&head,'a');
	linklist_print(head);


}

void test_linklist_pop2plus()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'x');
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'d');
	linklist_pushback(&head,'e');
	linklist_pushback(&head,'a');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("删除所有元素a的节点\n");
	linklist_pop2plus(&head,'a');
	linklist_print(head);

}
void test_linklist_nizhi()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_nizhi(head);

}
void test_linklist_left1()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("用不遍历链表的方法在b前面插入x\n");
	linklist_pushhighleft1(&head,linklist_find(head,'b'),'x');
	linklist_print(head);

}
void test_linklist_merge()
{
	HEADER; 
	linklist *head1; 
	linklist_init(&head1);
	linklist_pushback(&head1,'a');
	linklist_pushback(&head1,'c');
	linklist_pushback(&head1,'e');
	linklist_pushback(&head1,'g');
	linklist_print(head1);
	linklist *head2; 
	linklist_init(&head2);
	linklist_pushback(&head2,'b');
	linklist_pushback(&head2,'d');
	linklist_pushback(&head2,'f');
	linklist_pushback(&head2,'h');
	linklist_print(head2);
	linklist_print(linklist_merge(head1,head2));

}
void test_linklist_reverse()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_print(head);
	linklist_reverse(&head);
	linklist_print(head);

}

void test_linklist_size()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	printf("%d\n",linklist_size(head));

}

void test_linklist_findlastknode()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_pushback(&head,'e');
	linklist_pushback(&head,'f');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("打印倒数第三个节点\n");
	printf("[%c|%p]\n",(linklist_findlastknode(head,3)->data),(linklist_findlastknode(head,3)));
	
}





void test_linklist_eraselastknode()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_pushback(&head,'e');
	linklist_pushback(&head,'f');
	printf("打印当前链表\n");
	linklist_print(head);
	printf("删除倒数第三个节点\n");
	linklist_erase(&head,3);
	linklist_print(head);

}


void test_linklist_iscycle()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_pushback(&head,'e');
	linklist *pos=linklist_find(head,'e');
	pos->next=linklist_find(head,'c');
	printf("%d\n",linklist_iscycle(head));

}
void test_linklist_getcyclelen()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_pushback(&head,'e');
	linklist *pos=linklist_find(head,'e');
	pos->next=linklist_find(head,'c');
	printf("%d\n",linklist_getcyclelen(head));

}
void test_linklist_getcycleenter()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'a');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'d');
	linklist_pushback(&head,'e');
	linklist *pos=linklist_find(head,'e');
	pos->next=linklist_find(head,'c');
	printf("入口点是\n");
	printf("[%c|%p]\n",(linklist_getcycleenter(head))->data,linklist_getcycleenter(head));

}

void test_linklist_iscross()
{
	HEADER; 
	linklist *head1; 
	linklist_init(&head1);
	linklist_pushback(&head1,'a');
	linklist_pushback(&head1,'c');
	linklist_pushback(&head1,'e');
	linklist_pushback(&head1,'g');
	linklist *head2; 
	linklist_init(&head2);
	linklist_pushback(&head2,'b');
	linklist_pushback(&head2,'d');
	linklist_pushback(&head2,'f');
	linklist_pushback(&head2,'h');
	linklist_print(head1);
	linklist_print(head2);
	printf("将链表二的h链接到链表一的e上\n");
	linklist *pos=linklist_find(head2,'h');
	pos->next=linklist_find(head1,'e');
	printf("打印出两个链表相交点的位置");
	printf("[%c|%p]\n",(linklist_iscross(head1,head2))->data,linklist_iscross(head1,head2));

}
void test_linklist_bubblesort()
{
	HEADER; 
	linklist *head; 
	linklist_init(&head);
	linklist_pushback(&head,'f');
	linklist_pushback(&head,'e');
	linklist_pushback(&head,'d');
	linklist_pushback(&head,'c');
	linklist_pushback(&head,'b');
	linklist_pushback(&head,'a');
	printf("打印当前链表\n");
	linklist_print(head);
    linklist_bubblesort(head);
	printf("打印当前链表\n");
	linklist_print(head);
    
}


void test_linklist_iscrossplus()
{
	HEADER; 
	linklist *head1; 
	linklist_init(&head1);
	linklist_pushback(&head1,'a');
	linklist_pushback(&head1,'c');
	linklist_pushback(&head1,'e');
	linklist_pushback(&head1,'g');
	linklist_pushback(&head1,'i');
	linklist_pushback(&head1,'j');
	linklist_pushback(&head1,'k');
	linklist *head2; 
	linklist_init(&head2);
	linklist_pushback(&head2,'b');
	linklist_pushback(&head2,'d');
	linklist_pushback(&head2,'f');
	linklist_pushback(&head2,'h');
	linklist_print(head1);
	linklist_print(head2);
	printf("将链表二的h链接到链表一的c上\n");
    //printf("haha");
    linklist *pos=linklist_find(head2,'h');
    pos->next=linklist_find(head1,'g');
	linklist_print(head2);
    //printf("haha");
    linklist *pos1=linklist_find(head1,'k');
    pos1->next=linklist_find(head1,'j');
    //printf("haha");
	printf("打印出两个链表相交点的位置\n");
    linklist*cur=linklist_iscrossplus(head1,head2);
    printf("[%c,%p]",cur->data,cur);
	//printf("[%c|%p]\n",(linklist_iscrossplus(head1,head2))->data,linklist_iscrossplus(head1,head2));

}

test_linklist_union()
{
	HEADER; 
	linklist *head1; 
	linklist_init(&head1);
	linklist_pushback(&head1,'a');
	linklist_pushback(&head1,'c');
	linklist_pushback(&head1,'e');
	linklist_pushback(&head1,'g');
	linklist_print(head1);
	linklist *head2; 
	linklist_init(&head2);
	linklist_pushback(&head2,'b');
	linklist_pushback(&head2,'c');
	linklist_pushback(&head2,'d');
	linklist_pushback(&head2,'e');
	linklist_print(head2);
    linklist *pos= linklist_union(head1,head2);
	linklist_print(pos);

}
void test_copycomplex()
{
	HEADER; 
	complexnode *head;
    complexnode *a=creat1('a');
    complexnode *b=creat1('b');
    complexnode *c=creat1('c');
    complexnode *d=creat1('d');
    head =a;
    a->next=b;
    b->next=c;
    c->next=d;
    
    a->random=c;
    b->random=d;
    c->random=c;
    d->random=d;
    complexprint(head);
    printf("haha");
    complexprint(copycomplex(head));

}
















int main()
{

test_linklist_print();
test_linklist_pushback();
test_linklist_popback();
test_linklist_pushfront();
test_linklist_popfront();
test_linklist_find();
test_linklist_pushhighleft();
test_linklist_pushhighright();
test_linklist_pop1();
test_linklist_pop2();
test_linklist_pop2plus();
test_linklist_nizhi();
test_linklist_left1();
test_linklist_merge();
test_linklist_reverse();
test_linklist_size();
test_linklist_findlastknode();
test_linklist_eraselastknode();
test_linklist_iscycle();
test_linklist_getcyclelen();
test_linklist_getcycleenter();
test_linklist_iscross();
test_linklist_bubblesort();
test_linklist_iscrossplus();
test_linklist_union();
test_copycomplex();

return 0;
}




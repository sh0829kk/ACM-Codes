//
//  main.cpp
//  ds_02_1
//
//  Created by 可可 on 2019/12/15.
//  Copyright © 2019 可可. All rights reserved.
//

#include<iostream>
#include<cmath>
using namespace std;

struct node
{
    int xs,zs;
    node *next;
};

node *read()
{
    int n;
    cin>>n;
    node *head=new node;
    head->next=NULL;
    for(int i=0;i<n;i++)
    {
        node *r=head;
        node *s=new node;
        cin>>s->xs>>s->zs;
        if (s->xs!=0)//系数不为0插入链表
        {
            while (r->next!=NULL&&r->next->zs>=s->zs)//按照指数大小有序插入
            {
                r=r->next;
            }
            if (r->zs==s->zs)
            {
                r->xs+=s->xs;
            }
            else
            {
                s->next=r->next;
                r->next=s;
            }
        }
    }
    return head;
}

void print(node *head)  //输出链表
{
    node *p=head->next;
    if (p==NULL)
    {
        cout<<"0 0";
    }
    else
    {
        while(p)
        {
            cout<<p->xs<<" "<<p->zs;
            if (p->next)
            {
                cout<<" ";
            }
            p=p->next;
        }
    }
    cout<<endl;
}

node *add(node *a,node *b)  //相加链表
{
    node *head=new node;
    head->next=NULL;
    node *p=a->next;
    node *q=b->next;
    node *r=head;
    while (p!=NULL&&q!=NULL)
    {
        node *s=new node;
        s->next=NULL;
        if (p->zs>q->zs)
        {
            s->zs=p->zs;s->xs=p->xs;
            r->next=s;
            r=r->next;
            p=p->next;
        }
        else if (p->zs<q->zs)
        {
            s->zs=q->zs;s->xs=q->xs;
            r->next=s;
            r=r->next;
            q=q->next;
        }
        else
        {
            s->zs=q->zs;s->xs=q->xs+p->xs;
            if (s->xs!=0)
            {
                r->next=s;
                r=r->next;
            }
            p=p->next;
            q=q->next;
        }
    }
    if (p!=NULL)
    {
        r->next=p;
    }
    else
    {
        r->next=q;
    }
    return head;
}

node *mul(node *a,node *b)  //  链表相乘
{
    node *p=a->next;
    node *q=b->next;
    node *head=new node;
    head->next=NULL;
    while(p!=NULL)
    {
        while(q!=NULL)
        {
            node *s=new node;
            s->next=NULL;
            s->zs=p->zs+q->zs;
            s->xs=p->xs*q->xs;
            node *r=head;
            while(r->next!=NULL&&r->next->zs>=s->zs)
                r=r->next;
            if (r->zs==s->zs)
            {
                r->xs+=s->xs;
                if (r->xs==0)
                {
                    node *f=head;
                    while (f->next!=r)
                    {
                        f=f->next;
                    }
                    f->next=r->next;r=f;
                }
            }
            else
            {
                s->next=r->next;
                r->next=s;
            }
            q=q->next;
        }
        p=p->next;
        q=b->next;
    }
    return head;
}

int main()
{
    node *L1,*L2;
    L1=read();
    L2=read();
    node *sum;
    sum=add(L1,L2);
    node *m;
    m=mul(L1,L2);
    print(m);
    print(sum);
    return 0;
}

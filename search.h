//
//  search.h
//  MusicPlaylist
//
//  Created by Pawan on 7/15/18.
//  Copyright © 2018 Pawan. All rights reserved.
//

#ifndef search_h
#define search_h

#include <iostream>
#include <string>
using namespace std;
struct node
{
    struct node *alpha[26];
    bool end;
};

struct node *getnode()
{
    struct node *nn;
    nn=new node;
    for(int i=0;i<26;i++)
    {
        nn->alpha[i]=NULL;
    }
    nn->end=false;
    
    return nn;
}

void search_song(struct song *start)
{
    string m;
   
    struct node *ptr,*root=getnode();
    struct song *pre=start;
    while(pre)
    {
        string s;
         s=pre->songName;
        for(int j=0;j<s.length();j++)
        {
        
        ptr=root;
        for(int i=j;i<s.length();i++)
        {
            if(s[i]!=' ')
            {
               // cout<<s[i];
                int index=s[i]-'a';
            
            if(ptr->alpha[index]==NULL)
            {
                ptr->alpha[index]=getnode();
            }
            ptr=ptr->alpha[index];
            }
        }
            //cout<<endl;
        
        ptr->end=true;
        }
        cout<<endl;
        cout<<endl;
        pre=pre->next;
    }
     cin>>m;
    ptr=root;
    int flag=1;
    for(int i=0;i<m.length();i++)
    {
        
        int index=m[i]-'a';
        if(ptr->alpha[index])
        {
            ptr=ptr->alpha[index];
        }
        else
        {
            flag=0;
            break;
        }
    }
    if(ptr->end==true && flag==1)
    {
        cout<<"##find##";
    }
    else
    {
        cout<<"##NOOO##";
    }
}


#endif /* search_h */

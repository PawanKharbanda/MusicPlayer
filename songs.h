//
//  songs.h
//  MusicPlaylist
//
//  Created by Pawan on 7/15/18.
//  Copyright © 2018 Pawan. All rights reserved.
//

#ifndef songs_h
#define songs_h
#include <time.h>
#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct song
{
public:
    string songName;
    string songArtist;
    int love=0;
    int songPlays=0;
    int songId;
    struct song *next;
    struct song *prev;
    int visit=0;
};


class songs
{
public:
    struct song *hash[10]={NULL};
    int count_songs=0;
    string readsongs();
    struct song* addsongs(string s,struct song *start);
    void create_hash(struct song *start);
    void shuffle_play();
    void forward_play(struct song *start);
    void backward_play(struct song *start);
    struct song* custom_played(struct song *start,struct song *start1);
    struct song* recently_played(struct song *start,struct song *start1); //cache
};

string songs::readsongs ()
{
    string sentences;
    ifstream file("songsfile.txt");
    if(file.is_open())
    {
        getline(file, sentences);
    }
    else{
        cout<<"error";
    }
    file.close();
    
    return sentences;
    
}
struct song* songs::addsongs(string s,struct song *start)
{
    struct song *ptr,*nn;
    int l,i=0,id=1;
    string n,a;
    l=int(s.length());
    
    while(i<l)
    {
        while(s[i]!='*')
        {
            n=n+s[i];
            i++;
        }
        i++;
        while(s[i]!='|')
        {
            a=a+s[i];
            i++;
        }
        i++;
        
        nn=new song;
        
        nn->next=NULL;
        nn->prev=NULL;
        nn->songName=n;
        nn->songArtist=a;
        nn->songId=id;
        id++;
        n="\0";
        a="\0";
        count_songs++;
        if(start==NULL)
        {
            start=nn;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=nn;
            nn->prev=ptr;
        }
        
        
        
    }
    
    return start;
}
void songs::create_hash(struct song *start)
{
    struct song *ptr,*hptr,*hnn;
    ptr=start;
    while(ptr!=NULL)
    {
        hnn=new song;
        
        hnn->next=NULL;
        hnn->prev=NULL;
        hnn->songName=ptr->songName;
        hnn->songArtist=ptr->songArtist;
        hnn->songId=ptr->songId;
        //hash Creation
        int locate=ptr->songId%10;
        
        if(hash[locate]==NULL)
        {
            hash[locate]=hnn;
            
        }
        else
        {
            hptr=hash[locate];
            while(hptr->next!=NULL)
            {
                hptr=hptr->next;
            }
            hptr->next=hnn;
            
        }
        ptr=ptr->next;
    }
    
}
void songs::shuffle_play()
{
    
    
    int c=count_songs;
    while(c>0)
    {
        struct song *hptr;
        int val = rand() % 10;
        hptr=hash[val];
        if(hptr->visit==0)
        {
            cout<<hptr->songName<<val<<endl;
            hptr->visit=1;
            c--;
        }
        else
        {
            while(hptr!=NULL)
            {
                if(hptr->visit==0)
                {
                    cout<<hptr->songName<<val<<endl;
                    hptr->visit=1;
                    c--;
                    break;
                }
                else
                {
                    hptr=hptr->next;
                }
                
            }
            
        }
    }
    
}
void songs::forward_play(struct song *start)
{
    while(start!=NULL)
    {
        cout<<start->songName<<endl;
        start=start->next;
    }
}

void songs::backward_play(struct song *start)
{
    if(start!=NULL)
    {
        backward_play(start->next);
        cout<<start->songName<<endl;
    }
    
}

struct song* songs::recently_played(struct song *start,struct song *start1)
{
    static int c;
    if(start!=NULL)
    {
        struct song *nn,*ptr,*d;
        
        
        nn=new song;
        nn->songName=start->songName;
        nn->next=NULL;
        nn->prev=NULL;
        
        ptr=start1;
        while(ptr!=NULL)
        {
            if(ptr->songName==nn->songName)
            {
                if(ptr==start1)
                {
                    d=start1;
                    start1=start1->next;
                    start1->prev=NULL;
                    delete(d);
                }
                else if(ptr->next==NULL)
                {
                    d=ptr;
                    ptr=ptr->prev;
                    ptr->next=NULL;
                    delete(d);
                }
                else
                {
                    ptr=ptr->prev;
                    d=ptr;
                    ptr->next=ptr->next->next;
                    ptr=ptr->next;
                    ptr->prev=d;
                }
                c=c-1;
            }
            ptr=ptr->next;
        }
        
        if(c==5)
        {
            ptr=start1;
            while(ptr->next!=NULL)
            {
                ptr=ptr->next;
            }
            ptr=ptr->prev;
            ptr->next=NULL;
            c=c-1;
        }
        
        
        
        if(start1==NULL)
        {
            start1=nn;
        }
        else
        {
            start1->prev=nn;
            nn->next=start1;
            start1=nn;
            
        }
        c++;
        
    }
    /* struct song *ptr=start1;
     while(ptr!=NULL)
     {
     cout<<ptr->songName<<"  **  ";
     ptr=ptr->next;
     }
     
     cout<<endl;*/
    return start1;
}
struct song* songs::custom_played(struct song *start,struct song *start1)
{
    cout<<start->songName<<endl;
    start1=recently_played(start,start1);
    int f=1;
    while(f)
    {    int c;
        cin>>c;
        switch (c)
        {
            case 1:
                start=start->next;
                if(start!=NULL)
                {
                    cout<<start->songName<<endl;
                    start1=recently_played(start,start1);
                    
                }
                break;
                
            case 2:
                start=start->prev;
                if(start!=NULL)
                {
                    cout<<start->songName<<endl;
                    start1=recently_played(start,start1);
                    
                }
                break;
                
            case 0:
                f=0;
                break;
        }
    }
    return start1;
}

#endif /* songs_h */

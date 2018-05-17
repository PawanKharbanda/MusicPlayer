//
//  main.cpp
//  MusicPlaylist
//
//  Created by Pawan on 4/21/18.
//  Copyright © 2018 Pawan. All rights reserved.
//
/*#include <iostream>
#include <string>
#include <fstream>
using namespace std;
struct song
{
    string songName;
    string songArtist;
    int love=0;
    int songPlays=0;
    int songId;
    struct song *next;
};


class songs
{
public:
   string readsongs();
struct song* addsongs(string s,struct song *start);
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
    
{     while(s[i]!='*')
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
    nn->songName=n;
    nn->songArtist=a;
    nn->songId=id;
    id++;
    n="\0";
    a="\0";
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
    }
}
    
    return start;
}
int main()
{
    struct song *start;
    start=NULL;
    songs call;
    string s;
   s=call.readsongs();
    //cout<<s;
    start=call.addsongs(s,start);
    while(start!=NULL)
    {
        cout<<start->songName<<"  "<<start->songId<<endl;
        start=start->next;
    }
   
    return 0;
}*/




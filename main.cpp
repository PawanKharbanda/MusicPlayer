//
//  main.cpp
//  MusicPlaylist
//
//  Created by Pawan on 4/21/18.
//  Copyright © 2018 Pawan. All rights reserved.
//
#include <time.h>   
#include <iostream>
#include <string>
#include <fstream>
#include "songs.h"
//#include "search.h"
using namespace std;

int main()
{
    struct song *start=NULL,*start1=NULL;
    songs call;
    int f=1,c;
    string s;
    s=call.readsongs();
    start=call.addsongs(s,start);
    call.create_hash(start);
    //search_song(start);
    while(f)
    {
        cin>>c;
        switch (c)
        {
            case 1:
              call.forward_play(start);
                break;
                
            case 2:
               call.backward_play(start);
                break;
                
            case 3:
                srand (time(NULL));  
                call.shuffle_play();
                break;
                
            case 4:
                  start1=call.custom_played(start,start1);
                break;
                
            case 5:
                //recentlyPlayed
                cout<<endl<<"Recently Played 5 Songs are"<<endl;
                cout<<"::::::::::::::::::::::::::::::::::"<<endl;
                while(start1!=NULL)
                {
                    cout<<start1->songName<<endl;
                    start1=start1->next;
                }
                cout<<"::::::::::::::::::::::::::::::::::"<<endl;
                break;
                
            case 6:
                f=0;
                break;
                
        }
   
    }
    return 0;
}




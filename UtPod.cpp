//
// Created by Dell-5379 on 10/27/2019.
//


#include "Song.h"
#include "UtPod.h"
#include <string>
#include <iostream>
using namespace std;


    UtPod::UtPod(){
        memSize = MAX_MEMORY;
        songs = NULL;

    }
    UtPod::UtPod(int size){
    if (size > MAX_MEMORY)
    {
        memSize = MAX_MEMORY;

    }
    else {
        memSize = size;

    }
}


int UtPod::addSong(Song const &s){
        if (getRemainingMemory() > s.getsize()) {

            SongNode *temp = new SongNode;
            temp->s = s;
            temp->next = songs;
            songs = temp;

            return 0;
        }
        else {
            return  -1;
        }
}




int UtPod::removeSong(Song const &s){
    SongNode* back = NULL; // do i delete this??? at end??
    SongNode* forward = songs;


    if (songs == NULL) {
        return 0;
    }
    else {
        while ((forward != NULL) && !(forward->s == s)) {
            back = forward;
            forward = forward->next;
        }
        if (back == NULL) { //first element
            songs = forward->next;
            delete(forward);
            return 0;

        }
        else if (forward != NULL) {
            back->next = forward->next;
            delete(forward);
            return 0;

        }
    }
        return -1;
}

void UtPod::shuffle(){
    srand(currentTime);
    SongNode *back = songs;
    int numSong = 0;
    int switchFlag = 0;
    SongNode *p;

    while (back != NULL) {
        numSong++;
        back = back->next;
    }
    for (int i = 0;i < 2*numSong; i++) {
        int pPointer = (rand() % numSong);
        int backPointer = (rand() % numSong);
        SongNode *back = songs;
        SongNode *p = songs;
        if (numSong > 1 && pPointer !=backPointer) {

            for (int j = 0; j < backPointer;  j++) {
                back = back->next;
            }
            for (int j = 0; j < pPointer;  j++) {
                p = p->next;
            }
            Song temp = p->s;
            p->s = back->s;
            back->s = temp;
            switchFlag = 1;
            back = songs;
            p = back->next;
        }

    }


}






void UtPod::showSongList(){
    SongNode *p = songs;

    while (p != NULL) {
        cout <<  p->s << endl;
        p = p->next;
    }
    cout<< '\n'<< endl;
}




void UtPod::sortSongList() {
    SongNode *back = songs;
    int song = 0;
    int switchFlag = 0;

    while (back != NULL) {
        song++;
        back = back->next;
    }

    if (song > 1) {
        back = songs;
        SongNode *p = back->next;
        while (p != NULL) {
            if (p->s < back->s) {
                Song temp = p->s;
                p->s = back->s;
                back->s = temp;
                switchFlag = 1;
                back = songs;
                p = back->next;
            } else {
                back = p;
                p = p->next;
            }
        }
    }


}


void UtPod::clearMemory() {
    while (songs != NULL) {
        SongNode *p = songs;
        songs = songs->next;
        delete p;


    }
}


    int UtPod::getRemainingMemory() {
        SongNode *p = songs;
        int reMem = memSize;
        while (p != NULL) {
            reMem = reMem - p->s.getsize();
            p = p->next;
        }
        if ( reMem < 0 ){
            return 0;
        }
        else {
            return reMem;
        }


    }

UtPod::~UtPod(){
    clearMemory();
    cout<<"cleared Memory"<<endl;
    
}
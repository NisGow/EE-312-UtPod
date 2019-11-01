//
// Created by Dell-5379 on 10/27/2019.
//

#ifndef SONG_H
#define SONG_H

#include <string>
#include <iostream>
using namespace std;

class Song {

    private:
        string title;
        string artist;
        int size;


    public:
        Song();
        Song(string _title, string _artist , int _size);

        string getTitle() const;
        void setTitle(string n);
        string getArtist() const;
        void setArtist(string n);
        int getsize() const;
        void setSize(int n);

        bool operator >(Song const &rhs);
        bool operator <(Song const &rhs);
        bool operator ==(Song const &rhs);

        ~Song();

};
ostream& operator << (ostream& out, const Song &g);



#endif //UTPOD_SONG_H

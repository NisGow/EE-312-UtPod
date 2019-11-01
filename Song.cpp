//
// Created by Dell-5379 on 10/27/2019.
//

#include "Song.h"
Song::Song() {

}

Song::Song(string _title, string _artist, int _size)
{
    title = _title;
    artist = _artist;
    size = _size;
}


string Song::getTitle() const
{ return title; }

void Song:: setTitle(string n)
{
    title = n;
};
string Song::getArtist() const
{ return artist; }

void Song::setArtist(string n)
{
    artist = n;
};

int Song::getsize() const
{ return size; }

void Song::setSize(int n)
{
    size = n;
};

bool Song::operator >(Song const &rhs)
{
    if (artist > rhs.artist) {
        return (this->artist > rhs.artist);
    } else {
        if (artist == rhs.artist) {
            if (title > rhs.title) {
                return (this->title > rhs.title);
            } else {
                if (title == rhs.title) {
                    if (size > rhs.size) {
                        return (this->size > rhs.size);
                    } else {
                        return false;
                    }
                }
            }
            return false;
        }
    }
    return false;
}

bool Song::operator <(Song const &rhs) {
    if (artist < rhs.artist) {
        return (this->artist < rhs.artist);
    } else {
        if (artist == rhs.artist) {
            if (title < rhs.title) {
                return (this->title < rhs.title);
            } else {
                if (title == rhs.title) {
                    if (size < rhs.size) {
                        return (this->size < rhs.size);
                    } else {
                        return false;
                    }
                }
            }
            return false;
        }
    }
    return false;
}


bool Song::operator ==(Song const &rhs)
{
    return (title == rhs.title &&
            artist == rhs.artist &&
            size == rhs.size);

}

ostream& operator << (ostream& out, const Song &g) {
    out << g.getTitle() << " (" << g.getArtist() << ") - " << g.getsize();
    return out;
}

    Song::~Song()
{

}

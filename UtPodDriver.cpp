/* utPod_driver.cpp
Demo Driver for the UtPod.

Roger Priebe
EE 312 10/16/18

This is a basic driver for the UtPod.

You will want to do more complete testing.

*/
#include <cstdlib>
#include <iostream>
#include "Song.h"
#include "UtPod.h"

    using namespace std;

    int main(int argc, char *argv[])
    {

        UtPod t;
        cout << "Testing UtPod with adding song with no remaining mem and deleting a song that is not found"<< endl;

        Song s1("GOT7", "Fly", 35);
        int result = t.addSong(s1);
        cout << "add result = " << result << endl;

        Song s2("Seventeen", "Mansae", 17);
        result = t.addSong(s2);
        cout << "add result = " << result << endl;

        Song s3("Hot line Bling", "Drake", 300);
        result = t.addSong(s3);
        cout << "add result = " << result << endl;

        Song s4("100 Degrees", "Rich Brian", 50);
        result = t.addSong(s4);
        cout << "add result = " << result << endl;

        Song s5("Beatles", "Hey Jude5", 40);
        result = t.addSong(s5);
        cout << "add result = " << result << '\n'<< endl;

        cout << "Adding song that is too big" << result << endl;
        Song s6("Beatles", "Hey Jude5", 400);
        result = t.addSong(s6);
        cout << "add result = " << result << '\n'<< endl;


        cout << "Song List \n"<< endl;
        t.showSongList();
        t.shuffle();
        cout << "Shuffled List  \n"<< endl;
        t.showSongList();

        result = t.removeSong(s2);
        cout << "delete  S2 result = " << result << endl;

        result = t.removeSong(s3);
        cout << "delete S3 result = " << result << '\n' << endl;

        cout << "Deleted List "<< endl;
        t.showSongList();
        cout << "Remaining memory = " << t.getRemainingMemory() << endl;

        result = t.removeSong(s1);
        cout << "delete S1 result = " << result << endl;

        result = t.removeSong(s5);
        cout << "delete S5 result = " << result<< '\n' << endl;

        cout << "Deleting song that is not in UtPod" << result << endl;
        result = t.removeSong(s1);
        cout << "delete S1 result = " << result << endl;




        cout << "Testing UtPod with multiples of the same song "<< endl;

        Song s12("GOT7", "Fly", 35);
        result = t.addSong(s12);
        cout << "add result = " << result << endl;

        Song s22("GOT7", "Fly", 35);
        result = t.addSong(s22);
        cout << "add result = " << result << endl;

        Song s32("Hot line Bling", "Drake", 300);
        result = t.addSong(s32);
        cout << "add result = " << result << endl;

        Song s42("100 Degrees", "Rich Brian", 50);
        result = t.addSong(s42);
        cout << "add result = " << result << endl;

        Song s52("Beatles", "Hey Jude5", 40);
        result = t.addSong(s52);
        cout << "add result = " << result << '\n'<< endl;

        cout << "Song List \n"<< endl;
        t.showSongList();
        t.shuffle();
        cout << "Shuffled List  \n"<< endl;
        t.showSongList();
        t.sortSongList();
        t.showSongList();



        result = t.removeSong(s12);
        cout << "delete S11 result = " << result<< '\n' << endl;
        cout << "After Deleting Song List "<< endl;
        t.showSongList();

        t.clearMemory();

        cout << "Testing UtPod with one song and 0 songs "<< endl;

        Song s13("GOT7", "Fly", 35);
        result = t.addSong(s12);
        cout << "add result = " << result << endl;

        t.showSongList();
        t.sortSongList();
        t.showSongList();

        t.shuffle();
        t.showSongList();


        t.removeSong(s22);
        t.showSongList();







    }
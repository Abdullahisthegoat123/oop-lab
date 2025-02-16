#include <iostream>
using namespace std;

class musicplayer {
private:
    string playlist[100];
    int totalSongs = 0;
    string currentlyplayingsong;

public:
    void addSong(string songName) {
        playlist[totalSongs] = songName;
        totalSongs++;
    }

    void playSong(string songName) {
        bool isAvailable = false;
        for (int i = 0; i < totalSongs; i++) {
            if (playlist[i] == songName) {
                isAvailable = true;
                break;
            }
        }
        if (isAvailable) {
            currentlyplayingsong = songName;
            cout << "Now Playing: " << currentlyplayingsong << endl;
        } else {
            cout << "Song not found! Add it first." << endl;
        }
    }

    void showSongs() {
        cout << "\n--- Playlist ---\n";
        if (totalSongs == 0) {
            cout << "No songs added yet.\n";
            return;
        }
        for (int i = 0; i < totalSongs; i++) {
            cout << i + 1 << ". " << playlist[i] << endl;
        }
        cout << endl;
    }

    void removeSong(string songName) {
        bool exists = false;
        int songIndex;
        for (int i = 0; i < totalSongs; i++) {
            if (playlist[i] == songName) {
                exists = true;
                songIndex = i;
                break;
            }
        }
        if (exists) {
            for (int i = songIndex; i < totalSongs - 1; i++) {
                playlist[i] = playlist[i + 1];
            }
            totalSongs--;
            cout << "Song removed successfully!\n";
        } else {
            cout << "Song not found!\n";
        }
    }
};

int main() {
    musicplayer p;
    int begin = 1, ch;
    string songName;

    while (begin) {
        cout << "\n--- Music Player ---\n";
        cout << "1. Add Song\n2. Remove Song\n3. Play Song\n4. Show Songs\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> ch;

        switch (ch) {
            case 1:
                cout << "Enter song name to add: ";
                cin >> songName;
                p.addSong(songName);
                break;
            case 2:
                cout << "Enter song name to remove: ";
                cin >> songName;
                p.removeSong(songName);
                break;
            case 3:
                cout << "Enter song name to play: ";
                cin >> songName;
                p.playSong(songName);
                break;
            case 4:
                p.showSongs();
                break;
            case 5:
                begin = 0;
                break;
            default:
                cout << "Invalid choice! Try again.\n";
        }
    }
}

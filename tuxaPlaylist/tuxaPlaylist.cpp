// tuxaPlaylist.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// Struct untuk menyimpan informasi lagu
struct Song {
    string title;
    string artist;
    int duration; // durasi dalam detik

    // Operator overloading untuk membandingkan lagu berdasarkan judul
    bool operator<(const Song& other) const {
        return title < other.title;
    }
};

// Node untuk linked list
struct Node {
    Song song;
    Node* next;

    Node(Song s) : song(s), next(nullptr) {}
};

// Linked list untuk menyimpan playlist
class LinkedList {
public:
    LinkedList() : head(nullptr) {}

    void addSong(const Song& song) {
        Node* newNode = new Node(song);
        if (!head) {
            head = newNode;
        } else {
            Node* temp = head;
            while (temp->next) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
    }

    void displayPlaylist() const {
        Node* temp = head;
        while (temp) {
            cout << "Title: " << temp->song.title << ", Artist: " << temp->song.artist << ", Duration: " << temp->song.duration << " sec\n";
            temp = temp->next;
        }
    }

    Node* getHead() const {
        return head;
    }

private:
    Node* head;
};

// Function untuk mencari lagu berdasarkan judul
Song* searchSong(LinkedList& playlist, const string& title) {
    Node* temp = playlist.getHead();
    while (temp) {
        if (temp->song.title == title) {
            return &temp->song;
        }
        temp = temp->next;
    }
    return nullptr;
}

// Function untuk mengurutkan playlist
void sortPlaylist(vector<Song>& songs) {
    sort(songs.begin(), songs.end());
}

// Function untuk menampilkan menu
void displayMenu() {
    cout << "1. Tambah lagu ke playlist\n";
    cout << "2. Tampilkan playlist\n";
    cout << "3. Cari lagu\n";
    cout << "4. Urutkan playlist\n";
    cout << "5. Keluar\n";
}

int main() {
    LinkedList playlist;
    vector<Song> songArray;
    queue<Song> songQueue;
    int choice;
    
    do {
        displayMenu();
        cout << "Pilih opsi: ";
        cin >> choice;
        cin.ignore(); // ignore newline

        if (choice == 1) {
            Song song;
            cout << "Masukkan judul lagu: ";
            getline(cin, song.title);
            cout << "Masukkan artis lagu: ";
            getline(cin, song.artist);
            cout << "Masukkan durasi lagu (dalam detik): ";
            cin >> song.duration;
            cin.ignore(); // ignore newline

            playlist.addSong(song);
            songArray.push_back(song);
            songQueue.push(song);

        } else if (choice == 2) {
            playlist.displayPlaylist();

        } else if (choice == 3) {
            string title;
            cout << "Masukkan judul lagu yang dicari: ";
            getline(cin, title);
            Song* song = searchSong(playlist, title);
            if (song) {
                cout << "Lagu ditemukan: " << song->title << " oleh " << song->artist << "\n";
            } else {
                cout << "Lagu tidak ditemukan\n";
            }

        } else if (choice == 4) {
            sortPlaylist(songArray);
            cout << "Playlist setelah diurutkan:\n";
            for (const auto& song : songArray) {
                cout << "Title: " << song.title << ", Artist: " << song.artist << ", Duration: " << song.duration << " sec\n";
            }

        } else if (choice == 5) {
            cout << "Keluar dari program.\n";

        } else {
            cout << "Opsi tidak valid. Silakan coba lagi.\n";
        }
    } while (choice != 5);

    return 0;
}


// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file

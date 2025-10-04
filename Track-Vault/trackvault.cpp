#include <iostream>
#include <cstring>
#include <fstream>
#include <iomanip>

using namespace std;

const int maxrow = 50;

string TrckName[maxrow] = {};
string TrckID[maxrow] = {};
string TrckArtist[maxrow] = {};
string TrckAlbum[maxrow] = {};
string TrckRelease[maxrow] = {};

// Open Text File
void OpenFile(){

    string line;
    ifstream myfile("D:\\crudproject\\textfile.txt");

    if (myfile.is_open()){ 
 
    int x = 0;
    while (getline(myfile, line))
    {
        int l = line.length();
        TrckID[x] = line.substr(0, 3);
        TrckName[x] = line.substr(4,1 - 4);
        TrckArtist[x] = line.substr(0,0);
        x++;
    }
  }
  else{
    cout << "Unable to open the file" << endl;
  }
}

// Add Song Function
void AddSongs() {
    char name[20];
    char songid[5];
    char artist[20];
    char album[20];
    char year[5];

    cin.ignore();

    cout << "Song ID: ";
    cin.getline(songid, 5);
    cout << "Song Title: ";
    cin.getline(name, 20);
    cout << "Artist: ";
    cin.getline(artist, 20);
    cout << "Album: ";
    cin.getline(album, 20);
    cout << "Release year: ";
    cin.getline(year, 5);

    for (int x = 0; x < maxrow; x++) {
        if (TrckID[x] == "\0"){
            TrckID[x] = songid;
            TrckName[x] = name;
            TrckArtist[x] = artist;
            TrckAlbum[x] = album;
            TrckRelease[x] = year;
            break;
        }
    }
}

// List All Songs Function
void ListSongs() {
    system("CLS");

    cout << "\n                               YOUR TRACK-VAULT LIBRARY\nAll Songs" << endl;
    cout << "====================================================================================================================================" << endl;

    int counter = 0;
    cout << left; 
    cout << setw(6) << "No." 
         << "| " << setw(10) << "ID"
         << "| " << setw(25) << "TITLE"
         << "| " << setw(20) << "ARTIST"
         << "| " << setw(20) << "ALBUM"
         << "| " << setw(15) << "Release Year" << endl;
    cout << "------------------------------------------------------------------------------------------------------------------------------------\n";

    for (int x = 0; x < maxrow; x++) {
        if (TrckID[x] != "\0") { 
            counter++;
            cout << setw(6) << counter 
                 << "|  " << setw(10) << TrckID[x]
                 << "|  " << setw(25) << TrckName[x] 
                 << "  " << setw(20) << TrckArtist[x]
                 << "  " << setw(20) << TrckAlbum[x]
                 << "  " << setw(15) << TrckRelease[x] << endl;
        }
    }

    if (counter == 0) {
        cout << "No Record found!" << endl;
    }

    cout << "====================================================================================================================================\n";
}

 
// Search Song Function
void SearchSongs(string search) {
    system("CLS"); 
    int counter = 0;

    cout << "                                          RESULTS" << endl;
    cout << "========================================================================================================" << endl;

    for (int x = 0; x < maxrow; x++) 
    {
        if (TrckID[x] == search) 
        { 
            counter++;
            cout << "   " << counter << "    " << TrckID[x] << "    " << TrckName[x]<< "    " << TrckArtist[x] << "     " << TrckAlbum[x] << "     " << TrckRelease[x]<< endl;
            break; 
        }
    }

    if (counter == 0) {
        cout << "No Record Found!" << endl;
    }

    cout << "========================================================================================================" << endl;
}

// Update Song Details Function
void UpdateSongs(string search){

    char name[20];
    char songid[5];
    char artist[20];
    char album[20];
    char year[5];

    int counter = 0;

    for (int x = 0; x < maxrow; x++)
    {
        if (TrckID[x] == search)
        {
            counter++;

            cout << "Song Title: ";
            cin.getline(name, 20);

            TrckName[x] = name;

            cout << "Artist: ";
            cin.getline(artist, 20);

            TrckArtist[x] = artist;

            cout << "Album: ";
            cin.getline(album, 20);

            TrckAlbum[x] = album;

            cout << "Release Year: ";
            cin.getline(year, 5);

            TrckRelease[x] = year;

            cout << "Update Successful!" << endl;

            break;
        }
    }

        if (counter == 0){
            cout << "ID does not exist!" << endl;
        }

}

// Delete Song Record Function
void DeleteSongs(string search){

    int counter = 0;
    for (int x  = 0; x < maxrow; x++)
    {
        if (TrckID[x] == search){
            counter ++;

            TrckName[x] = " ";
            TrckID[x] = " ";
            TrckArtist[x] = " ";
            TrckAlbum[x] = " ";
            TrckRelease[x] = " ";

            cout << "Successfully Deleted!" << endl;
            break;
        }
    } 
    
    if (counter == 0){
        cout << "ID Number does not exist!";
    }
}

// Delete All Songs Function
void DeleteAllSongs() {
    for (int x = 0; x < maxrow; x++) {
        TrckID[x].clear();
        TrckName[x].clear();
        TrckArtist[x].clear();
        TrckAlbum[x].clear();
        TrckRelease[x].clear();
    }
    cout << "All songs have been successfully deleted!" << endl;
}


void SaveToFile(){
    ofstream myfile;
    myfile.open("D:\\crudproject\\textfile.txt");
    for (int x = 0; x < maxrow; x++){
        if (TrckID[x] == "\0"){
            break;
        }
        else{
            myfile << TrckID[x] + "          " + TrckName[x] + "          " + TrckArtist[x] + "          " + TrckAlbum[x]+ "          " + TrckRelease[x]<< endl;
        }
    }
}
int main() {

    int option;
    string trckID;
    system("CLS");
    OpenFile();

    do {
        cout << "                       WELCOME TO TRACK VAULT!\n                       Your Choice, Your Music.\nHOME" << endl;
        cout << "========================================================================" << endl;
        cout << "1- Add a song" << endl;
        cout << "2- Edit song details" << endl;
        cout << "3- Remove a song from library" << endl;
        cout << "4- Search a song" << endl;
        cout << "5- Open your library" << endl;
        cout << "6- Delete All Songs" << endl;
        cout << "7- Exit and Save to Textfile" << endl;
        cout << "========================================================================" << endl;

        cout << "Select option: ";
        cin >> option;

        switch (option) {
            case 1:
                AddSongs();
                system("CLS");
                break;
            case 2:
                cin.ignore();
                cout << "Search by ID >> ";
                getline(cin, trckID);
                system("CLS");
                UpdateSongs(trckID);
                break;
            case 3: 
                cin.ignore();  
                cout << "Delete by ID >> ";
                getline(cin,trckID); 
                DeleteSongs(trckID);
                cin.ignore();  
                system("CLS");
                break;        
            case 4:
                cin.ignore();
                cout << "Search by ID >> ";
                getline(cin, trckID);
                SearchSongs(trckID);
                break;
            case 5:
                ListSongs();
                break;
            case 6:
                 DeleteAllSongs();
                 break;
        }

    } while (option != 7);

     SaveToFile();

    cout << "Exit... Saved Successfully!" << endl;
    return 0;
}

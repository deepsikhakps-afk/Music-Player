#include <iostream>
#include <windows.h>
#include <stdio.h> // For getchar()
using namespace std;

// List of available songs
const char *songs[] = {
    "sample-1s.wav",
    "sample-2s.wav",
    "sample-3s.wav"};
const int songCount = sizeof(songs) / sizeof(songs[0]);

void playMusic(const char *filename)
{
    // system("cls");
    cout << "\n\nPlaying: " << filename << "\n";
    if (!PlaySound(TEXT(filename), NULL, SND_FILENAME | SND_ASYNC))
    {
        cout << "Error: Could not play the sound.\n";
    }
    else
    {
        cout << "Music is playing in the background...\n";
    }
    cout << "Press ENTER to return to menu.\n";
    getchar();
}

void stopMusic()
{
    PlaySound(NULL, NULL, 0);
    cout << "\nMusic stopped.\n";
    cout << "Press ENTER to return to menu.\n";
    getchar();
}

void showHomepage() {
    system("cls"); // Clears the console (Windows only)

    cout << "\n\n\n";
    cout << "               ==============================================\n";
    cout << "               ||         VIBE WITH SAHITYA MUSIC APP       ||\n";
    cout << "               ==============================================\n";

    cout << "\n\n";
    cout << "                      Developed by: Deepshikha \n";
    cout << "                      MCA Student, Chandigarh University\n";

    cout << "\n\n";
    cout << "          --------------------------------------------------\n";
    cout << "               Welcome to your personal music companion!\n\n\n";
    cout << "\n";
    cout << "               Here, rhythm meets code, and every beat\n";
    cout << "                         tells your story.\n";
    cout << "\n"; 
    cout << "              Whether you're chilling, coding, or celebrating—\n\n";
    cout << "               Vibe with Deepshikha is here to soundtrack your journey.\n";
    cout << "          -----------------------------------------------------\n";

    cout << "\n\n";
    cout << "               Press ENTER to continue...\n";
    getchar(); // Simple C-style input
}

void showMenu()
{
    int choice;
    do
    {
        // system("cls");
        cout << "\n\n";
        cout << "==================== MAIN MENU ====================\n";
        cout << "1. Play Music from List\n";
        cout << "2. Stop Music\n";
        cout << "3. Enter Custom Music Filename\n";
        cout << "4. Exit\n";
        cout << "===================================================\n";

        cout << "Enter your choice (1-4): ";
        cin >> choice;
        cin.ignore(); // Clear newline

        switch (choice)
        {
       case 1:
{
    // system("cls");
    cout << "\nChoose a song to play:\n";
    for (int i = 0; i < songCount; ++i)
    {
        cout << i + 1 << ". " << songs[i] << "\n";
    }
    cout << "Enter song number: ";
    int songChoice;
    cin >> songChoice;
    cin.ignore();
    if (songChoice >= 1 && songChoice <= songCount)
    {
        playMusic(songs[songChoice - 1]);
    }
    else
    {
        cout << "Invalid choice. Press ENTER to return.\n";
        getchar();
    }
    break;
}

        case 2:
            stopMusic();
            break;
        case 3:
        {
            //   system("cls");
            char filename[100];
            cout << "\nEnter the name of the .wav file (e.g., mytrack.wav): ";
            cin.getline(filename, sizeof(filename));

            playMusic(filename);
            break;
        }
        case 4:
            cout << "\nThank you for vibing with Deepshikha!\n";
            break;

        default:
            cout << "\nInvalid choice. Press ENTER to continue...\n";
            getchar();
        }
    } while (choice != 3);
}

int main()
{
    showHomepage();
    showMenu();
    return 0;
}
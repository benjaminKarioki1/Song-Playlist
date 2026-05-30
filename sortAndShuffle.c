// Include header file with declarations
#include "sortAndShuffle.h"

// Sort songs within each artist and then sort artists alphabetically
void sortFunction(Artist artists[], int artistCount) {
    // Bubble sort songs for each artist
    for (int i = 0; i < artistCount; i++) {
        for (int a = 0; a < artists[i].noOfSongs - 1; a++) {
            for (int b = 0; b < artists[i].noOfSongs - 1 - a; b++) {
                // Compare song titles
                if (strcmp(artists[i].Songs[b], artists[i].Songs[b + 1]) > 0) {
                    // Swap songs if out of order
                    char tmp[MAX_SIZE];
                    strcpy(tmp, artists[i].Songs[b]);
                    strcpy(artists[i].Songs[b], artists[i].Songs[b + 1]);
                    strcpy(artists[i].Songs[b + 1], tmp);
                }
            }
        }
    }

    // Bubble sort artists by name
    for (int i = 0; i < artistCount - 1; i++) {
        for (int j = 0; j < artistCount - 1 - i; j++) {
            // Compare artist names
            if (strcmp(artists[j].ArtistName, artists[j + 1].ArtistName) > 0) {
                // Swap artists if out of order
                Artist tmp = artists[j];
                artists[j] = artists[j + 1];
                artists[j + 1] = tmp;
            }
        }
        printf("%s", artists[i].ArtistName);

    }
}

// Check if playlist is valid (same song not within 5 positions)
static int isValid(Song playlist[], int size) {
    // Loop through each song
    for (int i = 0; i < size; i++) {
        // Find the duplicate of this song
        for (int j = i + 1; j < size; j++) {
            // Check if titles match
            if (strcmp(playlist[i].songTitle,
                       playlist[j].songTitle) == 0) {
                // If too close, invalid
                if (j - i <= 5) {
                    return 0;  // violation
                }
                // Stop searching for this song
                break; // found second copy
            }
        }
    }
    // All checks passed
    return 1; // valid
}

// Shuffle songs into playlist, duplicating and ensuring validity
int shuffleFunction(Song original[],
                         int totalSongs,
                         Song playlist[]) {
    // Check minimum songs
    if (totalSongs < 6) {
        printf("Not enough songs to satisfy constraint.\n");
        return 0;
    }

    // Calculate new size (doubled)
    int newSize = totalSongs * 2;

    // Duplicate songs into playlist
    for (int i = 0; i < totalSongs; i++) {
        playlist[i] = original[i];
        playlist[i + totalSongs] = original[i];
    }

    // Shuffle until valid
    do {
        // Fisher-Yates shuffle
        for (int i = newSize - 1; i > 0; i--) {
            int j = rand() % (i + 1);
            // Swap elements
            Song temp = playlist[i];
            playlist[i] = playlist[j];
            playlist[j] = temp;
        }
    // Repeat if not valid
    } while (!isValid(playlist, newSize));

    // Return new playlist size
    return newSize;
}


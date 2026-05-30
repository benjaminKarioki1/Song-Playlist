// Includes for standard libraries
#include <stdio.h>
#include <string.h>
#include "sortAndShuffle.h"
#include <stdlib.h>
#include <time.h>
// Define max artists and total songs
#define MAX_ARTISTS 4
#define TOTAL_SONGS 12

// Input artists and their songs from user
void inputArtists(Artist artists[], int *artistCount) {
    char buffer[MAX_SIZE];
    int artistIndex = 0;

    // Loop until max artists or empty input
    while (artistIndex < MAX_ARTISTS) {
        printf("Insert an artist/group name: ");
        fgets(buffer, sizeof(buffer), stdin);

        // Check for empty input
        if (strcmp(buffer, "\n") == 0) {
            if (*artistCount == 0) {
                printf("Error: Input at least one artist/group\n");
                continue;
            }
            break;
        }

        // Remove newline and copy name
        buffer[strcspn(buffer, "\n")] = '\0';
        strcpy(artists[artistIndex].ArtistName, buffer);

        int songIndex = 0;
        int songCount = 0;
        // Input songs for this artist
        while (songIndex < MAX_SONGS) {
            printf("Insert song %d for %s: ",
                   songIndex + 1,
                   artists[artistIndex].ArtistName);

            fgets(buffer, sizeof(buffer), stdin);

            // Check for empty input
            if (strcmp(buffer, "\n") == 0) {
                if (songCount == 0) {
                    printf("Error: Input at least one song\n");
                    continue;
                }
                break;
            }

            // Remove newline and copy song
            buffer[strcspn(buffer, "\n")] = '\0';
            strcpy(artists[artistIndex].Songs[songIndex], buffer);

            songIndex++;
            songCount++;
        }

        // Set song count for artist
        artists[artistIndex].noOfSongs = songCount;

        artistIndex++;
        (*artistCount)++;
    }
}

// Convert artists to flat song list
int SongList(Artist artists[], int artistCount, Song songList[]) {
    int k = 0;

    // Loop through artists and songs
    for (int i = 0; i < artistCount; i++) {
        for (int j = 0; j < artists[i].noOfSongs; j++) {
            // Copy song and artist to list
            strcpy(songList[k].songTitle, artists[i].Songs[j]);
            strcpy(songList[k].artistName, artists[i].ArtistName);
            k++;
        }
    }

    // Return total songs
    return k; 
}

// Print artists and their songs (unused)
void printArtistsAndSongs(Artist artists[], int artistCount) {
    // Loop through artists
    for (int i = 0; i < artistCount; i++) {
        printf("%s\n", artists[i].ArtistName);
        // Loop through songs
        for (int j = 0; j < artists[i].noOfSongs; j++) {
            printf("-%s\n", artists[i].Songs[j]);
        }
    }
}

// Main function
int main() {
    
    printf("   ♪♪♪\n");
    printf("  /\\_/\\\n");
    printf(" ( o.o )\n");
    printf("  > ^ <\n");
    printf(" Playlist Generator\n\n");

    // Declare arrays
    Artist artists[MAX_ARTISTS] = {};
    Song songList[TOTAL_SONGS] = {};
    Song playlist[TOTAL_SONGS * 2] = {};
    int artistCount = 0;

    // Seed random number generator
    srand(time(NULL));

    // Input artists
    inputArtists(artists, &artistCount);

    // Sort artists and songs
    sortFunction(artists, artistCount);

    // Create song list
    int totalSongs = SongList(artists, artistCount, songList);

    // Shuffle into playlist
    int playlistSize = shuffleFunction(songList,
                                        totalSongs,
                                        playlist);

    // Print shuffled playlist
    printf("\n--- Shuffled Playlist ---\n");
    for (int i = 0; i < playlistSize; i++) {
        printf("%s - %s\n",
               playlist[i].artistName,
               playlist[i].songTitle);
    }
    printf("Enjoy your music!\n");
    // Print ASCII art
    printf("\n");
    printf("               ________\n");
    printf("          _,.-Y  |  |  Y-._\n");
    printf("      .-~\"   ||  |  |  |   \"-.\n");
    printf("      I\" \"\"==\"|\" !\"\"! \"|\"[]\"\"|     _____\n");
    printf("      L__  [] |..------|:   _[----I\" .-{\"-.\n");
    printf("     I___|  ..| l______|l_ [__L]_[I_/r(=}=-P\n");
    printf("    [L______L_[________]______j~  '-=c_]/=-^\n");
    printf("     \\_I_j.--.\\==I|I==_/.--L_]\n");
    printf("       [_((==)[`-----\"](==)j\n");
    printf("          I--I\"~~\"\"\"~~\"I--I\n");
    printf("          |[]|         |[]|\n");
    printf("          l__j         l__j\n");
    printf("          |!!|         |!!|\n");
    printf("          |..|         |..|\n");
    printf("          ([])         ([])\n");
    printf("          ]--[         ]--[\n");
    printf("          [_L]         [_L] \n");
    printf("         /|..|\\       /|..|\\\n");
    printf("        `=}--{='     `=}--{='\n");
    printf("       .-^--r-^-.   .-^--r-^-.\n");
    printf("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");

    return 0;
}


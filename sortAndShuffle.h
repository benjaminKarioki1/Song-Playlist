#ifndef SORT_AND_SHUFFLE_H
#define SORT_AND_SHUFFLE_H

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <time.h>

// Define maximum size for strings
#define MAX_SIZE 40
// Define maximum number of songs per artist
#define MAX_SONGS 3

// Define structure to represent an artist with name, songs, and count
typedef struct {
    // Array to store artist's name
    char ArtistName[MAX_SIZE];
    // 2D array to store song titles for the artist
    char Songs[MAX_SONGS][MAX_SIZE];
    // Integer to store number of songs by the artist
    int noOfSongs;
} Artist;

// Define structure to represent a song with title and artist
typedef struct {
    // Array to store song title
    char songTitle[MAX_SIZE];
    // Array to store artist name
    char artistName[MAX_SIZE];
} Song;

// Function to sort artists array
void sortFunction(Artist artists[], int artistCount);
// Function to shuffle songs array
int shuffleFunction(Song original[],
                         int totalSongs,
                         Song playlist[]);

#endif

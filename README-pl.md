# 🎵 Song Playlist Generator

A C program that takes song and artist input, sorts them alphabetically, and generates a shuffled playlist that ensures no song repeats within 5 positions.

---

## Features

- Input up to 4 artists with up to 3 songs each
- Alphabetically sorts songs within each artist, then sorts artists by name
- Duplicates the playlist and shuffles it using the **Fisher-Yates algorithm**
- Enforces a constraint: the same song cannot appear within 5 positions of itself
- Reshuffle loop runs until a valid playlist is produced

---

## How It Works

### Input
Songs and artist names are read from `stdin` using `fgets()`, which safely handles spaces and prevents buffer overflows. Trailing newlines are stripped with `strcspn`.

### Sorting
Bubble sort is used to sort songs alphabetically within each artist, and then to sort artists by name. Given the small dataset size (max 4 artists × 3 songs), bubble sort is a simple and sufficient choice.

### Shuffling
The full playlist is first duplicated, then shuffled using the **Fisher-Yates algorithm**. After each shuffle, the playlist is validated — if any song appears within 5 positions of its duplicate, the shuffle runs again.

```c
do {
    // Fisher-Yates shuffle
    for (int i = newSize - 1; i > 0; i--) {
        int j = rand() % (i + 1);
        Song temp = playlist[i];
        playlist[i] = playlist[j];
        playlist[j] = temp;
    }
} while (!isValid(playlist, newSize));
```

---

## Constraints

| Parameter        | Limit |
|------------------|-------|
| Max artists      | 4     |
| Max songs/artist | 3     |
| Min gap (same song) | 5 positions |

---

## Build & Run

```bash
gcc -o playlist playlist.c
./playlist
```

Follow the prompts to enter artist names and their songs. The program will output a shuffled, valid playlist.

---

## Design Decisions

- **`fgets()` over `scanf()`** — handles spaces in names and avoids buffer overflows
- **Bubble sort over quicksort** — simpler implementation, sufficient for small input sizes
- **Rejection sampling for shuffle** — reshuffles until the 5-position constraint is satisfied; works reliably at this scale

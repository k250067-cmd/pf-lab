#include <stdio.h>
#include <string.h>

#define MAX_SONGS 10
#define MAX_LEN 200

char songs[MAX_SONGS][MAX_LEN];
int count = 0;

void loadFromFile() {
    FILE *ptr = fopen("songs.txt", "r");
    count = 0;

    if (!ptr) return;

    while (fgets(songs[count], MAX_LEN, ptr) && count < MAX_SONGS) {
        songs[count][strcspn(songs[count], "\n")] = 0;
        count++;
    }

    fclose(ptr);
}

void saveToFile() {
    FILE *ptr = fopen("songs.txt", "w");

    for (int i = 0; i < count; i++) {
        fputs(songs[i], ptr);
        fputc('\n', ptr);
    }

    fclose(ptr);
}

void addSong() {
    if (count >= MAX_SONGS) {
        printf("Playlist is full!\n");
        return;
    }

    printf("Enter new song title:\n");
    fgets(songs[count], MAX_LEN, stdin);
    songs[count][strcspn(songs[count], "\n")] = 0;

    count++;
    saveToFile();
    printf("Song added.\n");
}

void deleteSong() {
    char title[MAX_LEN];
    printf("Enter song title to delete:\n");
    fgets(title, MAX_LEN, stdin);
    title[strcspn(title, "\n")] = 0;

    int index = -1;
    for (int i = 0; i < count; i++) {
        if (strcmp(songs[i], title) == 0) {
            index = i;
            break;
        }
    }

    if (index == -1) {
        printf("Song not found.\n");
        return;
    }

    for (int i = index; i < count - 1; i++) {
        strcpy(songs[i], songs[i + 1]);
    }

    count--;
    saveToFile();
    printf("Song deleted.\n");
}

void updateSong() {
    char oldTitle[MAX_LEN], newTitle[MAX_LEN];

    printf("Enter song title to update:\n");
    fgets(oldTitle, MAX_LEN, stdin);
    oldTitle[strcspn(oldTitle, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(songs[i], oldTitle) == 0) {
            printf("Enter new title:\n");
            fgets(newTitle, MAX_LEN, stdin);
            newTitle[strcspn(newTitle, "\n")] = 0;

            strcpy(songs[i], newTitle);
            saveToFile();

            printf("Song updated.\n");
            return;
        }
    }

    printf("Song not found.\n");
}

void searchSong() {
    char title[MAX_LEN];

    printf("Enter song to search:\n");
    fgets(title, MAX_LEN, stdin);
    title[strcspn(title, "\n")] = 0;

    for (int i = 0; i < count; i++) {
        if (strcmp(songs[i], title) == 0) {
            printf("Song found at index %d\n", i);
            return;
        }
    }

    printf("Song not found.\n");
}

void showSongs() {
    if (count == 0) {
        printf("Playlist is empty.\n");
        return;
    }

    printf("\n--- Playlist ---\n");
    for (int i = 0; i < count; i++) {
        printf("%d. %s\n", i + 1, songs[i]);
    }
}

int main() {
    int choice;
    loadFromFile();

    while (1) {
        printf("1. Add Song\n");
        printf("2. Delete Song\n");
        printf("3. Update Song\n");
        printf("4. Search Song\n");
        printf("5. Show All Songs\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);
        getchar(); // clear newline

        switch (choice) {
            case 1: addSong(); break;
            case 2: deleteSong(); break;
            case 3: updateSong(); break;
            case 4: searchSong(); break;
            case 5: showSongs(); break;
            case 6: return 0;
            default: printf("Invalid choice.\n");
        }
    }
}














q3
#include <stdio.h>
#include <string.h>

#define MAX 40
#define LEN 50

char r[MAX][LEN];
int count = 0;

void load() {
    FILE *f = fopen("recipes.txt", "r");
    if (!f) return;
    while (count < MAX && fgets(r[count], LEN, f)) {
        r[count][strcspn(r[count], "\n")] = '\0';
        count++;
    }
    fclose(f);
}

void save() {
    FILE *f = fopen("recipes.txt", "w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s\n", r[i]);
    fclose(f);
}

void add() {
    if (count >= MAX) return;
    fgets(r[count], LEN, stdin);
    r[count][strcspn(r[count], "\n")] = '\0';
    count++;
}

void update() {
    char old[LEN], new[LEN];
    fgets(old, LEN, stdin);
    old[strcspn(old, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(r[i], old) == 0) {
            fgets(new, LEN, stdin);
            new[strcspn(new, "\n")] = '\0';
            strcpy(r[i], new);
            return;
        }
    }
}

void del() {
    char name[LEN];
    fgets(name, LEN, stdin);
    name[strcspn(name, "\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (strcmp(r[i], name) == 0) {
            for (int j = i; j < count - 1; j++)
                strcpy(r[j], r[j+1]);
            count--;
            return;
        }
    }
}

void search() {
    char key[LEN];
    fgets(key, LEN, stdin);
    key[strcspn(key, "\n")] = '\0';
    for (int i = 0; i < count; i++)
        if (strstr(r[i], key))
            printf("%s\n", r[i]);
}

void sort() {
    for (int i = 0; i < count - 1; i++)
        for (int j = i + 1; j < count; j++)
            if (strcmp(r[i], r[j]) > 0) {
                char t[LEN];
                strcpy(t, r[i]);
                strcpy(r[i], r[j]);
                strcpy(r[j], t);
            }
}

int main() {
    load();
    char choice[LEN];
    while (1) {
        fgets(choice, LEN, stdin);
        choice[strcspn(choice, "\n")] = '\0';
        if (strcmp(choice, "-1") == 0) break;
        if (!strcmp(choice,"add")) add();
        else if (!strcmp(choice,"update")) update();
        else if (!strcmp(choice,"delete")) del();
        else if (!strcmp(choice,"search")) search();
    }
    sort();
    save();
}








q4
#include <stdio.h>
#include <string.h>

#define MAX 50
#define LEN 80

char a[MAX][LEN];
int count = 0;

void load() {
    FILE *f = fopen("affirm.txt","r");
    if (!f) return;
    while (count < MAX && fgets(a[count], LEN, f)) {
        a[count][strcspn(a[count], "\n")] = '\0';
        count++;
    }
    fclose(f);
}

void save() {
    FILE *f = fopen("affirm.txt","w");
    for (int i = 0; i < count; i++)
        fprintf(f,"%s\n", a[i]);
    fclose(f);
}

int wordCount(char *s) {
    int c = 0;
    for (int i = 0; s[i]; i++)
        if ((i == 0 && s[i] != ' ') || (s[i] != ' ' && s[i-1] == ' '))
            c++;
    return c;
}

void add() {
    char temp[LEN];
    fgets(temp, LEN, stdin);
    temp[strcspn(temp, "\n")] = '\0';
    if (wordCount(temp) <= 7)
        strcpy(a[count++], temp);
}

void update() {
    char old[LEN], new[LEN];
    fgets(old, LEN, stdin);
    old[strcspn(old,"\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (!strcmp(old,a[i])) {
            fgets(new, LEN, stdin);
            new[strcspn(new,"\n")] = '\0';
            if (wordCount(new) <= 7)
                strcpy(a[i], new);
            return;
        }
    }
}

void del() {
    char temp[LEN];
    fgets(temp, LEN, stdin);
    temp[strcspn(temp,"\n")] = '\0';
    for (int i = 0; i < count; i++) {
        if (!strcmp(temp,a[i])) {
            for (int j = i; j < count - 1; j++)
                strcpy(a[j], a[j+1]);
            count--;
            return;
        }
    }
}

void search() {
    char key[LEN];
    fgets(key, LEN, stdin);
    key[strcspn(key,"\n")] = '\0';
    for (int i = 0; i < count; i++)
        if (strstr(a[i], key))
            printf("%s\n", a[i]);
}

int main() {
    load();
    char c[LEN];
    while (1) {
        fgets(c, LEN, stdin);
        c[strcspn(c,"\n")] = '\0';
        if (!strcmp(c,"-1")) break;
        if (!strcmp(c,"add")) add();
        else if (!strcmp(c,"delete")) del();
        else if (!strcmp(c,"update")) update();
        else if (!strcmp(c,"search")) search();
    }
    save();
}

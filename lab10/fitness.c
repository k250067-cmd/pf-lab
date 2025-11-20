// #include <stdio.h>
// #include <string.h>

// #define MAX_LEVELS 10
// #define DESC_LEN 30

// char game[MAX_LEVELS][DESC_LEN];
// int count = 0;

// void load() {
//     FILE *ptr = fopen("songs.txt", "r");
//     count = 0;

//     if (ptr == NULL) return;

//     while (count < MAX_LEVELS && fgets(game[count], DESC_LEN, ptr)) {
//         game[count][strcspn(game[count], "\n")] = '\0';
//         count++;
//     }
//     fclose(ptr);
// }

// void save() {
//     FILE *ptr = fopen("songs.txt", "w");
//     for (int i = 0; i < count; i++) {
//         fprintf(ptr, "%s\n", game[i]);
//     }
//     fclose(ptr);
// }

// void add() {
//     if (count >= MAX_LEVELS) {
//         printf("List is full!\n");
//         return;
//     }

//     printf("Input the description: ");
//     fgets(game[count], DESC_LEN, stdin);
//     game[count][strcspn(game[count], "\n")] = '\0';

//     count++;
//     save();
// }

// void del() {
//     char word[DESC_LEN];
//     printf("Enter the exact description to delete: ");
//     fgets(word, DESC_LEN, stdin);
//     word[strcspn(word, "\n")] = '\0';

//     int found = -1;
//     for (int i = 0; i < count; i++) {
//         if (strcmp(game[i], word) == 0) {
//             found = i;
//             break;
//         }
//     }

//     if (found == -1) {
//         printf("Not found.\n");
//         return;
//     }

//     for (int i = found; i < count - 1; i++) {
//         strcpy(game[i], game[i + 1]);
//     }

//     count--;
//     save();
// }

// void update() {
//     char oldVal[DESC_LEN], newVal[DESC_LEN];

//     printf("Enter old description: ");
//     fgets(oldVal, DESC_LEN, stdin);
//     oldVal[strcspn(oldVal, "\n")] = '\0';

//     int found = -1;
//     for (int i = 0; i < count; i++) {
//         if (strcmp(game[i], oldVal) == 0) {
//             found = i;
//             break;
//         }
//     }

//     if (found == -1) {
//         printf("Not found.\n");
//         return;
//     }

//     printf("Enter new description: ");
//     fgets(newVal, DESC_LEN, stdin);
//     newVal[strcspn(newVal, "\n")] = '\0';

//     strcpy(game[found], newVal);
//     save();
// }

// void search() {
//     char word[DESC_LEN];
//     printf("Enter keyword to search: ");
//     fgets(word, DESC_LEN, stdin);
//     word[strcspn(word, "\n")] = '\0';

//     for (int i = 0; i < count; i++) {
//         if (strstr(game[i], word)) {
//             printf("Found: %s\n", game[i]);
//         }
//     }
// }

// void showAll() {
//     printf("\n--- ALL DESCRIPTIONS ---\n");
//     for (int i = 0; i < count; i++) {
//         printf("%d. %s\n", i + 1, game[i]);
//     }
// }

// int main() {
//     int choice;

//     load();

//     while (1) {
//         printf("\n1. Add\n");
//         printf("2. Delete\n");
//         printf("3. Update\n");
//         printf("4. Search\n");
//         printf("5. Show All\n");
//         printf("6. Exit\n");
//         printf("Enter your choice: ");

//         scanf("%d", &choice);
//         getchar();

//         switch (choice) {
//             case 1: add(); break;
//             case 2: del(); break;
//             case 3: update(); break;
//             case 4: search(); break;
//             case 5: showAll(); break;
//             case 6: return 0;
//             default: printf("Invalid choice.\n");
//         }
//     }
// }










q5
#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 100

char tags[MAX][LEN];
int count = 0;

void load() {
    FILE *f = fopen("tags.txt","r");
    if (!f) return;
    while (fgets(tags[count], LEN, f)) {
        tags[count][strcspn(tags[count], "\n")] = '\0';
        count++;
    }
    fclose(f);
}

void save() {
    FILE *f = fopen("tags.txt","w");
    for (int i = 0; i < count; i++)
        fprintf(f, "%s\n", tags[i]);
    fclose(f);
}

void add(char *s) {
    strcpy(tags[count], s);
    count++;
}

void del(char *s) {
    int i, j;
    for (i = 0; i < count; i++) {
        if (strcmp(tags[i], s) == 0) {
            for (j = i; j < count - 1; j++)
                strcpy(tags[j], tags[j+1]);
            count--;
            return;
        }
    }
}

void update(char *old, char *new) {
    for (int i = 0; i < count; i++) {
        if (strcmp(tags[i], old) == 0) {
            strcpy(tags[i], new);
            return;
        }
    }
}

void search(char *key) {
    for (int i = 0; i < count; i++)
        if (strstr(tags[i], key))
            printf("%s\n", tags[i]);
}

int main() {
    load();
    int choice;
    char a[LEN], b[LEN];

    while (1) {
        printf("1 Add\n2 Delete\n3 Update\n4 Search\n5 Exit\n");
        scanf("%d",&choice);
        getchar();

        switch (choice) {
            case 1:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")]=0;
                add(a);
                break;

            case 2:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")]=0;
                del(a);
                break;

            case 3:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")]=0;
                fgets(b,LEN,stdin);
                b[strcspn(b,"\n")]=0;
                update(a,b);
                break;

            case 4:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")]=0;
                search(a);
                break;

            case 5:
                save();
                return 0;
        }
    }
}






q6
#include <stdio.h>
#include <string.h>

#define MAX 100
#define LEN 120

char notes[MAX][LEN];
int countn = 0;

void load() {
    FILE *f = fopen("episodes.txt","r");
    if (!f) return;
    while (fgets(notes[countn], LEN, f)) {
        notes[countn][strcspn(notes[countn], "\n")] = '\0';
        countn++;
    }
    fclose(f);
}

void save() {
    FILE *f = fopen("episodes.txt","w");
    for (int i = 0; i < countn; i++)
        fprintf(f,"%s\n",notes[i]);
    fclose(f);
}

void add(char *s) {
    strcpy(notes[countn], s);
    countn++;
}

void removeNote(char *s) {
    for (int i = 0; i < countn; i++) {
        if (strcmp(notes[i], s) == 0) {
            for (int j = i; j < countn - 1; j++)
                strcpy(notes[j], notes[j+1]);
            countn--;
            return;
        }
    }
}

void update(char *old, char *new) {
    for (int i = 0; i < countn; i++) {
        if (strcmp(notes[i], old) == 0) {
            strcpy(notes[i], new);
            return;
        }
    }
}

void search(char *key) {
    for (int i = 0; i < countn; i++)
        if (strstr(notes[i], key))
            printf("%s\n", notes[i]);
}

int countWord(char *word) {
    int total = 0;
    for (int i = 0; i < countn; i++) {
        char temp[LEN];
        strcpy(temp, notes[i]);
        char *p = strtok(temp, " ");
        while (p) {
            if (strcmp(p, word) == 0)
                total++;
            p = strtok(NULL, " ");
        }
    }
    return total;
}

int main() {
    load();
    int choice;
    char a[LEN], b[LEN];

    while (1) {
        printf("1 Add\n2 Remove\n3 Update\n4 Search\n5 Count Word\n6 Exit\n");
        scanf("%d",&choice);
        getchar();

        switch (choice) {
            case 1:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")] = 0;
                add(a);
                break;

            case 2:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")] = 0;
                removeNote(a);
                break;

            case 3:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")] = 0;
                fgets(b,LEN,stdin);
                b[strcspn(b,"\n")] = 0;
                update(a, b);
                break;

            case 4:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")] = 0;
                search(a);
                break;

            case 5:
                fgets(a,LEN,stdin);
                a[strcspn(a,"\n")] = 0;
                printf("%d\n", countWord(a));
                break;

            case 6:
                save();
                return 0;
        }
    }
}


#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[]) {
    if (argc < 3) {
        printf("Sai format\n");
        return 1; 
    }

    char *mode = argv[1];
    char *filename = argv[2];

    FILE *fin = fopen(filename, "r");
    if (fin == NULL) {
        printf("NO FILE\n");
        return 1;
    }

    FILE *fout = fopen("output.txt", "w"); 
    int count_out = 0;

    //======ENCODE=======

    if (strcmp(mode, "-e") == 0) {
        char c;
        while ((c = fgetc(fin)) != EOF) {
            char *morse = NULL;
        
            if (c >= 'a' && c <= 'z') c = c - 32;
            if (c == 'A') morse = "*===";
            else if (c == 'B') morse = "===***";
            else if (c == 'C') morse = "===*===*";
            else if (c == 'D') morse = "===**";
            else if (c == 'E') morse = "*";
            else if (c == 'F') morse = "**===*";
            else if (c == 'G') morse = "======*";
            else if (c == 'H') morse = "****";
            else if (c == 'I') morse = "**";
            else if (c == 'J') morse = "*=========";
            else if (c == 'K') morse = "===*===";
            else if (c == 'L') morse = "*===**";
            else if (c == 'M') morse = "======";
            else if (c == 'N') morse = "===*";
            else if (c == 'O') morse = "=========";
            else if (c == 'P') morse = "*======*";
            else if (c == 'Q') morse = "======*===";
            else if (c == 'R') morse = "*===*";
            else if (c == 'S') morse = "***";
            else if (c == 'T') morse = "===";
            else if (c == 'U') morse = "**===";
            else if (c == 'V') morse = "***===";
            else if (c == 'W') morse = "*======";
            else if (c == 'X') morse = "===**===";
            else if (c == 'Y') morse = "===*======";
            else if (c == 'Z') morse = "======**";
            else if (c == '1') morse = "*============";
            else if (c == '2') morse = "**=========";
            else if (c == '3') morse = "***======";
            else if (c == '4') morse = "****===";
            else if (c == '5') morse = "*****";
            else if (c == '6') morse = "===****";
            else if (c == '7') morse = "======***";
            else if (c == '8') morse = "=========**";
            else if (c == '9') morse = "============*";
            else if (c == '0') morse = "===============";
            else if (c == ' ') morse = " ";
            
            if (morse != NULL) {
                fprintf(fout, "%s ", morse); 
                int len = strlen(morse);
                for (int i = 0; i < len; i++) {
                    if (count_out < 20) {
                        printf("%c", morse[i]);
                        count_out++;
                    }
                }
                if (count_out < 20) {
                    printf(" "); 
                    count_out++;
                }
            }
        }
        if (count_out >= 20) printf("...\n");
        else printf("\n");
        printf("ENCODE DONE\n");
    }
    
    //=======DECODE===========
    
    else if (strcmp(mode, "-d") == 0) {
        char buffer[200]; 
        fgets(buffer, 200, fin);
        
        char *token = strtok(buffer, " ");
        while (token != NULL) {
            char decoded = 0;
            if (strcmp(token, "*===") == 0) decoded = 'A';
            else if (strcmp(token, "===***") == 0) decoded = 'B';
            else if (strcmp(token, "===*===*") == 0) decoded = 'C';
            else if (strcmp(token, "===**") == 0) decoded = 'D';
            else if (strcmp(token, "*") == 0) decoded = 'E';
            else if (strcmp(token, "**===*") == 0) decoded = 'F';
            else if (strcmp(token, "======*") == 0) decoded = 'G';
            else if (strcmp(token, "****") == 0) decoded = 'H';
            else if (strcmp(token, "**") == 0) decoded = 'I';
            else if (strcmp(token, "*=========") == 0) decoded = 'J';
            else if (strcmp(token, "===*===") == 0) decoded = 'K';
            else if (strcmp(token, "*===**") == 0) decoded = 'L';
            else if (strcmp(token, "======") == 0) decoded = 'M';
            else if (strcmp(token, "===*") == 0) decoded = 'N';
            else if (strcmp(token, "=========") == 0) decoded = 'O';
            else if (strcmp(token, "*======*") == 0) decoded = 'P';
            else if (strcmp(token, "======*===") == 0) decoded = 'Q';
            else if (strcmp(token, "*===*") == 0) decoded = 'R';
            else if (strcmp(token, "***") == 0) decoded = 'S';
            else if (strcmp(token, "===") == 0) decoded = 'T';
            else if (strcmp(token, "**===") == 0) decoded = 'U';
            else if (strcmp(token, "***===") == 0) decoded = 'V';
            else if (strcmp(token, "*======") == 0) decoded = 'W';
            else if (strcmp(token, "===**===") == 0) decoded = 'X';
            else if (strcmp(token, "===*======") == 0) decoded = 'Y';
            else if (strcmp(token, "======**") == 0) decoded = 'Z';
            else if (strcmp(token, "*============") == 0) decoded = '1';
            else if (strcmp(token, "**=========") == 0) decoded = '2';
            else if (strcmp(token, "***======") == 0) decoded = '3';
            else if (strcmp(token, "****===") == 0) decoded = '4';
            else if (strcmp(token, "*****") == 0) decoded = '5';
            else if (strcmp(token, "===****") == 0) decoded = '6';
            else if (strcmp(token, "======***") == 0) decoded = '7';
            else if (strcmp(token, "=========**") == 0) decoded = '8';
            else if (strcmp(token, "============*") == 0) decoded = '9';
            else if (strcmp(token, "===============") == 0) decoded = '0';
            else if (strcmp(token, "\n") == 0 || strcmp(token, "\r") == 0) {
            
            } else {
                printf("\nInvalid %s\n", token);
                fclose(fin);
                fclose(fout);
                return 1;
            }

            if (decoded != 0) {
                fprintf(fout, "%c", decoded); 
                if (count_out < 20) {
                    printf("%c", decoded);    
                    count_out++;
                }
            }

            token = strtok(NULL, " "); 
        }
        if (count_out >= 20) printf("...\n");
        else printf("\n");
        printf("DECODE DONE\n");
    } else {
        printf("INVALID\n");
    }

    fclose(fin);
    fclose(fout);
    return 0;
}

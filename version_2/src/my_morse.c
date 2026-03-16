#include <stdio.h>
#include <string.h>
#include <ctype.h>

typedef struct {
    char character;
    const char *morse_code;
} MorseMapping;

//============== LOOKUP TABLE
const MorseMapping morse_dict[] = {
    {'A', "*==="}, {'B', "===***"}, {'C', "===*===*"}, {'D', "===**"},
    {'E', "*"}, {'F', "**===*"}, {'G', "======*"}, {'H', "****"},
    {'I', "**"}, {'J', "*========="}, {'K', "===*==="}, {'L', "*===**"},
    {'M', "======"}, {'N', "===*"}, {'O', "========="}, {'P', "*======*"},
    {'Q', "======*==="}, {'R', "*===*"}, {'S', "***"}, {'T', "==="},
    {'U', "**==="}, {'V', "***==="}, {'W', "*======"}, {'X', "===**==="},
    {'Y', "===*======"}, {'Z', "======**"},
    {'1', "*============"}, {'2', "**========="}, {'3', "***======"},
    {'4', "****==="}, {'5', "*****"}, {'6', "===****"}, {'7', "======***"},
    {'8', "=========**"}, {'9', "============*"}, {'0', "==============="},
    {'\0', NULL}
};

const char* char_to_morse(char c) {
    c = toupper(c);
    for (int i = 0; morse_dict[i].character != '\0'; i++) {
        if (morse_dict[i].character == c) return morse_dict[i].morse_code;
    }
    return NULL;
}

char morse_to_char(const char *code) {
    for (int i = 0; morse_dict[i].character != '\0'; i++) {
        if (strcmp(morse_dict[i].morse_code, code) == 0) return morse_dict[i].character;
    }
    return '\0';
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        printf(" %s <-e|-d> <input_file>\n", argv[0]);
        return 1;
    }

    const char *operation_mode = argv[1];
    const char *filename = argv[2];

    FILE *input_file = fopen(filename, "r");
    if (!input_file) {
        printf("Error\n");
        return 1;
    }

    FILE *output_file = fopen("output.txt", "w");
    if (!output_file) {
        printf("Error\n");
        fclose(input_file);
        return 1;
    }

    int printed_chars = 0;

    //================ ENCODE =======================
    if (strcmp(operation_mode, "-e") == 0) {
        int current_char;
        while ((current_char = fgetc(input_file)) != EOF) {
            if (current_char == ' ' || current_char == '\n') {
                fprintf(output_file, " ");
                continue;
            }

            const char *morse = char_to_morse((char)current_char);
            if (morse) {
                fprintf(output_file, "%s ", morse);
                if (printed_chars < 20) {
                    printf("%s ", morse);
                    printed_chars += strlen(morse) + 1;
                }
            }
        }
        printf(printed_chars >= 20 ? "...\n" : "\n");
    }
    //============== DECODE====================
    else if (strcmp(operation_mode, "-d") == 0) {
        char buffer[50];
        while (fscanf(input_file, "%49s", buffer) == 1) {
            char decoded_char = morse_to_char(buffer);
            if (decoded_char != '\0') {
                fprintf(output_file, "%c", decoded_char);
                if (printed_chars < 20) {
                    printf("%c", decoded_char);
                    printed_chars++;
                }
            } else {
                printf("\nInvalid Morse sequence detected: %s\n", buffer);
                break;
            }
        }
        printf(printed_chars >= 20 ? "...\n" : "\n");
    } else {
        printf("INVALID\n");
    }

    fclose(input_file);
    fclose(output_file);
    return 0;
}

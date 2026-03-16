#include <stdio.h>
#include <stdlib.h>

void run_test(const char* test_name, const char* cmd, int expect_success) {
    char full_cmd[512];
    sprintf(full_cmd, "%s > /dev/null 2>&1", cmd); 

    int status = system(full_cmd);
    int is_success = (status == 0);

    if (is_success == expect_success) {
        printf("%-15s: OK\n", test_name);
    } else {
        printf("%-15s: FAIL\n", test_name);
    }
}

int main() {
    printf("--- TEST VERSION 1 ---\n");
    run_test("V1 Encode", "../version_1/my_morse -e data/test_input.txt", 1);
    run_test("V1 Decode", "../version_1/my_morse -d data/test_morse.txt", 1);
    run_test("V1 Invalid", "../version_1/my_morse -d data/invalid.txt", 0);
    
    printf("\n--- TEST VERSION 2 (Optimized) ---\n");
    run_test("V2 Encode", "../version_2/my_morse -e data/test_input.txt", 1);
    run_test("V2 Decode", "../version_2/my_morse -d data/test_morse.txt", 1);
    run_test("V2 Invalid", "../version_2/my_morse -d data/invalid.txt", 0);
    
    return 0;
}

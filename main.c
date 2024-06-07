#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generate_test_case(int number_of_lobsters) {
    printf("%d\n", number_of_lobsters);
    for (int i = 0; i < number_of_lobsters; i++) {
        float size = (float)(rand() % 200 + 1) / 10.0; // Sizes between 0.1 and 20.0
        float value = (float)(rand() % 1000 + 1) / 10.0; // Values between 0.1 and 100.0
        printf("%.1f %.1f\n", size, value);
    }
    float capacity = (float)(rand() % 950 + 50) / 10.0; // Capacity between 5.0 and 100.0
    printf("%.1f\n", capacity);
}

int main() {
    srand(time(NULL));

    int num_cases = 10;
    for (int i = 0; i < num_cases; i++) {
        int number_of_lobsters = rand() % 50 + 1; // Number of lobsters between 1 and 50
        printf("Test Case %d:\n", i + 1);
        generate_test_case(number_of_lobsters);
        printf("\n");
    }

    return 0;
}

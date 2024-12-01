#include "src/fdf.h"

int main(void)
{
    // Test Case 1: Regular sentence with spaces
    char *s1 = ft_strdup("Testando a strtok do eduardo");
    char *s2 = ft_strdup("Testando a strtok do eduardo");
    char *set1 = " ";
    printf("\nTest Case 1:\n");
    printf("ORIGINAL -> %s\n", strtok(s1, set1));
    printf("EDUARDOs -> %s\n", ft_strtok(s2, set1));
    while (1)
    {
        char *orig = strtok(NULL, set1);
        char *edu = ft_strtok(NULL, set1);
        printf("ORIGINAL -> %s\n", orig);
        printf("EDUARDOs -> %s\n", edu);
        if (!orig && !edu) break;
    }

    // Test Case 2: Empty string
    char *s3 = ft_strdup("");
    char *s4 = ft_strdup("");
    char *set2 = " ";
    printf("\nTest Case 2:\n");
    printf("ORIGINAL -> %s\n", strtok(s3, set2));
    printf("EDUARDOs -> %s\n", ft_strtok(s4, set2));

    // Test Case 3: String with only delimiters
    char *s5 = ft_strdup("!!!!, , ,!!!");
    char *s6 = ft_strdup("!!!!, , ,!!!");
    char *set3 = " !,";
    printf("\nTest Case 3:\n");
    printf("ORIGINAL -> %s\n", strtok(s5, set3));
    printf("EDUARDOs -> %s\n", ft_strtok(s6, set3));
    while (1)
    {
        char *orig = strtok(NULL, set3);
        char *edu = ft_strtok(NULL, set3);
        printf("ORIGINAL -> %s\n", orig);
        printf("EDUARDOs -> %s\n", edu);
        if (!orig && !edu) break;
    }

    // Test Case 4: String without delimiters
    char *s7 = ft_strdup("NoDelimitersHere");
    char *s8 = ft_strdup("NoDelimitersHere");
    char *set4 = " ";
    printf("\nTest Case 4:\n");
    printf("ORIGINAL -> %s\n", strtok(s7, set4));
    printf("EDUARDOs -> %s\n", ft_strtok(s8, set4));

    // Test Case 5: Delimiters at the beginning
    char *s9 = ft_strdup("  Leading delimiters and text");
    char *s10 = ft_strdup("  Leading delimiters and text");
    char *set5 = " ";
    printf("\nTest Case 5:\n");
    printf("ORIGINAL -> %s\n", strtok(s9, set5));
    printf("EDUARDOs -> %s\n", ft_strtok(s10, set5));
    while (1)
    {
        char *orig = strtok(NULL, set5);
        char *edu = ft_strtok(NULL, set5);
        printf("ORIGINAL -> %s\n", orig);
        printf("EDUARDOs -> %s\n", edu);
        if (!orig && !edu) break;
    }

    // Test Case 6: Delimiters at the end
    char *s11 = ft_strdup("Text with trailing delimiters   ");
    char *s12 = ft_strdup("Text with trailing delimiters   ");
    char *set6 = " ";
    printf("\nTest Case 6:\n");
    printf("ORIGINAL -> %s\n", strtok(s11, set6));
    printf("EDUARDOs -> %s\n", ft_strtok(s12, set6));
    while (1)
    {
        char *orig = strtok(NULL, set6);
        char *edu = ft_strtok(NULL, set6);
        printf("ORIGINAL -> %s\n", orig);
        printf("EDUARDOs -> %s\n", edu);
        if (!orig && !edu) break;
    }

    // Test Case 7: Multiple delimiters in a row
    char *s13 = ft_strdup("Word1,,,Word2,,Word3");
    char *s14 = ft_strdup("Word1,,,Word2,,Word3");
    char *set7 = ", ";
    printf("\nTest Case 7:\n");
    printf("ORIGINAL -> %s\n", strtok(s13, set7));
    printf("EDUARDOs -> %s\n", ft_strtok(s14, set7));
    while (1)
    {
        char *orig = strtok(NULL, set7);
        char *edu = ft_strtok(NULL, set7);
        printf("ORIGINAL -> %s\n", orig);
        printf("EDUARDOs -> %s\n", edu);
        if (!orig && !edu) break;
    }

    // Clean up
    free(s1);
    free(s2);
    free(s3);
    free(s4);
    free(s5);
    free(s6);
    free(s7);
    free(s8);
    free(s9);
    free(s10);
    free(s11);
    free(s12);
    free(s13);
    free(s14);

    return 0;
}

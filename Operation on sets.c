#include <stdio.h>

#define MAX 100

void display(int set[], int n) {
	int i;
    printf("{ ");
    for ( i = 0; i < n; i++) {
        printf("%d ", set[i]);
    }
    printf("}\n");
}

int isElementPresent(int set[], int n, int element) {
	int i;
    for (i = 0; i < n; i++) {
        if (set[i] == element) {
            return 1; 
        }
    }
    return 0;
}

void unionSets(int set1[], int set2[], int *n1, int *n2, int result[], int *nResult) {
	int i;
    *nResult = *n1;
    for ( i = 0; i < *n1; i++) {
        result[i] = set1[i];
    }

    for (i = 0; i < *n2; i++) {
        if (!isElementPresent(set1, *n1, set2[i])) {
            result[*nResult] = set2[i];
            (*nResult)++;
        }
    }
}

void intersectionSets(int set1[], int set2[], int n1, int n2, int result[], int *nResult) {
	int i;
    *nResult = 0;
    for (i = 0; i < n1; i++) {
        if (isElementPresent(set2, n2, set1[i])) {
            result[*nResult] = set1[i];
            (*nResult)++;
        }
    }
}

void differenceSets(int set1[], int set2[], int n1, int n2, int result[], int *nResult) {
	int i;
    *nResult = 0;
    for ( i = 0; i < n1; i++) {
        if (!isElementPresent(set2, n2, set1[i])) {
            result[*nResult] = set1[i];
            (*nResult)++;
        }
    }
}

int main() {
    int set1[MAX], set2[MAX], result[MAX];
    int i, n1, n2, nResult, choice, element;

    printf("Enter number of elements in set 1: ");
    scanf("%d", &n1);
    printf("Enter elements of set 1: ");
    for (i = 0; i < n1; i++) {
        scanf("%d", &set1[i]);
    }

    printf("Enter number of elements in set 2: ");
    scanf("%d", &n2);
    printf("Enter elements of set 2: ");
    for (i = 0; i < n2; i++) {
        scanf("%d", &set2[i]);
    }

    do {
        printf("\nMenu:\n");
        printf("1. Union of sets\n");
        printf("2. Intersection of sets\n");
        printf("3. Difference of sets (Set 1 - Set 2)\n");
        printf("4. Check if element is in set 1\n");
        printf("5. Check if element is in set 2\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                unionSets(set1, set2, &n1, &n2, result, &nResult);
                printf("Union of sets: ");
                display(result, nResult);
                break;
            case 2:
                intersectionSets(set1, set2, n1, n2, result, &nResult);
                printf("Intersection of sets: ");
                display(result, nResult);
                break;
            case 3:
                differenceSets(set1, set2, n1, n2, result, &nResult);
                printf("Difference (Set 1 - Set 2): ");
                display(result, nResult);
                break;
            case 4:
                printf("Enter element to check in set 1: ");
                scanf("%d", &element);
                if (isElementPresent(set1, n1, element)) {
                    printf("Element %d is present in set 1\n", element);
                } else {
                    printf("Element %d is not present in set 1\n", element);
                }
                break;
            case 5:
                printf("Enter element to check in set 2: ");
                scanf("%d", &element);
                if (isElementPresent(set2, n2, element)) {
                    printf("Element %d is present in set 2\n", element);
                } else {
                    printf("Element %d is not present in set 2\n", element);
                }
                break;
            case 6:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice, please try again.\n");
        }
    } while (choice != 6);

    return 0;
}


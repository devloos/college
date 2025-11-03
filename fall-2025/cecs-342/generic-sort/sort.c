#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define Person structure
typedef struct {
  char name[50];
  int age;
} Person;

// Comparison function for floating-point numbers (ascending order)
int compare_floats(const void *a, const void *b) {
  double fa = *(const double *)a;
  double fb = *(const double *)b;

  return fa - fb;
}

// Comparison function for people by name (alphabetical order)
int compare_people_by_name(const void *a, const void *b) {
  const Person *pa = (const Person *)a;
  const Person *pb = (const Person *)b;

  return strcmp(pa->name, pb->name);
}

// Comparison function for people by age (descending), then by name for fallback
int compare_people_by_age(const void *a, const void *b) {
  const Person *pa = (const Person *)a;
  const Person *pb = (const Person *)b;

  // First compare by age (descending - reverse the comparison)
  if (pa->age > pb->age) {
    return -1;
  }

  if (pa->age < pb->age) {
    return 1;
  }

  return 0;

  // If ages are equal, compare by name (ascending/alphabetical)
  return strcmp(pa->name, pb->name);
}

// Utility function to print floating-point array
void print_floats(const char *title, double arr[], int n) {
  printf("%s\n", title);

  for (int i = 0; i < n; i++) {
    printf("%.2f", arr[i]);

    if (i < n - 1) {
      printf(", ");
    }
  }

  printf("\n\n");
}

// Utility function to print people array
void print_people(const char *title, Person arr[], int n) {
  printf("%s\n", title);

  for (int i = 0; i < n; i++) {
    printf("%s, %d\n", arr[i].name, arr[i].age);
  }

  printf("\n");
}

int main() {
  printf("CECS 342 Assignment 5\n");
  printf("Name: Carlos Aguilera\n");
  printf("Algorithm: generic programming, Language: C\n\n");

  // Define the floating-point numbers array
  double numbers[] = {645.41, 37.59, 76.41,  5.31,    -34.23, 1.11,
                      1.10,   23.46, 635.47, -876.32, 467.83, 62.25};
  int NUM_COUNT = 12;

  // Sort numbers in ascending order
  qsort(numbers, NUM_COUNT, sizeof(double), compare_floats);
  print_floats("Numbers sorted in ascending order:", numbers, NUM_COUNT);

  const int PEOPLE_COUNT = 17;
  Person people1[] = {{"Hal", 20},       {"Susann", 31},   {"Dwight", 19},
                      {"Kassandra", 21}, {"Lawrence", 25}, {"Cindy", 22},
                      {"Cory", 27},      {"Mac", 19},      {"Romana", 27},
                      {"Doretha", 32},   {"Danna", 20},    {"Zara", 23},
                      {"Rosalyn", 26},   {"Risa", 24},     {"Benny", 28},
                      {"Juan", 33},      {"Natalie", 25}};

  Person people2[PEOPLE_COUNT];
  memcpy(people2, people1, sizeof(people1));

  // Sort people alphabetically by name
  qsort(people1, PEOPLE_COUNT, sizeof(Person), compare_people_by_name);
  print_people("People sorted alphabetically by name:", people1, PEOPLE_COUNT);

  // Sort people by age (descending), then by name (alphabetical)
  qsort(people2, PEOPLE_COUNT, sizeof(Person), compare_people_by_age);
  print_people("People sorted by age (descending), then by name:", people2,
               PEOPLE_COUNT);

  return 0;
}

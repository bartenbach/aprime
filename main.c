/*  Name: aprime
    Author: Blake Bartenbach
    Description: primality test program */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdint.h>
#include<stdbool.h>
#include<ctype.h>

void print_header();
void print_version();
void cmd_handler(char *cmd);
void primality_handler();
void assess_primality(int n);

const char *version = "0.0.3-indev";
int i;


int main() {
  print_header();
  while (1) {
    printf("(aprime) ");
    char cmd[20];
    fgets(cmd, sizeof(cmd), stdin);
    bool integer = true;

    for (i=0; i < strlen(cmd)-1; i++) {
      if (!isdigit(cmd[i])) {
          integer = false;
          break;
      }
    }
    if (integer == true) {
      int input;
      sscanf(cmd, "%d", &input);
      assess_primality(input);    
    } else {  
      cmd_handler(cmd);
    }
  }
}

void print_header() {
  printf("aprime - primality test program version %s\n\n", version);
}

void cmd_handler(char *cmd) {
  if (strncmp(cmd, "exit", 4) == 0) {
    exit(0);
  }
}

void primality_handler() {
  int retVal = 1;
  int num;
  while (retVal == 1) {
    retVal = get_number(); 
  }
  exit(1);
}

int get_number() {
  printf("(aprime) ");
  int ret, num;
  ret = scanf("%u", &num);
  assess_primality(num);
  return ret;
}

void assess_primality(int n) {
  if ( n < 2 ) {
    printf("   [[ %d is not prime (less than 2) ]]\n", n);
    return;
  }

  double m = n * 0.5;
  int i;

  for (i = 2; i <= m; i++) {
    if ( n != i && n % i == 0) {
      printf("    [[ %d is not prime (divisible by %d]]\n", n, i);
      return;
    } 
  }

  printf("    [[ %d is prime ]]\n", n);
}

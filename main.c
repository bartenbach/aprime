/*  Name: aprime
    Description: primality test program
    Author: Blake Bartenbach             */

#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void print_header();
void print_help();
void print_version();
void cmd_handler(char *cmd);
void primality_handler();
void assess_primality(int n);
char get_cmd();

const char *version = "0.0.1-indev";

int main() {
  print_header();
  while (1) {
    printf("(aprime) ");
    char cmd[5];
    scanf("%s", &cmd);
    cmd_handler(cmd);
  }
}

void print_header() {
  printf("aprime - primality test program version %s\n\n", version);
  printf("type \"help\" for commands\n");
}

void cmd_handler(char *cmd) {
  if (strncmp(cmd, "exit", 4) == 0) {
    exit(0);
  } else if (strncmp(cmd, "test",4) == 0) {
    primality_handler();
  } else if (strncmp(cmd, "help", 4) == 0) {
    print_help();
  }
}

void primality_handler() {
  int retVal = 1;
  int num;
  while (retVal == 1) {
    retVal = get_number(); 
  }
  exit(1); // TODO return to menu somehow
}

int get_number() {
  printf("> ");
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

char get_cmd() {
  char cmd[5];
  scanf("%s", &cmd);
  return *cmd;
}

void print_help() {
  printf("    exit - exits the program\n");
  printf("    test - test an integer for primality\n");
  printf("    help - show this menu\n");
}

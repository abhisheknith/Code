#include<stdio.h>

int main() {
      //27 is ESC ASCII char
      printf("%c[2J",27);   //clears screen
      printf("%c[100;50H",27); //sets cursor at [0,0]
      printf("Abhishek");
      printf("%c[10;50H",27); //sets cursor at [0,0]
    }

//Ayoub Rammo
//Standard Input and Output (C) 
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int first(char* input){ 
    int capital = 0; // keeps count
    int i = 0; 
    while (input[i] != '\0') { // loops till we hit end char
      if (input[i] >= 'A' && input[i] <= 'Z') // checks if it is uppercases
          capital++; // adds to count
      i++;
    }

    return capital; // returns count
    
}

int second(char* a, char * b){
    int i = 0;
    int diff = 0; // keeps track of count
    while (a[i] != '\0'){  // counts chars in a
      diff++; // increases count
      i++;
    }
    i = 0;
    while (b[i] != '\0'){ // counts chars in b
      diff--; // decreases count
      i++;
    }
    if(diff == 1 || diff == -1){ // if diff left is either 1 or -1 returns 1
      return 1;
    }
    return 0;
    
}

char* third(int number){
    char *c = malloc (sizeof (char) * 80); // creates new char
    strcpy (c,""); // marks it empty
    int values[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; // all values where roman numbers change
    int remainder[] = {0,0,0,0,0,0,0,0,0,0,0,0}; // keep track of occurrences
    for(int i = 12;i > -1 && number > 0;i--){ // loops to count number of occurrences of each change value
        remainder[i] = number/values[i]; // updates  remainder array 
        number = number % values[i--]; 
    }
    for(int i = 12;i > -1;i--){
        for(int j=0;j<remainder[i];j++){ // prints each change value to the number of count in   remainder array 
            char sym[][2] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"};
            strcat(c, sym[i]);
        }
    }
    return c;
}

int fourth(char a ,char b)     
{
    int n = a^b; // and between 2 chars  
    int count = 0;
    while (n) { // counts set bits in and result
        count += n & 1;
        n >>= 1;
    }            
    if(count > 1){ // if its greater than 1 returns 0 else 1
      return 0;
    }   
    return 1;
}


int main()              
{

    char * input = "ABghC";
    int number = 1380;
    printf("Capital Letters in %s: %d\n", input ,first(input));
    printf("Two Strings Differ by single char (1 - yes, 0 - no ): %d\n", second("acd","avbc"));   
    printf("Roman Representation of %d: %s \n", number, third(number));    
    printf("Given two characters differ by one single bit (1 - yes, 0 - no ): %d\n", fourth(0b1111,0b1101));    
    
    return (0);
}
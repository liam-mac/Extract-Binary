/*
Liam MacShane
Output_binary2.cpp
Program that extracts 0's and 1's from a text file and output only 0's 
and 1's to a new text file called BINARY.txt
----------
Inputs: my_input_program.txt
Outputs: BINARY.txt
*/

#include <stdio.h>
#include <stdlib.h>

#define RAM_SIZE 2304
/*  Allows up to 512 32-bit instructions w/ 4-bit parity
    512*36=18432 <--exact # of bits in RAM block
    18432/8=2304    */ 


int main(){

FILE *Orig_file;
FILE *binary_file;

char input_char; //The current character
char char_array[RAM_SIZE]; 


//Open File
//TODO: generalize this operation
Orig_file=fopen("my_input_program.txt" ,"r");

if(Orig_file==NULL)
    {
	fprintf(stderr, "Cannot open input file\n");
	exit(-1);
    }

//Read and parse file
else 
    {
    int i=0;
    while(input_char != EOF)
        { //while
        input_char = getc(Orig_file); //Gets the next byte from the infile
        if(input_char == '0' || input_char == '1') //if 0 or 1 is found
            {
            char_array[i] = input_char;
            i++; //Only increment when a 1 or 0 is found
            } //if 0 or 1
        } //while !EOF
    char_array[i]='\0'; //Set EOF
    } //else

//Save to new text file
binary_file=fopen("BINARY.txt" ,"w");
fputs(char_array, binary_file);

//Close files
fclose(binary_file);
fclose(Orig_file);

printf("\nExtraction Complete!!!\n");
return 0;
};//end main

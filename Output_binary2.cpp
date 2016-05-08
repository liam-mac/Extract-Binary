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


int main(){

FILE *Orig_file;
FILE *binary_file;

int i;
char input_char;//Represents the current character
char char_array[2304]; // 512X36 w/ parity..512*36=18432 (<--exact # of bits in RAM block), 18432/8=2304
// allows up to 512 32-bit instructions w/ 4-bit parity
char *string_ptr;
char string[] ="This is a string.";

//Open File
//TODO: generalize this operation
Orig_file=fopen("my_input_program.txt" ,"r"); //Save the input code as my_program

//TODO: change error messages to be a formal error message on the console 
if(Orig_file==NULL)
    {
        printf("Input file is empty");
    }
    
else if(!Orig_file)
    {
    printf("Input file not found"); //What does it mean if the pointer is 0 and not null?
    }
else    //Read and parse file
    {
    i=0;    //declare and define here   //The way I use I is a little wonky...
    input_char=5;//Random # zero would mess this up //What why do I have this? Just delete?
    while(input_char != EOF)
        {//while
            input_char = getc(Orig_file);//Gets the next byte from the input file
            printf("%d", input_char);
            if(input_char == 0x30 || input_char == 0x31) //if an ASCII 0 or 1 //Change to use single quotes
            {
                (char_array[i]) = input_char;//
                i++; 			//Only increment when a 1 or 0 is found
            }//if 0 or 1
        }//End while
    char_array[i]='\0'; //Set EOF

    binary_file=fopen("BINARY.txt" ,"w");   //Change this, doesn't beling in a place where you save the data.
    fputs(&(char_array[0]), binary_file);   //just fputs (char_array, binary file)?
    fclose(binary_file);

    }//end else


//Close file
fclose(Orig_file);//should probably close first

printf("\n\nExtraction Complete!!!"); //system pause? Or make a tiny window?
return 0;
};//end main

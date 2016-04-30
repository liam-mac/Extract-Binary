
//Declarations and stuff - make sure you keep file names straight - this will cause problems later
#include <stdio.h>
#include <stdlib.h>



int main(){

FILE *Orig_file;
FILE *binary_file;

int i; //Counter
char input_char;//Represents the current character
char char_array[2304]; // 512X36 w/ parity..512*36=18432 (<--exact # of bits in RAM block), 18432/8=2304
// allows 512 32 bit instructions w/ parity

char *string_ptr;
char string[] ="This is a string.";

//Open File
Orig_file=fopen("my_input_program.txt" ,"r"); //Save the input code as my_program


if(Orig_file==NULL)
    {
        printf("It looks like the input file is empty... 0.o");
    }
    
else if(!Orig_file)
              {
               printf("PANIC! not at the disco...");
               }
    else{
        i=0;
        printf("\n\nDid we make it this far??");

       input_char=5;//Random# zero would mess this up
       while(input_char != EOF) //lateer change to dowhile
            {//Begin while
                     printf("\nHow about here????");
                     input_char = getc(Orig_file);//Gets the next byte from the input file
                     printf("%d", input_char);
                if(input_char == 0x30 || input_char == 0x31) //if an ASCII 0 or 1 is found
                    {
                        (char_array[i]) = input_char;//
                        printf("%d", char_array[i]); //THIS LOOKS LIKE IT's WORKING CORRECTLY
                        i++; 			//Only increment when a 1 or 0 is found
                    }//brackets for if statements??
                    
            }//End while
        char_array[i]='\0';    
        printf("Did we accidently end up here?");
        //fprintf(binary_file, "%s", char_array); // Do I need to say char_array[i] or something
     
     //   string_ptr=(&string[1]);//Points to start of string 
     //    fputs(string_ptr, binary_file);
     
     binary_file=fopen("BINARY.txt" ,"w"); //Save the input code as my_program

    //   fputs(string, binary_file);
       printf("%X", &char_array[0]);
        fputs(&(char_array[0]), binary_file);
        fclose(binary_file);
        printf("\nALMOST THERE");
        }//end else


//Close file
fclose(Orig_file);

printf("\n\nMovin' on up!!!");
return 0;
};//end main

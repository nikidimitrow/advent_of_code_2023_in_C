//:for: uint32_t
#include <stdint.h> 

//:for: fopen, fgets, feof, fflush
#include <stdio.h>  

//:for strcmp
#include <string.h> 

int main(){
    printf("[BEG:main]\n");
    fflush(stdout);

    size_t num_non_empty_lines_found = 0;
    FILE* file_pointer = NULL;
    const char* file_name = "input";
    file_pointer = fopen( file_name, "r" );

    //: Init to null character because fgets
    //: will not change string if file is empty.
    //: Leading to reporting that an empty file
    //: contains exactly 1 non-blank line.
    //:
    //: Macro contains todays date, as a paranoid
    //: measure to ensure no collisions with
    //: other people's code.
    #define JOHN_MARKS_MAX_LINE_2019_03_03 256
    char single_line[ 
        JOHN_MARKS_MAX_LINE_2019_03_03 
    ] = "\0";
    int max_line = JOHN_MARKS_MAX_LINE_2019_03_03;
    #undef  JOHN_MARKS_MAX_LINE_2019_03_03

    //: This could happen if you accidentially
    //: spelled the filename wrong:
    if(NULL==file_pointer){
        printf("[ERROR:CheckFileNameSpelling]\n");
        return( 1 );
    };;

    //# DONT DO THIS! If you spelled the file  #//
    //# name wrong, this condition will lead   #//
    //# to an infinite loop.                   #//
    //- while( !feof(file_pointer )){ ... }    -//  
    while(fgets( 
    /**/single_line 
    ,   max_line
    ,   file_pointer 
    )){

        //: Check for empty lines:
        if( strcmp(single_line,"\n"  ) != 0 &&
            strcmp(single_line,"\r\n") != 0 &&
            strcmp(single_line,"\0"  ) != 0 &&
        1){
            printf("[LINE_HAS_CONTENT]\n");
            num_non_empty_lines_found++;
        }else{
            printf("[LINE_IS_EMPTY]\n");
            continue;
        };;

        //: Do stuff with non empty line:
        printf( "[Content]:%s\n", single_line );
    };;

    if(num_non_empty_lines_found<1){
        printf("[WARNING:FileWasEmpty]\n");
        printf("[EmptyFileName]:%s\n", file_name);
        fflush(stdout);
    };;

    printf("[END:main]\n");fflush(stdout);
    return( 0 );

};;
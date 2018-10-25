#pragma warning(disable:4996)

#include "u2d.h"

int main(char arg, char *args[]) {
    if (arg <= 1)
	    help(1);

	if ((*param != 'u') && (*param != 'd'))
	    help(1);
	
	if (arg != 4 ) {
	    printf("param error\n");
	    help(1);
	}
	    
	if ( *file_in == *file_out){
	    printf("input file should not be the same of output\n");
	    help(0);
	}
        
	if (exist(file_in) ){
    	printf("File in not exist\n");
	    help(0);
	}

	if ( !exist(file_out) ){ 
	    printf("File out exist!\n");
	    help(0);
	}
	
	convert(*param, file_in, file_out);
}

void help (int i) {
    if (i)
    printf("Usage: u2d { [u]nix [d]os } input file output file");
    exit(0);
}

int exist( char *file) {
    
	FILE *fp;
    
	if ( (fp = fopen(file, "r")) == NULL){
		fflush(fp);
		return 1;
	}
	else {
		fflush(fp);
		return 0;
	}
}

void convert(int par, char *in, char *out) {
    FILE *filein, *fileout;
	char c;

	filein = fopen(in, "r");
    fileout = fopen(out, "w");

	if (par == 'd') {	/*convert in dos */
		while ((c = getc(filein)) != EOF) {
			if (c != 0x0A){
				putc(c,fileout);
			} 
			else {
				putc(0x0D, fileout);
				putc(0x0A, fileout);
			}
		}
	} 
	if (par == 'u'){
		while ((c = getc(filein)) != EOF) {
			if (c == 0x0D)
				continue;
			putc(c, fileout);
		}
	}

	fclose(filein);
	fclose(fileout);
}

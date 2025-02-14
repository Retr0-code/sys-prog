#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[]) 
{
    FILE* fp;
    void filecopy(FILE *, FILE *);
    char *prog = argv[0];

    // By default stdin writes to stdout
    if (argc == 1) {
        filecopy(stdin, stdout);
    }
    else {
        // Iterate through all arguments
        while (--argc > 0) {
            // Opens file of next argument
            if ((fp = fopen(*++argv, "r")) == NULL) {
                // On fail
                fprintf(stderr, "%s: can't open %s\n", prog, *argv);
                exit(1);
            }
            // Prints file to stdout
            filecopy(fp, stdout);
            fclose(fp);
        }
        
    }

    if (ferror(stdout)) {
        fprintf(stderr, "%s: error writing stdout\n", prog);
        exit(2);
    }

    exit(0);
}

void filecopy(FILE *ifp, FILE *ofp)
{
    int c;

    while ((c = getc(ifp)) != EOF) {
        putc(c, ofp);
    }
}
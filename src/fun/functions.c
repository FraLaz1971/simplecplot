#include <stdio.h>
#include <stdlib.h>
#include "functions.h"

void parserow(char *mybuffer, int mncols){
            cc=0; fcharcount=0;colcount=0; int lx; double ly;
    		while( mybuffer[cc] != RS ){ /* while on line characters */
			if ( (mybuffer[cc] != FS) ){
				/* field[fcharcount][rowcount]=mybuffer[cc]; */
					temp[fcharcount] = mybuffer[cc];
					fcharcount++;
				if ( (mybuffer[cc] != '\t') && (mybuffer[cc] != ' ' ) ){
				}
				/* printf("cc = %d fcc = %d temp = %s\n", cc, fcharcount, temp);  */
			} else {
/*				fprintf(stderr, "%s \n", temp); */
                lx=rowcount*mncols+colcount; ly= atof(temp);
                xdata[lx]=lx;                     
                ydata[lx]=ly;                     
                colcount++;
				fcharcount=0;
				memcpy(temp, "", FSIZE);
			}
			cc++;
		}
        lx=rowcount*mncols+colcount; ly= atof(temp);
        xdata[lx]=lx;                     
        ydata[lx]=ly;
		fprintf(stderr, "%f\t%f\n",xdata[lx], ydata[lx]); 
		printf("%f\t%f\n",xdata[lx], ydata[lx]); 
		colcount++;

}

void showdata(double *mydata, int mnrows, int mncols){
    fprintf(stderr, "showdata() START\n");
    int myrowcount=0; int mycolcount=0;
    for(myrowcount=0;myrowcount<mnrows;myrowcount++){
        for(mycolcount=0;mycolcount<mncols;mycolcount++){
                printf("%f ", mydata[myrowcount*mncols+mycolcount]);
        }
        printf("\n");
    }
    fprintf(stderr, "showdata() STOP\n");
}


void open_metadata_file(const char *metafilen){
   /* Open the file */
    mptr = fopen(metafilen,"r");
    /* checking if file exists */
    if (ptr==NULL) 
        { 
            fprintf(stderr, "no such metadata file: %s.\n", metafilen); 
            exit(EXIT_FAILURE); 
        }         
}

void parse_metadata_file(FILE *fp){
    
}

void close_metadata_file(FILE *mfp){
    fclose(mfp);			/* Close the metadata file.	*/    
}

void open_data_file(const char *filen){
    /* Open the file */
    ptr = fopen(filen,"r");
    /* checking if file exists */
    if (ptr==NULL) 
        { 
            fprintf(stderr, "no such file: %s.\n", filen); 
            exit(EXIT_FAILURE); 
        }     
}

void parse_data_file(char * mybuffer, int mnrows, int mncols){
	rowcount=0; totlines=0; totchars=0;
	while (((characters=getline(&mybuffer,&bufsize,ptr)) != EOF) && (rowcount < mnrows) ) /* until you reach the end of the file or the asked n. of rows*/
    {
        parserow(mybuffer, rowcount);/* O/P the field values to the screen	*/
        rowcount++;
    }
    
}

void close_data_file(FILE *fp){
    fclose(fp);			/* Close the file.	*/
}

void allocate_buffer(char *mybuffer){
	mybuffer = (char *)malloc(bufsize * sizeof(char));
    if( mybuffer == NULL)
    {
        		perror("parsefile.c: Unable to allocate mybuffer");
        		exit(1);
    }
}

void allocate_data(double *mydata){
   	/* allocate an array of float to contain the read data */
	mydata = (double *)calloc(nrows*ncols, sizeof(double));
    if( mydata == NULL)
    {
        		perror("parsefile.c: Unable to allocate array double 'mydata' ");
        		exit(1);
    }
    
}

void deallocate_buffer(char *mybuffer){
    free(mybuffer);
}

void deallocate_data(double *mydata){
    free(mydata);    
}

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "functions.h"
#include "data.h"


void set_default_metadata(struct MetaDataMx2 *metadMx2)
{
    metadMx2->ncolumns = 2;
    metadMx2->nrows = 32768;
    metadMx2->dsname = "AwesomeData";
    metadMx2->cname[0] = "x-val";
    metadMx2->cname[1] = "y-val";
    metadMx2->ctype[0] = "real";
    metadMx2->ctype[1] = "real";
    metadMx2->cunit[0] = "s";
    metadMx2->cunit[1] = "#";
}

void set_default_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2)
{
    fprintf(stderr, "*** set_default_data() START ***\n");
     for ( a=0; a < (metadMx2->nrows); a++ )
     {
        t=a-(metadMx2->nrows/2);
        dMx2->x[a]=t/(metadMx2->nrows/2);
        dMx2->y[a]=exp(dMx2->x[a]);
     }
    fprintf(stderr, "*** set_default_data() STOP ***\n");
}

/* copy data from origin ordMx2 to destination dedMx2*/
void copy_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dedMx2, struct DataMx2 *ordMx2)
{
    fprintf(stderr, "*** copy_data() START ***\n");
     for ( a=0; a < (metadMx2->nrows); a++ )
     {
        t=a-(metadMx2->nrows/2);
        dedMx2->x[a]=ordMx2->x[a]; dedMx2->y[a]=sin(t);
     }
    fprintf(stderr, "*** copy_data() STOP ***\n");
}


void display_metadata(struct MetaDataMx2 *metadMx2)
{
    fprintf(stderr, "*** display_metadata() START ***\n");
    fprintf(stderr, "ncolumns = %i\n", metadMx2->ncolumns); /* print n. of columns of the matrix */
    fprintf(stderr, "nrows = %i\n", metadMx2->nrows); /* n. of rows of the matrix */
    fprintf(stderr, "name of the dataset = %s\n", metadMx2->dsname); /* name of the dataset */
    /* printing labels of columns in the matrix */
    fprintf(stderr, "cname[%i] = %s\tcname[%i] = %s\n", 0, metadMx2->cname[0], 1, metadMx2->cname[1]);
    /* printing data type of columns in the matrix */
    fprintf(stderr, "ctype[%i] = %s\tctype[%i] = %s\n", 0, metadMx2->ctype[0], 1, metadMx2->ctype[1]);
    /* printing physical units of columns in the matrix */
    fprintf(stderr, "cunit[%i] = %s\tcunit[%i] = %s\n", 0, metadMx2->cunit[0], 1, metadMx2->cunit[1]);
    fprintf(stderr, "*** display_metadata() STOP ***\n");
}


void display_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2)
{
    fprintf(stderr, "*** display_data() START ***\n");
     for ( a=0; a < metadMx2->nrows; a++ )
     {
        #ifdef DEBUG
        fprintf(stderr, "%.6f\t%.6f #row %i\n", dMx2->x[a], dMx2->y[a], a);
        #endif
        fprintf(stdout, "%.6f\t%.6f\n", dMx2->x[a], dMx2->y[a]);
     }
    fprintf(stderr, "*** display_data() STOP ***\n");
}

void test_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2){
    set_default_metadata(metadMx2);
    display_metadata(metadMx2);
    set_default_data(metadMx2, dMx2);
    v=metadMx2->nrows;
    for(a=0; a<v; a++)
        vx=a-(v/2);
        dMx2->x[a]=vx;dMx2->x[a]=vx*vx*vx;
    display_data(metadMx2, dMx2);
}

void simple_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2){
    set_default_metadata(metadMx2);
    set_default_data(metadMx2, dMx2);
    v=metadMx2->nrows;
    for(a=0; a<v; a++)
        vx=a-(v/2);
        dMx2->x[a]=vx;dMx2->x[a]=vx*vx*vx;
    display_data(metadMx2, dMx2);
}

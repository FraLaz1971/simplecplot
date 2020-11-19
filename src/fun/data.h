#ifndef DATA_H
#define DATA_H

#include "functions.h"

struct MetaDataMx2{
    int ncolumns; /* n. of columns of the matrix */
    int nrows; /* n. of columns of the matrix */
    char *dsname;   /* name of the dataset */
    char *cname[2]; /* name of the string*/
    char *ctype[2]; /* data type of the items of this column */
    char *cunit[2]; /* physical unit of the measurement */
};


struct DataMx2{
    double x[RMAX];
    double y[RMAX];
};

void set_default_metadata(struct MetaDataMx2 *metadMx2);

void set_default_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2);

void copy_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dedMx2, struct DataMx2 *ordMx2);

void display_metadata(struct MetaDataMx2 *metadMx2);

void display_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2);

void simple_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2);

void test_data(struct MetaDataMx2 *metadMx2, struct DataMx2 *dMx2);

#endif // DATA_H

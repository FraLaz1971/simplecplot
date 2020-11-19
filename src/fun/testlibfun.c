#include <stdio.h>
#include <stdlib.h>
#include "functions.h"
#include "plot.h"

int main(int argc, char **argv)
{
   int tnrows, tncols; buffer =  (char *) malloc(256*sizeof(char));
   struct MetaDataMx2 m2d;    struct DataMx2 d2d;
   if (argc == 4){
    tnrows=atoi(argv[2]); tncols=(atoi(argv[3]));
    	/* allocate a mybuffer of chars with length bufsize */
    memcpy(infile, argv[1], strlen(argv[1]));
    open_data_file(infile);

    allocate_buffer(buffer);

    allocate_data(data);

    data = (double *)malloc(tnrows*sizeof(double));
    
    parse_data_file(buffer, tnrows, tncols);

/*    showdata(data, nrows, ncols); */
    create_data_file("temp.tsv", &m2d, &d2d);
    /* */
/*    gp_plot_screen("ascii2screen.gp"); */
/*    gp_plot_png("test.gp"); */
//    pu_graph("ciccio.gp"); 
    deallocate_buffer(buffer);

    deallocate_data(data);

    return 0;
 
    } else {
    printf("usage: %s infilename nrows ncolumns\n", argv[0]);
	return 1;
}


}

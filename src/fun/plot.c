/* functions to plot science data using gnuplot */

#include <string.h>
#include <math.h>
#include "plot.h"
/* create the file containing 2D points to be plotted
saving it on an ascii text file, takes in input
the string with the file name ofname, points are real
numbers separated by tabs */

int create_data_file(char *ofname, struct MetaDataMx2 *m2d, struct DataMx2 *d2d ){
         /* open output file for writing */
     char tempfname[255];
     strcpy(tempfname, ofname);
#ifdef DEBUG
     fprintf(stderr, "create_data_file(): start! ");
     fprintf(stderr, "create_data_file(): going to open file %s \n", tempfname);
#endif
     strcat(es, ": Can't open file "); strcat(es, tempfname); strcat(es, " for writing \n");
     ofptr = fopen(tempfname,"w");
     if ( ofptr == NULL  )  /* if can't open outfile receive an herror on opening file */
     {
       printf("Error OPENING FILE: err msg = %s\n", strerror(errno));
       fprintf(stderr,"fopen() failed in source file %s at line # %d\n", __FILE__,__LINE__);
       perror(es);  /* then handle the error */
       printf("exit value = %d : exiting\n", EXIT_FAILURE);
         exit(EXIT_FAILURE);
     } else {
       ret = ferror ( ofptr );
    }
#ifdef DEBUG
    fprintf(stderr, "%s: file %s correctly open for writing\n", "plot.c", ofname);
#endif
    /* process input data */
/*     while ( ( ch = fgetc(ifptr)) != EOF ) */ /* until you don't get the end of input file */
     fprintf(ofptr, "%s %s\n", "#ascii 2D points, file ", tempfname);
     fprintf(ofptr, "%s\n", "# time(s)\tcounts(#)");
     step = 1;
     for ( a=0; a < m2d->nrows; a++ )
     {
/*       fputc(ch,ofptr);  */ /* write the file content on outfile */
        fprintf(ofptr, "  %.6f\t%.6f\n", d2d->x[a], d2d->y[a] );
       if(ferror(ofptr))
       {
         printf("File Error writing rows ..!!\n");
         fprintf(stderr,"fopen() failed in source file %s at line # %d\n", __FILE__,__LINE__);
       }
     }
        fprintf(ofptr, "  %s\n", "e");
}

/* create a gnuplot commands file with directives on how to plot
the points */

int create_gp_cmd_file(char *gp_cmds_fn, struct MetaDataMx2 *m2d){
             /* open output file for writing */
     strcat(es, ": Can't open file "); strcat(es, gp_cmds_fn); strcat(es, " for writing \n");
     ofptr = fopen(gp_cmds_fn,"w");
     if ( ofptr == NULL  )  /* if can't open outfile receive an herror on opening file */
     {
       printf("Error OPENING FILE: err msg = %s\n", strerror(errno));
       fprintf(stderr,"fopen() failed in source file %s at line # %d\n", __FILE__,__LINE__);
       perror(es);  /* then handle the error */
       printf("exit value = %d : exiting\n", EXIT_FAILURE);
         exit(EXIT_FAILURE);
     } else {
       ret = ferror ( ofptr );
    }
#ifdef DEBUG
    fprintf(stderr, "%s: file %s correctly open for writing\n", "plot.c", gp_cmds_fn);
#endif
    /* process input data */
/*     while ( ( ch = fgetc(ifptr)) != EOF ) */ /* until you don't get the end of input file */
        fprintf(ofptr, "%s\n", "#!/usr/bin/env gnuplot");
        fprintf(ofptr, "%s\n", "# gnuplot commandfile created by fralaz1971@gmail.com");
        fprintf(ofptr, "%s\n", "set terminal qt persist");
        fprintf(ofptr, "set xlabel '%s (%s)'\n", m2d->cname[0], m2d->cunit[0]);
        fprintf(ofptr, "set ylabel '%s (%s)'\n", m2d->cname[1], m2d->cunit[1]);
        fprintf(ofptr, "set title '%s'\n", m2d->dsname);
        fprintf(ofptr, "%s\n", "plot 'fixed.tsv' using 1:2 with lines smooth cspline");

}

/* launch gnuplot cmd withn gp_cmds_ifn as gnuplot command file and plot to screen */
int gp_plot_screen(char * gp_cmds_ifn){
               fprintf(stderr,"gp_plot_screen: trying to plot on screen" );
               if (system("bash launchgp_screen.sh")){
               fprintf(stderr,"system() failed to launch gnuplot command source file %s at line # %d, is gnuplot installed and its path included in the PATH environment variable?\n", __FILE__,__LINE__);
    }
}
/* launch gnuplot cmd withn gp_cmds_ifn as gnuplot command file
 and save plot to png file */
int gp_plot_png(char * gp_cmds_ifn){
    if (system("bash launchgp_png.sh")){
               fprintf(stderr,"system() failed to launch gnuplot command source file %s at line # %d, is gnuplot installed and its path included in the PATH environment variable?\n", __FILE__,__LINE__);
    }
}

int pu_graph(char * gp_cmds_ifn){
/*    if (system("gnuplot -p -e \"plot \'ciao.tsv\'\"")){*/
    if (system("graph -T ps test.tsv >out.ps ; okular out.ps")){
               fprintf(stderr,"system() failed to launch plotutils:graph command source file %s at line # %d, is plotutils:graph installed and its path included in the PATH environment variable?\n", __FILE__,__LINE__);
    }
}

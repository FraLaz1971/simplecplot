set terminal qt persist 
set xlabel 'ThisXaxis'
set ylabel 'ThisYaxis'
set title 'AweSomePlot'
set datafile separator "\t"
plot 'myfile.tsv' using 1:2


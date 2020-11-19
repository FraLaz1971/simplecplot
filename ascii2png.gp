set term png
set output 'myfile.png'
set xlabel 'ThisXaxis'
set ylabel 'ThisYaxis'
set title 'AweSomePlot'
set datafile separator "\t"
plot 'myfile.tsv'

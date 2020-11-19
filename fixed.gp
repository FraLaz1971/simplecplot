#!/usr/bin/env gnuplot
# gnuplot commandfile created by fralaz1971@gmail.com
set terminal qt persist
set xlabel 'x-val (s)'
set ylabel 'y-val (#)'
set title 'AwesomeData'
plot 'fixed.tsv' using 1:2 with lines smooth cspline

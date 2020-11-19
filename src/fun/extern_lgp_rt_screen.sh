#!/usr/bin/env bash

echo "executing extern gnuplot runtime launch $0 $@"
echo "extern_lgp_rt_screen.sh: creating temp. files"
./testlibfun table.csv 1 1
ls -alhrt *.gp *tsv
echo "executing extern gnuplot runtime: gnuplot -p fixed.gp"

gnuplot -p fixed.gp


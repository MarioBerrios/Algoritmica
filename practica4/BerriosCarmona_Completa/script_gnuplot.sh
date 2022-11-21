#!/bin/bash

#OJO: adaptar las leyendas a los nombres de las variables. En el eje Y se miden tiempos y en el eje X es el tamaño del ejemplar.
cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Tiempo"
set ylabel ""
plot './BBVA.txt' using 1:2 t "Serie temporal" w l, 'salida' using 1:2 t "Serie segmentada" w l,
_end_

#!/bin/bash

#OJO: adaptar las leyendas a los nombres de las variables. En el eje Y se miden tiempos y en el eje X es el tamaño del ejemplar.
cat << _end_ | gnuplot
set terminal postscript eps color
set output "grafico.eps"
set key right bottom
set xlabel "Numero de elementos N"
set ylabel "Tiempo (microsegundos)"
plot 'datosFinales.txt' using 1:2 t "Tiempos reales frente a numero elementos", 'datosFinales.txt' using 1:3 t "Tiempos estimados frente a numero elementos" w l 
_end_

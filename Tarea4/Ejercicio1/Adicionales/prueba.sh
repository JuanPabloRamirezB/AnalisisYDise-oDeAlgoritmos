#!/bin/bash 
# Crear o vaciar el archivo de resultados 
> tiempos25Lineas.txt

for i in {0..9}; 
do nombre_archivo="./1600lineas/1600lineasEj$i.txt" 
./prog < $nombre_archivo >> "./1600lineas/tiempos1600Lineas.txt"
echo "Ejecutado con $nombre_archivo" 
done

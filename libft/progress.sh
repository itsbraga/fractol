#!/bin/bash

# total_files=$1
# compiled_files=$2
# progress_size=50

# # Calculer le pourcentage de fichiers compilés
# percentage=$(echo "$compiled_files * 100 / $total_files" | bc)

# # Calculer le nombre de '#' à afficher
# num_hashes=$(echo "$percentage * $progress_size / 100" | bc)

# # Afficher la barre de progression
# echo -n "Loading... ["
# for ((i=1; i<=num_hashes; i++)); do
#     echo -n "#"
#     sleep 0.1
# done
# for ((i=num_hashes+1; i<=progress_size; i++)); do
#     echo -n " "
# done
# echo -n "]"
# echo -ne "\r"

total_files=$1
compiled_files=$2
progress_size=50

# Calculer le pourcentage de fichiers compilés
percentage=$(echo "$compiled_files * 100 / $total_files" | bc)

# Calculer le nombre de '#' à afficher
num_hashes=$(echo "$percentage * $progress_size / 100" | bc)

# Construire la barre de progression
progress_bar="Loading... ["
for ((i=1; i<=num_hashes; i++)); do
    progress_bar+="#"
done
for ((i=num_hashes+1; i<=progress_size; i++)); do
    progress_bar+=" "
done
progress_bar+="]"

# Afficher la barre de progression
echo -ne "$progress_bar\r"

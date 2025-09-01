#!/bin/bash
#SBATCH --job-name=data_el_paper
#SBATCH --time=03:00:00               # max run time hh:mm:ss
#SBATCH --ntasks=1                   # number of tasks (processes)
#SBATCH --cpus-per-task=1            # number of CPU cores per task
#SBATCH --mem=12G                     # memory required
#SBATCH --output=job_%j.out          # output file (%j expands to job ID)
#SBATCH --error=job_%j.err           # error file
#SBATCH --mail-user=robert.mihai.amarinei@ecern.ch
#SBATCH --mail-type=BEGIN,END,FAIL


source ~/.bashrc 
ana
./ProduceAllTrees.sh



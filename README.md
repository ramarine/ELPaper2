# Second EL study

This is a simplified repo based on more complex TPC_Analysis repo. It contains the scripts used to generate WF sums. Eventually it will also generate the plots for the paper. 

### Run the code

`root -lb 'GeneralAna_v8.C("C4500_LSF2450_ThGUp2150_ThGDnGND_PMesh0_TPC1650_p2_0")'`

### Data file path (.txt and binary)

`/srv/beegfs/scratch/users/a/amarinei/Swan_Data/Configuration_P25/Batch_2/NegScan/ThGEM2150/C4500_LSF2450_ThGUp2150_ThGDnGND_PMesh0_TPC1650_p2_0`

For pressure 1 data from EL Paper 2: `/home/amarinei/Year1_PhD/TPC/Comissioning/TPC_Ana/LeCroyPMT_Ana/Swan_Data/Configuration_P25`

### Analysis file

`/home/amarinei/Year1_PhD/TPC/ELPaper2/GeneralAna_v8.C` --> This is for individual plots for single files
` /home/amarinei/Year1_PhD/TPC/ELPaper2/ELPaper2_Ana.C` --> This is for all plots generated in the study. 

`string prefix_path_data = "/srv/beegfs/scratch/users/a/amarinei/Swan_Data/Configuration_P25/Batch_2/NegScan/ThGEM2150/";`
`string path_prefix_AnaResults = "/srv/beegfs/scratch/users/a/amarinei/Swan_TTrees/Configuration_P25/Batch_2/NegScan/WFSumInvestigation";`


### Data taking log

https://docs.google.com/spreadsheets/d/10en9j8fPv_pPa2r3pkVkPmqnrOk5nnK1XwuN5S1xI3I/edit?gid=0#gid=0


### GeneralAna_v8

In this file I take all events and I process them one by one. In this file I create the waveform sum histograms: raw, flat and sum.
WF_sum_raw adds all the bins of the signal event waveforms. 
WF_sum adds only bins above NSigma * rms. 

Equivalently for histograms:
hWF_sum_raw has the WF_sum_raw values.
hWF_sum_flat has the WF_sum values.// no normalization. this the one we use in general. 
hWF_sum has the normalize per bin height WF_sum values.





### ELPaper2_Ana









#ifndef ELECTRODIALYSISCONTROL_H
#define ELECTRODIALYSISCONTROL_H

/*TODO: test if these functions can be run within a while loop in the 
electrodialysis task or if separate tasks need to be created*/
void controlElectrodialysis(void* parameters);
void actuatePump(void* parameters);
void monitorVoltage(void* parameters);
void controlPG03(void* parameters);
void controlLLS05(void* parameters);

#endif
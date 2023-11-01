#include <stdbool.h>

typedef struct{
	
	int ano;
	int mes;
	int dia;
	
	}Data;
	

bool dataValida(Data dt);

int nDiasAno(Data dt);

Data incData(Data dt);

int cmpData(Data dt1, Data dt2);

int difData(Data dt1, Data dt2);

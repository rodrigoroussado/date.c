#include "date.h"
#include <stdbool.h>

#define MAX_MESES 12

//Implementação das funções declaradas no data.h

bool AnoBissexto(int ano){

	if( (ano % 4 == 0 && ano % 100 != 0) || (ano % 400 == 0) ){return true;} //Se o ano for bissexto, retorna true
	else{return false;}

}


int diasDoMes(int mes, int ano) {
   
    int dias[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; // começa com 0 para nao termos de subtrair ao mes 1
    
    if (mes == 2 && AnoBissexto(ano)) {
        return 29;
   
    }
    else{return dias[mes];}
	
}


bool dataValida(Data dt){
	
	//Validar ano
	if(dt.ano < 0){return false;}
	else{
		
		//Validar mês do ano
		if(dt.mes < 1 || dt.mes > 12){return false;}
		else{
			
			//Validar dia do mês
			if(dt.dia < 1 || dt.dia > diasDoMes(dt.mes, dt.ano)){return false;}
			else{return true;}
			
		}
	}
}


int nDiasAno(Data dt){
	
	int nd;
	int soma_dias[MAX_MESES + 1] = {0, 0, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334, 365};
	
	nd = soma_dias[dt.mes] + dt.dia;
	
	if( AnoBissexto(dt.ano) == true && dt.mes > 2){nd++;}
	
	return nd;
	
}


Data incData(Data dt){
	
	//Incrementar dia
	dt.dia++;
	
	//Se o dia ficar maior que diasMes(dt.mes, dt.ano)
	if( dt.dia > diasDoMes(dt.mes, dt.ano) ){
		
		//dt.dia = 1 e incrementa o dt.mes
		dt.dia = 1;
		dt.mes++;
		
		//Se o mês ficar maior que 12
		if(dt.mes > 12){
		
			//dt.dia = 1, dt. mes = 1 e incrementa dt.ano
			dt.dia = 1;
			dt.mes = 1;
			dt.ano++;
			
			return dt;
			
		}
		else{return dt;}
		
	}
	else{return dt;}
	
}


int cmpData(Data dt1, Data dt2){
	
	int diferenca = 0;
	
	//Comparar anos
	diferenca = dt1.ano - dt2.ano;
	
	if(diferenca != 0){return diferenca;}
	else{
		
		//Comparar mês
		diferenca = dt1.mes - dt2.mes;
		
		if(diferenca != 0){return diferenca;}
		else{
			
			//Comparar dias
			diferenca = dt1.dia - dt2.dia;
			
			return diferenca;
			
		}
		
	}
	
}



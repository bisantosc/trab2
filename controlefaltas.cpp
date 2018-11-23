//Bianca Santos
//Rodrigo Piccini

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "aluno.h"
//#include "mainfaltas.cpp"

using namespace std;

//class aluno {

    	//private:

	//public:

   	//string nome;
   	//int aulaf;
	//int matricula;
	
	
      //aluno(int matricula, string nome, int aulaf) {    
	//this->nome=nome;
	//this->aulaf=aulaf;
	//this->matricula=matricula;
       	

    //}
//};

void carregar (vector<aluno> & lista) {   

       string nome;
       int aulaf;
	int matricula;

       ifstream alunos;                                

       alunos.open("alunos.txt");       

       if(! alunos.is_open() ) {         

              cerr << "erro ao abrir arquivo" << endl;
		exit(-1);

       }
	alunos >> matricula;
       alunos >> nome;
       alunos >> aulaf;
	

       while (alunos.good()){      
	
		 
        aluno a(matricula,nome, aulaf);     
       	lista.push_back(a);   
   
		alunos >> matricula;       
       	alunos >> nome;             
       	alunos >> aulaf;     
		

       }
	alunos.close();    

}

void mostrar(vector<aluno> lista) {

	string status;  
      	
                     
	for(int i = 0; i < lista.size(); i++) {     

	       int aulat=68;
	       int x;
	       x = aulat*25/100;

	       if (x<lista[i].aulaf){                    

		       status =  "Reprovado" ;      
		
	       }else{
	
		       status = "OK" ;
		
	       }

	cout << lista[i].matricula << ", " << lista[i].nome << ", " << lista[i].aulaf << ", " <<  status << endl;

	}

}

void gravar(vector<aluno> presenca,int m) {
	ofstream relatorio;
	string status;
	int aulat=68;
	int x;
	x = aulat*25/100;

	relatorio.open("relatorio.txt");

	relatorio << "atestado de frequencia" << endl;
    for(int i = 0; i < presenca.size(); i++) {

		if(presenca[i].matricula == m){
			
			 if (x<presenca[i].aulaf){                    

		       		status =  "Reprovado" ;      
		
	       		}else{
	
		       		status = "OK" ;
		
	       		}	

    			relatorio << presenca[i].matricula << ", " << presenca[i].nome << ", "<< presenca[i].aulaf << ", "<<status << endl;
    		
		}
	}
	relatorio.close();

}


//int main () {

//	int m;

//	cout << "Controle de Faltas \n" << endl;

//	vector<aluno> lista;
//	carregar (lista);
//	mostrar (lista);

//	cout << "Digite a matricula do aluno para verificar o atestado de frequencia: " << endl;
//	cin >> m;

//	gravar (lista,m);

//    return 0;
//}



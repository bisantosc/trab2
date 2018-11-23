#include <string>

 using namespace std;

class aluno {

    //private:

public:

    	string nome;
    	int aulaf;
	int matricula;
	
	
       aluno(int matricula, string nome, int aulaf) {    
	this->nome = nome;
	this->aulaf = aulaf;
	this->matricula = matricula;
       	

    }
};


#include  <stdio.h>
#include <stdlib.h>
//A linha #include <stdio.h> inclui o arquivo-cabeçalho stdio.h.
//stdio.h é um cabeçalho da biblioteca padrão do C.
//Possui definições de subrotinas relativas às operações de entrada/saída.
//Algumas funções desta biblioteca que são muito utilizadas:
//printf(), função usada para imprimir dados na tela;
//scanf(), função usada para capturar dados do usuário;
//fprintf(), função usada para imprimir dados em arquivo;
//fscanf(), função usada para ler dados de arquivos.

#include <string.h>

//A linha #include <string.h> inclui o arquivo-cabeçalho string.h.
//A biblioteca string.h da linguagem C contém funções para manipular strings.
//A utilizamos para ter acesso à função strcmp que compara o conteúdo de duas strings.
//Variável do tipo inteiro = strcmp(string1, string2).

#define TAMNOME 50 //50 é o tamanho da constante.
#define TAMSOBRENOME 50 //50 é o tamanho da constante.

int tipo_ord = 0, busca = -1;

typedef struct data {

    int dia;
    int mes;
    int ano;

} data;

//Um registro (= record) é um pacote de variáveis, possivelmente de tipos diferentes.
//Cada variável é um campo do registro.
//Na linguagem C, registros são conhecidos como structs (o nome é uma abreviatura de structure).
//Registros podem ser tratados como um novo tipo-de-dados.

typedef struct registro {

    char nome [TAMNOME]; //Variável do tipo char com tamanho da constante TAMNOME, ou seja, 50.
    char sobrenome [TAMSOBRENOME]; //Variável do tipo char com tamanho da constante TAMSOBRENOME, ou seja, 50.
    data datadenascimento;
    int prontuario;
    char curso [4]; //Limite de caracteres para cursos de 3 letras.

} aluno;

aluno alunos[1000]; //Recebe até 1000 cadastros.

void menu() { //Função do menu principal, exibe as opções.
    printf("\n0 - Finalizar programa.\n");
    printf("1 - Cadastrar aluno.\n");
    printf("2 - Imprimir todos os alunos.\n");
    printf("3 - Buscar aluno.\n");
    printf("4 - Ordenar.\n");
    printf("5 - Gravacao arquivo.\n");
    printf("6 - Leitura arquivo.\n");
}

int counter = 0; //Criação do contador de cadastros.
void cadastrar_aluno(){ //Função de cadastro de alunos.
    aluno novo_aluno; //Recebe os valores de nome, sobrenome, prontuário, curso, e data de nascimento.
    printf("Digite o nome do aluno: ");
    fflush(stdin);
    fgets(novo_aluno.nome, TAMNOME, stdin);
    printf("Digite o sobrenome do aluno: ");
    fflush(stdin);
    fgets(novo_aluno.sobrenome, TAMSOBRENOME, stdin);
    printf("Digite o prontuario: ");
    scanf("%d", &novo_aluno.prontuario);
    printf("Digite o curso do aluno: ");
    fflush(stdin);
    fgets(novo_aluno.curso, 4, stdin);
    printf("Digite a data de nascimento (dia,mes,ano): ");
    scanf("%d,%d,%d",&novo_aluno.datadenascimento.dia,&novo_aluno.datadenascimento.mes,&novo_aluno.datadenascimento.ano);

	//A função fflush descarrega os buffers de saída de um fluxo de dados.
	//Isto é, qualquer dado ainda não escrito no disco e guardado nos buffers temporários de saída, é escrito. Com isso, o buffer é limpo.
	//O fluxo continua funcionando normalmente após o uso do fflush.
    //fflush é utilizada aqui para corrigir o problema do scanf com a não execução de chamadas.
    //stdin é o dispositivo de entrada padrão, no caso o teclado.
    //fgets lê do fluxo para uma cadeia de strings.

	alunos[counter] = novo_aluno; //Utiliza o valor do contador para o posicionamento do cadastro do aluno.
	counter++; //Por ter sido adicionado um aluno, o contador recebe + 1. 
}

int compararAluno(aluno A1, aluno A2, int criterio){
	switch (criterio){
		case 1: {
			if(strcmp(A1.nome, A2.nome) == 0) return 0; //São iguais.
			else if (strcmp(A1.nome, A2.nome) == -1) return -1; //A1 vem antes de A2.
			else if  (strcmp(A1.nome, A2.nome) == 1) return 1; //A2 vem antes de A1.
			break;
		}
		case 2:{
			if(strcmp(A1.sobrenome, A2.sobrenome) == 0) return 0; //São iguais.
			else if (strcmp(A1.sobrenome, A2.sobrenome) == -1) return -1; //A1 vem antes de A2.
			else if  (strcmp(A1.sobrenome, A2.sobrenome) == 1) return 1; //A2 vem antes de A1.
			break;
		}
		case 3: {
			if(A1.prontuario == A2.prontuario) return 0; //São iguais.
			else if (A1.prontuario < A2.prontuario) return -1; //A1 vem antes de A2.
			else if  (A1.prontuario > A2.prontuario) return 1; //A2 vem antes de A1.
			break;
		}
		case 4: {
			if(strcmp(A1.curso, A2.curso) == 0) return 0; //São iguais.
			else if (strcmp(A1.curso, A2.curso) == -1) return -1; //A1 vem antes de A2.
			else if  (strcmp(A1.curso, A2.curso) == 1) return 1; //A2 vem antes de A1.
			break;
		}
		case 5: {
			if(A1.datadenascimento.ano == A2.datadenascimento.ano){
				if(A1.datadenascimento.mes == A2.datadenascimento.mes){
					if(A1.datadenascimento.dia == A2.datadenascimento.dia) return 0; //São iguais.
					else if(A1.datadenascimento.dia < A2.datadenascimento.dia) return -1; //A1 vem antes de A2.
					else if (A1.datadenascimento.dia > A2.datadenascimento.dia) return 1; //A2 vem antes de A1.
				}
				else if(A1.datadenascimento.mes < A2.datadenascimento.mes) return -1; //A1 vem antes de A2.
				else if(A1.datadenascimento.mes > A2.datadenascimento.mes) return 1; //A2 vem antes de A1.
			} 
			else if(A1.datadenascimento.ano < A2.datadenascimento.ano) return -1; //A1 vem antes de A2.
			else if(A1.datadenascimento.ano > A2.datadenascimento.ano) return 1; //A2 vem antes de A1.
			break;
		}
		default: {
			break;
		}
	}
}

void imprimir_aluno(){ //Função de exibição de cadastros.
	int i;
	for (i = 0; i < counter; i++){ //Percorre os cadastros do primeiro (posição[0]) até o último (posição[counter]), imprimindo todos os alunos.
		printf("--------------------------- \n");
		printf("Nome --> %s", alunos[i].nome);
		printf("Sobrenome --> %s", alunos[i].sobrenome);
		printf("Prontuario --> %d \n",alunos[i].prontuario);
		printf("Curso --> %s \n",alunos[i].curso);
		printf("Nascimento --> %d/%d/%d \n",alunos[i].datadenascimento.dia,alunos[i].datadenascimento.mes,alunos[i].datadenascimento.ano);
	}
}

void sub_menu(){ //Função de exibição do submenu de busca.
    printf("0 - Voltar ao menu principal.\n");
    printf("1 - Buscar por nome.\n");
    printf("2 - Buscar por sobrenome.\n");
    printf("3 - Buscar por prontuario.\n");
    printf("4 - Buscar por curso.\n");
    printf("5 - Buscar por data de nascimento.\n");
    printf("Escolha uma opcao: ");
}

void buscar_aluno_linear(){ //Função de busca linear por cadastros. 
    int sm = busca;
        if (sm == 1){ //Se a opção desejada for 1, a busca ocorre por nome.
            int i, j, parada = 0, aux; //Criação da variável parada, que recebe valor 0.
            char busca_nome[TAMNOME];
            printf("Digite o nome do aluno: ");
            fflush(stdin);
    		fgets(busca_nome, TAMNOME, stdin);
            for (i = 0; i < counter; i++){
            	if (strcmp(alunos[i].nome, busca_nome) == 0) { //Compara se alunos[i].nome é igual a busca_nome.
            		parada = 1; //Se a função, após percorrer todos os alunos, encontrar uma correspondência, o valor de parada é trocado. 
            		printf("---------------------------\n");
					printf("Nome --> %s", alunos[i].nome);
					printf("Sobrenome --> %s", alunos[i].sobrenome);
					printf("Prontuario --> %d \n",alunos[i].prontuario);
					printf("Curso --> %s \n",alunos[i].curso);
					printf("Nascimento --> %d/%d/%d \n",alunos[i].datadenascimento.dia,alunos[i].datadenascimento.mes,alunos[i].datadenascimento.ano);
					printf("---------------------------\n");
				}
			}
        	if (parada == 0){ //Se o valor da variável parada não sofrer alterações, o aluno não foi encontrado.
				printf("Aluno nao cadastrado.\n");
			}
			else{
				printf("Deseja excluir os dados do(s) aluno(s) buscado(s)? \n 1 - Sim. \n 2 - Nao. \n");
            	scanf("%d",&aux);
            	if (aux == 1){ //Opção de excluir os dados do(s) aluno(s) buscado(s) é escolhida.
    				int a, b;
    				for(a = 0; a < counter; a++){
        				if(strcmp(alunos[a].nome, busca_nome) == 0){ //Se a busca for bem sucedida:
							for(b = a; b < counter-1; b++){
                				alunos[b] = alunos[b+1]; //O aluno em questão é excluído e o próximo toma seu lugar. Assim, todos os alunos seguintes são realocados.
							}
							counter--; //Atualiza o contador de cadastros ao excluir um aluno.
        				}
    				}
    				printf("Dados excluidos com sucesso. \n");
				}
			}
        }
        
        else if (sm == 2){ //Se a opção desejada for 2, a busca ocorre por sobrenome.
        	int i, j, parada = 0, aux; //Criação da variável parada, que recebe valor 0.
            char busca_sobrenome[TAMSOBRENOME];
            printf("Digite o sobrenome do aluno: ");
            fflush(stdin);
    		fgets(busca_sobrenome, TAMSOBRENOME, stdin);
            for (i = 0; i < counter; i++){
            	if (strcmp(alunos[i].sobrenome, busca_sobrenome) == 0) {
            		parada = 1; //Se a função, após percorrer todos os alunos, encontrar uma correspondência, o valor de parada é trocado.
            		printf("---------------------------\n");
					printf("Nome --> %s", alunos[i].nome);
					printf("Sobrenome --> %s", alunos[i].sobrenome);
					printf("Prontuario --> %d \n",alunos[i].prontuario);
					printf("Curso --> %s",alunos[i].curso);
					printf("Nascimento --> %d/%d/%d \n",alunos[i].datadenascimento.dia,alunos[i].datadenascimento.mes,alunos[i].datadenascimento.ano);
					printf("---------------------------\n");
				}
			}
            
        	if (parada == 0){ //Se o valor da variável parada não sofrer alterações, o aluno não foi encontrado.
				printf("Aluno nao cadastrado.\n");
			}
			else{
				printf("Deseja excluir os dados do(s) aluno(s) buscado(s)? \n 1 - Sim. \n 2 - Nao. \n");
            	scanf("%d",&aux);
            	if (aux == 1){ //Opção de excluir os dados do(s) aluno(s) buscado(s) é escolhida.
    				int a, b;
    				for(a = 0; a < counter; a++){
        				if(strcmp(alunos[a].sobrenome, busca_sobrenome) == 0){ //Se a busca for bem sucedida:
							for(b = a; b < counter-1; b++){
                				alunos[b] = alunos[b+1]; //O aluno em questão é excluído e o próximo toma seu lugar. Assim, todos os alunos seguintes são realocados.
							}
							counter--; //Atualiza o contador de cadastros ao excluir um aluno.
        				}
    				}
    				printf("Dados excluidos com sucesso. \n");
				}
			}
        }
        
        else if (sm == 3){ //Se a opção desejada for 3, a busca ocorre por prontuário.
            printf("Digite o prontuario do aluno: ");
            int pront,i,parada=0,aux; //Criação da variável parada, que recebe valor 0.
            scanf("%d/n",&pront);
            for (i = 0; i < counter; i++){
            	if (alunos[i].prontuario == pront){
            	printf("---------------------------\n");
					printf("Nome --> %s", alunos[i].nome);
					printf("Sobrenome --> %s", alunos[i].sobrenome);
					printf("Prontuario --> %d \n",alunos[i].prontuario);
					printf("Curso --> %s \n",alunos[i].curso);
					printf("Nascimento --> %d/%d/%d \n",alunos[i].datadenascimento.dia,alunos[i].datadenascimento.mes,alunos[i].datadenascimento.ano);
					printf("---------------------------\n");
					parada = 1;	//Se a função, após percorrer todos os alunos, encontrar uma correspondência, o valor de parada é trocado.
				}
			}
			if (parada == 0){ //Se o valor da variável parada não sofrer alterações, o aluno não foi encontrado.
				printf("Aluno nao cadastrado.\n");
			}
			else{
				printf("Deseja excluir os dados do(s) aluno(s) buscado(s)? \n 1 - Sim. \n 2 - Nao. \n");
            	scanf("%d",&aux);
            	if (aux == 1){ //Opção de excluir os dados do(s) aluno(s) buscado(s) é escolhida.
    				int a, b;
    				for(a = 0; a < counter; a++){
        				if(alunos[a].prontuario == pront){ //Se a busca for bem sucedida:
							for(b = a; b < counter-1; b++){
                				alunos[b] = alunos[b+1]; //O aluno em questão é excluído e o próximo toma seu lugar. Assim, todos os alunos seguintes são realocados.
							}
							counter--; //Atualiza o contador de cadastros ao excluir um aluno.
        				}
    				}
    				printf("Dados excluidos com sucesso. \n");
				}
			}
        }
        
        else if (sm == 4){ //Se a opção desejada for 4, a busca ocorre por curso.
            int i, j, parada = 0, aux; //Criação da variável parada, que recebe valor 0.
            char busca_curso[4];
            printf("Digite o curso do aluno: ");
            fflush(stdin);
    		fgets(busca_curso, 4, stdin);
            for (i = 0; i < counter; i++){
            	if (strcmp(alunos[i].curso, busca_curso) == 0) {
            		parada = 1; //Se a função, após percorrer todos os alunos, encontrar uma correspondência, o valor de parada é trocado.
            		printf("---------------------------\n");
					printf("Nome --> %s", alunos[i].nome);
					printf("Sobrenome --> %s", alunos[i].sobrenome);
					printf("Prontuario --> %d \n",alunos[i].prontuario);
					printf("Curso --> %s",alunos[i].curso);
					printf("Nascimento --> %d/%d/%d \n",alunos[i].datadenascimento.dia,alunos[i].datadenascimento.mes,alunos[i].datadenascimento.ano);
					printf("---------------------------\n");
				}
			}
        	if (parada == 0){ //Se o valor da variável parada não sofrer alterações, o aluno não foi encontrado.
				printf("Aluno nao cadastrado.\n");
			}
			else{
				printf("Deseja excluir os dados do(s) aluno(s) buscado(s)? \n 1 - Sim. \n 2 - Nao. \n");
            	scanf("%d",&aux);
            	if (aux == 1){ //Opção de excluir os dados do(s) aluno(s) buscado(s) é escolhida.
    				int a, b;
    				for(a = 0; a < counter; a++){
        				if(strcmp(alunos[a].curso, busca_curso) == 0){ //Se a busca for bem sucedida:
							for(b = a; b < counter-1; b++){
                				alunos[b] = alunos[b+1]; //O aluno em questão é excluído e o próximo toma seu lugar. Assim, todos os alunos seguintes são realocados.
							}
							counter--; //Atualiza o contador de cadastros ao excluir um aluno.
        				}
    				}
    				printf("Dados excluidos com sucesso. \n");
				}
			}
        }
           else if (sm == 5){ //Se a opção desejada for 5, a busca ocorre por data de nascimento.
            printf("Digite a data de nascimento do aluno (dia,mes,ano): ");
            int dd,dm,da,i,parada=0,aux; //Criação da variável parada, que recebe valor 0.
            scanf("%d,%d,%d",&dd,&dm,&da);
            for (i = 0; i < counter; i++){
                if (alunos[i].datadenascimento.dia == dd && alunos[i].datadenascimento.mes == dm && alunos[i].datadenascimento.ano == da){
                    printf("---------------------------\n");
					printf("Nome --> %s", alunos[i].nome);
					printf("Sobrenome --> %s", alunos[i].sobrenome);
					printf("Prontuario --> %d \n",alunos[i].prontuario);
					printf("Curso --> %s",alunos[i].curso);
					printf("Nascimento --> %d/%d/%d \n",alunos[i].datadenascimento.dia,alunos[i].datadenascimento.mes,alunos[i].datadenascimento.ano);
					printf("---------------------------\n");
					parada = 1;	//Se a função, após percorrer todos os alunos, encontrar uma correspondência, o valor de parada é trocado.
                }
            }
            if (parada == 0){ //Se o valor da variável parada não sofrer alterações, o aluno não foi encontrado.
				printf("Aluno nao cadastrado.\n");
			}
			else{
				printf("Deseja excluir os dados do(s) aluno(s) buscado(s)? \n 1 - Sim. \n 2 - Nao. \n");
            	scanf("%d",&aux);
            	if (aux == 1){ //Opção de excluir os dados do(s) aluno(s) buscado(s) é escolhida.
    				int a, b;
    				for(a = 0; a < counter; a++){
        				if(alunos[a].datadenascimento.dia == dd && alunos[a].datadenascimento.mes == dm && alunos[a].datadenascimento.ano == da){ //Se a busca for bem sucedida:
							for(b = a; b < counter-1; b++){
                				alunos[b] = alunos[b+1]; //O aluno em questão é excluído e o próximo toma seu lugar. Assim, todos os alunos seguintes são realocados.
							}
							counter--; //Atualiza o contador de cadastros ao excluir um aluno.
        				}
    				}
    				printf("Dados excluidos com sucesso. \n");
				}
			}
        }
}

int buscaBinaria (aluno vetor[], int tamanho, aluno chave, int criterio) { //Procura a chave especificada partindo do meio do conjunto.
		int ini = 0;
		int fim = tamanho-1;
		int meio;
			while (ini <= fim) { //A busca continua pela metade do subvetor que restou.
				meio = (ini + fim)/2;
				if (compararAluno(chave, vetor[meio], criterio) == 0) return meio; 
				if (compararAluno(chave, vetor[meio], criterio) == -1) fim = meio-1;
				else ini = meio+1;
			}
		return -1; //Caso não encontrado.

	}

void buscar_aluno_binario(int criterio){ //Função de busca binária.
	switch (criterio){
		case 1: { //Busca pelo nome.
			aluno teste;
			printf("Digite o nome do aluno: ");
    		fflush(stdin);
    		fgets(teste.nome, TAMNOME, stdin);
    		int index = buscaBinaria(alunos, counter, teste, criterio);
			printf("---------------------------\n"); //Quando encontrado, imprime o resultado.
			printf("Nome --> %s", alunos[index].nome);
			printf("Sobrenome --> %s", alunos[index].sobrenome);
			printf("Prontuario --> %d \n",alunos[index].prontuario);
			printf("Curso --> %s",alunos[index].curso);
			printf("Nascimento --> %d/%d/%d \n",alunos[index].datadenascimento.dia,alunos[index].datadenascimento.mes,alunos[index].datadenascimento.ano);
			printf("---------------------------\n");
			break;
		}
		case 2: { //Busca pelo sobrenome.
			aluno teste;
			printf("Digite o sobrenome do aluno: ");
    		fflush(stdin);
    		fgets(teste.sobrenome, TAMSOBRENOME, stdin);
    		int index = buscaBinaria(alunos, counter, teste, criterio);
			printf("---------------------------\n");
			printf("Nome --> %s", alunos[index].nome);
			printf("Sobrenome --> %s", alunos[index].sobrenome);
			printf("Prontuario --> %d \n",alunos[index].prontuario);
			printf("Curso --> %s",alunos[index].curso);
			printf("Nascimento --> %d/%d/%d \n",alunos[index].datadenascimento.dia,alunos[index].datadenascimento.mes,alunos[index].datadenascimento.ano);
			printf("---------------------------\n");
			break;
		}
		case 3: { //Busca pelo prontuário.
			aluno teste;
			printf("Digite o prontuario do aluno: ");
    		scanf("%d", &teste.prontuario);
    		int index = buscaBinaria(alunos, counter, teste, criterio);
			printf("---------------------------\n");
			printf("Nome --> %s", alunos[index].nome);
			printf("Sobrenome --> %s", alunos[index].sobrenome);
			printf("Prontuario --> %d \n",alunos[index].prontuario);
			printf("Curso --> %s \n",alunos[index].curso);
			printf("Nascimento --> %d/%d/%d \n",alunos[index].datadenascimento.dia,alunos[index].datadenascimento.mes,alunos[index].datadenascimento.ano);
			printf("---------------------------\n");
			break;
		}
		case 4: { //Busca pelo curso.
			aluno teste;
			printf("Digite o curso do aluno: ");
    		fflush(stdin);
    		fgets(teste.curso, 4, stdin);
    		int index = buscaBinaria(alunos, counter, teste, criterio);
			printf("---------------------------\n");
			printf("Nome --> %s", alunos[index].nome);
			printf("Sobrenome --> %s", alunos[index].sobrenome);
			printf("Prontuario --> %d \n",alunos[index].prontuario);
			printf("Curso --> %s",alunos[index].curso);
			printf("Nascimento --> %d/%d/%d \n",alunos[index].datadenascimento.dia,alunos[index].datadenascimento.mes,alunos[index].datadenascimento.ano);
			printf("---------------------------\n");
			break;
		}
		case 5: { //Busca pela data de nascimento.
			aluno teste;
			printf("Digite a data de nascimento do aluno: ");
    		scanf("%d,%d,%d", &teste.datadenascimento.dia,&teste.datadenascimento.mes,&teste.datadenascimento.ano);
    		int index = buscaBinaria(alunos, counter, teste, criterio);
			printf("---------------------------\n");
			printf("Nome --> %s", alunos[index].nome);
			printf("Sobrenome --> %s", alunos[index].sobrenome);
			printf("Prontuario --> %d \n",alunos[index].prontuario);
			printf("Curso --> %s",alunos[index].curso);
			printf("Nascimento --> %d/%d/%d \n",alunos[index].datadenascimento.dia,alunos[index].datadenascimento.mes,alunos[index].datadenascimento.ano);
			printf("---------------------------\n");
			break;
		}
	}
	
}

void buscar_aluno(){ //Função de busca linear ou binária. Chama a função específica de acordo com a escolha.
	int opcBusca = -1;
	while(opcBusca != 0){
		sub_menu();
		scanf("%d",&opcBusca);
		busca = opcBusca;
		if(busca == tipo_ord){
			buscar_aluno_binario(opcBusca); //Chama a busca binária.
		}
		else{
			buscar_aluno_linear(); //Chama a busca linear.
		}
	}
}

void tipo_de_ord(){ //Submenu de ordenação.
	printf("0 - Sair.\n");
	printf("1 - Quick Sort.\n");
	printf("2 - Merge Sort.\n");
	printf("3 - Insertion Sort.\n");
	printf("4 - Selection Sort.\n");
	printf("Escolha a opcao: ");
}

void sub_menu_ord(){ //Função de exibição do submenu de critérios de ordenação.
	printf("0 - Sair.\n");
	printf("1 - Por nome.\n");
	printf("2 - Por sobrenome.\n");
	printf("3 - Por prontuario.\n");
	printf("4 - Por curso.\n");
	printf("5 - Por data de nascimento.\n");
	printf("Escolha a opcao: ");
}

void quickSort(aluno vetor[], int inicio, int fim, int criterio){ //Opção de ordenação rápida (quickSort).
   
   aluno pivo, aux; //Escolhe um elemento da lista chamado pivô.
   int i, j, meio;
   
   i = inicio;
   j = fim;
   
   meio = ((i + j) / 2);
   pivo = vetor[meio];
   
   do{
      while (compararAluno(vetor[i], pivo, criterio) == -1) i = i + 1; //Reorganiza a lista de forma que os elementos menores que o pivô fiquem de um lado,
      while (compararAluno(vetor[j], pivo, criterio) == 1) j = j - 1; //e os maiores fiquem de outro. Esta operação é chamada de “particionamento”.
      
      if(i <= j){
         aux = vetor[i];
         vetor[i] = vetor[j];
         vetor[j] = aux;
         i = i + 1;
         j = j - 1;
      }
   }while(j > i);
   
   //Recursivamente ordena a sub-lista abaixo e acima do pivô. 
   
   if(inicio < j) quickSort(vetor, inicio, j, criterio); 
   if(i < fim) quickSort(vetor, i, fim, criterio);
}

void mergeSort(aluno vetor[], int posicaoInicio, int posicaoFim, int criterio){ //Opção de ordenação mergeSort.
    
    //Merge Sort divide a sequência original em pares de dados, agrupa estes pares na ordem desejada; 
    //depois as agrupa as sequências de pares já ordenados, formando uma nova sequência ordenada de quatro elementos, e assim por diante, até ter toda a sequência ordenada.
    
	int i, j, k, metadeTamanho;
	aluno *vetorTemp;
	if(posicaoInicio == posicaoFim) return;
    metadeTamanho = (posicaoInicio + posicaoFim ) / 2;

    mergeSort(vetor, posicaoInicio, metadeTamanho, criterio);
    mergeSort(vetor, metadeTamanho + 1, posicaoFim, criterio);

    i = posicaoInicio;
    j = metadeTamanho + 1;
    k = 0;
    vetorTemp = malloc((posicaoFim - posicaoInicio + 1) * sizeof(aluno)); 
    
    while(i < metadeTamanho + 1 || j  < posicaoFim + 1) {
        if (i == metadeTamanho + 1 ) { 
            vetorTemp[k] = vetor[j];
            j++;
            k++;
        }
        else {
            if (j == posicaoFim + 1) {
                vetorTemp[k] = vetor[i];
                i++;
                k++;
            }
            else {
                if (compararAluno(vetor[i], vetor[j], criterio) == -1) {
                    vetorTemp[k] = vetor[i];
                    i++;
                    k++;
                }
                else {
                    vetorTemp[k] = vetor[j];
                    j++;
                    k++;
                }
            }
        }

    }
    for(i = posicaoInicio; i <= posicaoFim; i++) {
        vetor[i] = vetorTemp[i - posicaoInicio];
    }
    free(vetorTemp);
}

void insertionSort(aluno vetor[], int tamanho, int criterio){ // Opção de oordenação por inserção (insertionSort).
    
    //A cada passo a partir do segundo elemento seleciona o próximo item da sequência e o coloca no local apropriado de acordo com o critério de ordenação.
    
	int i, j;
	aluno key;
	for(i = 1; i< tamanho; i++){
		key = vetor[i];
		j=i-1;
		while(j >=0 && compararAluno(vetor[j], key, criterio) == 1){
			vetor[j+1] = vetor[j];
			j = j-1;
		}
		vetor[j+1] = key;
	}
}


void selectionSort() { //Função de ordenação por selectionSort. 
	int opc = -1; //Opção -1 para que a repetição comece.
	while (opc != 0){ //Para que o menu seja exibido sempre, é utilizado 0 na condição.
		sub_menu_ord(); //Exibe o submenu.
		scanf("%d",&opc); //Aceita o valor da opção desejada. 
		if (opc == 1) { //Se a opção desejada for 1, a ordenação ocorre por nome.
			tipo_ord = 1;
			int i,j,x,auxPront,auxData[2]; //Variáveis tipo int.
	    	char aux[TAMNOME],auxCurso[4]; //Variáveis tipo char.
 			for (i = 0; i < counter;i++){
                for (j = i+1; j < counter; j++){
                    for (x = 0; x < TAMNOME; x++){
                        if (strcmp(alunos[i].nome,alunos[j].nome) > 0){
                        	
                        	//strcmp compara o conteúdo de duas strings.
							//Possíveis valores de retorno:
							//0: conteúdo das strings são iguais;
							//< 0: conteúdo da string1 é menor do que string2;
							//> 0: conteúdo da string1 é maior do que string2.
							
							//Ao ser utilizada, analisa se alunos[i].nome é maior que alunos[j].nome.
							//Se for o caso, há a substituição dos dados e ordenação dos alunos.
                        	
							strcpy(aux,alunos[i].nome); //A variável aux recebe o nome do aluno[i].
	                   		strcpy(alunos[i].nome,alunos[j].nome); //O nome do aluno[i] recebe agora o nome do aluno[j].
	                    	strcpy(alunos[j].nome,aux); //O nome do aluno[j] recebe agora o conteúdo de aux, ou seja, o nome do aluno [i].
                            
                            strcpy(aux,alunos[i].sobrenome); //A variável aux recebe o sobrenome do aluno[i].
	                   		strcpy(alunos[i].sobrenome,alunos[j].sobrenome); //O sobrenome do aluno[i] recebe agora o sobrenome do aluno[j].
	                    	strcpy(alunos[j].sobrenome,aux); //O sobrenome do aluno[j] recebe agora o conteúdo de aux, ou seja, o sobrenome do aluno[i].
	                    	
							strcpy(auxCurso,alunos[i].curso); //A variável auxCurso recebe o curso do aluno[i].
	                   		strcpy(alunos[i].curso,alunos[j].curso); //O curso do aluno[i] recebe agora o curso do aluno[j].
	                    	strcpy(alunos[j].curso,auxCurso); //O curso do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxPront = alunos[i].prontuario; //A variável auxPront recebe o curso do aluno[i].
	                    	alunos[i].prontuario = alunos[j].prontuario; //O prontuário do aluno[i] recebe agora o prontuário do aluno[j].
	                    	alunos[j].prontuario = auxPront; //O prontuário do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxData[0] = alunos[i].datadenascimento.dia; //A variável auxData[0] recebe o dia de nascimento do aluno[i].
							alunos[i].datadenascimento.dia = alunos[j].datadenascimento.dia; //O dia de nascimento do aluno[i] recebe agora o dia de nascimento do aluno[j].
							alunos[j].datadenascimento.dia = auxData[0]; //O dia de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o dia de nascimento do aluno[i].
							
							auxData[1] = alunos[i].datadenascimento.mes; //A variável auxData[1] recebe o mês de nascimento do aluno[i].
							alunos[i].datadenascimento.mes = alunos[j].datadenascimento.mes; //O mês de nascimento do aluno[i] recebe agora o mês de nascimento do aluno[j].
							alunos[j].datadenascimento.mes = auxData[1]; //O mês de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o mês de nascimento do aluno[i].
							
							auxData[2] = alunos[i].datadenascimento.ano; //A variável auxData[2] recebe o ano de nascimento do aluno[i].
							alunos[i].datadenascimento.ano = alunos[j].datadenascimento.ano; //O ano de nascimento do aluno[i] recebe agora o ano de nascimento do aluno[j].
							alunos[j].datadenascimento.ano = auxData[2]; //O ano de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o ano de nascimento do aluno[i].
	    	            }
	        	    }
	        	}
	    	}
	    	printf("Alunos ordenados por nome.\n");
		}
		
		else if (opc == 2){ //Se a opção desejada for 2, a ordenação ocorre por sobrenome.
			tipo_ord = 2;
			int i,j,x,auxPront,auxData[2]; //Variáveis tipo int.
	    	char aux[TAMSOBRENOME],auxCurso[4]; //Variáveis tipo char.
	    	for (i = 0; i < counter;i++){
	        	for (j = i+1; j < counter; j++){
	           		for (x = 0; x < TAMSOBRENOME; x++){
	               		if (strcmp(alunos[i].sobrenome,alunos[j].sobrenome) > 0){
	               			
	               			//strcmp compara o conteúdo de duas strings.
							//Possíveis valores de retorno:
							//0: conteúdo das strings são iguais;
							//< 0: conteúdo da string1 é menor do que string2;
							//> 0: conteúdo da string1 é maior do que string2.
							
							//Ao ser utilizada, analisa se alunos[i].sobrenome é maior que alunos[j].sobrenome.
							//Se for o caso, há a substituição dos dados e ordenação dos alunos.
	               			
	                   		strcpy(aux,alunos[i].nome); //A variável aux recebe o nome do aluno[i].
	                   		strcpy(alunos[i].nome,alunos[j].nome); //O nome do aluno[i] recebe agora o nome do aluno[j].
	                    	strcpy(alunos[j].nome,aux); //O nome do aluno[j] recebe agora o conteúdo de aux, ou seja, o nome do aluno [i].
                            
                            strcpy(aux,alunos[i].sobrenome); //A variável aux recebe o sobrenome do aluno[i].
	                   		strcpy(alunos[i].sobrenome,alunos[j].sobrenome); //O sobrenome do aluno[i] recebe agora o sobrenome do aluno[j].
	                    	strcpy(alunos[j].sobrenome,aux); //O sobrenome do aluno[j] recebe agora o conteúdo de aux, ou seja, o sobrenome do aluno[i].
	                    	
							strcpy(auxCurso,alunos[i].curso); //A variável auxCurso recebe o curso do aluno[i].
	                   		strcpy(alunos[i].curso,alunos[j].curso); //O curso do aluno[i] recebe agora o curso do aluno[j].
	                    	strcpy(alunos[j].curso,auxCurso); //O curso do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxPront = alunos[i].prontuario; //A variável auxPront recebe o curso do aluno[i].
	                    	alunos[i].prontuario = alunos[j].prontuario; //O prontuário do aluno[i] recebe agora o prontuário do aluno[j].
	                    	alunos[j].prontuario = auxPront; //O prontuário do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxData[0] = alunos[i].datadenascimento.dia; //A variável auxData[0] recebe o dia de nascimento do aluno[i].
							alunos[i].datadenascimento.dia = alunos[j].datadenascimento.dia; //O dia de nascimento do aluno[i] recebe agora o dia de nascimento do aluno[j].
							alunos[j].datadenascimento.dia = auxData[0]; //O dia de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o dia de nascimento do aluno[i].
							
							auxData[1] = alunos[i].datadenascimento.mes; //A variável auxData[1] recebe o mês de nascimento do aluno[i].
							alunos[i].datadenascimento.mes = alunos[j].datadenascimento.mes; //O mês de nascimento do aluno[i] recebe agora o mês de nascimento do aluno[j].
							alunos[j].datadenascimento.mes = auxData[1]; //O mês de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o mês de nascimento do aluno[i].
							
							auxData[2] = alunos[i].datadenascimento.ano; //A variável auxData[2] recebe o ano de nascimento do aluno[i].
							alunos[i].datadenascimento.ano = alunos[j].datadenascimento.ano; //O ano de nascimento do aluno[i] recebe agora o ano de nascimento do aluno[j].
							alunos[j].datadenascimento.ano = auxData[2]; //O ano de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o ano de nascimento do aluno[i].
	    	            }
	        	    }
	        	}
	    	}
	    	printf("Alunos ordenados por sobrenome.\n");
		}
		
		else if (opc == 3){ //Se a opção desejada for 3, a ordenação ocorre por prontuário.
			tipo_ord = 3;
			int i,j,auxPront,auxData[4];
	    	char aux[TAMNOME],auxCurso[4];
	    	for (i = 0; i < counter;i++){
	        	for (j = 0; j < counter; j++){
		            if (alunos[i].prontuario < alunos[j].prontuario){ //Se o prontuário do aluno[i] for menor que o prontuário do aluno[j]:
		                strcpy(aux,alunos[i].nome); //A variável aux recebe o nome do aluno[i].
	                   	strcpy(alunos[i].nome,alunos[j].nome); //O nome do aluno[i] recebe agora o nome do aluno[j].
	                    strcpy(alunos[j].nome,aux); //O nome do aluno[j] recebe agora o conteúdo de aux, ou seja, o nome do aluno [i].
                            
                        strcpy(aux,alunos[i].sobrenome); //A variável aux recebe o sobrenome do aluno[i].
	                   	strcpy(alunos[i].sobrenome,alunos[j].sobrenome); //O sobrenome do aluno[i] recebe agora o sobrenome do aluno[j].
	                    strcpy(alunos[j].sobrenome,aux); //O sobrenome do aluno[j] recebe agora o conteúdo de aux, ou seja, o sobrenome do aluno[i].
	                    	
						strcpy(auxCurso,alunos[i].curso); //A variável auxCurso recebe o curso do aluno[i].
	                   	strcpy(alunos[i].curso,alunos[j].curso); //O curso do aluno[i] recebe agora o curso do aluno[j].
	                    strcpy(alunos[j].curso,auxCurso); //O curso do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
						auxPront = alunos[i].prontuario; //A variável auxPront recebe o curso do aluno[i].
	                    alunos[i].prontuario = alunos[j].prontuario; //O prontuário do aluno[i] recebe agora o prontuário do aluno[j].
	                    alunos[j].prontuario = auxPront; //O prontuário do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
						auxData[0] = alunos[i].datadenascimento.dia; //A variável auxData[0] recebe o dia de nascimento do aluno[i].
						alunos[i].datadenascimento.dia = alunos[j].datadenascimento.dia; //O dia de nascimento do aluno[i] recebe agora o dia de nascimento do aluno[j].
						alunos[j].datadenascimento.dia = auxData[0]; //O dia de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o dia de nascimento do aluno[i].
							
						auxData[1] = alunos[i].datadenascimento.mes; //A variável auxData[1] recebe o mês de nascimento do aluno[i].
						alunos[i].datadenascimento.mes = alunos[j].datadenascimento.mes; //O mês de nascimento do aluno[i] recebe agora o mês de nascimento do aluno[j].
						alunos[j].datadenascimento.mes = auxData[1]; //O mês de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o mês de nascimento do aluno[i].
							
						auxData[2] = alunos[i].datadenascimento.ano; //A variável auxData[2] recebe o ano de nascimento do aluno[i].
						alunos[i].datadenascimento.ano = alunos[j].datadenascimento.ano; //O ano de nascimento do aluno[i] recebe agora o ano de nascimento do aluno[j].
						alunos[j].datadenascimento.ano = auxData[2]; //O ano de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o ano de nascimento do aluno[i].
	    	        }
	        	}
	    	}
	    	printf("Alunos ordenados por prontuario.\n");
		}
		
		else if (opc == 4){ //Se a opção desejada for 4, a ordenação ocorre por curso.
			tipo_ord = 4;
			int i,j,x,auxPront,auxData[2];
	    	char aux[TAMNOME],auxCurso[4];
	    	for (i = 0; i < counter;i++){
	        	for (j = 0; j < counter; j++){
	           		for (x = 0; x < 4; x++){
	               		if (strcmp(alunos[i].curso,alunos[j].curso) < 0){
	               			
	               			//strcmp compara o conteúdo de duas strings.
							//Possíveis valores de retorno:
							//0: conteúdo das strings são iguais;
							//< 0: conteúdo da string1 é menor do que string2;
							//> 0: conteúdo da string1 é maior do que string2.
							
							//Ao ser utilizada, analisa se alunos[i].curso é menor que alunos[j].curso.
							//Se for o caso, há a substituição dos dados e ordenação dos alunos.
	               			
	                   		strcpy(aux,alunos[i].nome); //A variável aux recebe o nome do aluno[i].
	                   		strcpy(alunos[i].nome,alunos[j].nome); //O nome do aluno[i] recebe agora o nome do aluno[j].
	                    	strcpy(alunos[j].nome,aux); //O nome do aluno[j] recebe agora o conteúdo de aux, ou seja, o nome do aluno [i].
                            
                            strcpy(aux,alunos[i].sobrenome); //A variável aux recebe o sobrenome do aluno[i].
	                   		strcpy(alunos[i].sobrenome,alunos[j].sobrenome); //O sobrenome do aluno[i] recebe agora o sobrenome do aluno[j].
	                    	strcpy(alunos[j].sobrenome,aux); //O sobrenome do aluno[j] recebe agora o conteúdo de aux, ou seja, o sobrenome do aluno[i].
	                    	
							strcpy(auxCurso,alunos[i].curso); //A variável auxCurso recebe o curso do aluno[i].
	                   		strcpy(alunos[i].curso,alunos[j].curso); //O curso do aluno[i] recebe agora o curso do aluno[j].
	                    	strcpy(alunos[j].curso,auxCurso); //O curso do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxPront = alunos[i].prontuario; //A variável auxPront recebe o curso do aluno[i].
	                    	alunos[i].prontuario = alunos[j].prontuario; //O prontuário do aluno[i] recebe agora o prontuário do aluno[j].
	                    	alunos[j].prontuario = auxPront; //O prontuário do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxData[0] = alunos[i].datadenascimento.dia; //A variável auxData[0] recebe o dia de nascimento do aluno[i].
							alunos[i].datadenascimento.dia = alunos[j].datadenascimento.dia; //O dia de nascimento do aluno[i] recebe agora o dia de nascimento do aluno[j].
							alunos[j].datadenascimento.dia = auxData[0]; //O dia de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o dia de nascimento do aluno[i].
							
							auxData[1] = alunos[i].datadenascimento.mes; //A variável auxData[1] recebe o mês de nascimento do aluno[i].
							alunos[i].datadenascimento.mes = alunos[j].datadenascimento.mes; //O mês de nascimento do aluno[i] recebe agora o mês de nascimento do aluno[j].
							alunos[j].datadenascimento.mes = auxData[1]; //O mês de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o mês de nascimento do aluno[i].
							
							auxData[2] = alunos[i].datadenascimento.ano; //A variável auxData[2] recebe o ano de nascimento do aluno[i].
							alunos[i].datadenascimento.ano = alunos[j].datadenascimento.ano; //O ano de nascimento do aluno[i] recebe agora o ano de nascimento do aluno[j].
							alunos[j].datadenascimento.ano = auxData[2]; //O ano de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o ano de nascimento do aluno[i].
	    	            }
	        	    }
	        	}
	    	}
	    	printf("Alunos ordenados por curso.\n");
		}
		
		else if (opc == 5){ //Se a opção desejada for 5, a ordenação ocorre por data de nascimento.
			tipo_ord = 5;
			int i,j,auxPront,auxData[4];
	    	char aux[TAMNOME],auxCurso[4];
	    	for (i = 0; i < counter;i++){
	        	for (j = 0; j < counter; j++){
		            if (alunos[i].datadenascimento.ano < alunos[j].datadenascimento.ano){
		            	
		            	//Se o ano de nascimento do aluno[i] for menor que o do aluno[j], há a substituição dos dados e ordenação dos alunos.
		            	
		            	strcpy(aux,alunos[i].nome); //A variável aux recebe o nome do aluno[i].
	                   	strcpy(alunos[i].nome,alunos[j].nome); //O nome do aluno[i] recebe agora o nome do aluno[j].
	                    strcpy(alunos[j].nome,aux); //O nome do aluno[j] recebe agora o conteúdo de aux, ou seja, o nome do aluno [i].
                            
                        strcpy(aux,alunos[i].sobrenome); //A variável aux recebe o sobrenome do aluno[i].
	                   	strcpy(alunos[i].sobrenome,alunos[j].sobrenome); //O sobrenome do aluno[i] recebe agora o sobrenome do aluno[j].
	                    strcpy(alunos[j].sobrenome,aux); //O sobrenome do aluno[j] recebe agora o conteúdo de aux, ou seja, o sobrenome do aluno[i].
	                    	
						strcpy(auxCurso,alunos[i].curso); //A variável auxCurso recebe o curso do aluno[i].
	                	strcpy(alunos[i].curso,alunos[j].curso); //O curso do aluno[i] recebe agora o curso do aluno[j].
	                   	strcpy(alunos[j].curso,auxCurso); //O curso do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
						auxPront = alunos[i].prontuario; //A variável auxPront recebe o curso do aluno[i].
	                    alunos[i].prontuario = alunos[j].prontuario; //O prontuário do aluno[i] recebe agora o prontuário do aluno[j].
	                    alunos[j].prontuario = auxPront; //O prontuário do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
						auxData[0] = alunos[i].datadenascimento.dia; //A variável auxData[0] recebe o dia de nascimento do aluno[i].
						alunos[i].datadenascimento.dia = alunos[j].datadenascimento.dia; //O dia de nascimento do aluno[i] recebe agora o dia de nascimento do aluno[j].
						alunos[j].datadenascimento.dia = auxData[0]; //O dia de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o dia de nascimento do aluno[i].
							
						auxData[1] = alunos[i].datadenascimento.mes; //A variável auxData[1] recebe o mês de nascimento do aluno[i].
						alunos[i].datadenascimento.mes = alunos[j].datadenascimento.mes; //O mês de nascimento do aluno[i] recebe agora o mês de nascimento do aluno[j].
						alunos[j].datadenascimento.mes = auxData[1]; //O mês de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o mês de nascimento do aluno[i].
							
						auxData[2] = alunos[i].datadenascimento.ano; //A variável auxData[2] recebe o ano de nascimento do aluno[i].
						alunos[i].datadenascimento.ano = alunos[j].datadenascimento.ano; //O ano de nascimento do aluno[i] recebe agora o ano de nascimento do aluno[j].
						alunos[j].datadenascimento.ano = auxData[2]; //O ano de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o ano de nascimento do aluno[i].
	    	        }
	    	        else if (alunos[i].datadenascimento.ano == alunos[j].datadenascimento.ano){
	    	        	if (alunos[i].datadenascimento.mes < alunos[j].datadenascimento.mes){
	    	        		
			            	//Caso o ano de nascimento do aluno[i] seja igual ao do aluno[j], a strcpy compara os valores dos meses.
							//Se o mês de nascimento do aluno[i] for menor que o do aluno[j], há a substituição dos dados e ordenação dos alunos.
	    	        		
	    	        		strcpy(aux,alunos[i].nome); //A variável aux recebe o nome do aluno[i].
	                   		strcpy(alunos[i].nome,alunos[j].nome); //O nome do aluno[i] recebe agora o nome do aluno[j].
	                    	strcpy(alunos[j].nome,aux); //O nome do aluno[j] recebe agora o conteúdo de aux, ou seja, o nome do aluno [i].
                            
                            strcpy(aux,alunos[i].sobrenome); //A variável aux recebe o sobrenome do aluno[i].
	                   		strcpy(alunos[i].sobrenome,alunos[j].sobrenome); //O sobrenome do aluno[i] recebe agora o sobrenome do aluno[j].
	                    	strcpy(alunos[j].sobrenome,aux); //O sobrenome do aluno[j] recebe agora o conteúdo de aux, ou seja, o sobrenome do aluno[i].
	                    	
							strcpy(auxCurso,alunos[i].curso); //A variável auxCurso recebe o curso do aluno[i].
	                   		strcpy(alunos[i].curso,alunos[j].curso); //O curso do aluno[i] recebe agora o curso do aluno[j].
	                    	strcpy(alunos[j].curso,auxCurso); //O curso do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxPront = alunos[i].prontuario; //A variável auxPront recebe o curso do aluno[i].
	                    	alunos[i].prontuario = alunos[j].prontuario; //O prontuário do aluno[i] recebe agora o prontuário do aluno[j].
	                    	alunos[j].prontuario = auxPront; //O prontuário do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
							auxData[0] = alunos[i].datadenascimento.dia; //A variável auxData[0] recebe o dia de nascimento do aluno[i].
							alunos[i].datadenascimento.dia = alunos[j].datadenascimento.dia; //O dia de nascimento do aluno[i] recebe agora o dia de nascimento do aluno[j].
							alunos[j].datadenascimento.dia = auxData[0]; //O dia de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o dia de nascimento do aluno[i].
							
							auxData[1] = alunos[i].datadenascimento.mes; //A variável auxData[1] recebe o mês de nascimento do aluno[i].
							alunos[i].datadenascimento.mes = alunos[j].datadenascimento.mes; //O mês de nascimento do aluno[i] recebe agora o mês de nascimento do aluno[j].
							alunos[j].datadenascimento.mes = auxData[1]; //O mês de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o mês de nascimento do aluno[i].
							
							auxData[2] = alunos[i].datadenascimento.ano; //A variável auxData[2] recebe o ano de nascimento do aluno[i].
							alunos[i].datadenascimento.ano = alunos[j].datadenascimento.ano; //O ano de nascimento do aluno[i] recebe agora o ano de nascimento do aluno[j].
							alunos[j].datadenascimento.ano = auxData[2]; //O ano de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o ano de nascimento do aluno[i].
						}
						else if (alunos[i].datadenascimento.mes == alunos[j].datadenascimento.mes){
							if (alunos[i].datadenascimento.dia < alunos[j].datadenascimento.dia){
								
								//Caso o mês de nascimento do aluno[i] seja igual ao do aluno[j], a strcpy compara os valores dos dias.
								//Se o dia de nascimento do aluno[i] for menor que o do aluno[j], há a substituição dos dados e ordenação dos alunos.
								
								strcpy(aux,alunos[i].nome); //A variável aux recebe o nome do aluno[i].
	                   			strcpy(alunos[i].nome,alunos[j].nome); //O nome do aluno[i] recebe agora o nome do aluno[j].
	                    		strcpy(alunos[j].nome,aux); //O nome do aluno[j] recebe agora o conteúdo de aux, ou seja, o nome do aluno [i].
                            
                           	 	strcpy(aux,alunos[i].sobrenome); //A variável aux recebe o sobrenome do aluno[i].
	                   			strcpy(alunos[i].sobrenome,alunos[j].sobrenome); //O sobrenome do aluno[i] recebe agora o sobrenome do aluno[j].
	                    		strcpy(alunos[j].sobrenome,aux); //O sobrenome do aluno[j] recebe agora o conteúdo de aux, ou seja, o sobrenome do aluno[i].
	                    	
								strcpy(auxCurso,alunos[i].curso); //A variável auxCurso recebe o curso do aluno[i].
	                   			strcpy(alunos[i].curso,alunos[j].curso); //O curso do aluno[i] recebe agora o curso do aluno[j].
	                    		strcpy(alunos[j].curso,auxCurso); //O curso do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
								auxPront = alunos[i].prontuario; //A variável auxPront recebe o curso do aluno[i].
	                    		alunos[i].prontuario = alunos[j].prontuario; //O prontuário do aluno[i] recebe agora o prontuário do aluno[j].
	                    		alunos[j].prontuario = auxPront; //O prontuário do aluno[j] recebe agora o conteúdo de aux, ou seja, o curso do aluno[i].
	                    	
								auxData[0] = alunos[i].datadenascimento.dia; //A variável auxData[0] recebe o dia de nascimento do aluno[i].
								alunos[i].datadenascimento.dia = alunos[j].datadenascimento.dia; //O dia de nascimento do aluno[i] recebe agora o dia de nascimento do aluno[j].
								alunos[j].datadenascimento.dia = auxData[0]; //O dia de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o dia de nascimento do aluno[i].
							
								auxData[1] = alunos[i].datadenascimento.mes; //A variável auxData[1] recebe o mês de nascimento do aluno[i].
								alunos[i].datadenascimento.mes = alunos[j].datadenascimento.mes; //O mês de nascimento do aluno[i] recebe agora o mês de nascimento do aluno[j].
								alunos[j].datadenascimento.mes = auxData[1]; //O mês de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o mês de nascimento do aluno[i].
							
								auxData[2] = alunos[i].datadenascimento.ano; //A variável auxData[2] recebe o ano de nascimento do aluno[i].
								alunos[i].datadenascimento.ano = alunos[j].datadenascimento.ano; //O ano de nascimento do aluno[i] recebe agora o ano de nascimento do aluno[j].
								alunos[j].datadenascimento.ano = auxData[2]; //O ano de nascimento do aluno[j] recebe agora o conteúdo de aux, ou seja, o ano de nascimento do aluno[i].
							}
						}
					}
	        	}
	    	}
	    	printf("Alunos ordenados por data de nascimento.\n");
		}
	}	
}

void ordenar(){ //Função de ordenação.
	int tipo = -1;
	while (tipo !=0){
		tipo_de_ord();
		scanf("%d",&tipo);
		if (tipo == 1){ //Por quickSort.
			int criterio = -1;
			while(criterio != 0){
				sub_menu_ord();
				scanf("%d", &criterio); //Por critério.
				if(criterio == 1){
					quickSort(alunos, 0, (counter-1), 1);
				}
				else if(criterio == 2){
					quickSort(alunos, 0, (counter-1), 2);
				}
				else if(criterio == 3){
					quickSort(alunos, 0, (counter-1), 3);
				}
				else if(criterio == 4){
					quickSort(alunos, 0, (counter-1), 4);
				}
				else if(criterio == 5){
					quickSort(alunos, 0, (counter-1), 5);
				}	
			}
		}
		else if(tipo == 2){ //Por mergeSort.
			int criterio = -1;
			while(criterio != 0){
				sub_menu_ord();
				scanf("%d", &criterio); //Por critério.
				if(criterio == 1){
					mergeSort(alunos, 0, (counter-1), 1);
				}
				else if(criterio == 2){
					mergeSort(alunos, 0, (counter-1), 2);
				}
				else if(criterio == 3){
					mergeSort(alunos, 0, (counter-1), 3);
				}
				else if(criterio == 4){
					mergeSort(alunos, 0, (counter-1), 4);
				}
				else if(criterio == 5){
					mergeSort(alunos, 0, (counter-1), 5);
				}	
			}
		}
		else if(tipo == 3){ //Por insertionSort.
			insertionSort(alunos, counter, 1);
			int criterio = -1;
			while(criterio != 0){
				sub_menu_ord();
				scanf("%d", &criterio); //Por critério.
				if(criterio == 1){
					insertionSort(alunos, counter, 1);
				}
				else if(criterio == 2){
					insertionSort(alunos, counter, 2);
				}
				else if(criterio == 3){
					insertionSort(alunos, counter, 3);
				}
				else if(criterio == 4){
					insertionSort(alunos, counter, 4);
				}
				else if(criterio == 5){
					insertionSort(alunos, counter, 5);
				}	
			}
		}
		else if(tipo == 4){ //Por selectionSort.
			selectionSort();
		}
	}
}

void gravarArquivo(){ //Função de gravação dos cadastros em arquivo.
	FILE *arq;
	int i, result;
	arq = fopen("arquivo.txt", "w"); //Abre arquivo .txt para escrita.
	if (arq == NULL){
		printf("Não foi possível abrir.");
		return;
	}
	for(i=0; i<counter; i++){ //Grava os cadastros dos alunos um por um.
		fprintf(arq, "%s%s%d\n%s\n%d\n%d\n%d\n", alunos[i].nome, alunos[i].sobrenome, alunos[i].prontuario, alunos[i].curso, alunos[i].datadenascimento.dia,alunos[i].datadenascimento.mes,alunos[i].datadenascimento.ano);
	}
	fclose(arq); //Fecha o arquivo.
}

int lerArquivo(void){ //Função de leitura dos cadastros em arquivo.
    int i = 0, j, a;
    char line[50];
    aluno x;

    FILE *arquivo;
    arquivo = fopen("arquivo.txt", "r"); //Abre arquivo .txt para leitura.

    while(fgets(line, sizeof line, arquivo) != NULL){ //Enquanto houver dados:
    	if(i == 0){
    		strcpy(x.nome,strdup(line));
		}else if(i == 1){ 
			strcpy(x.sobrenome,strdup(line));
		}else if (i == 2){
			x.prontuario = atoi(strdup(line));
		}else if(i == 3){
			strcpy(x.curso,strdup(line));
			
		}else if(i==4){
			x.datadenascimento.dia = atoi(strdup(line));
		}else if (i == 5){
			x.datadenascimento.mes = atoi(strdup(line));
		}else if (i==6){
			x.datadenascimento.ano = atoi(strdup(line));
			alunos[counter] = x;
			counter++;
			i = -1;
		}
        
        i++; //Para imprimir os dados dos alunos de forma ordenada e indicar início de outro cadastro.
    }
    

    fclose(arquivo); //Fecha o arquivo.

}


int main() { //Menu com suas respectivas funções.
    int m = -1;
    while(m != 0) {
        menu(); //Exibe menu principal.
        printf("Escolha uma opcao: ");
        scanf("%d", &m); //Aceita o valor da opção desejada.
        if (m == 1){ //Opção 1.
            cadastrar_aluno(); //Função de cadastro de alunos. Abre o submenu com as informações a serem preenchidas.
        }
        else if (m == 2){ //Opção 2.
            imprimir_aluno(); //Função de exibição de cadastros.
        }
        else if (m == 3){ //Opção 3.
            buscar_aluno(); //Função de busca. Abre o submenu com as opções de critérios.
        }
        else if (m == 4){ //Opção 4.
        	ordenar(); //Função de ordenação. Abre o submenu com as opções de critérios.
		}
		else if (m == 5){ //Opção 5.
			gravarArquivo(); //Função de gravação dos dados no arquivo.
		}
		else if (m == 6){ //Opção 6.
			lerArquivo(); //Função de leitura dos dados no arquivo.
		}
    }
}	
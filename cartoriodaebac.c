#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca das strings



int registro()//Função responsável para cadastrar os usuários no sistema.
{
	//inicio da criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da criação de variáveis/string
	
	printf("Por favor, digite seu CPF para ser registrado: ");//Variável da CPF(junto da explicação de como funciona os arquivos
	scanf("%s", cpf);//%s refere-se as strings, o "scanf" serve pra scanear as strings dentro da função do CPF
	
	strcpy(arquivo, cpf); //responsável por copiar o valor das STRINGS
	
	FILE *file; //Criação do arquivo no banco de dados
	file = fopen(arquivo, "w"); //Criação do arquivo no banco de dados
	fprintf(file,cpf); //salva valor da variável
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a");//atualizar o arquivo criado pra separar as informações com uma virgula
	fprintf(file,",");//atualizar o arquivo criado pra separar as informações com uma virgula
	fclose(file);//fecha arquivo
	
	printf("Agora digite o nome desejado para ser registrado: ");//Variável do nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo criado
	fprintf(file,nome);//armazena os dados digitados no arquivo criado
	fclose(file);//fecha o arquivo criado
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo criado
	fprintf(file,",");//adiciona a separação entre vírgulas no arquivo criado pra distinguir dados dentro do arquivo.
	fclose(file);//fecha o arquivo criado
	
	printf("Digite o sobrenome a ser registrado: ");//Variável do sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo
	fprintf(file,sobrenome);//adiciona o sobrenome nos dados do cadastro do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo
	fprintf(file,",");//adiciona vírgula para a separação dos dados no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite a profissão/cargo a ser registrado: ");//Variável do cargo/profissão
	scanf ("%s",cargo);//escaneia a string correspodente no arquivo criado
	
	file = fopen(arquivo, "a");//abre o arquivo e atualiza
	fprintf(file,cargo);//adiciona o cargo ao arquivo junto ao resto dos dados fornecidos pelo usuário
	fclose(file);// fecha o arquivo

    system("pause");//termina o cadastro
	
}


int consulta()//Função da consulta
{
	setlocale(LC_ALL, "Portuguese");//Pros acentos do PTBR funcionarem
    char cpf[40];//String do CPF no arquivo
    char conteudo[200];//String pra poder dar resultado da consulta
    
    printf("Por favor, digite o CPF que do usuário que deseja consultar: ");	
    scanf("%s",cpf);//escanear a string específica digitada pelo usuário no arquivo(o cpf)
    system("cls");
    
    FILE *file;//abrir o arquivo
    file = fopen(cpf,"r");//ler o arquivo e identificar o cpf
    
    if(file == NULL)//caso não encontre o usuário
    {
    	printf("O usuário não foi encontrado.\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)//Enquanto o código pega as informações para o conteúdo no arquivo, caso ele não encontre nada ele para o processo.
    {
    	printf("Essas são as informações consultadas: ");//conclusão das informações mostrando para o usuário na CMD
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    
    system("pause");
    
}



int deletar()//Função de deletar usuário
{
    char cpf[40];//String para o CPF
    
    printf("Digite o CPF do usuário que você deseja deletar: ");
    scanf("%s", cpf);//escanear o CPF no arquivo visando as strings
    
    remove(cpf);//remover o CPF do banco de dados
    
    FILE *file;//abrir o arquivo
    file = fopen(cpf,"r");//abrir e ler o arquivo em busca do CPF
    
    if(file == NULL)//caso não seja encontrado o CPF solicitado
    {
    	system("cls");
    	printf("O usuário inserido não se encontra no sistema.\n");
    	system("pause");
	}
    else//caso seja encontrado
	{
        printf("O usuário foi apagado com sucesso!\n");
        system("pause");    
	}
	
	fclose(file);
	
}


int main()//Função main
{
	int opcao=0;//Definindo variáveis
	int laco=1;//Variável pra repetição do laço
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	    printf("\t### Cartório da EBAC ###\n");//Início do menu
	    printf("[Este Software é de livre uso, fornecido e desenvolvido por e para os alunos.]\n\n");
	    printf("Por favor, escolha a opção desejada abaixo: \n\n");
	    printf("\t1 - Registrar nome(s).\n");
	    printf("\t2 - Consultar nome(s).\n");
	    printf("\t3 - Deletar nome(s). \n\n");
		printf("Digite a opção desejada: ");//Final do menu
	
	scanf("%d", &opcao);//armazenamento de dados do usuário
	
	system("cls");//responsável por limpar a tela
	
    switch(opcao)//Seleção de opções do menu/ida e volta para a tela inicial caso opção inválida.
    {
    	case 1:
        registro();//responsável por chamar as funções
        break;
        
        case 2:
        consulta();
        break;
        
        case 3:
        deletar();
        break;  
        
        default://caso o usuário escolha uma opção inexistente
        printf("Selecione uma opção válida!\n");
        system("pause");
        break;
	}
	}
}


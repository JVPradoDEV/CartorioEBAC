#include <stdio.h> //biblioteca de comunica��o com o usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca das strings



int registro()//Fun��o respons�vel para cadastrar os usu�rios no sistema.
{
	//inicio da cria��o de vari�veis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//fim da cria��o de vari�veis/string
	
	printf("Por favor, digite seu CPF para ser registrado: ");//Vari�vel da CPF(junto da explica��o de como funciona os arquivos
	scanf("%s", cpf);//%s refere-se as strings, o "scanf" serve pra scanear as strings dentro da fun��o do CPF
	
	strcpy(arquivo, cpf); //respons�vel por copiar o valor das STRINGS
	
	FILE *file; //Cria��o do arquivo no banco de dados
	file = fopen(arquivo, "w"); //Cria��o do arquivo no banco de dados
	fprintf(file,cpf); //salva valor da vari�vel
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a");//atualizar o arquivo criado pra separar as informa��es com uma virgula
	fprintf(file,",");//atualizar o arquivo criado pra separar as informa��es com uma virgula
	fclose(file);//fecha arquivo
	
	printf("Agora digite o nome desejado para ser registrado: ");//Vari�vel do nome
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo criado
	fprintf(file,nome);//armazena os dados digitados no arquivo criado
	fclose(file);//fecha o arquivo criado
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo criado
	fprintf(file,",");//adiciona a separa��o entre v�rgulas no arquivo criado pra distinguir dados dentro do arquivo.
	fclose(file);//fecha o arquivo criado
	
	printf("Digite o sobrenome a ser registrado: ");//Vari�vel do sobrenome
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo
	fprintf(file,sobrenome);//adiciona o sobrenome nos dados do cadastro do arquivo
	fclose(file);//fecha o arquivo
	
	file = fopen(arquivo, "a");//abre e atualiza o arquivo
	fprintf(file,",");//adiciona v�rgula para a separa��o dos dados no arquivo
	fclose(file);//fecha o arquivo
	
	printf("Digite a profiss�o/cargo a ser registrado: ");//Vari�vel do cargo/profiss�o
	scanf ("%s",cargo);//escaneia a string correspodente no arquivo criado
	
	file = fopen(arquivo, "a");//abre o arquivo e atualiza
	fprintf(file,cargo);//adiciona o cargo ao arquivo junto ao resto dos dados fornecidos pelo usu�rio
	fclose(file);// fecha o arquivo

    system("pause");//termina o cadastro
	
}


int consulta()//Fun��o da consulta
{
	setlocale(LC_ALL, "Portuguese");//Pros acentos do PTBR funcionarem
    char cpf[40];//String do CPF no arquivo
    char conteudo[200];//String pra poder dar resultado da consulta
    
    printf("Por favor, digite o CPF que do usu�rio que deseja consultar: ");	
    scanf("%s",cpf);//escanear a string espec�fica digitada pelo usu�rio no arquivo(o cpf)
    system("cls");
    
    FILE *file;//abrir o arquivo
    file = fopen(cpf,"r");//ler o arquivo e identificar o cpf
    
    if(file == NULL)//caso n�o encontre o usu�rio
    {
    	printf("O usu�rio n�o foi encontrado.\n");
	}
    
    while(fgets(conteudo, 200, file) != NULL)//Enquanto o c�digo pega as informa��es para o conte�do no arquivo, caso ele n�o encontre nada ele para o processo.
    {
    	printf("Essas s�o as informa��es consultadas: ");//conclus�o das informa��es mostrando para o usu�rio na CMD
    	printf("%s", conteudo);
    	printf("\n\n");
	}
    
    system("pause");
    
}



int deletar()//Fun��o de deletar usu�rio
{
    char cpf[40];//String para o CPF
    
    printf("Digite o CPF do usu�rio que voc� deseja deletar: ");
    scanf("%s", cpf);//escanear o CPF no arquivo visando as strings
    
    remove(cpf);//remover o CPF do banco de dados
    
    FILE *file;//abrir o arquivo
    file = fopen(cpf,"r");//abrir e ler o arquivo em busca do CPF
    
    if(file == NULL)//caso n�o seja encontrado o CPF solicitado
    {
    	system("cls");
    	printf("O usu�rio inserido n�o se encontra no sistema.\n");
    	system("pause");
	}
    else//caso seja encontrado
	{
        printf("O usu�rio foi apagado com sucesso!\n");
        system("pause");    
	}
	
	fclose(file);
	
}


int main()//Fun��o main
{
	int opcao=0;//Definindo vari�veis
	int laco=1;//Vari�vel pra repeti��o do la�o
	
	for(laco=1;laco=1;)
	{
	    system("cls");
	    
	    setlocale(LC_ALL, "Portuguese");//Definindo linguagem
	
	    printf("\t### Cart�rio da EBAC ###\n");//In�cio do menu
	    printf("[Este Software � de livre uso, fornecido e desenvolvido por e para os alunos.]\n\n");
	    printf("Por favor, escolha a op��o desejada abaixo: \n\n");
	    printf("\t1 - Registrar nome(s).\n");
	    printf("\t2 - Consultar nome(s).\n");
	    printf("\t3 - Deletar nome(s). \n\n");
		printf("Digite a op��o desejada: ");//Final do menu
	
	scanf("%d", &opcao);//armazenamento de dados do usu�rio
	
	system("cls");//respons�vel por limpar a tela
	
    switch(opcao)//Sele��o de op��es do menu/ida e volta para a tela inicial caso op��o inv�lida.
    {
    	case 1:
        registro();//respons�vel por chamar as fun��es
        break;
        
        case 2:
        consulta();
        break;
        
        case 3:
        deletar();
        break;  
        
        default://caso o usu�rio escolha uma op��o inexistente
        printf("Selecione uma op��o v�lida!\n");
        system("pause");
        break;
	}
	}
}


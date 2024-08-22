#include <stdio.h> //Biblioteca de comunicação com usuario
#include <stdlib.h> //Biblioteca de alocação de espaco em memoria
#include <locale.h> //Blibioteca de alocação de texto por regiao
#include <string.h>//Biblioteca para strings


int registro()//Funcao de registro de nomes
{
	//inicio das variaveis/string
	char arquivo[40];//definicao de variavel chamado arquivo
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final das variaveis/string
	
	printf("Digite o CPF a ser cadastrado: ");
	scanf("%s", cpf);//"%s" = string ; esssa linha scaneia o numero digitado pelo usuario e atribui a variavel 'cpf'
	
	strcpy(arquivo, cpf);//copia o valor atribuido ao variavel 'cpf' para o variavel 'arquivo'
	
	FILE *file; //cria arquivo
	file = fopen(arquivo, "w"); //cria ( "w" ) e nomeia o arquivo criado com o numero cpf registrado pelo usuario
	fprintf(file, cpf); //escreve dentro do arquivo o numero 'cpf' definido pelo usuario 
	fprintf(file, ", ");
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s", nome);
	
	file = fopen(arquivo, "a");//abre o item com o mesmo nome/valor de 'arquivo' e atualiza ( "a" ) as informacoes dele;
	fprintf(file, nome);//coloca dentro do arquivo o valor da variavel 'nome', previamente digitado pelo usuario.
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file, sobrenome);
	fprintf(file, ", ");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fprintf(file, ".");
	fclose (file);
	
	system("pause");
}

int consulta()//inicio da funcao da consulta de nomes
{
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");// "r" = read. nesse caso ele vai ler o conteudo interno do arquivo cujo o nome e igual a variavel 'cpf'.
	
	if(file == NULL)//NULL ocorre quando o usuario digita um cpf que nao existe no cadastro, ou seja, no qual a pasta com o valor de 'cpf' digitado nao existe.
	{
		printf("Arquivo não localizado\n");
	}
	
	while(fgets(conteudo, 200, file) !=NULL)//se o programa localizar algum arquivo.fgets vai salvar os dados do arquivo 'file' na variavel 'conteudo', fazendo isso ate 200 caracteres (tamanho da string).
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s",conteudo);
		printf("\n\n");
	}
	
	system("pause");
}//fim da funcao da consulta de nomes

int deletar()//inicio das funcoes de deletar nomes
{
	char cpf[20];
	
	printf("Digite o CPF de usuário a ser deletado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf, "r");
	
	if(file == NULL)
	{
		printf("Usário não encontrado.\n");
		system("pause");
	}
	else
	{
		printf("Usário deletado com sucesso.\n");
		system("pause");
	}
	
	fclose(file);
	
	remove(cpf);//deleta o arquivo inteiro com o nome = variavel 'cpf' digitado pelo usuario	
}//fim das funcoes de deletar nomes

int main()
{
	int opcao=0;//Variável utilizada para a seleção por parte do usuário.
	int fixo=1;//Variável de valor imutável
	
	setlocale(LC_ALL,"Portuguese");//Definição de idioma.
	
	
	for(fixo=1;fixo=1;)//Inicio de ciclo do menu (o programa volta a pagina inicial apos uso).
	{
		system("cls");//limpa a tela.
		
		printf("### Cartório da EBAC ###\n\n");//Ínicio do texto do menu.
		printf("Escolha a opção que deseja no menu: \n");
		printf("\t1 - Registrar nomes. \n");
		printf("\t2 - Consultar nomes. \n");
		printf("\t3 - Deletar nomes. \n");
		printf("\t4 - Sair do sistema. \n");
		printf("Opção:");//Fim do texto do menu.
		
		scanf("%d", &opcao);//Faz com que a escolha do usuário substitua o valor da variável.
		
		system("cls");
		
		switch(opcao)//Ínicio das funcões de seleção de menu.
		{
			case 1:
			registro();
			break;
			
			case 2:
			consulta();
			break;
			
			case 3:
			deletar();
			break;
			
			case 4:
			printf("Obrigado por utilizar o sistema! \n");
			return 0;
			break;
			
			default: 
			printf("Essa opção não está disponivel. \n");
			system("pause");
			break;
		}//Fim das funcões de seleção de menu.
	}//Inicio de ciclo de funcionamento do menu:
}

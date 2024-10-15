#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <string.h>


int registro()
{
    char arquivo[40];
    char cpf[40];
    char nome[40];
    char sobrenome[40];
    char cargo[40];
    
    printf("Digite o CPF a ser registrado: ");
    scanf("%s", cpf);
    
    strcpy(arquivo, cpf);
    
    FILE *file;
    file = fopen(arquivo, "w");
    fprintf(file,cpf);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o nome a ser registrado: ");
    scanf("%s", nome);
    
    file = fopen(arquivo, "a");
    fprintf(file,nome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
	
	printf("Digite o sobrenome a ser registrado: ");
    scanf("%s", sobrenome);    

    file = fopen(arquivo, "a");
    fprintf(file,sobrenome);
    fclose(file);
    
    file = fopen(arquivo, "a");
    fprintf(file,",");
    fclose(file);
    
    printf("Digite o cargo a ser registrado: ");
    scanf("%s", cargo);    

    file = fopen(arquivo, "a");
    fprintf(file,cargo);
    fclose(file);

	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser consultado: ");
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível localizar o CPF\n\n");
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações  do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");
	}
		
	system("pause");
	fclose(file);
}


int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF do usuário a ser deletado: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	
	if(file == NULL)
	{
		printf("usuário não encontrado\n");
		system("pause");
	}
	
    
}

int main()
{
   int opcao=0;
   int x=1;
   
   for(x=1;x=1;)
   {
     system("cls");
		
     setlocale(LC_ALL, "Portuguese");
   
     printf("\t****Cartório da EBAC**** \n\n");
     printf("Escolha sua opção abaixo: \n\n");
     printf("\t[1] - Registrar os nomes\n");
     printf("\t[2] - Consultar os nomes\n");
     printf("\t[3] - Deletar os nomes\n\n");
     printf("Software de uso livre entre alunos\n\n\n");
   
     scanf("%d", &opcao);
   
     system("cls");
     
     switch(opcao)
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
		
		default:
     	printf("Opção inválida\n\n");
		system("pause");
		break;			
	 }
     
}
} 

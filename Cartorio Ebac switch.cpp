#include <stdio.h> //biblioteca de comunicação com usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocação de texto por região
#include <string.h> //biblioteca responsável pela string
//Funções 
int registro ()
    {
	
	printf("Você escolheu o registro de nomes!\n");
    printf("Deseja continuar?\n");
    printf("\t1 - Sim!\n");
    printf("\t2 - Não!\n");
    printf("Opção: "); //Fim do menu
	
    int escolha=2;
    scanf("%d", &escolha); //Armazenamento da escolha do usuário
    system("cls");
	
        if   (escolha==1) //Inicia-se o registro!
        {
	    char arquivo [40];
	    char cpf [40];
	    char nome [40];
	    char sobrenome [40];
     	char cargo [40];
	
    	printf("Digite o CPF a ser cadastrado: ");
    	scanf("%s", cpf);  //Armazenamento da escolha do usuário
    	strcpy(arquivo, cpf); //"string copy (strcpy) - responsável por copiar os valores das string
	
    	FILE *file; //Comando para criar o arquivo
    	file = fopen(arquivo, "w"); //Abre o arquivo (fopen) e escreve ("w")
    	fprintf(file, cpf); //Salvo o valor da variável cpf no arquivo 
    	fclose(file); //Fecha o arquivo
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file,","); //Salvo o arquivo e insiro a virgula para separar as variáveis
    	fclose(file); 
	
    	printf("Digite o nome a ser cadastrado: ");
    	scanf("%s", nome); //Armazenamento da escolha do usuário
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file, nome);  //Salvo o valor da variável nome no arquivo
    	fclose(file);

    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file,","); //Salvo o arquivo e insiro a virgula para separar as variáveis
    	fclose(file); 
	
    	printf("Digite o sobrenome a ser cadastrado: ");
    	scanf("%s", sobrenome); //Armazenamento da escolha do usuário
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file, sobrenome);  //Salvo o valor da variável sobrenome no arquivo
    	fclose(file);
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file,","); //Salvo o arquivo e insiro a virgula para separar as variáveis
    	fclose(file); 
	
    	printf("Digite o cargo a ser cadastrado: ");
    	scanf("%s", cargo); //Armazenamento da escolha do usuário
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file, cargo);  //Salvo o valor da variável cargo no arquivo
    	fclose(file);
	
        }
           if (escolha==2) //Volta ao menu!
           {
           return 0;
           }
               if (escolha>2)
               {
               printf("Essa opção não existe!\n");
               system("pause");
               } 
	system("cls");
} //end registro

int consultar ()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo linguagens 
	char cpf [40];
	char conteudo [200];
	
	printf("Você escolheu consultar os nomes!\n");
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

	if (file == NULL)
    {
	printf("Não foi possivel abrir o arquivo, o mesmo não foi localizado! \n");
    }
    
    while (fgets(conteudo, 200, file) != NULL )
	{
		printf("\nEssas são as informações do usuário:");
		printf("%s", conteudo);
		printf("\n\n");
	}
	
	fclose(file);
	system("pause");
	system("cls");
} //end consultar

int deletar ()
{
	char cpf [40];
	printf("Você escolheu deletar o nomes!\n");
	
	printf("Digite o CPF do usuário a ser deletado: \n");
	printf("Opção: ");
	
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	if(file == NULL)
	{
		printf ("O usuário não se encontra no sistema! \n");
		system("pause");
	}
	else 
	{
		remove (cpf);
		printf ("CPF deletado com sucesso! \n");
		system("pause");

	}
	system("cls");
} //end deletar

int dft ()
{
    printf("Essa opção não existe!\n");
	system("pause");

} //end dft

int main ()

    {
    int opcao=0; //Definindo variáveis
	int laco=1;
	char senhadigitada [10]="a";
	int comparacao; 
	
	printf("\t ### Cartório da EBAC ###\n\n"); //Inicio do menu
	printf("Login de administrador!\n Digite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	    system("cls");
    	for (laco=1;laco=1;)
	
    	{
	        setlocale(LC_ALL,"Portuguese"); //Definindo linguagens 
	    
	        printf("\t Escolha a opção desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n"); 
	        printf("\t4 - Sair do sistema\n");
	        printf("Opção: ");//Fim do menu
	
     	    scanf("%d", &opcao); //Armazenamento da escolha do usuário
	
    	    system("cls"); //Limpar tela
	    
            switch (opcao) //inicio da seleção do menu
            {
    	
                case 1:  
       	        registro ();
	            break;
	    
        	    case 2:
	            consultar ();
	            break;
	    
        	    case 3:
                deletar ();
                break; 
        
                case 4:
                printf("Obrigado por utilizar o sistema!");
                return 0;
        
         	    default:
        	    dft ();
        		break;
 
        } //end switch
   } //end for
} //end if

else

printf("Senha incorreta!");

}//end main

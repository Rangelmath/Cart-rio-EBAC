#include <stdio.h> //biblioteca de comunica��o com usu�rio
#include <stdlib.h> //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> //biblioteca de aloca��o de texto por regi�o
#include <string.h> //biblioteca respons�vel pela string
//Fun��es 
int registro ()
    {
	
	printf("Voc� escolheu o registro de nomes!\n");
    printf("Deseja continuar?\n");
    printf("\t1 - Sim!\n");
    printf("\t2 - N�o!\n");
    printf("Op��o: "); //Fim do menu
	
    int escolha=2;
    scanf("%d", &escolha); //Armazenamento da escolha do usu�rio
    system("cls");
	
        if   (escolha==1) //Inicia-se o registro!
        {
	    char arquivo [40];
	    char cpf [40];
	    char nome [40];
	    char sobrenome [40];
     	char cargo [40];
	
    	printf("Digite o CPF a ser cadastrado: ");
    	scanf("%s", cpf);  //Armazenamento da escolha do usu�rio
    	strcpy(arquivo, cpf); //"string copy (strcpy) - respons�vel por copiar os valores das string
	
    	FILE *file; //Comando para criar o arquivo
    	file = fopen(arquivo, "w"); //Abre o arquivo (fopen) e escreve ("w")
    	fprintf(file, cpf); //Salvo o valor da vari�vel cpf no arquivo 
    	fclose(file); //Fecha o arquivo
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file,","); //Salvo o arquivo e insiro a virgula para separar as vari�veis
    	fclose(file); 
	
    	printf("Digite o nome a ser cadastrado: ");
    	scanf("%s", nome); //Armazenamento da escolha do usu�rio
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file, nome);  //Salvo o valor da vari�vel nome no arquivo
    	fclose(file);

    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file,","); //Salvo o arquivo e insiro a virgula para separar as vari�veis
    	fclose(file); 
	
    	printf("Digite o sobrenome a ser cadastrado: ");
    	scanf("%s", sobrenome); //Armazenamento da escolha do usu�rio
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file, sobrenome);  //Salvo o valor da vari�vel sobrenome no arquivo
    	fclose(file);
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file,","); //Salvo o arquivo e insiro a virgula para separar as vari�veis
    	fclose(file); 
	
    	printf("Digite o cargo a ser cadastrado: ");
    	scanf("%s", cargo); //Armazenamento da escolha do usu�rio
	
    	file = fopen (arquivo, "a"); //Abre o arquivo (fopen) e atualiza ("a")
    	fprintf(file, cargo);  //Salvo o valor da vari�vel cargo no arquivo
    	fclose(file);
	
        }
           if (escolha==2) //Volta ao menu!
           {
           return 0;
           }
               if (escolha>2)
               {
               printf("Essa op��o n�o existe!\n");
               system("pause");
               } 
	system("cls");
} //end registro

int consultar ()
{
	setlocale(LC_ALL,"Portuguese"); //Definindo linguagens 
	char cpf [40];
	char conteudo [200];
	
	printf("Voc� escolheu consultar os nomes!\n");
	printf ("Digite o CPF a ser consultado: ");
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf, "r");

	if (file == NULL)
    {
	printf("N�o foi possivel abrir o arquivo, o mesmo n�o foi localizado! \n");
    }
    
    while (fgets(conteudo, 200, file) != NULL )
	{
		printf("\nEssas s�o as informa��es do usu�rio:");
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
	printf("Voc� escolheu deletar o nomes!\n");
	
	printf("Digite o CPF do usu�rio a ser deletado: \n");
	printf("Op��o: ");
	
	scanf("%s", cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	fclose(file);
	if(file == NULL)
	{
		printf ("O usu�rio n�o se encontra no sistema! \n");
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
    printf("Essa op��o n�o existe!\n");
	system("pause");

} //end dft

int main ()

    {
    int opcao=0; //Definindo vari�veis
	int laco=1;
	char senhadigitada [10]="a";
	int comparacao; 
	
	printf("\t ### Cart�rio da EBAC ###\n\n"); //Inicio do menu
	printf("Login de administrador!\n Digite a sua senha:");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	    system("cls");
    	for (laco=1;laco=1;)
	
    	{
	        setlocale(LC_ALL,"Portuguese"); //Definindo linguagens 
	    
	        printf("\t Escolha a op��o desejada do menu:\n\n");
	        printf("\t1 - Registrar nomes\n");
	        printf("\t2 - Consultar nomes\n");
	        printf("\t3 - Deletar nomes\n"); 
	        printf("\t4 - Sair do sistema\n");
	        printf("Op��o: ");//Fim do menu
	
     	    scanf("%d", &opcao); //Armazenamento da escolha do usu�rio
	
    	    system("cls"); //Limpar tela
	    
            switch (opcao) //inicio da sele��o do menu
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

#include <stdio.h>
#include <conio.h>
#include <time.h>
#include <windows.h>

//Declaración de variables
	int random=0, fil=0, col=0, sumafil=0, sumacol=0, sumadig=0, aux=0, lienzo[20][20], f=0, c=0, fin=0, valrep, auxfil=0, auxcol=0, auxdig=0, opt,win=0, lose=0,auxdiagonal=0;
    int sw=0,modi, ff, cc, auxli[20][20], fff,ccc;
error(){
	system("cls");
	system("color fc");
	printf("\n ERROR!\n");
	system("pause > nul");
}

printlienzo(){
	//Impresion de matriz		
	system("cls");
	printf("\n <<<<<<<<<<<<<<<<<<<<<  CUADRADO MAGICO  >>>>>>>>>>>>>>>>>>>>");
	printf("\n\n");
	for(fil=0;fil<3;fil++)
	{
		printf("\n");
		for(col=0;col<3;col++)
		{
			printf(" [ %d ] ",lienzo[fil][col]);
		}
	}
}

sumas(){
	//Suma por fila
	for(fil=0;fil<3;fil++)
	{
		for(col=0;col<3;col++)
		{
			sumafil=sumafil+lienzo[fil][col];
		}
		printf("\n La suma de la fila [ %d ]: %d", fil, sumafil);
		if(sumafil==15){
			auxfil++;
		}
		sumafil=0;
 	}	
   		printf("\n");
   		//Suma por columna
   		for(col=0;col<3;col++)
		{
			for(fil=0;fil<3;fil++)
			{
				sumacol=sumacol+lienzo[fil][col];
			}
			printf("\n La suma de la columna [ %d ]: %d", col, sumacol);
			if(sumacol==15){
				auxcol++;
			}
			sumacol=0;
		}
   		printf("\n");
   		//Suma de diagonal
   		for(col=0;col<3;col++)
		{	
			for(fil=0;fil<3;fil++)
			{
				if(fil==col)
				sumadig=sumadig+lienzo[fil][col];
			}
					
   		}
   		auxdig=sumadig;
   		sumadig=0;
   		printf("\n La suma dela diagonal es: %d", auxdig);
}

windeath(){
	//WIN OR DEATH
  		if(auxfil==3 && auxcol==3 && auxdig==15)
   		{
   			printf("\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>> You win");
   			win++;
   			
   		} 
		else
		{
			printf("\n\n >>>>>>>>>>>>>>>>>>>>>>>>>>>> You lose");
			lose++;
			
		}
		printf("\n\n");
		system("pause > nul");
		
}

play(){
	
	system("cls");
	system("color f0");
	printf("\n <<<<<<<<<<<<<<<<<<<<<  CUADRADO MAGICO  >>>>>>>>>>>>>>>>>>>>");
	printf("\n\n INSTRUCCIONES:");
	printf("\n Para que el cuadrado sea valido, la suma de los elementos de \n cada columna, fila y su diagonal deben ser iguales a 15\n");
	//Enceramiento del LIENZO
	for(fil=0;fil<3;fil++)
	{
		for(col=0;col<3;col++)
		{
			lienzo[fil][col]=0;
		}
	}
	fil=0; col=0;
	auxfil=0; auxcol=0; auxdig=0;
	//Numero BASE
	printf("\n\n ------------------------------------> El numero base sera: %d",random+1);
	lienzo[1][1]=random+1;
	printf("\n\n");
	system("pause");
	//INICIO Ingreso de datos
	for(fil=0;fil<3;fil++)
	{
		for(col=0;col<3;col++)
		{
			if(fil==1 && col==1)
			{}
			else
			{
				system("cls");
				//Impresion de matriz
				printf("\n <<<<<<<<<<<<<<<<<<<<<  CUADRADO MAGICO  >>>>>>>>>>>>>>>>>>>>");
				printf("\n\n");
				for(f=0;f<3;f++)
				{	
					printf("\n");
					for(c=0;c<3;c++)
					{
						printf(" [ %d ] ",lienzo[f][c]);
					}
   				}
   				printf("\n\n");
				
				//Validar que aux esté dentro del rango   //Validacion de numeros repetidos.
	           
				do{
					printf(" -------------------------------------------------\n Ingrese el numero en la posicion [%d][%d]: ", fil, col);
					scanf("%d",&lienzo[fil][col]);
					if((lienzo[fil][col]<1) || (lienzo[fil][col]>9) || (lienzo[fil][col]==lienzo[fil-1][col-1]))
					{
						printf("\n error.. el numero esta fuera de rango o el numero esta repetido");
					}
										
				}while((lienzo[fil][col]<1) || (lienzo[fil][col]>9) ||  (lienzo[fil][col]==lienzo[fil-1][col-1]) );
		                   
			}
		}
    }
	//FIN Ingreso de datos	
	printlienzo();
	printf("\n");
	sumas();
	windeath();
}

 volver() {
	do
	{
		system("cls");	
		system("color f0");
		printf("\n <<<<<<<<<<<<<<<<<<<<<  CUADRADO MAGICO  >>>>>>>>>>>>>>>>>>>>");
		printf("\n\n");
		for(fil=0;fil<3;fil++)
			{
				printf("\n");
				for(col=0;col<3;col++)
				{
					printf(" [ %d ] ",lienzo[fil][col]);
				}
			}
		do
		{
			printf("\n\nDesea modificar algun numero de la tabla? (Si=1 / No=0): ");
			scanf("%d",&opt);
			if(opt<0 || opt >1){
				error();
			}else {
				if (opt==0){
					system("cls");
					system("color f0");	
					printf("\n <<<<<<<<<<<<<<<<<<<<<  CUADRADO MAGICO  >>>>>>>>>>>>>>>>>>>>");
					printf("\n\n");		 
					windeath();
				}
			}
		} while(opt<0 || opt >1);
	switch(opt){
		case 1:
			printf(" Ingrese el numero a modificar :");
			scanf("%d",&modi);
			sw=0;
			for(f=0;f<3;f++)
			{
				for(c=0;c<3;c++)
				{
					if (modi==lienzo[f][c])
					{
						printf("\n Ingrese numero a cambiar :");
						scanf("%d",&lienzo[f][c]);
						sw=1;
						f=100;
						c=100;
					}		
				}
			}
			if(sw==0)
			{
				system("color f0");
				printf(" No existe el numero \n");
				system("pause > nul");
			}
			system("color f0");
			printf("\n");
			printlienzo();
			system("pause > nul");
			printf("\n");
			sumas();
			windeath();
			do{
				printf("\n\n Terminar el juego? (Si=0 / No=1): ");
				scanf("%d",&opt);
				if(opt<0 || opt >1){
					error();
				} else {
					if (opt==0){
						system("cls");
						system("color f0");	
						printf("\n <<<<<<<<<<<<<<<<<<<<<  CUADRADO MAGICO  >>>>>>>>>>>>>>>>>>>>");
						printf("\n\n");		 
						system("pause");
					}
				}
			} while(opt<0 || opt >1);
		break;
		}
	}while(opt==1);
}



main()
{
	do{
	//Obteniendo el número base de forma randómica
	srand(time(NULL));
	random=rand()%8;
		//Menu
		do{
			system("cls");
			system("color f0");
			printf("\n <<<<<<<<<<<<<<<<<<<<<  CUADRADO MAGICO  >>>>>>>>>>>>>>>>>>>>");
			printf("\n\n SELECCIONE UNA OPCION: \n\n\t1) Administracion ....... 1 \n\t2) Jugar ................ 2 \n\t3) Mis Records .......... 3 \n\t4) Salir ................ 4\n\n\tIngrese su opcion: ");
			scanf("%d",&opt);
			//error
			if(opt<1 || opt>4){
				system("cls");
				system("color fc");
				printf("\n ERROR!\n Seleccione una opcion entre la <1> y la <4>...");
				system("pause > nul");
			}
		} while(opt<1 || opt>4);
	
		switch(opt){
		case 1:
			//Menu
			do{
				system("cls");
				system("color f0");
				printf("\n <<<<<<<<<<<<<<<<<<<<<  ADMINISTRACION  >>>>>>>>>>>>>>>>>>>>");
				printf("\n\n SELECCIONE UNA OPCION: \n\n\t1) Dedinir numero base ... 1 \n\t2) Cancelar ... 2\n\n\tIngrese su opcion: ");
				scanf("%d",&opt);
				//error
				if(opt<1 || opt>2){
					error();
				}
			} while(opt<1 || opt>2);
			if (opt==1){
				do{
				system("cls");
				system("color f0");
				printf("\n\n RECUERDE QUE EL NUMERO BASE ES AQUEL QUE OCUPA LA POSICION\n CENTRAL DEL JUEGO\n\n Ingrese el numero base: ");
				scanf("%d",&random);
				random=random-1;
				if (random<0 || random>8){
					error();
				}
				} while (random<0 || random>8);
				play();
				volver();
												
			}
			else{
				printf("\n\n CANCELADO...\n Presione una tecla para continuar... ");
				system("pause > nul");
			}
		break;
		case 2:
			play();
			volver();
		
		break;
		case 3:
			system("cls");
			system("color f0");
			printf("\n <<<<<<<<<<<<<<<<<<<<<   MIS RECORDS   >>>>>>>>>>>>>>>>>>>>");
			printf("\n\n Numero de victorias............................[%d]", win);	
			printf("\n Numero de derrotas.............................[%d]", lose);
			printf("\n\n");
			system("pause > nul");
		break;
		case 4:
			system("cls");
			system("color f0");
			printf("\n <<<<<<<<<<<<<<<<<<<<<      SALIR      >>>>>>>>>>>>>>>>>>>>");
			printf("\n\n Resultados:");
			printf("\n Numero de victorias............................[%d]", win);	
			printf("\n Numero de derrotas.............................[%d]", lose);
			printf("\n\n <<<<<<<<<<<<< Gracias por jugar CUADRO MAGICO! >>>>>>>>>>>");
			printf("\n\n");
			system("pause > nul");
		break;
		}//End Switch
	} while(opt<4 || opt>4);//End Do while del MENU principal
} //End Main





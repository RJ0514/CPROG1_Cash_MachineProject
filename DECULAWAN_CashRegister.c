/*12074039, Ryan Jay Deculawan, S22
Supermarket Cash Register

Goal: Simulate the process of purchasing several food items.

TODO:
1.)	Perform a transaction by selecting from a list of available items to purchase and indicating the quantity of that item to buy in the transaction
2.)	Perform a "check out", where the user will indicate the amount paid
3.)	Print out the "Official Receipt", which will indicate the results of the transaction
4.)	Print out a "report", showing how much of each item has been sold

*/
#include <stdio.h>
#include <stdlib.h>

/* Displays the Main Menu Choices*/
void mainMenu(){
	printf("Hi, Welcome to the Cash Register!\n\n");
	printf("Select an option below:\n\n");
	printf("[1] New Transaction\n");
	printf("[2] Generate Report\n");
	printf("[3] Exit the Program\n");
}

/* For handling current transaction AND updating the current cart */
void Cart(int nPotato,int nAp, int nOr, int nBa, int nPop, int nWa, int nCo, int nTot){			
	printf("Current Cart:\n");
	printf("\nPotato			50.00  x%d\n",	nPotato);
	printf("Apple			35.00  x%d\n",	nAp);
	printf("Orange			40.00  x%d\n",	nOr);
	printf("Banana			25.00  x%d\n",	nBa);
	printf("Popcorn			120.00 x%d\n",	nPop);
	printf("Bottled Water		20.00  x%d\n",	nWa);
	printf("Cola			45.00  x%d\n",	nCo);
	printf("---------------------------------------\n");		

	printf("Total:			P %d.00\n\n",nTot);
				
	printf("[1] Purchase Items\n");
	printf("[2] Check Out\n");
	printf("[3] Cancel Transaction\n\n");
}

///In order to check which food was purchased and to print the Official Reciept.
void Receipt(int nPot, int nAp, int nOr,int nBa, int nPop, int nWa, int nCo, int nTotal, double dMoney){	
	printf("Official Receipt\n\n");

	//If statements for checking purchased food items.
	if(nPot>0)
		printf("Potato		50.00 x %d = %d.00\n",nPot,nPot*50);	
			
	if(nAp>0)
		printf("Apple		35.00 x %d = %d.00\n",nAp,nAp*35);
	
	if(nOr>0)
		printf("Orange		40.00 x %d = %d.00\n",nOr,nOr*40);
	
	if(nBa>0)
		printf("Banana		25.00 x %d = %d.00\n",nBa,nBa*25);
	
	if(nPop>0)
		printf("Popcorn		120.00 x %d = %d.00\n",nPop,nPop*120);
	
	if(nWa>0)
		printf("Bottled Water	20.00 x %d = %d.00\n",nWa,nWa*20);
	
	if(nCo>0)
		printf("Cola		45.00 x %d = %d.00\n",nCo,nCo*45);	
			
	printf("---------------------------------------\n");
	printf("Total:		P %d.00\n",nTotal);
	printf("Cash Tendered:	P %.2lf\n", dMoney);			//the data type double is for anticipating centavos.
	printf("Change		P %.2lf\n\n",dMoney - nTotal);
	printf("Thank you for shopping!\n\n");
}

///Displays the corresponding number for selecting food items.
void Choose(){
	printf("[1] Potato\n");
	printf("[2] Apple\n");
	printf("[3] Orange\n");
	printf("[4] Banana\n");
	printf("[5] Popcorn\n");
	printf("[6] Bottled Water\n");-
	printf("[7] Cola\n");
	printf("[8] Cancel\n\n");
	printf("Purchase which item?");
	
}

/// The Daily Report of successful transactions
void Report(int nPot, int nAp, int nOr,int nBa, int nPop, int nWa, int nCo){
	int nTotal = nPot * 50 + nAp * 35 + nOr * 40 + nBa * 25 + nPop * 120 + nWa * 20 + nCo * 45;
	
	system("CLS");
	printf("Daily Report:\n\n");
	printf("Potato: 			50.00  x %d\n",nPot);
	printf("Apple:	 			35.00  x %d\n",nAp);
	printf("Orange:	 			40.00  x %d\n",nOr);
	printf("Banana:	 			25.00  x %d\n",nBa);
	printf("Popcorn:	 		120.00 x %d\n",nPop);
	printf("Bottled Water:	 		20.00  x %d\n",nWa);
	printf("Cola:			 	45.00  x %d\n",nCo);

	printf("\n------------------------------------------\n");
	printf("TOTAL:				P %d.00",nTotal);
	
	printf("\n\n[1] Return to the main menu\n");
	
}

// Checks for non zero items and displays the list of items the user wants to purchase. Similar to Receipt
void checkout(int nPot, int nAp, int nOr,int nBa, int nPop, int nWa, int nCo, int nTotal){
	system("CLS");
	
	///If statements for checking purchased food items.
	printf("Check Out \n\n");
	if(nPot>0)
		printf("Potato		50.00	x %d = %d.00\n",nPot,nPot*50);
	
	if(nAp>0)
		printf("Apple 		35.00	x %d = %d.00\n",nAp, nAp*35);	
				
	if(nOr>0)
		printf("Orange 		40.00	x %d = %d.00\n",nOr, nOr*40);	
						
	if(nBa>0)
		printf("Banana 		25.00	x %d = %d.00\n",nBa, nBa*25);	
				
	if(nPop>0)
		printf("Popcorn		120.00	x %d = %d.00\n",nPop, nPop* 120);		
					
	if(nWa>0)
		printf("Bottled Water	20.00	x %d = %d.00\n",nWa, nWa* 20);	
					
	if(nCo>0)
		printf("Cola 		45.00	x %d = %d.00\n",nCo, nCo* 45);
						
	printf("---------------------------------------\n");
						
	printf("Total:		P %d.00\n\n",nTotal);
}

///Displays the process of selecting the food item quantity.
int choiceItems(int nChoiceItems, int *nPot, int *nAp, int *nOr, int *nBa, int *nPop, int *nWa, int *nCo){	/// Pointers are used to update the values in main.
	int Pot, Ap, Or, Ba, Pop, Wa, Co;
	
	if (nChoiceItems == 1){
		printf("Buying Potato!\n\n");
		do{					
			printf("Enter Quantity?");
			scanf("%d",&Pot);
		}while(Pot<=0);							///While loop to anticipate invalid inputs.
		printf("\n%d Potatoes purchased!",Pot);
		*nPot = Pot;							///Updates The nPot in main()
		getch();
		return *nPot;
	}
	
	else if (nChoiceItems == 2){
		printf("Buying Apple!\n\n");
		do{
			printf("Enter Quantity?");
			scanf("%d",&Ap);
		}while(Ap<=0);
		printf("\n%d Apples purchased!",Ap);
		*nAp = Ap;
		getch();
		return *nAp;
	}
	
	else if (nChoiceItems == 3){
		printf("Buying Orange!\n\n");
		do{
			printf("Enter Quantity?");
			scanf("%d",&Or);
		}while(Or<=0);
		printf("\n%d Oranges purchased!",Or);
		*nOr = Or;
		getch();
		return *nOr;
	}
	
	else if (nChoiceItems == 4){
		printf("Buying Banana!\n\n");
		do{
			printf("Enter Quantity?");
			scanf("%d",&Ba);
		}while(Ba<=0);
		printf("\n%d Bananas purchased!",Ba);
		*nBa = Ba;
		getch();
		return *nBa;
	}
	
	else if (nChoiceItems == 5){
		printf("Buying Popcorn!\n\n");
		do{
			printf("Enter Quantity?");
			scanf("%d",&Pop);
		}while(Pop<=0);
		printf("\n%d Popcorns purchased!",Pop);
		*nPop = Pop;
		getch();
		return *nPop;
	}
	
	else if (nChoiceItems == 6){
		printf("Buying Bottled Water!\n\n");
		do{
			printf("Enter Quantity?");
			scanf("%d",&Wa);
		}while(Wa<=0);
		printf("\n%d Water Bottles purchased!",Wa);
		*nWa = Wa;
		getch();
		return *nWa;
	} 
	
	else if (nChoiceItems == 7){
		printf("Buying Cola!\n\n");
		do{
			printf("Enter Quantity?");
			scanf("%d",&Co);
		}while(Co<=0);
		printf("\n%d Cola Bottles purchased!",Co);
		*nCo = Co;
		getch();
		return *nCo;
	}
}


int main(){
	int nChoice, nChoiceCart, nChoiceItems;
	
	///Variables for new transactions
	int nPot, nAp, nOr, nBa, nPop, nWa, nCo;
	
	//Variables for the Daily Report
	int nPotato=0, nApple=0, nOrange=0, nBanana=0, nPopcorn=0, nWater=0, nCola=0;		
	int nTotal;
	
	int nBack;
	
	///To anticipate money with cents.
	double dMoney;
	
	
	
	do{
		system("CLS");
		mainMenu();
		
		scanf("%d",&nChoice);	
		
		///For New Transactions
		if (nChoice == 1){
			// To reset the whole cart
			nCo = nWa = nPop = nBa = nOr = nAp = nPot = 0;		
			
			do{
				nTotal = nPot * 50 + nAp * 35 + nOr * 40 + nBa * 25 + nPop * 120 + nWa * 20 + nCo * 45;
				system("CLS");
				Cart(nPot,nAp, nOr , nBa, nPop, nWa, nCo, nTotal);
				scanf("%d", &nChoiceCart);
				
				///If the User wants to Purchase an item
				if (nChoiceCart == 1){
					system("CLS");
					Choose();
					scanf("%d", &nChoiceItems);	
					
					if (nChoiceItems >= 1 && nChoiceItems <= 7){
						choiceItems(nChoiceItems, &nPot, &nAp, &nOr, &nBa, &nPop, &nWa, &nCo);
					}
				}
				
				///If the User wants to Check Out
				else if(nChoiceCart == 2 && nTotal > 1){
					checkout(nPot,nAp, nOr , nBa, nPop, nWa, nCo, nTotal);
					
					do{
						printf("Enter Amount:");
						scanf("%lf",&dMoney);			
					}while(dMoney < nTotal);			//Loop to anticpate incorrect ammounts.
						
					system("CLS");		
					Receipt(nPot, nAp, nOr, nBa, nPop, nWa, nCo, nTotal, dMoney);
					printf("Press any key to go back to Main Menu\n");
					getch();
							
					nChoiceCart = 3;					
					
				///Update the Daily Report after a successful transaction
					nPotato+=nPot;		
					nApple+=nAp;
					nOrange+=nOr;
					nBanana+=nBa;
					nPopcorn+=nPop;	
					nWater+=nWa;
					nCola+=nCo;
					fflush(stdin);
				}	
			}while(nChoiceCart != 3 || nChoiceCart == 2);
		}
		
		//If the User wants to check the Daily Report.
		else if(nChoice ==2){ 
			do{
				system("CLS");
				Report(nPotato,nApple,nOrange,nBanana,nPopcorn,nWater,nCola);
				scanf("%d",&nBack);	
			}while(nBack != 1);
		}
	}while(nChoice !=3);
	
	printf("\nCCPROG1 Machine Project Complete! *High Five*");
	
	return 0;
}

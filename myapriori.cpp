#include<stdio.h>
int main(){
	
	int input[10][10], colc[10], i, j, n, n1, k, L1[10][2], lc=1, row, col;
	int items[10], a1[30], icounter = 1, ecounter = 1, min, length = 0;
	
	printf("***APRIORI ALGORITHM IMPLEMENTATION***\n\n");
	
	printf("Enter minimum support acceptance = ");
	scanf("%d",&min);
	printf("\nEnter the number of transaction   ");
	scanf("%d",&n);
	
	for( i = 1; i <= n; i++ ){
		
		printf("\nEnter the number of items for TID %d=	",i);
		scanf("%d", &n1);
		colc[i] = n1;
		printf("\nEnter items ");
		for( j = 1; j <= n1; j++ ){
			scanf("%d", &input[i][j]);
			a1[icounter] = input[i][j]; // Copying items of multiD array into a single array
			icounter++;
			}	
		}
	
	
	printf("TID\t ITEMS \n\n");
	
	for(i = 1 ; i <= n ; i++){	// Printing the TID and itemset given by user in a tabular format 
		printf("%d\t ",i);
		for(j = 1 ;j <= colc[i]; j++){ 
			printf("%d ", input[i][j]);
		}
		printf("\n\n"); 
	}
	
	printf("\n\n ");
	printf("index=%d\n",icounter);
	printf("**Generating C1**\n\n ");	
		
	printf("Itemset\t Support\n");
	
	for( i = 1 ;i < icounter ; i++) {

		for( j = i + 1 ;j < icounter ; j++ ){
			
			if ( a1[i] == a1[j] ){
				
				ecounter++;
				for( k = j; k < icounter; k++ ){
					if( j + 2 == icounter-1){
						j = j-1;
					}
					
					a1[k] = a1[k+1];
			
				}
				icounter--;
			}
		}
		if( ecounter >= min ){
			
			for( row = 1; row <= 1; row++ ){
				
				for(  col = 1; col <= 2; col++ ){
					
			//	if( col == 1){
						L1[row][col] = a1[i];
						L1[row][col] = ecounter;
			//	}	
				
			//	else{
					
			//	}
			}
			lc++;
			printf("\n");
		}
		printf("  %d\t\t %d", a1[i], ecounter);
		ecounter = 1;
		printf("\n");
		
		}
		else{
			
		printf("  %d\t\t   %d", a1[i], ecounter);
		ecounter = 1;
		printf("\n"); 	
		}
			
	}
	printf( "index =%d \n\n", icounter );
	printf("L1 FROM C1 \n\n ");
	printf("ITEMSET\t\tSUPPORT \n\n");
	
	for( i = 1; i < lc; i++ ){
		
		for( j = 1; j <=2; j++ ){
			
			printf("  %d\\t\t  %d\n", L1[i][j]);
			
		}
	}
	

}

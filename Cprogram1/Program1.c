/*
 * Program1.c
 *
 *  Created on: Feb 9, 2023
 *      Author: b527h871
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){

	const char *months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	float data[12];
	FILE *fileptr;
	fileptr = fopen("input.txt","r");
	for (int i=0;i<12;i++){
		fscanf(fileptr, "%f", &data[i]);
	}
	printf("Monthly sales report for 2022:\n\n%-15s%s\n\n","Month","Sales");
	for (int i=0; i<12;i++){
		printf("%-15s$%5.2f\n",months[i],data[i]);
	}
	printf("\n\nSales Summary:\n\n");
	float min_sales = data[0];
	int min_month = 0;
	for (int i=1;i<12;i++){
		if (data[i]<min_sales){
			min_sales = data[i];
			min_month = i;
		}
	}
	printf("%-15s$%5.2f (%s)\n","Minimum sales: ",min_sales,months[min_month]);
	float max_sales = data[0];
	int max_month = 0;
	for (int i=1;i<12;i++){
		if (data[i]>max_sales){
			max_sales = data[i];
			max_month = i;
		}
	}
	printf("%-15s$%5.2f (%s)\n","Maximum sales: ",max_sales,months[max_month]);
	float average = 0.00;
	for(int i=0; i<12; i++){
		average += data[i];
	}
	average /=12;
	printf("%-15s$%5.2f\n", "Average sales: ", average);
	printf("\n\nSix-Month Moving Average Report:\n\n");
	for(int i=0;i<7;i++){
		float total = 0.00;
		for(int j=i;j<i+6;j++){
			total += data[j];
		}
		total /= 6;
		printf("%-10s- %-10s $%5.2f\n", months[i],months[i+5],total);
	}
	int index[12]= {0,1,2,3,4,5,6,7,8,9,10,11};
	printf("\n\nSales Report (Highest to Lowest):\n\n%-15s%s\n\n","Month","Sales");
	int true = 0;
	while(true == 0){
		true = 1;
		for (int i=0; i<11;i++){
			if(data[i]<data[i+1]){
				float temp = data[i];
				data[i] = data[i+1];
				data[i+1] = temp;
				true =0;
				int index_temp = index[i];
				index[i] = index[i+1];
				index[i+1] = index_temp;
			}
		}
	}
	for(int i=0;i<12;i++){
		printf("%-15s$%5.2f\n",months[index[i]],data[i]);
	}
}


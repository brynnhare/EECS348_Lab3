/*
 * Program2.c
 *
 *  Created on: Feb 9, 2023
 *      Author: b527h871
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
	int x = 5;
	while (x == 5){
		int score;
		printf("Enter 0 or 1 to STOP\nEnter the NFL score: ");
		scanf("%d",&score);
		if (score <= 1){
			printf("Program ending...");
			x=1;
			break;
		}
		else{
			printf("Possible combinations of scoring plays: \n\n");
			int td_2pt,td_fg,td,fg,safety;
			int max_td_2pt = score/8;
			int max_td_fg = score/7;
			int max_td = score/6;
			int max_fg = score/3;
			int max_safety = score/2;
			for(td_2pt =0;td_2pt<=max_td_2pt;td_2pt++){
				for(td_fg =0;td_fg<=max_td_fg;td_fg++){
					for(td =0;td<=max_td;td++){
						for(fg =0;fg<=max_fg;fg++){
							for(safety =0;safety<=max_safety;safety++){
								if(((td_2pt*8)+(td_fg*7)+(td*6)+(fg*3)+(safety*2))==score){
									printf("%d TD + 2pt, %d TD + FG, %d TD, %d FG, %d Safety\n",td_2pt,td_fg,td,fg,safety);
								}
							}
						}
					}
				}
			}
		}
	}
}

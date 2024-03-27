//1970년 이후 달력 프로그램
#include <stdio.h>
 
int cal(int year, int mon){
    int date;
    if(mon<=7 && mon%2==1 && mon!=2){
        date = 31;
    }
    else if(mon>=8 && mon%2==0 && mon!=2){
        date = 31;
    }
    else if(mon<=7 && mon%2==0 && mon!=2){
        date = 30;
    }
    else if(mon>=8 && mon%2==1 && mon!=2){
        date = 30;
    }
    else if(mon==2){
        date = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0)?29:28;
    }
    else{
        printf("ERROR!");
    }
    return date;
}

int printCal(int year, int mon, int tab, int willPrint){
    int date = cal(year, mon);
    int printDay;
    for(int i=0;i<tab;i++){
        printf("\t");
    }
    for(int x=0;x<5;x++){
        for(int y=0;y<7;y++){
            printDay = 7*x+y+1;
            if(printDay<=date){
                if(willPrint==1){
                    printf("%d\t", printDay);
                }
            }
            else{
                tab = (y+tab)%7;
                break;
            }
            if(willPrint==1){
                if((printDay+tab)%7==0){
                    printf("\n");
                }
            }
        }
    }
    return tab;
}

int main(void) {    //main 함수
    int year, mon, willPrint = 0;
    printf("년과 달을 입력: ");
    scanf("%d %d", &year, &mon);
    int tab = 4;    //1970년 1월 1일 요일 맞춤
    for(int calYear = 1970; calYear<=year; calYear++){
        int objMon = (calYear==year)?mon:12;
        for(int calMon = 1; calMon<=objMon; calMon++){
            if((calYear==year)&&(calMon==objMon)){
                printf("%d년 %d월\n", year, mon);
                printf("\n일\t월\t화\t수\t목\t금\t토\n");
                printf("\n");
                willPrint = 1;
            }
            tab = printCal(calYear, calMon, tab, willPrint);
        }
    }
    printf("\n");
}

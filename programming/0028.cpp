#include <bits/stdc++.h>
struct am{
    char name[25];
    int goal = 0;
    int point = 0;
    int wasgoal = 0;
};
am data[6];
int catd[6][6];
void sw(int j){
    am catche;
    catche.goal=data[j].goal;
    catche.point=data[j].point;
    catche.wasgoal=data[j].wasgoal;
    strcpy(catche.name,data[j].name);
    data[j].goal=data[j+1].goal;
    data[j].point=data[j+1].point;
    data[j].wasgoal=data[j+1].wasgoal;
    strcpy(data[j].name,data[j+1].name);
    data[j+1].goal=catche.goal;
    data[j+1].point=catche.point;
    data[j+1].wasgoal=catche.wasgoal;
    strcpy(data[j+1].name,catche.name);
}
int main(){
    for(int i = 1;i<=4;i++){
        scanf("%s",data[i].name);
    }
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=4;j++){
            scanf("%d",&catd[i][j]);
        }
    }
    for(int i = 1;i<=4;i++){
        for(int j = 1;j<=4;j++){
            if(i==j){
                continue;
            }
            if(catd[i][j]>catd[j][i]){
                data[i].point+=3;
            }else if(catd[i][j]==catd[j][i]){
                data[i].point+=1;
            }
            data[i].goal+=catd[i][j];
            data[i].wasgoal+=catd[j][i];
        }
    }
    for(int i = 1;i <=4;i++){
        for(int j = 1;j<=3;j++){
            if(data[j].point>data[j+1].point){
                sw(j);
            }
        }
    }
    for(int i = 1;i <=4;i++){
        for(int j = 1;j<=3;j++){
            if(data[j].point==data[j+1].point){
                if(data[j].goal-data[j].wasgoal>data[j+1].goal-data[j+1].wasgoal){
                    sw(j);
                }else if(data[j].goal-data[j].wasgoal==data[j+1].goal-data[j+1].wasgoal){
                    if(data[j].goal>data[j+1].goal){
                        sw(j);
                    }
                }
            }
        }
    }
    for(int i = 4;i >=1;i--){
        printf("%s %d\n",data[i].name,data[i].point);
    }
}

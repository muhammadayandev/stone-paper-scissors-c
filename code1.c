#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int game(char user, char comp){
    if(comp==user){
        return -1;
    }

    if(comp=='s' && user=='p'){
        return 1;
    } else if(comp=='p' && user=='s'){
        return 0;
    }

    if(comp=='s' && user=='z'){
        return 0;
    } else if(comp=='z' && user=='s'){
        return 1;
    }

    if(comp=='p' && user=='z'){
        return 1;
    } else if(comp=='z' && user=='p'){
        return 0;
    }

    if(comp!='s' && comp!='p' && comp!='z'){
        printf("Invalid Input from computer side\n");
        exit(0);
    }
    return -1;
}
int main(){
    int n,result;
    srand(time(NULL));
    char user,comp;
    int t_user=0, t_comp=0;
    char end;
    do{
        n = rand()%3;
        if(n==0)
            comp='s';
        else if(n==1)
            comp='p';
        else
            comp='z';
        printf("\n\n\n\n\t\t\t\tEnter s for STONE, p for PAPER and z for SCISSOR\n\t\t\t\t\t\t\t");
        scanf(" %c", &user);

        result = game(user,comp);
        if(result== -1){
            printf("\n\t\t\t\t\t\t\tRound Draw!\n");
        } else if(result==0){
            printf("\n\t\t\t\t\t\t\tYou Lose! Computer chose %c\n",comp);
            t_comp++;
        } else{
            printf("\n\t\t\t\t\t\t\tYou Win! Computer chose %c\n",comp);
            t_user++;
        }

        printf("Do You Want To Play Again? (Y/N): ");
        scanf(" %c", &end);
    } while(end=='Y' || end=='y');

    printf("\n===== FINAL SCORE =====\n");
    printf("You: %d | Computer: %d\n", t_user, t_comp);

    if (t_user > t_comp)
        printf("You WON the match!\n");
    else if (t_user < t_comp)
        printf("Computer WON the match!\n");
    else
        printf("Match DRAW!\n");

    return 0;

}
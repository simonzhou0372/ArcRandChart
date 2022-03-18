#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int bar,note,t,t_sum,choice;
    float bpm;
    FILE *fp=NULL;
    srand((unsigned int)time(0));
    //谱面文件读取
    fp=fopen("2.aff","w+");
    //输入BPM
    printf("Please enter BPM:\n");
    scanf("%f",&bpm);
    printf("BPM is %.2f.\n",bpm);
    //输入小节号
    printf("Please enter bars:\n");
    scanf("%d",&bar);
    printf("bar is %d.\n",bar);
    printf("Loading...\n");
    //总时间
    t_sum=3000+(15000/bpm)*(4*bar);
    //初始值
    fprintf(fp,"AudioOffset:0\n");
    fprintf(fp,"-\n");
    fprintf(fp,"timing(0,%.2f,4.00);\n",bpm);
    //黑线布置
    fprintf(fp,"arc(0,%d,0.00,0.00,b,1.00,1.00,0,none,true);\n",t_sum);
    fprintf(fp,"arc(0,%d,1.00,1.00,b,1.00,1.00,0,none,true);\n",t_sum);
    fprintf(fp,"arc(0,%d,0.50,0.50,b,1.00,1.00,0,none,true);\n",t_sum);

    for(int i=0;i<4*bar;i++){
            choice=rand()%2;
            t=3000+(15000/bpm)*(i+1);
            if(choice==0){                      //天键
                note = (rand()%3)+1;
                if(note==1)fprintf(fp,"arc(%d,%d,0.00,0.00,b,1.00,1.00,0,none,true)[arctap(%d)];\n",t,t+1,t);
                else if(note==2)fprintf(fp,"arc(%d,%d,1.00,1.00,b,1.00,1.00,0,none,true)[arctap(%d)];\n",t,t+1,t);
                else if(note==3)fprintf(fp,"arc(%d,%d,0.50,0.50,b,1.00,1.00,0,none,true)[arctap(%d)];\n",t,t+1,t);
            }
            else if(choice==1){                //地键
                note = (rand()%4)+1;
                fprintf(fp,"(%d,%d);\n",t,note);
            }
    }
    fclose(fp);
    printf("Complete.\n");
    return 0;
}

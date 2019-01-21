//
//  main.c
//  string2int
//
//  Created by shidingyuan on 2017/10/9.
//  Copyright © 2017年 Shi Dingyuan. All rights reserved.
//


//注意栈顶是待写入状态
//注意多次循环i的值可能失控
//注意因if-else语句导致的不可复用性
#include <stdio.h>
#include <stdlib.h>
//检查合法性函数
int judge(char* s){
    int tag=0;
    int i=1;
    while(s[i]!='\0'){
        //出现非法字符
        if(!(s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/'||s[i-1]=='('||s[i-1]==')'||(s[i-1]>='0'&&s[i-1]<='9')))
            return 0;
        //连续的运算符
        else if((s[i-1]=='+'||s[i-1]=='-'||s[i-1]=='*'||s[i-1]=='/')&&(s[i]=='+'||s[i]=='-'||s[i]=='*'||s[i]=='/'))
            return 0;
        //连续的括号
        else if((s[i-1]=='('&&s[i]==')')||(s[i-1]==')'&&s[i]=='('))
            return 0;
        //括号不匹配 注意此时无法访问到最后一个元素
        else{
            if(s[i-1]=='(')
                tag++;
            else if(s[i-1]==')'){
                if(--tag<0)
                    return 0;
            }
        }
        i++;
    }
    //检查最后一个元素
    return !(tag-(s[i-1]==')'));
}
float calculate(char*s){
    if(!judge(s)){
        printf("表达式非法");
        return 0;
    }
    int signsize = 0,numsize = 0;
    //符号栈与数字栈指针声明
    char* signb,*signt;
    float* numb,*numt;
    //确定静态栈的大小
    char *i = s;
    char *head = s; //标记头部，用于以后判断
    int flag = 0; //负数标记，1表示负数
    while(*i!='\0'){
        //扫描到运算符(除减号以外)则符号栈大小增加1
        if(*i=='*'||*i=='/'||*i=='('||*i==')')
            signsize += 1;
        //扫描到数字且数字下一位是运算符(或'\0')，说明是一个数字，数字栈大小增加1
        else if(*i<='9'&&*i>='0'&&!(*(i+1)>='0'&&*(i+1)<='9'))
            numsize += 1;
        //遇到减号，有可能是负号
        else if(*i=='-'){
            //负号特征：前面有个'('或者是字符串第一个
            if(!(i==head||*(i-1)=='('))
                signsize +=1;
        }
        //遇到加号，有可能是正号
        else if(*i=='+'){
            //正号特征：前面有个'('或者是字符串第一个
            if(!(i==head||*(i-1)=='('))
                signsize +=1;
        }
        i++;
    }
    //开辟栈空间
    signb = (char*)malloc(sizeof(char)*signsize);
    signt = signb;
    numb = (float*)malloc(sizeof(float)*numsize);
    numt = numb;
    //压栈过程(其中也有部分出栈)
    float temp=0;  //用于传递值的中间变量
    float number = 0;  //寻找实际数值的中间变量
    for(i = s;*i!='\0';i++){
        //扫到数字，向后寻找直至确定真实数值，并压入数字栈
        if((*i<='9')&&(*i>='0')){
            for(number = 0;*i>='0'&&*i<='9';i++)
                number = number*10+(*i-'0');
            if(flag==1){
                number = -number;
                //使用后复原
                flag = 0;
            }
            *numt = number;
            numt++;
            i--;
        }
        //扫到'('，直接压入符号栈
        else if(*i=='('){
            *signt = '(';
            signt++;
        }
        //扫到'+' '-'
        else if(*i=='+'||*i=='-'){
            //如果是个负号，flag置1
            if(*i=='-'&&(i==head||*(i-1)=='('))
                flag = 1;
            else if(*i=='+'&&(i==head||*(i-1)=='('))
                flag = 0;
            //栈顶是*或/，则可以先算，因为+-优先级低，两个运算符之间有没有括号，可以算
            else if(*(signt-1)=='*'){
                //注意栈顶是待写入值，所以栈顶实际应该-1
                temp = (*(numt-1))*(*(numt-2));
                //两个值的乘积的出后压栈，替代原来的两个数
                numt--;
                *(numt-1) = temp;
                //算过的符号去除
                signt--;
                *(signt) = *i;
                signt++;
            }
            else if(*(signt-1)=='/'){
                temp = (*(numt-2))/(*(numt-1));
                numt--;
                *(numt-1) = temp;
                signt--;
                *(signt) = *i;
                signt++;
            }
            else{
                *(signt) = *i;
                signt++;
            }
            
        }
        //扫到'*' '/'，直接压栈
        else if(*i=='*'||*i=='/'){
            *signt = *i;
            signt++;
        }
        //扫到右括号
        else if(*i==')'){
            //在左括号以前，之间的运算符全部处理
            for(;*(signt-1)!='(';signt--){
                //括号中的运算符+-一定后出栈，因为压栈前已经把当时栈顶的*/处理掉了
                //这样恰好不影响优先级
                if(*(signt-1)=='*')
                    temp = (*(numt-1))*(*(numt-2));
                else if(*(signt-1)=='/')
                    temp = (*(numt-2))/(*(numt-1));
                else if(*(signt-1)=='+')
                    temp = (*(numt-1))+(*(numt-2));
                else
                    temp = (*(numt-2))-(*(numt-1));
                numt--;
                *(numt-1) = temp;
            }
            //处理过的符号去除
            signt--;
        }
    }
    //出栈过程，此时已无括号，+-也一定会后出栈，原因同前述
    while(signt!=signb){
        if(*(signt-1)=='*')
            temp = (*(numt-1))*(*(numt-2));
        //注意除法和减法的顺序，栈底是前面那个数
        else if(*(signt-1)=='/')
            temp = (*(numt-2))/(*(numt-1));
        else if(*(signt-1)=='+')
            temp = (*(numt-1))+(*(numt-2));
        else
            temp = (*(numt-2))-(*(numt-1));
        numt--;
        *(numt-1) = temp;
        signt--;
    }
    //返回栈顶数值，即运算结果
    return *(numt-1);
}
int main(int argc, const char * argv[]){
    char *s = "-1+8*(+5-(-31))";
    printf("%f\n",calculate(s));
    printf("%d",judge(s));
    return 0;
}

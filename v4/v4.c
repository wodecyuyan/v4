#include<stdio.h>
#include<string.h>
#include<stdlib.h>


int isOperator(char c)
{
	if(c=='+'||c=='-'||c=='*'||c=='/')return 1;
	else return 0;
}

void moveoperator(char *p)
{
	while(*p!='10'){
		*p=*(p+1);
		p++;
	}
}

void moveoperand(float*p,float*end){
	while(p!=end){
		*p=*(p+1);
		p++;
	}
}
int main()
{
	char strExp[]="1-2.5*4+10.1/5.1";
	char operators[100]={'\0'};
	float operands[100];
	
	//extract operator + - * /
	
	int i;
	int operatorsIndex=0;
	for(i=0;i<strlen(strExp);i++)
	{
		if(isOperator(strExp[i]))
		{
			operators[operatorsIndex]=strExp[i];
			operatorsIndex++;
		}
	}
	puts(operators);
	
	//extract oprand 1 2.5 4 10.2 5.1
		
	int	operandsIndex=0;
	for(i=0;i<strlen(strExp);i++)
	{
		char temp[100]={'\0'};
		int tempIndex=0;
		while(!isOperator(strExp[i]))
		{
			temp[tempIndex]=strExp[i];
			i++;
			tempIndex++;
		}
		float floatV=atof(temp);
		operands[operandsIndex++]=floatV;
	}
	for(i=0;i<operandsIndex;i++)
		printf("%0.lf\n",operands[i]);

	//handle * /
	char *poperator=operators;
	float *poperand=operands;
	while(*poperator!='\0')
	{
		if(*poperator=='*')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand*rightOperand;
			*poperand=res;
			moveoperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else if(*poperator=='/')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftoperand/rightoperand;
			*poperand=res;
			moveoperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
		else
		{
			poprator++;
			poprand++;
		}
	}
	puts(operators);
	
	//handle + -
	*poperator=operators;
	*poperand=operand;
	while(*poperator!='\0')
	{
		if(*poperator=='+'){
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftOperand+rightOperand;
			*poperand=res;
			moveoperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}else if(*poperator=='-')
		{
			float leftOperand=*poperand;
			float rightOperand=*(poperand+1);
			float res=leftoperand-rightoperand;
			*poperand=res;
			moveoperator(poperator);
			moveOperand(poperand+1,&operands[operandsIndex--]);
		}
	}
	printf("the result is %0.2f\n",operands[0]);
	return 0;

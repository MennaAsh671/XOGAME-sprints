#include <stdio.h>

typedef struct stack {
	int element[30];
	int top;
}stack_t;
void createstack(stack_t* stack) {

	stack->top = -1; //stack is empty

}
int push(stack_t* stack, int item) {

	if (stack->top == 6)
		printf("\nstack is full ,cannot add elements");

	else
	{
		stack->element[stack->top + 1] = item; stack->top++;
	}
}
int pop(stack_t* stack) {
	if (stack->top == -1) {
		//printf("stack is empty (error)\n");
		return 0;
	}
	else {
		//  printf("the popped element is :%d", stack->element[stack->top]);
		stack->top--;
		return 1;
	}
}
int display_stack(stack_t* stack) {
	printf("\n The stack is");
	for (int i = 0; i < 7; i++)
	{
		printf("% d", stack->element[i]);
	}
};
int get_top(stack_t* stack) {
	if (stack->top == -1) {
		printf("\nstack is empty (error)");
		return 0;
	}
	else {
		printf("\ntop of the stack is: %d", stack->element[stack->top]);
		return 1;
	}
}
int full_check(stack_t* stack) {
	if (stack->top == 6) {
		printf("\nstack is full ,cannot add elements");
		return 1;
	}
	else
		return 0;
	
}
int empty_check(stack_t* stack) {
	if (stack->top == -1) 
		return 1;
	else
		return 0;
	
}



int main() {

	stack_t stk;
	createstack(&stk);
	int count = 0, count1 = 0, count2=0;
	//test cases 
	
	char item[] = { '(','(','x',' + ','y',')' ,')' };
	 
	//char item[] = { '(','x',' + ','y' };

	//char item[] = { '(','x',' + ','y',']' };

	//char item[] = { '(','{','x',' + ','y',')',')'};

	//char item[] = { '(','x',' + ','y',')' };
	
	for (int i = 0; i < 5; i++)
	{
		push(&stk, item[i]);
	}

	for (int i = 0; i < 7; i++)
	{
		if (stk.element[i] == '{')
		{
			count++;
			for (int i = 0; i < 7; i++)
			{
				if (stk.element[i] == '}') {
					count++;
					break;
				}
			}
		}
		else if (stk.element[i] == '(')
		{
			count1++;
			for (int i = 0; i < 7; i++)
			{
				if (stk.element[i] == ')') {
					count1++;
					break;
				}
			}
		}
		else if  (stk.element[i] == '[')
		{
			count2++;
			for (int i = 0; i < 7; i++)
			{
				if (stk.element[i] == ']') {
					count2++;
					break;
		
				}
			}
		}
			
	}

	if (count % 2 ==0 && count1 % 2 == 0 && count2 % 2 == 0)
		printf("Balanced\n");
	else
	{
		printf("Unbalanced\n");
		printf("Invalid Expression");
	}
}

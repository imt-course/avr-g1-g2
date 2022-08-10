#include <stdio.h>
#include "std_types.h"


typedef struct {
	u32 num1;
	u32 num2;
	u32 operation;
} Calculte;

typedef struct {
	u32 salary;
	u32 bonus;
	u32 deductions;
	u32 net;
} Employee;

typedef union {
	struct Bit {
		u8 B0 : 1;
		u8 B1 : 1;
		u8 B2 : 1;
		u8 B3 : 1;
		u8 B4 : 1;
		u8 B5 : 1;
		u8 B6 : 1;
		u8 B7 : 1;
	};
	u8 Byte;
} Register;


u32 get_result(const Calculte *input_ref);
u32 get_net   (Employee employees[], u8 arr_size);



int main (void) {
	Register reg = {0,0,0,0,0,0,0,0};
	reg.B0 = 1;
	reg.B5 = 1;
	reg.Byte = 25;
}



u32 get_result(const Calculte *input_ref) {
	u32 result = 0;
	switch(input_ref->operation) {
		
		case '+':
			//result = (*input_ref).num1 + (*input_ref).num2;
			result = input_ref->num1 + input_ref->num2;
			break;
			
		case '-':
			//result = (*input_ref).num1 - (*input_ref).num2;
			result = input_ref->num1 - input_ref->num2;
			break;
			
		case '*':
			//result = (*input_ref).num1 * (*input_ref).num2;
			result = input_ref->num1 * input_ref->num2;
			break;
			
		case '/':
			//result = (*input_ref).num1 / (*input_ref).num2;
			result = input_ref->num1 / input_ref->num2;
			break;
		default:
			break;
	}
	return result;
}


u32 get_net (Employee employees[], u8 arr_size) {
	
	u32 total_net = 0;
	u8 i;
	
	for (i=0; i<arr_size; i++) {
		
		printf("Please enter Employee %d Salary: ", i+1);
		scanf("%d", &employees[i].salary);
		
		printf("Please enter Employee %d Bonus: ", i+1);
		scanf("%d", &employees[i].bonus);
		
		printf("Please enter Employee %d Deductions: ", i+1);
		scanf("%d", &employees[i].deductions);
		
		employees[i].net = employees[i].salary 
						 + employees[i].bonus 
						 - employees[i].deductions;
						 
		total_net += employees[i].net;
	}
	return total_net;
}
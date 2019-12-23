#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>
#define SIZE 3

typedef enum __VarType {
  V_uint8,
  V_uint16,
  V_uint32,
  V_bool,
} VarType;

typedef struct __Var {
  VarType type;
  union {
    uint8_t  u8;
    uint16_t u16;
    uint32_t u32;
    bool tf;
  };
} Var;

void write_uint8_t(Var *v, uint8_t u8) {
  v->type = V_uint8;
  v->u8 = u8;
}

void write_uint16_t(Var *v, uint16_t u16) {
  v->type = V_uint16;
  v->u16 = u16;
}

void write_uint32_t(Var *v, uint32_t u32) {
  v->type = V_uint32;
  v->u32  = u32;
}

void write_bool(Var *v,  bool tf){
	v->type = V_bool;
	v->tf = tf;
}

void print_data(Var *v, int n){
	int i;
	for( i = 0 ; i < n ; i++ ){
	switch( (v+i)->type ) {
      case V_uint8  : printf("uint8   %d\n", (v+i)->u8);  break;
      case V_uint16 : printf("uint16  %d\n", (v+i)->u16); break;
      case V_uint32 : printf("uint32  %d\n", (v+i)->u32); break;
      case V_bool   : printf("bool    %d\n", (v+i)->tf);  break;
    }
    
	}
}

void erase_data(Var *v, int n){
	int i;
	for( i = 0 ; i < n ; i++ ){
		(v+i)->type = 0;
		(v+i)->u8 = 0; 
		(v+i)->u16 = 0;
		(v+i)->u32 = 0;
		(v+i)->tf = 0;
	}
}

void is_busy(Var *v, int n){
	int i, sum = 0;
	for( i = 0 ; i < n ; i++ ){
		sum += sizeof((v+i)->type);
	}
	  
    char hexaDeciNum[100]; 
      
    i = 0; 
    while(sum!=0) 
    {    
        int temp  = 0; 
           
        temp = sum % 16; 
          
        if(temp < 10) 
        { 
            hexaDeciNum[i] = temp + 48; 
            i++; 
        } 
        else
        { 
            hexaDeciNum[i] = temp + 55; 
            i++; 
        } 
          
        sum = sum/16; 
    } 
      
    int j;
    printf("Hexadecimal memory: ");
    for(j=i-1; j>=0; j--) 
        printf("%c",hexaDeciNum[j]);  
    printf("\n");
	
}
int main(int argc, char **argv) {

  Var *v;
  v=malloc(100*sizeof(Var));
  
  int n;
  scanf("%d",&n); // enter the number of numbers you want to add to the flash memory
  int i, datatype, num;
  for ( i = 0 ; i < n ; i++){
  	  	scanf("%d%d",&datatype,&num); // enter 1 if you want to add uint8, 2 for uint16, 3 for uint32, 4 for bool and the value of the number
  	  	switch(datatype){
  	  		case 1: write_uint8_t(v+i , num); break;
  	  		case 2: write_uint16_t(v+i , num); break;
  	  		case 3: write_uint32_t(v+i , num); break;
  	  		case 4: write_bool(v+i , num); break;
  	  			default : printf("Error!, you do not enter the proper data type!"); return 0;
			}
  }
  
  print_data(v,n);
  
  is_busy(v,n);
  
  erase_data(v,n);
  
  print_data(v,n);

  return 0;
}
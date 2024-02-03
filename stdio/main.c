#include <stdio.h>
#include "stdint.h"
#include "math_test.h"

void main(){
	bool b = true;
	int a = 5;
  	printf("%d\n", a);
	printf("%d\n", b);
  	a = _plus(a);
  	printf("%d\n", a);
  	a = _minus(a);
  	printf("%d\n", a);
}

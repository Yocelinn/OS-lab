#include <stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	int num[6] = {0};
	int i=0;
	while(n/10 != 0){
		//n%10可以从个位开始依次得到每一位，/10消去刚得到的那一位
		num[i++] = n%10;
		n = n/10;
	}
	num[i] = n%10;
	int count = i;
	int flag = 1;
	for(;count - i <= i;i--){
		//如果是奇数位,当i处于中间位时，跳出？
		if(num[i] != num[count - i]){
			flag = 0;
			break;	
		}
	}
	
	if (flag == 1) {
		printf("Y\n");
	} else {
		printf("N\n");
	}
	return 0;
}

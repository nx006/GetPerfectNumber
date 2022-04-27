#include <stdio.h>
#include <stdlib.h>

//Return true if num is a perfect number.
//Return false if num is not a perfect number.
int perfect(int num)
{
	//약수를 저장할 배열을 적절히 큰 크기로 선언한다
	//N의 약수의 개수가 N개보다 클 수가 없으므로 N개 크기의 배열을 선언한다.
	int* divisor = (int*)malloc(sizeof(int)*num);
	int factorCount = 0; //약수의 개수를 저장하는 변수

	//약수를 찾을 때는, 1부터 N까지의 숫자를 검사할 수도 있지만, N/2보다 큰 N의 약수는 존재할 수 없다(자기자신은 제외)
	//따라서 N/2까지만 약수를 검사하면 된다.
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0) { //num%i == 0 ->i 는 num의 약수
			divisor[factorCount] = i;
			factorCount++;
		}
	}

	//divisor 배열에 담긴 모든 약수의 합계를 더한다.
	int sum = 0; //약수들의 합계
	for (int i = 0; i < factorCount; i++) {
		sum += divisor[i];
	}
	
	free(divisor);
	//만약 sum == num 이면 1, sum!=num이면 0을 반환한다.
	if (sum == num) {
		return 1;
	}
	else {
		return 0;
	}
}

//양의 정수를 입력받는다.
int getNum()
{
	int userNum = 0;
	while (userNum <= 0) {
		printf("Input a positive integer: ");
		scanf_s("%d", &userNum);

		if (userNum <= 0)printf("%d is not a positive integer\n");
	}

	return userNum;
}

void printPerfect(int endNum)
{
	int startNum = 1; //시작 숫자, 기본적으로 1부터 검사한다.
	printf("Perfect numbers from %d to %d are as follows:\n", startNum, endNum);

	//startNum(1)부터 끝 넘버까지 검사
	for (int i = startNum; i <= endNum; i++) {
		if (perfect(i)) { //i가 perfect Number라면 i값 출력
			printf("%d	", i);
		}
	}
	printf("\n");
}

int main(void)
{
	int userNum = getNum();
	printPerfect(userNum);

	return 0;
}
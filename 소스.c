#include <stdio.h>
#include <stdlib.h>

//Return true if num is a perfect number.
//Return false if num is not a perfect number.
int perfect(int num)
{
	//����� ������ �迭�� ������ ū ũ��� �����Ѵ�
	//N�� ����� ������ N������ Ŭ ���� �����Ƿ� N�� ũ���� �迭�� �����Ѵ�.
	int* divisor = (int*)malloc(sizeof(int)*num);
	int factorCount = 0; //����� ������ �����ϴ� ����

	//����� ã�� ����, 1���� N������ ���ڸ� �˻��� ���� ������, N/2���� ū N�� ����� ������ �� ����(�ڱ��ڽ��� ����)
	//���� N/2������ ����� �˻��ϸ� �ȴ�.
	for (int i = 1; i <= num / 2; i++) {
		if (num % i == 0) { //num%i == 0 ->i �� num�� ���
			divisor[factorCount] = i;
			factorCount++;
		}
	}

	//divisor �迭�� ��� ��� ����� �հ踦 ���Ѵ�.
	int sum = 0; //������� �հ�
	for (int i = 0; i < factorCount; i++) {
		sum += divisor[i];
	}
	
	free(divisor);
	//���� sum == num �̸� 1, sum!=num�̸� 0�� ��ȯ�Ѵ�.
	if (sum == num) {
		return 1;
	}
	else {
		return 0;
	}
}

//���� ������ �Է¹޴´�.
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
	int startNum = 1; //���� ����, �⺻������ 1���� �˻��Ѵ�.
	printf("Perfect numbers from %d to %d are as follows:\n", startNum, endNum);

	//startNum(1)���� �� �ѹ����� �˻�
	for (int i = startNum; i <= endNum; i++) {
		if (perfect(i)) { //i�� perfect Number��� i�� ���
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
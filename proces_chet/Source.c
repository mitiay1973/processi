#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <Windows.h>

int main(int argc, char** argv)
{
	FILE* otvet = fopen("Otvet.txt", "w+");
	float Disckiriminant, x1, x2;
	float a = strtol(argv[1],NULL,10);
	float b = strtol(argv[2], NULL, 10);
	float c = strtol(argv[3], NULL, 10);
	Disckiriminant = b * b - 4 * a * c;
	if ((a != 0) && (b != 0) && (c != 0))
	{
		Disckiriminant = b * b - 4 * a * c;
		if (Disckiriminant < 0)
		{
			printf("������ ���");
			fprintf(otvet, "������������ = %f ������ ���", Disckiriminant);
			fclose(otvet);

		}
		else if (Disckiriminant == 0)
		{
			x1 = -b / (2 * a);
			fprintf(otvet, "������������ = %f ���������� ������:1 x: %f ", Disckiriminant, x1);
			fclose(otvet);
		}
		else if (Disckiriminant > 0)
		{
			x1 = (-b + sqrt(Disckiriminant)) / (2 * a);
			x2 = (-b - sqrt(Disckiriminant)) / (2 * a);
			printf("x1: % f x2 : % f", x1, x2);
			fprintf(otvet, "������������ = %f ���������� ������:2 x1: %f x2: %f", Disckiriminant, x1, x2);
			fclose(otvet);
		}
	}
	else if ((c == 0) && (b == 0))
	{
		x1 = 0;
		printf("������ ��������� = %f ", x1);
		fprintf(otvet, "������ ��������� = %f ", x1);
		fclose(otvet);
	}
	else if (b == 0)
	{

		if (-c / a < 0)
		{
			printf("�� ����� ������");
		}
		else
		{
			x1 = sqrt((-c / a));
			printf("����� ��������� = %f � -%f", x1, x1);
			fprintf(otvet, "����� ��������� = %f � -%f", x1, x1);
			fclose(otvet);
		}
	}
	else if (c == 0)
	{
		x1 = -b / a;
		x2 = 0;
		printf("����� ��������� = %f � %f", x1, x2);
		fprintf(otvet, "����� ��������� = %f � %f", x1, x2);
		fclose(otvet);
	}
	else if (a == 0)
	{
		x1 = -c / b;
		printf("������ ��������� = %f ", x1);
		fprintf(otvet, "����� ��������� = %f ", x1);
		fclose(otvet);
	}
	return 0;
}

	
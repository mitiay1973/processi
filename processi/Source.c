#define _CRT_SECURE_NO_WARNINGS
#define _CRT_NONSTDC_NO_DEPRECATE
#include <stdio.h>
#include<stdlib.h>
#include <math.h>
#include <Windows.h>

#define PATH "C:\\Users\\СорокинДА\\source\\repos\\processi\\x64\\Debug\\proces_chet.exe "

void main()
{
	system("chcp 1251> nul");
	FILE* file;
	char line[254];
	float x1, x2;
	float a1 = 0, b1 = 0, c1 = 0, a11=0,b11=0,c11=0;
	if ((file = fopen("zadacha.txt", "r")))
	{
		fgets(line, 254, file);
		int cha = 0;
		double apr = 0;
		int ymna = 1;
		for (int i = 0; i < 255; i++)
		{
			if (line[i] != 32)
			{
				cha++;
			}
			else
			{
				break;
			}
		}
		for (int i = cha - 1; i >= 0; i--)
		{
			if (line[i] == 46)
			{
				int chha = 1;
				for (int j = 1; j < cha - i; j++)
				{
					chha = chha * 10;
				}
				a11 = a1;
				a1 = a1 / chha;
				ymna = 1;
			}
			else
			{
				if (line[0] == 45)
				{
					if (line[i] != 45)
					{
						apr = line[i] - '0';
						a1 += apr * ymna;
						ymna = ymna * 10;
					}
					else
					{
						a1 = a1 * -1;
					}
				}
				else
				{
					apr = line[i] - '0';
					a1 += apr * ymna;
					ymna = ymna * 10;
				}
			}
		}

		int chb = cha;
		double bpr = 0;
		int ymnb = 1;
		for (int i = cha + 1; i < 255; i++)
		{
			if (line[i] != 32)
			{
				chb++;
			}
			else
			{
				break;
			}
		}
		for (int i = chb; i >= cha + 1; i--)
		{
			if (line[i] == 46)
			{
				int chhb = 1;
				for (int j = 1; j < chb + 1 - i; j++)
				{
					chhb = chhb * 10;
				}
				b11 = b1;
				b1 = b1 / chhb;
				ymnb = 1;
			}
			else
			{
				if (line[cha + 1] == 45)
				{
					if (line[i] != 45)
					{
						bpr = line[i] - '0';
						b1 += bpr * ymnb;
						ymnb = ymnb * 10;
					}
					else
					{
						b1 = b1 * -1;
					}
				}
				else
				{
					bpr = line[i] - '0';
					b1 += bpr * ymnb;
					ymnb = ymnb * 10;
				}
			}
		}
		int chc = chb;
		double cpr = 0;
		int ymnc = 1;
		for (int i = chb + 2; i < 255; i++)
		{
			if (line[i] != -52)
			{
				chc++;
			}
			else
			{
				break;
			}
		}
		for (int i = chc; i >= chb + 2; i--)
		{
			if (line[i] == 46)
			{
				int chhc = 1;
				for (int j = 1; j < chc + 1 - i; j++)
				{
					chhc = chhc * 10;
				}
				c11 = c1;
				c1 = c1 / chhc;
				ymnc = 1;
			}
			else
			{
				if (line[chb + 2] == 45)
				{
					if (line[i] != 45)
					{
						cpr = line[i] - '0';
						c1 += cpr * ymnc;
						ymnc = ymnc * 10;
					}
					else
					{
						c1 = c1 * -1;
					}
				}
				else
				{
					cpr = line[i] - '0';
					c1 += cpr * ymnc;
					ymnc = ymnc * 10;
				}
			}
		}
	}
	STARTUPINFO si;
	PROCESS_INFORMATION pi = { 0 };
	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(pi));
	char* koef = malloc(100);
	char sta[20];
	char stb[20];
	char stc[20];
	char staa[20];
	char stbb[20];
	char stcc[20];
	itoa(a1, sta, 10);
	itoa(b1, stb, 10);
	itoa(c1, stc, 10);
	itoa(a11, staa, 10);
	itoa(b11, stbb, 10);
	itoa(c11, stcc, 10);
	snprintf(koef, 100, "%s %s.%s %s.%s %s.%s",PATH ,sta,staa,stb,stbb, stc,stcc);
	if (!CreateProcessA(NULL,koef, NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi))
	{
		printf("Ошибка");
	}
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
}
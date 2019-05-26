#include<iostream>
#include<fstream>
#include<cstdio>
#include<cstdlib>
#include<conio.h>
#include<string>
#include<vector>
using namespace std;

char map[100][100];
bool ending[100][100];
fstream source;
int column, row;
int temps;
char trace[100000][100][100];
int run;
void buildBool() {
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			if (map[i][j] == '2') ending[i][j] = true;
		}
}
void check() {
	int k = 0;
	for (int i = 0; i < row; i++){
		for (int j = 0; j < column; j++) {
			cout << map[i][j];
			if (i == 0 && j == column-1) { cout << "                               �ثe�@���F " << temps << " �B ";  j++ ; }	
			}
		cout << endl;
	}
	cout << "\n��Jr (�B��>0) �i�H��^�W�@�B" << endl;
}
void trackON(){

	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++) {
			trace[run][i][j] = map[i][j];
		}
	run += 1;
	temps += 1;
}
void Print_rule()
{
	system("color A");
	cout << "�w��Ө�ܮw�f�A�H�U���ҹ� : " << endl;

	cout << "     ///////\n     /01--2/\n     ///////" << endl;

	cout << "�W�h�� : �m�ܮw�f�n���C���W�h�A�h�O��t�u�H�����a�A�H�u���v���覡�A���ʽc�l�C�i�H�b�S����ê���]�p���������ê���^�����p�U�A�V���B�k�B�W�B�U���a�貾�ʡC�N�c�l���ʨ���w�I�A�F����w�ƶq�A�Y�i�L���C\n";
	cout << "\n�����a���ʽc�l�A������n�`�N�G\n\n";
	cout << "����������c�l�A���a�N���i�H�I������A��c�l���^��ųB�C�Y�c�l�u��H�u�Q���v���覡�Q���ʡA���O�H�u�Q�ԡv���覡�Q���ʡC\n���p�G���a���������A����������ⰼ�S����ê���A�h���a�i�H�³o��Ӥ��P����V�����c�l�C\n";
	cout << " /(��)\n -(�D��)\n 0(�H���X�o�I)\n 1(�c�l)\n 2(���I)\n" << endl;
	system("pause");
	system("CLS");
	system("color F");
}
int Flag()
{
	int out = 1;
	for (int i = 0; i < row; i++)
		for (int j = 0; j < column; j++)
		{
			if (ending[i][j] == true) { out = 0; break; }
		}
	return out;
}
int play(int x, int y) {

	temps = 0;
	int c;
	check();
	run = 1;
	memset(ending,'0', sizeof(ending));
	buildBool();
	while (!Flag()) {
		c = getch();
		if (temps>0 && c == 'r') //back
		{
			system("cls");
			for (int i = 0; i < row; i++)
				for (int j = 0; j < column; j++) {
					map[i][j] = trace[temps - 1][i][j];
					if (map[i][j] == '0'){x = i; y = j;}
				}
			temps -= 1;
			run -= 1;
		}
		else if (c == 224) {  //c==224  224 is up,down,lefy,right command
				c = getch();
				system("cls");
				switch (c) {
					case 80:
						//cout << "�U" << endl;
						if (map[x + 1][y] != '/')
						{
							if (map[x + 1][y] == '-' && map[x + 1][y] != '1') {
								map[x + 1][y] = '0'; map[x][y] = '-'; x += 1; trackON();
							}
							else if (map[x + 1][y] == '1')
							{
								if (map[x + 2][y] == '2') {
									map[x + 1][y] = '0'; map[x + 2][y] = '1'; map[x][y] = '-'; ending[x+2][y] = false; x += 1; trackON();
								}
								else if (map[x + 2][y] != '/') {
									map[x + 2][y] = '1'; map[x + 1][y] = '0'; map[x][y] = '-';x += 1; trackON();
								}
							}
						}
						break;

					case 72:
					//cout << "�W" << endl;

					if (map[x - 1][y] != '/')
					{
						if (map[x - 1][y] == '-' && map[x - 1][y] != '1') {
							map[x - 1][y] = '0'; map[x][y] = '-'; x -= 1; trackON();
						}
						else if (map[x - 1][y] == '1')
						{
							if (map[x - 2][y] == '2') {
								map[x - 1][y] = '0'; map[x - 2][y] = '1'; map[x][y] = '-'; ending[x - 2][y] = false; x -= 1; trackON();
							}
							else if (map[x - 2][y] != '/') {
								map[x - 2][y] = '1'; map[x - 1][y] = '0'; map[x][y] = '-';  x -= 1; trackON();
							}
						}
					}
					break;
					case 75:
					//cout << "��" << endl;
					if (map[x][y - 1] != '/')
					{
						if (map[x][y - 1] == '-' && map[x][y - 1] != '1') {
							map[x][y - 1] = '0'; map[x][y] = '-'; y -= 1; trackON();
						}
						else if (map[x][y - 1] == '1')
						{
							if (map[x][y - 2] == '2') {
								map[x][y - 1] = '0'; map[x][y - 2] = '1'; map[x][y] = '-'; ending[x][y-2] = false; y -= 1; trackON();
							}
							else if (map[x][y - 2] != '/') {
								map[x][y - 2] = '1'; map[x][y - 1] = '0'; map[x][y] = '-';  y -= 1; trackON();
							}
						}
					}
					break;
					case 77:
					//cout << "�k" << endl;
					if (map[x][y + 1] != '/')
					{
						if (map[x][y + 1] == '-' && map[x][y + 1] != '1') { map[x][y + 1] = '0'; map[x][y] = '-'; y += 1; trackON();
						}
						else if (map[x][y + 1] == '1')
						{
							if (map[x][y + 2] == '2') {
								map[x][y + 1] = '0'; map[x][y + 2] = '1'; map[x][y] = '-'; ending[x][y+2] = false; y += 1; trackON();
							}
							else if (map[x][y + 2] != '/') {
								map[x][y + 2] = '1'; map[x][y + 1] = '0'; map[x][y] = '-'; y += 1; trackON();
							}
						}
					}
					break;
					default:break;
				}
			}
				else continue; //avoid another key
		check();

	}
	if (Flag() == 1) {cout << "\nCompleted !! " << endl; system("pause");}
	return Flag();
}
int main()
{
	int startx, starty;
	int result;
	source.open("allmission.txt", ios::in);
	if (!source)
	{
		cerr << "map doesn't exist !";
		exit(1);
	}
	Print_rule();
	for (int time = 0; time < 3; time++)
	{
		memset(map, 'o', sizeof(map));
		source >> row >> column;
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				source >> map[i][j];
				if (map[i][j] == '0') { startx = i; starty = j; }
			}
		}
		//initialize trace 0 by original map
	
		for (int i = 0; i < row; i++) {
			for (int j = 0; j < column; j++) {
				trace[0][i][j] = map[i][j];
				//cout << trace[0][i][j];  <-it's use to scout trace matrix
				}
			//cout << endl;
		}
			
			switch (time) {
			case 0:
				cout << "�բϢۢӡ@�ݢܢ� \n�Y�N�}�l" << endl;
				system("pause");
				system("CLS");
				result = play(startx, starty);
				system("cls");
				if (result == 1) cout << "\n���ߧAĹ�o�Ĥ@��   �@���F " << temps << " �B !!\n" << endl;
				system("pause");
				system("CLS");
				break;
			case 1:
				cout << "�բϢۢӡ@����  \n�Y�N�}�l" << endl;
				system("pause");
				system("CLS");
				result = play(startx, starty);
				system("cls");
				if (result == 1) cout << "\n���ߧAĹ�o�ĤG��   �@���F " << temps << " �B !!\n" << endl;
				system("pause");
				system("CLS");
				break;
			case 2:
				cout << "�բϢۢӡ@��֢�Ӣ�  \n�Y�N�}�l" << endl;
				system("pause");
				system("CLS");
				result = play(startx, starty);
				system("cls");
				if (result == 1) cout << "\n���ߧAĹ�o�ĤT��   �@���F " << temps << " �B !!\n" << endl;
				system("pause");
				break;
			}
		}
		system("cls");
		cout << "\n\n\n     �C �� �� ��   " << endl;
		source.close();
		return 0;
	}

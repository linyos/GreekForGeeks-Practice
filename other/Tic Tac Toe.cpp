#include <iostream>
using namespace std;



// �ӧQ�P�_
bool winner(char map[3][3]) {
	for (int  i = 0; i < 3; i++)
	{
		// �C�ӧQ�P�_
		if (map[i][0] != ' ' && map[i][0] == map[i][1] && map[i][1]==map[i][2])
		{
			return true;
		}
	}

	for (int i = 0; i < 3; i++)
	{
		if (map[0][i] != ' ' && map[0][i]==map[1][i] && map[1][i] == map[i][2])
		{
			return true;
		}
	}

	if (map[0][0] != ' ' && map [0][0] ==map[1][1] && map[1][1] ==map[2][2])
	{
		return true;
	}
	if (map[0][2] != ' ' && map[0][2] == map[1][1] && map[1][1] == map[0][2])
	{
		return true;
	}
	return false;
}



// �P�_�O�_�o��l���m�X�l
bool  TFset(char Player, int Switch, char map[3][3]) {
	// �Ĥ@�C�P�_
	if (Switch==7 && map [0][0]==' ' )
	{
		map[0][0] = Player;
		return true;
	}
	else if (Switch==8 && map[0][1]==' ')
	{
		map[0][1] = Player;
		return true;
	}
	else if (Switch==9 && map[0][2]==' ')
	{
		map[0][2] = Player;
		return true;
	}

	// �ĤG�C�P�_
	else if (Switch == 4 && map[1][0] == ' ')
	{
		map[1][0] = Player;
		return true;
	}
	else if (Switch == 5 && map[1][1] == ' ')
	{
		map[1][1] = Player;
		return true;
	}
	else if (Switch == 6 && map[1][2] == ' ')
	{
		map[1][2] = Player;
		return true;
	}


	// �ĤT�C�P�_
	else if (Switch == 1 && map[2][0] == ' ')
	{
		map[2][0] = Player;
		return true;
	}
	else if (Switch == 2 && map[2][1] == ' ')
	{
		map[2][1] = Player;
		return true;
	}
	else if (Switch == 3 && map[2][2] == ' ')
	{
		map[2][2] = Player;
		return true;
	}

	else
	{
		cout << "Input InValidate" << endl;
	}


}

void show(char map[3][3]) {
	for (int i = 0; i < 3; i++){
		cout << "�СССС�" << endl;
		for (int j = 0; j < 3; j++){
			cout << "|" << map[i][j] << " ";	
		}
		cout << "|" << endl;
	}
	cout << " �СССС�" << endl;
}

int main() {
	char map[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };//�Ŧa��
	char Player = 'O';//�Ĥ@���Ѥl��O  
	int Switch;//���U���Ʀr�䱱�
	show(map);
	while (1)
	{
		cout << "�]�����h�X�A�Ʀr���ӤE�c��^" << endl;
		cin >> Switch;

		// ��J0 == end
		if (Switch == 0)
		{
			break;
		}

		system("CLS"); //�M���e�����t�Φr

		bool TFSet = TFset(Player, Switch, map);
		show(map);

		if (winner(map) == true)
		{
			cout << Player << " Winner " << endl;
			break;
		}

		bool mapover = true;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (map[i][j]==' ')
				{
					mapover = false;
				}
			}
		}
		if (mapover==true)
		{
			cout << "�����ӭt" << endl;
			break;
		}

		if (TFSet==true)
		{
			if (Player=='O')
			{
				Player = 'X';
			}
			else
			{
				Player = 'O';
			}
		}




	}




	show(map);
	system("pause");
	return 0;
}
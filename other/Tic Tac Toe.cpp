#include <iostream>
using namespace std;



// 勝利判斷
bool winner(char map[3][3]) {
	for (int  i = 0; i < 3; i++)
	{
		// 列勝利判斷
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



// 判斷是否這位子能放置旗子
bool  TFset(char Player, int Switch, char map[3][3]) {
	// 第一列判斷
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

	// 第二列判斷
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


	// 第三列判斷
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
		cout << "－－－－－" << endl;
		for (int j = 0; j < 3; j++){
			cout << "|" << map[i][j] << " ";	
		}
		cout << "|" << endl;
	}
	cout << " －－－－－" << endl;
}

int main() {
	char map[3][3] = { {' ',' ',' '},{' ',' ',' '},{' ',' ',' '} };//空地圖
	char Player = 'O';//第一顆棋子為O  
	int Switch;//按下的數字鍵控制項
	show(map);
	while (1)
	{
		cout << "（按０退出，數字鍵比照九宮格）" << endl;
		cin >> Switch;

		// 輸入0 == end
		if (Switch == 0)
		{
			break;
		}

		system("CLS"); //清除畫面的系統字

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
			cout << "不分勝負" << endl;
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
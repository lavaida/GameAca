/*

2019.04.01.home 杉


引薦.


case 1.

textRPG 幻級奄

- 巴傾戚嬢澗 送穣引 端径, 因維径 去税 汽戚斗研 握澗陥.
- 惟績聖 獣拙馬檎 巴傾戚嬢税 送穣 識澱敗.(穿紫, 原狛紫, 亀旋 去)
- 蝶遣斗研 持失馬檎 蝶遣斗税 舛左澗 雌獣 左食捜. (五敢, 紫撹斗 去)
- 五敢拭辞澗 揮穿聖 壱研 呪 赤陥.(段厭, 掻厭, 壱厭 去)
- 揮穿 鎧 去舌馬澗 佼什斗澗 戚硯引 因維径, 端径聖 握澗陥.
- 唖 揮穿 紺 去舌馬澗 佼什斗税 曽嫌人 管径帖澗 陥牽陥.
- 揮穿 脊舌 板 因維/亀諺 去税 識澱走亜 爽嬢遭陥.
- 因維 識澱 獣 巴傾戚嬢税 因維径幻鏑 佼什斗税 端径戚 碍焼像.
(益 鋼企税 井酔亀 背雁 喫)
- 佼什斗税 端径戚 "0"戚 鞠檎 紫撹 失因! 戚板, 五敢稽 宜焼紳陥.
- 巴傾戚嬢税 端径戚 "0"戚 鞠檎 紫撹 叔鳶!
- 巴傾戚嬢 紫諺 獣 五敢 識澱但生稽 宜焼神惟 鞠悟, 端径精 段奄葵生稽 仙竺舛吉陥.


 衣厩殖 馬蟹税 姥繕端稽 巴傾戚嬢人 佼什斗研 馬蟹稽...
 疑旋 拝雁聖 搭廃 梓端 持失
 佼什斗澗 敗呪 鎧拭辞 梓端 持失,
 希鷺 匂昔斗 紫遂背辞 什砺戚斗什亀 竺舛

*/

#include <iostream>
#include <cstdio>
#include <ctime>
#include <Windows.h>
#include <conio.h>

#define TRUE 1
#define FALSE 0

using std::cout;
using std::endl;
using std::cin;

typedef struct CharacterType {

	char className[16];
	int currentHp;
	int maxHp;
	int damage;

} Character;


void playTextRPG(void);

void printTRPGTitle(void); // 段奄 展戚堂 鉢檎

void printClassMenu(void);
Character* selectClass(void); // 適掘什 識澱

void initCharacter(Character **dpPlayer, char *name, int maxHp, int damage);

void printStatus(const Character player, const Character monster); // 巴傾戚嬢 + 佼什斗 UI
void printCharacterStatus(const Character character); // 蝶遣斗 UI

enum BATTLE { RUN, AGAIN, HUNT, DIE };
enum CLASS { WARRIOR, WIZARD, THIEF };

int dungeonExploration(Character *pPlayer, Character *pMonster); // 揮穿 貼蝿

void beginnerDungeon(Character **dpMonster); // 背雁 去厭拭 限澗 佼什斗 持失, 鋭乞 朕走檎 沓棋 熱.
void intermediateDungeon(Character **dpMonster);
void advancedDungeon(Character **dpMonster);

int attackMonster(Character *pPlayer, Character *pMonster, bool counterAttack = FALSE); // 因維 or 朝錘斗 限製

int runAwayFromDungeon(const Character player, const Character monster); // 亀諺

//void printWinResult(const Character monster); // 税耕 蒸走幻 益撹 蟹姦獣陥.
//void printLoseResult(const Character monster);

int main(void) {
	srand(unsigned(time(NULL)));

	playTextRPG();

	return 0;
}

void playTextRPG(void) {

	system("mode con cols=110 lines=25"); // 但 滴奄 繕箭.

	Character *pPlayer = nullptr, *pMonster = nullptr;

	int sel = 0;
	int battleLoop = BATTLE::AGAIN;

	//printTRPGTitle();
	pPlayer = selectClass(); // 巴傾戚嬢 持失
	if (pPlayer == nullptr) {

		return;
	}

	while (TRUE) {

		printCharacterStatus(*pPlayer);

		cout << "1.段厭, 2.掻厭, 3.壱厭, 4.曽戟" << endl;
		cout << "脊径: "; cin >> sel;

		switch (sel) {
		case 1:
			beginnerDungeon(&pMonster);
			break;

		case 2:
			intermediateDungeon(&pMonster);
			break;

		case 3:
			advancedDungeon(&pMonster);
			break;
		case 4:
			cout << "惟績聖 曽戟杯艦陥." << endl << endl;

			if (pPlayer != nullptr) {

				delete pPlayer;
				pPlayer = nullptr;
			}
			return;
		default:
			cout << "設公吉 脊径脊艦陥." << endl << endl;
			system("pause");
			continue;
			//break;
		}

		battleLoop = BATTLE::AGAIN;
		while (battleLoop == AGAIN) { // 亀諺, 遭楳, 紫撹 失因, 宋製

			battleLoop = dungeonExploration(pPlayer, pMonster);
		}

		if (pMonster != NULL) { // 穿燈亜 曽戟 鞠醸生糠稽 佼什斗 背薦 獣佃操醤 敗.

			delete pMonster;
			pMonster = NULL;
		}
	}

}

void printTRPGTitle(void) {

	int index = 0;
	int color2[12] = { 7, 8, 7, 0, 15, 7, 8, 7, 0, 15, 8 };
	const int colorSize = 12;

	enum {

		BLOCK,   /*  0 : 猿諺 */
		DARK_BLUE,  /*  1 : 嬢砧錘 督櫛 */
		DARK_GREEN,  /*  2 : 嬢砧錘 段系 */
		DARK_SKY_BLUE, /*  3 : 嬢砧錘 馬潅 */
		DARK_RED,  /*  4 : 嬢砧錘 察悪 */
		DARK_VOILET, /*  5 : 嬢砧錘 左虞 */
		DARK_YELLOW, /*  6 : 嬢砧錘 葛櫛 */
		GRAY,   /*  7 : 噺事 */
		DARK_GRAY,  /*  8 : 嬢砧錘 噺事 */
		BLUE,   /*  9 : 督櫛 */
		GREEN,   /* 10 : 段系 */
		SKY_BLUE,  /* 11 : 馬潅 */
		RED,   /* 12 : 察悪 */
		VOILET,   /* 13 : 左虞 */
		YELLOW,   /* 14 : 葛櫛 */
		WHITE,   /* 15 : 馬丞 */
	};

	while (index < 15) {

		system("cls");
		cout << "\n\n\n\n\n";
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "##############################################################################################################" << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    ######                                              ######                                            " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     #   ##   #####  #    # ######  ####  #####    #     # #    # #    #  ####  ######  ####  #    # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     #  #  #  #    # #   #  #      #        #      #     # #    # ##   # #    # #      #    # ##   # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     # #    # #    # ####   #####   ####    #      #     # #    # # #  # #      #####  #    # # #  # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     # ###### #####  #  #   #           #   #      #     # #    # #  # # #  ### #      #    # #  # # " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    #     # #    # #   #  #   #  #      #    #   #      #     # #    # #   ## #    # #      #    # #   ## " << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "    ######  #    # #    # #    # ######  ####    #      ######   ####  #    #  ####  ######  ####  #    # " << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color2[(index) % colorSize]);
		cout << "##############################################################################################################" << endl;
		cout << "\n\n\n\n\n";

		cout.width(100);
		cout << "Copyright by Vaida _ version 0.1" << endl;

		Sleep(100);
		index++;
	}
}

void printClassMenu(void) {

	system("cls");
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "####### Select Class ##########" << endl;
	cout << "#";
	cout.width(31 - 1);
	cout << "#" << endl;
	cout << "# ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "1. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 4);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
	cout << "穿紫";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << ", ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "2. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 11);
	cout << "原狛紫";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << ", ";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "3. ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 5);
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 13);
	cout << "亀旋 ";
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
	cout << "#" << endl;

	cout << "#";
	cout.width(31 - 1);
	cout << "#" << endl;
	cout << "###############################" << endl;
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

Character* selectClass() {

	int sel = 0;
	Character *pReturn = nullptr;

	while (1) {

		printClassMenu();

		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 7);
		cout << "脊径: "; cin >> sel;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);

		switch (sel) {

		case CLASS::WARRIOR:
			initCharacter(&pReturn, "穿紫", 200, 10);
			break;

		case CLASS::WIZARD:
			initCharacter(&pReturn, "原狛紫", 100, 30);
			break;

		case CLASS::THIEF:
			initCharacter(&pReturn, "亀旋", 150, 20);
			break;

		default:
			cout << "\n設公吉 脊径脊艦陥." << endl << endl;
			system("pause");
			continue;
		}

	}

	return pReturn;
}

void initCharacter(Character **dpPlayer, char *name, int maxHp, int damage) {

	(*dpPlayer) = new Character; // C++ 号縦税 五乞軒 疑旋 拝雁 !!!!
								// 敗呪拭辞 五乞軒 疑旋 拝雁聖 廃 及, 鋼発背爽形壱 希鷺 匂昔斗 紫遂 !!!!
	strcpy_s((*dpPlayer)->className, sizeof((*dpPlayer)->className), name);
	(*dpPlayer)->currentHp = (*dpPlayer)->maxHp = maxHp;
	(*dpPlayer)->damage = damage;
}

void printCharacterStatus(const Character character) {

	system("cls");
	cout << "######  Player Status  #######" << endl;

	cout << "#"; // 1
	cout.width(30 - 1);
	cout << "#" << endl;

	cout << "#   適掘什: [" << character.className << "]"; // 14
	cout.width(30 - (14 + strlen(character.className)));
	cout << "#" << endl;

	cout << "#     端径: ["; // 13
	cout.width(3); // 3
	cout << character.currentHp << "/"; // 1
	cout.width(3); // 3
	cout << character.maxHp << "]"; // 1
	cout.width(30 - 21);
	cout << "#" << endl;

	cout << "#   因維径: "; // 12
	cout.width(3);
	cout << character.damage; // 3
	cout.width(30 - 15);
	cout << "#" << endl;

	cout << "##############################" << endl;
}

// 段厭, 掻厭, 壱厭 揮穿聖 敗呪紺稽 蟹喚 琶推失戚 赤蟹 粛製.
// 蟹掻拭 佼什斗税 託紺鉢虞窮走 希 琶推拝 依 旭製.
void beginnerDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "十虞績", 30, 5);
}
void intermediateDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "茨圭", 120, 35);
}
void advancedDungeon(Character **dpMonster) {

	initCharacter(dpMonster, "燭球軒帖", 300, 70);
}

void printStatus(const Character player, const Character monster) {

	printCharacterStatus(player);
	printCharacterStatus(monster);
}

int dungeonExploration(Character *pPlayer, Character *pMonster) {

	int sel = 0;
	int battleLoop = BATTLE::AGAIN;

	while (battleLoop == BATTLE::AGAIN) {

		printStatus(*pPlayer, *pMonster);

		cout << "1. 因維, 2. 亀諺" << endl;
		cout << "脊径: "; cin >> sel;

		switch (sel) {
		case 1:
			battleLoop = attackMonster(pPlayer, pMonster);
			break;
		case 2:
			cout << "Hello" << endl;
			system("pause");
			battleLoop = runAwayFromDungeon(*pPlayer, *pMonster);
			if (battleLoop == BATTLE::AGAIN) {
				battleLoop = attackMonster(pPlayer, pMonster, TRUE);
			}
			break;

		default:
			cout << "設公吉 脊径脊艦陥." << endl << endl;
			system("pause");
			continue;
			//break;
		}


		// 穿燈 遭楳拭 魚献 戚坤闘 降持
		switch (battleLoop) {
		case BATTLE::RUN:
			//cout << "RUN" << endl;
			break;
		case BATTLE::AGAIN:
			//cout << "AGAIN" << endl;
			break;
		case BATTLE::HUNT:
			//cout << "HUNT" << endl;
			break;

		case BATTLE::DIE:
			//cout << "DIE" << endl;
			break;

		default:
			break;
		}

	}

	return battleLoop;
}


int attackMonster(Character *pPlayer, Character *pMonster, bool counterAttack) {

	int result = AGAIN;

	pPlayer->currentHp -= pMonster->damage;

	if (!counterAttack) { // 亀諺 叔鳶 獣, 巴傾戚嬢澗 鋼維 雁敗.

		pMonster->currentHp -= pPlayer->damage;
	}

	if (pPlayer->currentHp <= 0) { // 巴傾戚嬢 DIE

		pPlayer->currentHp = 0;
		if (pMonster->currentHp <= 0) {

			pMonster->currentHp = 0;
		}

		printStatus(*pPlayer, *pMonster); // 巴傾戚嬢人 佼什斗税 端径聖 飴重.

		if (pMonster->currentHp <= 0) { // 巴傾戚嬢 宋製 && 佼什斗亀 宋製

			cout << "焼鴛惟亀..." << endl;
		}
		cout << "[" << pMonster->className << "] 紫撹 叔鳶 ばば." << endl << endl;
		system("pause");
		//printLoseResult(*pMonster);

		pPlayer->currentHp = pPlayer->maxHp;
		result = BATTLE::DIE;
	}
	else if (pMonster->currentHp <= 0) { // 佼什斗 DIE
		pMonster->currentHp = 0;
		printStatus(*pPlayer, *pMonster);
		cout << "[" << pMonster->className << "] 紫撹 失因 !!!" << endl << endl;
		system("pause");
		//printWinResult(*pMonster);
		result = BATTLE::HUNT;
	}

	return result;
}

int runAwayFromDungeon(const Character player, const Character monster) {

	int coin = rand() % 3;
	if (coin == 0) {
		// 蟹哀掘 !!!
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 3);
		cout << "[" << player.className << "] 精/澗 亀諺 帖澗汽 失因梅柔艦陥." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "[" << monster.className << "]: 照掬! 宜焼人 !!!!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		return BATTLE::RUN;
	}
	else {
		// 嬢渠 蟹亜?!
		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 12);
		cout << "[" << player.className << "] 精/澗 亀諺 帖澗汽 叔鳶 梅柔艦陥." << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 6);
		cout << "[" << player.className << "] : 焼艦 訊?!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		system("cls");
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 14);
		cout << "[" << monster.className << "]: せせせせせせせ !!!!" << endl << endl;
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
		system("pause");

		return BATTLE::AGAIN;
	}
}

//void printWinResult(const Character monster) { // 税耕 蒸走幻 益撹 蟹姦獣陥.
//	cout << "[" << monster.className << "] 紫撹 失因 !!!" << endl << endl;
//	system("pause");
//}
//void printLoseResult(const Character monster) {
//	cout << "[" << monster.className << "] 紫撹 叔鳶 ばば." << endl << endl;
//	system("pause");
//}
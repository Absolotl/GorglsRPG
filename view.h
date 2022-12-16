class View
{
	private:
	std::string line0, line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11, line12;
	std::vector <std::string> lines;
	void drawElements(std::string titel, std::vector <std::string> lines);
	char mapUnknown[MAPHEIGTH][MAPLENGTH];
	std::string status;
	std::string location;
	void revealMap(int posX, int posY)
	{
		mapUnknown[posY][posX] = 'P';
		if (posY+1 < MAPHEIGTH)	{ mapUnknown[posY+1][posX] = mapKnown[posY+1][posX]; }
		if (posX+1 < MAPHEIGTH)	{ mapUnknown[posY][posX+1] = mapKnown[posY][posX+1]; }
		if (posY-1 >= 0)		{ mapUnknown[posY-1][posX] = mapKnown[posY-1][posX]; }
		if (posX-1 >= 0)		{ mapUnknown[posY][posX-1] = mapKnown[posY][posX-1]; }
	}
	void drawTitle();
	void drawCharCreation();
	
	public:
	View()
	{ 
		for (int y = 0; y < MAPHEIGTH; y++) { for (int x = 0; x < MAPLENGTH; x++) { mapUnknown[y][x] = '?'; } }
		drawTitle();
	}
	void drawBattle(Character *a, Character *b);
	void drawItemList(std::vector<Item> list, int index);
	void drawMiniMap(Character a, int posX, int posY);
	void drawMenu();
	void drawMap();

	void setStatus(std::string status) { this->status = status; }
	void setLocation(std::string location) { this->location = location; }

};

void View::drawElements(std::string titel, std::vector<std::string> lines)
{
	for (int i = 0; i < lines.size(); i++)
	{
		while (lines[i].length()<97)
		{
			lines[i].push_back(' ');			
		}
	}
	
	
	if (titel.length() % 2 == 0) titel.push_back(' ');
	while (titel.length() < 97)
	{
		titel.push_back(' ');
		titel.push_back('#');		
	}
	std::cout << "# "<< titel << " #\n";
	for (int i = 0; i < lines.size(); i++)
	{
		if (i == lines.size() -3 && lines.size() == 12)
		{
			std::cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #\n";
		}
		
		std::cout << "# ";
		for (int j = 0; j < lines[i].size(); j++)
		{
			if (j > 41 && j < 56)
			{
				switch (lines[i][j])
				{
				case 'g':
					std::cout << dye::light_yellow(lines[i][j]);
					break;
				case 'r':
					std::cout << dye::blue(lines[i][j]);
					break;
				case 'f':
					std::cout << dye::green(lines[i][j]);
					break;
				case 'm':
					std::cout << dye::grey(lines[i][j]);
					break;
				case 'b':
					std::cout << dye::red(lines[i][j]);
					break;
				case 'H':
					std::cout << dye::red(lines[i][j]);
					break;	
				default:
					std::cout << lines[i][j];
					break;
				}
			}
			else std::cout << lines[i][j];
		}
		
		//std::cout << lines[i];
		std::cout << " #\n";
	}
	std::cout << "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #"  << std::endl;
}

void View::drawBattle(Character *a, Character *b)
{
	int round = 1;
	std::string message1, message2;

	//Line0
	line0 = a->getName();
	while (line0.length() < 48)
	{
		line0.push_back(' ');
	}
	line0.append("# ");
	line0.append(b->getName());
	//Line1
	line1 = "--------+-------------------------------------- # --------+--------------------------------------";
	//Line2
	line2 = "HP      | ";
	if (a->getHpCur() < 100) line2.push_back(' ');
	if (a->getHpCur() < 10) line2.push_back(' ');
	line2.append(std::to_string(a->getHpCur()));
	line2.append(" / ");
	line2.append(std::to_string(a->getHpMax()));
	while (line2.length() < 48)
	{
		line2.push_back(' ');
	}
	line2.append("# HP      | ");
	if (b->getHpCur() < 100) line2.push_back(' ');
	if (b->getHpCur() < 10) line2.push_back(' ');
	line2.append(std::to_string(b->getHpCur()));
	line2.append(" / ");
	line2.append(std::to_string(b->getHpMax()));
	//Line3
	line3 = "HP      | ";
	if (a->getHpCur() < 100) line3.push_back(' ');
	if (a->getHpCur() < 10) line3.push_back(' ');
	line3.append(std::to_string(a->getHpCur()));
	line3.append(" / ");
	line3.append(std::to_string(a->getHpMax()));
	while (line3.length() < 48)
	{
		line3.push_back(' ');
	}
	line3.append("# HP      | ");
	if (b->getHpCur() < 100) line3.push_back(' ');
	if (b->getHpCur() < 10) line3.push_back(' ');
	line3.append(std::to_string(b->getHpCur()));
	line3.append(" / ");
	line3.append(std::to_string(b->getHpMax()));
	//Line4
	line4 = "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #";
	//Line5
	line5 = "Round ";
	line5.append(std::to_string(round++));
	line6 = message1;
	line7 = message2;
	//Line8
	//line8 = "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #";
	//Line9
	line9  = "+---------+------------+-----------+------------+-----------+----------+";
	line10 = "| OPTIONS | [a] Attack | [s] Spell | [d] Defend | [i] Items | [f] Flee |";
	line11 = "+---------+------------+-----------+------------+-----------+----------+";
	
	lines = {line0, line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11};
	drawElements("VERSUS", lines);
}

void View::drawItemList(std::vector<Item> list, int index)
{
	std::vector<std::string> show {"","","","","","","","","",""}; 
	
	for (int i = 0; i < list.size() && i < 8; i++)
	{
		if (i == index) show[i] = "o ";
		else show[i] = "- ";
		show[i].append(list[i].getTitel());
		while (show[i].length() < 26)
		{
			show[i].push_back(' ');
		}		
		show[i].append("| ");
		show[i].append(list[i].getDescription());
	}
	
	line0 = "Name                      | Effect";
	line1 = "--------------------------+----------------------------------------------------------------------";
	line2 = show[0];
	line3 = show[1];
	line4 = show[2];
	line5 = show[3];
	line6 = show[4];
	line7 = show[5];
	line8 = show[6];	
	//line8 = "# # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # # #";
	line9  = "+---------+-------------+---------------+---------+------------+----------+";
	line10 = "| OPTIONS | [8] Move up | [2] Move down | [u] Use | [d] Delete | [b] Back |";
	line11 = "+---------+-------------+---------------+---------+------------+----------+";
	
	lines = {line0, line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11};
	drawElements("ITEMS", lines);	
}

void View::drawMiniMap(Character a, int posX, int posY)
{
	line0 = "Name   | ";
	line0.append(a.getName());
	while (line0.length() < 38)	{ line0.push_back(' ');	}
	line0.push_back('#');
	line1 = "# # # # # # # # # # # # # # # # # # # #";
	line1 = "-------+----------------------------- #";
	line2 = "Class  | ";
	line2.append(a.getClass());
	while (line2.length() < 38)	{ line2.push_back(' ');	}
	line2.push_back('#');
	line7 = line5 = line3 = line1;
	line4 = "Level  | ";
	line4.append(std::to_string(a.getLevel()));
	while (line4.length() < 38)	{ line4.push_back(' ');	}
	line4.push_back('#');
	line6 = "Health | ";
	line6.append(std::to_string(a.getHpCur()) + " / " + std::to_string(a.getHpMax()));
	while (line6.length() < 38)	{ line6.push_back(' ');	}
	line6.push_back('#');
	line8 = "Mana   | ";
	line8.append(std::to_string(a.getManaCur()) + " / " + std::to_string(a.getManaMax()));
	while (line8.length() < 38)	{ line8.push_back(' ');	}
	line8.push_back('#');
	line9  = "+---------+-------------+----------------+---------------+---------------+-----------+----------+";
	line10 = "| OPTIONS | [8] Move up | [6] Move right | [2] Move down | [4] Move left | [i] Items | [m] Menu |";
	line11 = "+---------+-------------+----------------+---------------+---------------+-----------+----------+";


	revealMap(posX, posY);
	line0.append(" + ------------- + # ");
	line1.append(" | ");
	for (int i = -3; i <= 3; i++)
	{
		if (posY - 3 >= 0 && posX + i >= 0 && posX + i < MAPLENGTH) line1.push_back(mapUnknown[posY - 3][posX + i]);
		else line1.push_back('#');
		line1.push_back(' ');
	}
	line1.append("| # ");
	line2.append(" | ");
	for (int i = -3; i <= 3; i++)
	{
		if (posY - 2 >= 0 && posX + i >= 0 && posX + i < MAPLENGTH) line2.push_back(mapUnknown[posY - 2][posX + i]);
		else line2.push_back('#');
		line2.push_back(' ');
	}
	line2.append("| # ");
	line3.append(" | ");
	for (int i = -3; i <= 3; i++)
	{
		if (posY - 1 >= 0 && posX + i >= 0 && posX + i < MAPLENGTH) line3.push_back(mapUnknown[posY - 1][posX + i]);
		else line3.push_back('#');
		line3.push_back(' ');
	}
	line3.append("| # ");
	line4.append(" | ");
	for (int i = -3; i <= 3; i++)
	{
		if (posX + i >= 0 && posX + i < MAPLENGTH) line4.push_back(mapUnknown[posY][posX + i]);
		else line4.push_back('#');
		line4.push_back(' ');
	}
	line4.append("| # ");
	line5.append(" | ");
	for (int i = -3; i <= 3; i++)
	{
		if (posY + 1 < MAPHEIGTH && posX + i >= 0 && posX + i < MAPLENGTH) line5.push_back(mapUnknown[posY + 1][posX + i]);
		else line5.push_back('#');
		line5.push_back(' ');
	}
	line5.append("| # ");
	line6.append(" | ");
	for (int i = -3; i <= 3; i++)
	{
		if (posY + 2 < MAPHEIGTH && posX + i >= 0 && posX + i < MAPLENGTH) line6.push_back(mapUnknown[posY + 2][posX + i]);
		else line6.push_back('#');
		line6.push_back(' ');
	}
	line6.append("| # ");
	line7.append(" | ");
	for (int i = -3; i <= 3; i++)
	{
		if (posY + 3 < MAPHEIGTH && posX + i >= 0 && posX + i < MAPLENGTH) line7.push_back(mapUnknown[posY + 3][posX + i]);
		else line7.push_back('#');
		line7.push_back(' ');
	}
	line7.append("| # ");
	line8.append(" + ------------- + # ");
	mapUnknown[posY][posX] = mapKnown[posY][posX];
	

	line0.append("Location: " + location);
	line1.append("# # # # # # # # # # # # # # # # # # #");
	bool lineBreak1 = true;
	bool lineBreak2 = true;
	for (int i = 0; i < status.length(); i++)
	{		
		if (i < 36)	line2.push_back(status[i]);
		else if (i < 72) {
			if (lineBreak1 == true) line2.push_back('-');
			lineBreak1 = false;
			line3.push_back(status[i]);
		} else if (i < 111) { 
			if (lineBreak2 == true) line3.push_back('-');
			lineBreak2 = false;
			line4.push_back(status[i]);
		}
	}
	
	line5.append("# # # # # # # # # # # # # # # # # # #");
	line6.append("   [8]    # # # # # # # # # # # # # #");
	line7.append("[4] o [6] # # # # # # # # # # # # # #");
	line8.append("   [2]    # # # # # # # # # # # # # #");
	
	lines = {line0, line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11};
	drawElements("#", lines);
}

void View::drawMenu()
{
	line0.erase();
	while (line0.length() < 97)
	{
		line0.push_back(' ');
	}
	line1 = "                                      + ----------------- +                                      ";
	line2 = "                                      |   [m] K a r t e   |                                      ";
	line6 = "                                      | [b] Z u r u e c k |                                      ";
	line10 ="                                      | [q] B e e n d e n |                                      ";
	line3 = line5 = line7 = line9 = line11 = line1;
	line4 = line8 = line12 = line0;
	lines = {line0, line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11, line12};
	drawElements("MENU", lines);
}

void View::drawTitle()
{
	line0 = "                                                                                                 ";
	line1 = "           T T T   H   H   E E E       L       E E E     G G     E E E   N     N   D D           ";
	line2 = "             T     H   H   E           L       E       G         E       N N   N   D   D         ";
	line3 = "             T     H H H   E E E       L       E E E   G   G G   E E E   N N N N   D   D         ";
	line4 = "             T     H   H   E           L       E       G     G   E       N   N N   D   D         ";
	line5 = "             T     H   H   E E E       L L L   E E E     G G     E E E   N     N   D D           ";
	line6 = "                                                                                                 ";
	line7 = "                       O     F F F        G       O     R R       G     L                        ";
	line8 = "                     O   O   F          G       O   O   R   R   G       L                        ";
	line9 = "                     O   O   F F        G   G   O   O   R R     G   G   L                        ";
	line10= "                     O   O   F          G   G   O   O   R R     G   G   L                        ";
	line11= "                       O     F            G       O     R   R     G     L L L                    ";
	line12= "                                                                                                 ";
	lines = {line0, line1, line2, line3, line4, line5, line6, line7, line8, line9, line10, line11, line12};
	
	drawElements("#", lines);
}

void View::drawCharCreation()
{
	line1 = "";
}

void View::drawMap()
{
	std::cout << "Here is the map:\n";
	for (int i = 0; i < MAPHEIGTH; i++)
	{
		for (int j = 0; j < MAPLENGTH; j++)
		{
			switch (mapKnown[i][j])
			{
			case 'g':
				std::cout << dye::light_yellow(mapKnown[i][j]);
				break;
			case 'r':
				std::cout << dye::blue(mapKnown[i][j]);
				break;
			case 'f':
				std::cout << dye::green(mapKnown[i][j]);
				break;
			case 'm':
				std::cout << dye::grey(mapKnown[i][j]);
				break;
			case 'b':
				std::cout << dye::red(mapKnown[i][j]);
				break;
			case 'H':
				std::cout << dye::red(mapKnown[i][j]);
				break;	
			default:
				std::cout << mapKnown[i][j];
				break;
			}
			std::cout << ' ';
		}
		std::cout << '\n';
	}	
	std::cout <<"press Enter to return.";
	std::cin;
	std::cout << '\n';
	drawMenu();
}


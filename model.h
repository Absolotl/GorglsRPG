class Model
{
	private:
	int tableId = 0;
	int posX, posY;
	int index = 0;
	int nItems = 0;
	Character *a;
	Character *b;
	void rollingDice(int rn);
	std::string checkTile(char tile);

	public:
	Model(std::string name, int klasse)
	{
		posX = START_X;
		posY = START_Y;
		a = new Character(klasse, false);
		a->setName(name);
	}
	Character getPlayer() { return *a; }
	int getPositionX() { return posX; }
	int getPositionY() { return posY; }
	int getIndex() { return index;}

	//Map
	std::string moveUp() 	{if (posY - 1 >= 0) {--posY;} 		return checkTile(mapKnown[posY][posX]);}
	std::string moveRight()	{if (posX + 1 < MAPLENGTH) {++posX;}return checkTile(mapKnown[posY][posX]);}
	std::string moveDown() 	{if (posY + 1 < MAPHEIGTH) {++posY;}return checkTile(mapKnown[posY][posX]);}
	std::string moveLeft() 	{if (posX - 1 >= 0) {--posX;} 		return checkTile(mapKnown[posY][posX]);}

	//List
	void nextEntry()
	{
		if (index + 1 < (a->getBag().size())) index++;
		else index = 0;			
	}
	void previousEntry()
	{ 
		if (index - 1 >= 0)	index--;		
		else index = (a->getBag().size() - 1);
	}
	std::string rnjeesus(int rn);
	void useItem()
	{
		if (a->getBag().size() > 0)
		{
			std::cout << "index: " << index << '\n';
			a->getBag().erase(a->getBag().begin() + index);
			nItems--;
			index--;
		}		
	}

//Destruktor
	~Model()
	{
		std::cout << "Model Destruktor\n";
		delete a;
		a = NULL;
		delete b;
		b = NULL;
	}
};

void Model::rollingDice(int rn)
{
	std::cout << "Nr.: " << rn;
	if (rn < 5)
	{
		/* code */
	}
	else if (rn < 16)
	{
		/* code */
	}	
}

std::string Model::checkTile(char tile)
{
	switch (tile)
	{
	case 'g':
		return "Grasslands";
	case 'f':
		return "Forest";
	case 'm':
		return "Mountain";
	case 'H':
		return "Your moms house :P";
	case 'b':
		return "Bridge";
	case 'r':
		return "River";
	default:
		return "Somewhere in Space";
	}
}

std::string Model::rnjeesus(int rn)
{
	switch (rn)
	{
	case 5:
	case 15:
	case 25:
	case 35:
	case 45:
		a->gotItem(*new Item(1));
		nItems++;
		return ("got Item: " + a->getBag()[a->getBag().size()-1].getTitel());
	case 55:
	case 65:
	case 75:
	case 85:
	case 95:
		a->gotItem(*new Item(0));
		nItems++;
		return ("got Item: " + a->getBag()[a->getBag().size()-1].getTitel());
	case 10:
	case 30:
	case 50:
	case 60:
	case 70:
		return "A wild Fitzli appears! TODO";
	default:
		return ("random Number: " + std::to_string(rn));
	}
}
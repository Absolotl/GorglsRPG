class Controller
{
	private:
	View *view;
	Model *model;
	char input;
	bool menuBattle, menuItem, menuMain;
	bool menuMap = true;
	bool processUserInput(char input);
	std::random_device dev;

	public:
	Controller(View *view, Model *model)
	{
		this->view = view;
		this->model = model;
		view->setLocation("Home");
		view->drawMiniMap(model->getPlayer(), START_X, START_Y);
	}	
	void getUserInput()
	{
		std::cout << "Input: ";
		std::cin >> input;
		std::cout << '\n'; 
		if (processUserInput(input) == false) 
		{
			std::cout << "Wrong input.\n";
			getUserInput();
		}
		if (input != 'q' && input != 'Q') getUserInput();
	}	
};

bool Controller::processUserInput(char input)
{
	std::mt19937 rng(dev());
	std::uniform_int_distribution<std::mt19937::result_type> distributer(1, 100);
	switch (input)
	{
	case '8':
		if (menuItem == true) 
		{
			model->previousEntry();
			view->drawItemList(model->getPlayer().getBag(), model->getIndex());
		}
		else if (menuMap == true) 
		{
			view->setLocation(model->moveUp());
			view->setStatus(model->rnjeesus(distributer(rng)));
			view->drawMiniMap(model->getPlayer(), model->getPositionX(), model->getPositionY());			
		}
		else return false;
		return true;
	case '6':
		if (menuMap == true) 
		{
			view->setLocation(model->moveRight());
			view->setStatus(model->rnjeesus(distributer(rng)));
			view->drawMiniMap(model->getPlayer(), model->getPositionX(), model->getPositionY());	
		}
		else return false;
		return true;
	case '2':
		if (menuItem == true)
		{
			model->nextEntry();
			view->drawItemList(model->getPlayer().getBag(), model->getIndex());
		}
		else if (menuMap == true) 
		{
			view->setLocation(model->moveDown());
			view->setStatus(model->rnjeesus(distributer(rng)));
			view->drawMiniMap(model->getPlayer(), model->getPositionX(), model->getPositionY());
		}
		else return false;
		return true;
	case '4':
		if (menuMap == true) 
		{
			view->setLocation(model->moveLeft());
			view->setStatus(model->rnjeesus(distributer(rng)));
			view->drawMiniMap(model->getPlayer(), model->getPositionX(), model->getPositionY());
		}
		else return false;
		return true;
	case 'A':
	case 'a':
		/* code */
		return true;
	case 'S':
	case 's':
		/* code */
		return true;
	case 'D':
	case 'd':
		/* code */
		return true;
	case 'I':
	case 'i':
		if (menuMap == true)
		{
			menuItem = true;
			menuMap = false;
			view->drawItemList(model->getPlayer().getBag(), model->getIndex());
			return true;
		}
		else return false;
	case 'F':
	case 'f':
		/* code */
		return true;
	case 'M':
	case 'm':
		if (menuMap == true)
		{
			view->drawMenu();
			menuMain = true;
			menuMap = false;
			return true;
		}
		else if (menuMain == true)
		{
			view->drawMap();
			return true;
		}		
		else return false;
	case 'U':
	case 'u':
		if (menuItem == true)
		{
			model->useItem();
			view->drawItemList(model->getPlayer().getBag(), model->getIndex());
		}
		
		return true;
	case 'B':
	case 'b':
		if (menuItem == true || menuMain == true)
		{
			menuMain = false;
			menuItem = false;
			menuMap = true;
			view->drawMiniMap(model->getPlayer(), model->getPositionX(), model->getPositionY());
			return true;
		}
		else return false;
	case 'Q':
	case 'q':
		if (menuMain == true) return true;
		else return false;
	default:
		return false;
	}
	return false;
}
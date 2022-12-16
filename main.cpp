#include <iostream>
#include <string>
#include <chrono>
#include <thread>
#include <vector>
#include <random>
#include "../Libs/color-console-master/include/color.hpp"

#include "Character.h"
#include "Class.h"
#include "map.h"
#include "model.h"
#include "view.h"
#include "controller.h"


int main()
{
	std::string name;
	int klasse;
	View view;

	//setup Character
	std::cout <<"\n> What's your Name? ";
	std::cin >> name;
	std::cout <<"\n\n> Choose a Class: ";
	std::cin >> klasse;		
	std::cout << "\n\n";	

	Model *model = new Model(name, klasse);

	Controller *controller = new Controller(&view, model);

	controller->getUserInput();

	std::cout << "Bye Bye\n" << std::endl;
	delete model;
	model = NULL;

	return 0;
}
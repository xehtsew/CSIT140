#include <iostream>
#include <string>
#include "Game.h"
#include "Addition.h"
#include "Subtraction.h"
#include "Multiplication.h"
#include "Division.h"

using namespace std;

int main() {
	//create game object
	Game g;
	//call the splashscreem
	g.splashScreen();
	//start game
	g.menu();
	return 0;
}
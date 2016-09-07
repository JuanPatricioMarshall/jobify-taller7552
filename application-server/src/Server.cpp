#include "Server.h"
#include <thread>

using namespace std;

Server::Server() {
	running = false;
	clientHandler = new ClientHandler();
	sharedServerHandler = new SharedServerHandler();	
}

bool Server::isReady(){
	return (sharedServerHandler->isRunning() && clientHandler->isRunning());
}

Server::~Server() {
	delete sharedServerHandler;
	delete clientHandler;
}

void Server::startClientHandler(){
	clientHandler->run();	
}

void Server::startSharedServerHandler(){
	sharedServerHandler->run();
}

void Server::run(){
	running = true;
	thread t_clientHandler(&Server::startClientHandler,this);
	thread t_sharedServerHandler(&Server::startSharedServerHandler,this);

	//todo SACAR. Es solo para que mustre algo. De hecho los metodos van a ser diferentes
	sharedServerHandler->connectToUrl("http://jobify-professional.herokuapp.com/db", NULL, NULL);

	while (running)
	{//Coordinacion de client con shared

	}
	

	//Llega a hacer el join? ver SWAP
	t_clientHandler.join();
	t_sharedServerHandler.join();
}

void Server::stop(){
	running = false;
	clientHandler->stop();
	sharedServerHandler->stop();
}

#include "Server.h"
#include <thread>

using namespace std;

Server::Server() {
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
	thread t_clientHandler(&Server::startClientHandler,this);
	thread t_sharedServerHandler(&Server::startSharedServerHandler,this);
	//Llega a hacer el join? ver SWAP
	t_clientHandler.join();
	t_sharedServerHandler.join();
}
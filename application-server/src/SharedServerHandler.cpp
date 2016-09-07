#include "SharedServerHandler.h"

SharedServerHandler::SharedServerHandler(){
	running = true;
}

SharedServerHandler::~SharedServerHandler() {
   mg_mgr_free(&manager);
}

bool SharedServerHandler::isRunning(){
	return SharedServerHandler::running;
}

void SharedServerHandler::run() {
	while(running){}

}

void SharedServerHandler::stop(){
	mtx.lock();
	running = false;
	mtx.unlock();
}
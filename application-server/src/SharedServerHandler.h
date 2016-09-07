#ifndef SHAREDSERVERHANDLER_H_
#define SHAREDSERVERHANDLER_H_

#include "../src/3rdparty/mongoose/mongoose.h"

class SharedServerHandler {
public:
	SharedServerHandler();

	virtual ~SharedServerHandler();

    bool isRunning();

    void run();

private:
	bool running;
    struct mg_mgr manager; //Se usa si va con Mongoose 
};

#endif /* SHAREDSERVERHANDLER_H_ */
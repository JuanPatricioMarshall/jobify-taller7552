#ifndef SHAREDSERVERHANDLER_H_
#define SHAREDSERVERHANDLER_H_

#include "../src/3rdparty/mongoose/mongoose.h"
#include <mutex>

class SharedServerHandler {
public:
	SharedServerHandler();

	virtual ~SharedServerHandler();

    bool isRunning();

    void run();

    void stop();

private:
	bool running;
    struct mg_mgr manager; //Se usa si va con Mongoose 
    std::mutex mtx;
};

#endif /* SHAREDSERVERHANDLER_H_ */
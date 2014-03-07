#ifndef _HTTP_PARSER_
#define _HTTP_PARSER_
#include <string>
#include <list>
#include "HttpTask.h"
#include "ClientAccept.h"
enum RequestMethod { GET, POST } REQUEST_METHOD;
enum RequestVersion {HTTP0, HTTP1} REQUEST_VERSION;
class HttpParser
{
public:
	std::string* parseRequest(HttpTask *task);
	bool isEnding(std::list<WSABUF> &inBuffer);
	~HttpParser();
private:
	std::string split(std::string& processStr, std::string separator);
	int contentLength;
	int remainBytes;
};

#endif
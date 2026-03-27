#pragma once

#include <iostream>
#include <string>
#include <curl/curl.h>

using namespace std;


class EmailSender{



private:
		string smtp_server;
		string username;
		string password;
		string from;
		string to;
		string subject;
		string body;
		
public:
	void CEmailSender(const string serveur, const string user, const string password, const string from, const string to, const string subject, const string body);
	
	void setSmtpServer(const string serveur);
	void setUsername(const string user);
	void setPassword(const string password);
	void setFrom(const string from);
	void setTo(const string to);
	void setSubject(const string subject);
	void setBody(const string body);


	bool sendEmail();



};

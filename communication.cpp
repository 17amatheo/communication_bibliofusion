
#include "communication.h"


void EmailSender::CEmailSender(const string serveur, const string user, const string password, const string from, const string to, const string subject, const string body) :
	smtp_server(serveur), username(user), password(password), from(from), to(to), subject(subject), body(body) {
}

void EmailSender::setSmtpServer(const string _serveur) : smtp_server(_serveur) {}

void EmailSender::setUsername(const string _user) : username(_user) {}

void EmailSender::setPassword(const string _password) : password(_password) {}

void EmailSender::setFrom(const string _from) : from(_from) {}

void EmailSender::setTo(const string _to) : to(_to) {}

void EmailSender::setSubject(const string _subject) : subject(_subject) {}

void EmailSender::setBody(const string _body) : body(_body) {}

bool EmailSender::sendEmail() {
	CURL *curl;
	CURLcode res = CURLE_OK;
	struct curl_slist *recipients = NULL;
	curl = curl_easy_init();
	if(curl) {
		curl_easy_setopt(curl, CURLOPT_USERNAME, username.c_str());
		curl_easy_setopt(curl, CURLOPT_PASSWORD, password.c_str());
		curl_easy_setopt(curl, CURLOPT_URL, smtp_server.c_str());
		curl_easy_setopt(curl, CURLOPT_MAIL_FROM, from.c_str());
		recipients = curl_slist_append(recipients, to.c_str());
		curl_easy_setopt(curl, CURLOPT_MAIL_RCPT, recipients);
		curl_easy_setopt(curl, CURLOPT_READFUNCTION, NULL);
		curl_easy_setopt(curl, CURLOPT_READDATA, NULL);
		curl_easy_setopt(curl, CURLOPT_UPLOAD, 1L);
		res = curl_easy_perform(curl);
		if(res != CURLE_OK)
			cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res) << endl;
		curl_slist_free_all(recipients);
		curl_easy_cleanup(curl);
	}
	return (res == CURLE_OK);
}


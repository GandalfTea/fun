
//	This code is brought to you by Ben's Lemon.
// 	In this almost all functions return a bool because I wanted to make them text-independent.



#pragma once

#include "SHA_256.h"
#include <string>
#include <vector>
#include <map>

SHA_256 SHA_256;
struct UserCredential;
std::map<std::string, std::string> EncryptedLoginInfo;
std::vector <UserCredential> EncryptedUsernames;

struct UserCredential{
	bool isLoggedIn = false;
	std::string eUsername = "Uninitialized.";

	void initialize(std::string eUsername, std::string ePassward, UserCredential User){
		EncryptedLoginInfo[eUsername] = ePassward;

		User.eUsername = eUsername;
		EncryptedUsernames.push_back(User);
	}
};

UserCredential User;


//This is used to not bind the whole thing to the primitive string or size_t.
struct EncryptedData{
	std::string String; 
};

class UserLogin {

	public :
		std::string Encrypt(const std::string toEncrypt){
			
			string hash = SHA_256.Encrypt(toEncrypt);
			std::cout << "\n To Encrypt : " << toEncrypt;
			std::cout << "\n\n hash : " << hash;

			return hash;
		}




		bool Register(const std::string& Username, const std::string& Passward){
			EncryptedData eUsername;
			EncryptedData ePassward;
			eUsername.String = Encrypt(Username);
			ePassward.String = Encrypt(Passward);
			
			if (EncryptedUsernames.size() != 0) {
				// Check for already existing user.
				for (auto User : EncryptedUsernames) {
					if (User.eUsername == eUsername.String){
						//User already exists.
						return false;
					}else{
						//Register
						User.initialize(eUsername.String, ePassward.String, User);

						std::cout << "\n\nUsername : " << eUsername.String;
						std::cout << "\nPassward : " << ePassward.String;

						return true;
					}
				}
			}else{
				//Register if vector is empty;
				User.initialize(eUsername.String, ePassward.String, User);
				return true;
			}
			//Uber-safe in case I dumb.
			return false;
		}



		bool Login(const std::string& Username, const std::string& Passward){
		
			for (auto User : EncryptedUsernames) {
				if(User.eUsername == Encrypt(Username)){
					EncryptedData eUsername;
					EncryptedData ePassward;
					eUsername.String = Encrypt(Username);
					ePassward.String = Encrypt(Passward);
					std::cout << "\n\nUsername : " << eUsername.String;
					std::cout << "Passward : " << ePassward.String;

					if (EncryptedLoginInfo[eUsername.String] == ePassward.String){
						User.isLoggedIn = true;
						return true;

					}else{
						//Passward incorrect.
						return false;
					}
				}
			}
			//User does not exist, please try again.
			return false;
		}
		

		void DeleteUser(const std::string& Username, const std::string& Passward){
			EncryptedData eUsername;
			EncryptedData ePassward;
			eUsername.String = Encrypt(Username);
			ePassward.String = Encrypt(Passward);


			//hope this fucking works
			EncryptedLoginInfo.erase(eUsername.String);
			//delete from vector
		}

		bool anyLoggedIn(){

			if (EncryptedUsernames.size() != 0) {
				for (auto User : EncryptedUsernames) {
					if (User.isLoggedIn){
						return true;
					}
				}
				return false;
			}
			return false;
		}

};

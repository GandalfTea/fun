
//	This code is brought to you by Ben's Lemon.
// 	In this almost all functions return a bool because I wanted to make them text-independent.



#pragma once

//DEBUG
#include<iostream>

#include <string>
#include <vector>
#include <map>

struct UserCredential;
std::map<std::string, std::string> EncryptedLoginInfo;
std::vector <UserCredential> EncryptedUsernames;

struct UserCredential{
	bool isLoggedIn = false;
	std::string eUsername;

	void initialize(std::string eUsername, std::string ePassward, UserCredential User){
		EncryptedLoginInfo[eUsername] = ePassward;

		this->eUsername = eUsername;
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
		std::string Encrypt(const std::string& toEncrypt){
			// size_t Encrypted;
			// char EncryptThing[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 1, 2, 3, 4, 5, 6, 7, 8, 9};
			// for (size_t i{}; i = toEncrypt.length(); i++){
			// 	 Encrypted = EncryptThing[i];
			// }
			// return Encrypted;
			std::string dicks = "69";
			return dicks;
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
			
			//Login doesn't work;
			for (auto User : EncryptedUsernames) {
				if(User.eUsername == Encrypt(Username)){
					EncryptedData eUsername;
					EncryptedData ePassward;
					eUsername.String = Encrypt(Username);
					ePassward.String = Encrypt(Passward);
	
					if (EncryptedLoginInfo[eUsername.String] == ePassward.String){
						User.isLoggedIn = true;
						return true;
						// Login doesn't do shit.

					}else{
						//Passward incorrect.
						return false;
					}
				} else{
					//User does not exist, please try again.
					return false;
				}
			}
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

		bool isLoggedIn(std::string Username);

};

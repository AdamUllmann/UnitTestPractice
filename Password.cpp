#include "Password.h"
#include <string>

using std::string;

/*
   The function receives a string counts how many times the same character 
   occurs at the beginning of the string, before any other characters (or the
   end of the string). The function is case-sensitive so 'Z' is different than
   'z' and any ASCII characters are allowed.
   */
int Password::count_leading_characters(string phrase){
	int repetition = 1;
	int index = 0;
	while( index < phrase.length()-1 && phrase[index] == phrase[index+1] ){
		repetition++;
		index++;
	}
	return repetition;
}

bool Password::has_mixed_case(string str) {
	if (isupper(str[0])) {
		for (int i = 0; i < str.size(); i++) {
			if (!isupper(str[i])) {
				return 1;
			}
		}
		return 0;
	}
	else {
		for (int i = 0; i < str.size(); i++) {
			if (isupper(str[i])) {
				return 1;
			}
		}
		return 0;
	}
}






//constructor sets the default password to "ChicoCA-95929"
Password::Password() {
	pass_history.push_back("ChicoCA-95929");
}

/*
   receives a password and sets the latest in pass_history to it if and only
   if it meets all criteria:
   1. The password is at least 8 letters long, but no longer than 20
   2. It has no more than 3 of the same leading characters
   3. It has mixed case (at least one upper case and at least one lower case)
   4. It was not a previous password in the history
   */
bool Password::set(string str) {
	if (str.size() >= 8 && str.size() <= 20) {
		if (!(str[0] == str[1] && str[1] == str[2]) && has_mixed_case(str)) {
				for (int i = 0; i < pass_history.size(); i++) {
					if (str == pass_history[i]) {
						return 0;
					}
					//pass_history.push_back(str);
				}
				pass_history.push_back(str);
				return 1;
		}
	}
	return 0;
}

/*
   receives a string and authenticates it against the latest password in the
   pass_history, returning true for an exact match or false when it does not match
   or if a password has not been set.
   */
bool Password::authenticate(string str) {
	if (str == pass_history[pass_history.size()-1]) {
		return 1;
	}
	return 0;
}











/*
// Implementation A
#include <cctype>
bool Password::has_mixed_case(string str)
{
bool has_lower = false;
bool has_upper = false;
for (char ch : str)
{
if (std::islower(ch))
{
has_lower = true;
}
else if (std::isupper(ch))
{
has_upper = true;
}
}
return has_lower && has_upper;
}

// Implementation B
bool Password::has_mixed_case(string str)
{
int count_lower = 0;
for (int i = 0; i < str.length(); i++)
{
if (str[i] >= 'a' && str[i] <= 'z')
{
count_lower++;
}
}
return count_lower > 0 && count_lower < str.length();
}


// Implementation C
bool Password::has_mixed_case(string str)
{
bool lower = false;
bool upper = false;
for (int i = 0; i < str.length(); i++)
{
if (str[i] >= 'a' && str[i] <= 'z')
{
lower = true;
}
else if (str[i] >= 'A' && str[i] <= 'Z')
{
upper = true;
}
}
return upper && lower;
} 
// Implementation D
#include <cctype>
bool Password::has_mixed_case(string str)
{
bool is_lower = false;
bool is_upper = false;
for (char c : str)
{
if (std::islower(c))
{
is_lower = true;
}
else
{
is_upper = true;
}
}
return is_lower && is_upper;
}
// Implementation E
bool Password::has_mixed_case(string str)
{
	bool found = false;
	for(char c : str){
		if( !found && c >= 'A' && c <= 'Z' ){
			found = true;
		}
		else if( found && c >= 'a' && c <= 'z'){
			return true;
		}
	}
	return false;
}
*/

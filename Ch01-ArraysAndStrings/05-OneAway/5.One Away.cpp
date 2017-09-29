/* 
 * Problem: There are three possible edits that can be performed on a string.
 * 1. Insert a char.
 * 2. Delete a char.
 * 3. Replace a char.
 *
 * Given two strings, determine if they are one or 0 edit away.
 *
 * Approach :
 * 1. Case when strings are of some length --> possible edit is replace.
 *    If there are more than one mismatch, return false
 *
 * 2. Case when One string is bigger than another
 *    Smaller string ------------> Bigger String
 *                     insert
 *                     delete
 *    smaller string <-----------  Bigger String
 *
 *    Idea is check if there are more than one mismatch discounting the already
 *    difference in the string. Therefore for first mismatch we do not move the pointer
 *    pointing to smaller string, and then expect it to match from next char of bigger
 *    string.
 */

#include<string>
#include<iostream>
#include<cmath>
using namespace std;

bool isOneAway(string s1, string s2){
	string a,b;
	a = s1.length() >= s2.length() ? s1 : s2;
	b = s1.length() < s2.length() ? s1 : s2;
	int len1, len2;
	len1 = a.length();
	len2 = b.length();
	if(abs(len1-len2)>1)
		return false;
	
	bool flag = false;
	for(int i=0,j=0;i<len1 && j<len2;){
		if(a[i]!=b[j]){
			if(flag)
				return false;
			flag = true;
			if(len1 == len2)
				i++,j++;
			else
				i++;
		}
		else
			i++,j++;
	}
	return true;
}

bool oneEditAway( const std::string & str1, const std::string & str2 )
{
    if ( std::abs( int(str1.length()) - int(str2.length()))  > 1 ) {
        return false;
    }

    int len1 = str1.length();
    int len2 = str2.length();
    std::string smaller = len1 < len2 ? str1 : str2;
    std::string bigger =  len1 < len2 ? str2 : str1;
    
    unsigned int i = 0, j = 0; 
    bool mismatchDone = false;
    while ( i < smaller.length() && j < bigger.length() )
    {
        if ( smaller[i] != bigger[j] ) {
            if (mismatchDone) {
                return false;
            }
            mismatchDone = true;
            if ( len1 == len2 ) {
                ++i;   //case of replace
            }
        } else {
                ++i;   //move short pointer if its a match, dont move it in case of first mismatch
        }
        ++j;           //always move long string pointer.
    }
    return true;
}

int main(void){
	string s1,s2;
	getline(cin,s1);
	getline(cin,s2);
	if(isOneAway(s1,s2))
		cout<<"One edit away."<<endl;
	else
		cout<<"Not one edit away."<<endl;
	return 0;
}

//Codechef starters 97 contest DIV3 3rd question
//https://www.codechef.com/problems/SMILEY?tab=statement

#include <iostream>
using namespace std;

int main() {
	int t;
	cin >> t;
	while(t--){
	    int n;
	    cin >> n;
	    string s;
	    cin >> s;
	    int ans = 0, start = 0, end = 0, colon = 0;
	    for(int i = 0; i < n; i++){
	        if(s[i] == ':'){
	            colon++;
	            if(start >= 1 and end == 0 and colon > 1){ //this indicates that between the first and the second colon there exits only open parentheses
	                ans++;
	            }
	            start = 0; //make both colon and start equal to zero whenever we encounter a colon 
	            end = 0;
	        }else if(s[i] == ')'){
	            start++;
	        }else{
	            end++;
	        }	    
	    }
	    cout << ans << endl;
	}
}
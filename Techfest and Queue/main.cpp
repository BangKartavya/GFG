<<<<<<< HEAD
//Driver Code Starts

#include<bits/stdc++.h>
using namespace std;
//Driver Code Ends


class Solution {
public:
    
	int sumOfPowers(int a, int b){
	    int ans = 0;
	    
	    for(int i = a ;i<=b;i++) {
	        int temp = i;
	        for(int j = 2;j<=sqrt(i);j++) {
	            if(temp%j==0) {
	                while(temp%j==0) {
	                    ans++;
	                    temp/=j;
	                } 
	        }
	    }
	    if(temp>1) ans++;
	    }
	    return ans;
	}
};

//Driver Code Starts

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
=======
//Driver Code Starts

#include<bits/stdc++.h>
using namespace std;
//Driver Code Ends


class Solution {
public:
    
	int sumOfPowers(int a, int b){
	    int ans = 0;
	    
	    for(int i = a ;i<=b;i++) {
	        int temp = i;
	        for(int j = 2;j<=sqrt(i);j++) {
	            if(temp%j==0) {
	                while(temp%j==0) {
	                    ans++;
	                    temp/=j;
	                } 
	        }
	    }
	    if(temp>1) ans++;
	    }
	    return ans;
	}
};

//Driver Code Starts

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int a, b;
		cin >>  a >> b;
		Solution obj;
		int ans = obj.sumOfPowers(a, b);
		cout << ans <<"\n";
	}
	return 0;
}
>>>>>>> 8bb8f945b61be1bc374c97a68b80698e62462d40
//Driver Code Ends
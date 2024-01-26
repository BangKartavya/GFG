//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};


// } Driver Code Ends
//class implemented
/*
struct Item{
    int value;
    int weight;
};
*/


class Solution
{
    public:
    //Function to get the maximum total value in the knapsack.
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        vector<pair<double,int>> valuePerWeight;
        
        for(int i=0;i<n;i++) {
            double valPerWt = (double)arr[i].value/arr[i].weight;
            valuePerWeight.push_back({valPerWt,i});
        }
        
        sort(valuePerWeight.rbegin(),valuePerWeight.rend());
        
        double maxValue = 0.0;
        
        for(int i =0;i<n;i++) {
            int index = valuePerWeight[i].second;
            
            if(arr[index].weight<=W) {
                maxValue += arr[index].value;
                W-=arr[index].weight;
            }
            else {
                double fraction = (double)W/arr[index].weight;
                maxValue+=fraction*arr[index].value;
                break;
            }
        }
        return maxValue;
    }
        
};


//{ Driver Code Starts.
int main()
{
	int t;
	//taking testcases
	cin>>t;
	cout<<setprecision(6)<<fixed;
	while(t--){
	    //size of array and weight
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		//value and weight of each item
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}
		
		//function call
		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
// } Driver Code Ends
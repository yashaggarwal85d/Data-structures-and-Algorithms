#include<bits/stdc++.h>
using namespace std;

void search(char *pat, char *txt, int *suffArr, int n) 
{ 
    int m = strlen(pat);
	
	int l = 0, r = n-1;
	while (l <= r) 
    { 
        int mid = l + (r - l)/2; 
        int res = strncmp(pat, txt+suffArr[mid], m); 
  
        if (res == 0) 
        { 
            cout << "Pattern found at index " << suffArr[mid]; 
            return; 
        } 
  
        if (res < 0)
			r = mid - 1; 
  
        else
			l = mid + 1; 
    } 
  
    cout << "Pattern not found"; 
} 
  
int main() 
{ 
    char txt[] = "banana";  // text 
    char pat[] = "nan";   // pattern to be searched in text 
  
    int n = strlen(txt); 
    int suffArr[]={5,3,1,0,4,2}; 
    
	search(pat, txt, suffArr, n); 
  
    return 0; 
}
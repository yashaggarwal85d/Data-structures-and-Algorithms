#include <bits/stdc++.h> 
using namespace std;

auto computeLPSArray(string pat)
{ 
    int m=pat.size();
    vector<int> lps(m,0);
	int j = 0;
    
    int i = 1; 
	while (i < m)
    { 
		if (pat[i] == pat[j])
        { 
			j++; 
			lps[i] = j; 
			i++; 
		} 
		else 
		{ 
			if (j != 0) 
			    j = lps[j - 1]; 
			
            else 
			{ 
				lps[i] = 0; 
				i++; 
			} 
		} 
	} 
    return lps;
} 

void KMPSearch(string pat,string txt) 
{ 
	int m = pat.size();
	int n = txt.size(); 

	vector<int> lps=computeLPSArray(pat); 

	int i = 0; 
	int j = 0;

	while (i < n)
    { 
		if (pat[j] == txt[i])
        { 
			j++; 
			i++; 
		} 
        if (j == m)
        { 
			printf("Found pattern at index %d ", i - j); 
			j = lps[j - 1]; 
		} 
        else if (i < n && pat[j] != txt[i]) 
        { 
			if (j == 0) 
                i++;
            else
				j = lps[j - 1]; 
		} 
	} 
} 

int main() 
{ 
	string txt = "ABABDABACDABABCABAB"; 
	string pat = "ABABCABAB"; 
	KMPSearch(pat, txt); 
	return 0; 
} 

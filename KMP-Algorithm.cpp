void KMP(string s, string pat)
{
    int n = s.length();
    int m = pat.length();
    
    // Here we will prepare lps array " Longest Prefix Suffix"
    
    ll lps[m];
    lps[0] = 0;
    int len = 0, i=1;
    
    while(i<m)
    {
        if(pat[i] == pat[len])
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
        {
            if(len==0)
            {
                lps[i] = 0;
                i++;
            }
                
            else
            {
                len = lps[len-1];
            }
        }
    }
    
    // Now we will search for pattern in the string.
    
    i = 0;
    int j = 0;
    while(i<n)
    {
        if(pat[j]==s[i])
        {
            i++;
            j++;
        }
        
        if(j==m)
        {
            cout<<"pattern found at index : "<<i-j<<"\n";
            j = lps[j-1];
        }
        
        else if(i<n && pat[j] != s[i])
        {
            if(j==0)i++;
            else
            j = lps[j-1];
        }
    }
}

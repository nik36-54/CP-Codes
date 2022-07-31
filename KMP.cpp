Need of Preprocessing ? An important question arises from the above explanation,
    how to know how many characters to be skipped.To know this,
    we pre - process pattern and prepare an integer array
                 lps[] that tells us the count of characters to be skipped.

             void
             computeLps(string pat, int m, int *lps)
{
    int len = 0;
    lps[0] = 0;
    int i = 1;

    while (i < m)
    {
        if (pat[i] == pat[len])
        {
            lps[i] = len + 1;
            len++;
            i++;
        }
        else
        {
            if (len == 0)
            {
                lps[i] = 0;
                i++;
            }
            else
            {
                len = lps[len - 1];
            }
        }
    }
}

void kmp(string txt, string pat)
{
    int n = len(txt);
    int m = len(pat);

    int lps[m];

    computeLps(pat, m, lps);
    int i = 0, j = 0;

    while ((n - i) >= (m - j))
    {
        if (txt[i] == pat[j])
        {
            i++;
            j++;
        }
        if (j == m)
        {
            cout << "Found pattern at index: " << i - j << "\n";
            j = lps[j - 1];
        }
        else if (i < n && txt[i] != pat[j])
        {
            if (j == 0)
                i++;
            else
                j = lps[j - 1];
        }
    }
}

Time Complexity : O(n + m)
                      space Complexity : O(m)
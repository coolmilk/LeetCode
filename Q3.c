/**
Longest Substring Without Repeating Characters
Given a string, find the length of the longest substring without repeating characters.
**/

//check repeat character in substring
int validation (char *s, char *e)
{
  char map[]={0};
  int i, len=e-s+1;
  for(i=0;i<len;i++)
  {
    if(map[*(s+i)]==0) map[*(s+i)]=1;
    else return -1;
  }
  return 0;
}

int lengthOfLongestSubstring (char* s)
{
  char *L, *R;
  int len=0, max=1;
  if(*s==0) return 0;
  while(*(s+len)!=0) len++;

  for(L=s;L<s+len;L++)
  {
    for(R=L+1;R<s+len;R++)
    {
      if(R-L+1 < max) continue;
      if(validation(L, R)==-1) break;
      else
       if(R-L+1 > max) max=R-L+1;
    }
  }
  return max;
}

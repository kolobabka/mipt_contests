#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void patpreproc(char const * needle, int * needle_lps);
char * strstrci(char const * needle, int const * needle_lps, char const * haystack);

int main ()
{
  char* haystack = NULL;
  haystack = (char*) calloc (1076, sizeof (char));
  strcpy(haystack,"kXGUTxDnKsXSnJatRaXhhjVJMQQruHtbSfbGAqMmIEyQmnoEarhABDrCbjGcMxyBEiKfriuttNeCPtvIBesMZvAfABiyXJOzJFHJcoxsQddZGPkTFtJQyfiZKpchQVeCHlQNvcmpEvBIsxoCZeHCTieltPgjihqgTicLkbYsuNNqhLfdZnpbPkKYPxpjplSUaWvTprSlxWVKfriuttNeCPtvIBPrLToPAKDnlrcnKuNVGhZZbYbNvYDFCDPnSWxibwzOlxumjfgxEPAdCILRSSKmrmSYlKngcxYaWEMQcvNKszGMhFMePcequYtaqaFeqNLsdkuptuAeHReTaQnhIWgsDEEEMGjibQgMlAfUwCVOjEZsUfyqYVYzIcaqUpirKauquPReQBqTshaHDyQFRIFPmwgnUuXbqfaLgFruSfqxUjpZwNTDUCxHygqkokujsJnPAvoBYKlhIPgQKyQdBuaEYJRpgQNwQOaWRiaeFcuUQxYEtVCkJSNdyITnuahFeXkSAjYzhTOgyXNAumUMhIdGVedsfstgKEtEBlUfmWiOjpPBvoMKfriuttNeCPtvIBXqotnqJrPtsyhnYTYWHzlGqgKVHixqykNRHOPcjTFupEOeLYPzykqDBwykfceMBcIsIsvlvgJiJDbcAYRcjHIhiatrLlSTDDJYqBxLivAKfriuttNeCPtvIBjFrSlDSOUqKwoKQVcvuUgWxSkLHfEfdgWcLTwALfMsYFhdvJuGJvjLatqJztKMGfAMBKfriuttNeCPtvIBvoditaGTwOeqdEJHvwNDLsOndXrWNETsEuwscerNzAXHMvrXOYIgwKzqfwWygKQISpVWXveLAumKSQzaxJxqFyMQbryZUWMhFZRfBDbXXWrPIHriFkNKQsFCzXxmJgisRgPEVYNRfxOSzUfiEOqKwoDCzBydxeRdEmnuPshMKsTDTkwrsTJEpWBgZfsnzYcgddYxTSHCUFmxUIKedJSviElFVAoPwwjTbLDuDbIiEIBvMDbFdhVUleeAqPhBTkREwVAdRnMjyaGOSTNjpgPrSNLGiblBIObdhlieGjS");

  char* needle = NULL;
  needle = (char*) calloc (16, sizeof (char));
  strcpy (needle, "eednobuhrsqqupz");
  char* result = NULL;
  int* needle_lps = NULL;

  result = strstrci (needle, needle_lps, haystack);

  printf("%s\n", result);
}

void patpreproc(char const * needle, int * needle_lps)
{

  int i = 1, j = 0;
  int len = strlen (needle);
  needle_lps = (int*) calloc (len, sizeof(int));

  while (i < len)
  {
    if (tolower (needle[j]) == tolower(needle[i]))
    {
      needle_lps[i] += needle_lps[i-1] + 1;
      j++;
      i++;
    }
    else
    {
      j = 0;
      i++;
    }
  }

}

char * strstrci(char const * needle, int const * needle_lps, char const * haystack)
{

  int i = 0, j = 0, pos = 0;
  int buflen = strlen (haystack);
  int needlen = strlen (needle);

  patpreproc(needle, needle_lps);

  while (i < buflen)
  {
    if (tolower (haystack[i]) == tolower (needle[j]))
    {
      if (j + 1 == needlen)
      {
        return haystack + i - needlen + 1;
      }
      i++;
      j++;
    }
    else
    {
      if (j == 0)
      {
        i++;
      }
      else
      {
       i = pos + j - needle_lps[j-1];
       pos = i;
      }
      j = 0;
    }
  }
  return NULL;
}

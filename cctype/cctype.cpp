#include <iostream>
#include "cctype.hpp"

namespace my
{
   int isalnum(int ch)
   {
     int i{48};
     if(ch>48 && ch<123)
     {
        if(ch>90 && ch<97)
        {
          return 0;
        }
        else if(ch>57 && ch<65)
        {
          return 0;
        }
        return 1;
     }
     return 0;
   }
   int isalpha(int ch)
   {
     int i{65};
     if(ch>65 && ch<123)
     {
        if(ch>90 && ch<97)
        {
          return 0;
        }  
        return 1;
     }
     return 0;
   }
   int islower(int ch)
   {
     if(ch>96 && ch<123)
     {
       return 1;
     }
     return 0;
   }
   int isupper(int ch)
   {
     if(ch>64 && ch<91)
     {
       return 1;
     }
     return 0;
   }
   int isdigit(int ch)
   {
     if(ch>47 && ch<58)
     {
       return 1;
     }
     return 0;
   }
   int isxdigit(int ch)
   {
     if(ch>47 && ch<58)
     {
       return 1;
     }
     else if(ch>64 && ch<71)
     {
       return 1;
     }
     else if(ch>96 && ch<103)
     {
       return 1;
     }
     return 0;
   }
   int iscntrl(int ch)
   {
     if(ch>0 && ch<32)
     {
       return 1;
     }
     return 0;
   }
   int isgraph(int ch)
   {
     if(ch>47 && ch<58)
     {
       return 1;
     }
     else if(ch>64 && ch<91)
     {
       return 1;
     }
     else if(ch>96 && ch<123)
     {
       return 1;
     }
     else 
     {
       if(1==ispunct(ch)){return 1;}
       return 0;
     }
     return 0;
   }
   int isspace(int ch)
   {
     if(ch==32 || ch==12 || ch==10 )
     {
       return 1;
     }
     else if(ch==13 || ch==9 || ch==11)
     {
       return 1;
     }
     return 0;
   }
   int isblank(int ch)
   {
     if(ch==32 || ch==9)
     {
       return 1;
     }
     return 0;
   }
   int isprint(int ch)
   {
     if(ch>31 && ch<127)
     {
       return 1;
     }
     return 0;
   }
   int ispunct(int ch)
   {
     if(ch>47 && ch<58)
     {
       return 0;
     }
     else if(ch>64 && ch<91)
     {
       return 0;
     }
     else if(ch>96 && ch<123)
     {
       return 0;
     }
     return 1;
   }
   int tolower(int ch)
   {
     return (ch+32);
   }
   int toupper(int ch)
   {
     return (ch-32);
   }
}

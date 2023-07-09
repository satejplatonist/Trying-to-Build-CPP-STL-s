#include <iostream>

namespace my
{
   class String
   {
      private:
      char* value;
      typedef unsigned long long int size_type;
      size_type string_size_t;

      public:
      String()
      {
          value = nullptr;
          string_size_t=0;
      }
      String(const char* temp)
      { 
          string_size_t=size(const_cast<char*>(temp))+4;
          value=new char[string_size_t];
          str_copy(value,temp);
      }
      String(const String &obj)
      {
         if(value==nullptr)
        {
          string_size_t=size(obj.value)+4;
          value=new char[string_size_t];
          str_copy(value,obj.value);
        }
        else
        {
          delete[] value;
          string_size_t=size(obj.value)+4;
          value=new char[string_size_t];
          str_copy(value,obj.value);
        }
      }
      void operator=(String &obj)
      {
        if(value==nullptr)
        {
          string_size_t=size(obj.value)+4;
          value=new char[string_size_t];
          str_copy(value,obj.value);
        }
        else
        {
          delete[] value;
          string_size_t=size(obj.value)+4;
          value=new char[string_size_t];
          str_copy(value,obj.value);
        }
      }
      ~String()
      {
         delete[] value;
      }
      inline unsigned int size() const noexcept
      {
          return size(value);
      }
      unsigned long long capacity() const noexcept
      {
        return (string_size_t);
      }
      /*void reserve(size_type newCap)
      {
        
      }*/
      bool empty()const noexcept
      {
        if(value!=nullptr)
        {
          return false;
        }
        return true;
      }
      private:
      inline unsigned int size(char* _tp)const noexcept
      {
          int count{0};
          char *tp = new char;
          tp = _tp;
          while (*tp != '\0')
          {
              count++;
              tp++;
          }
          return count;
      }
      inline void str_copy(char* &ref,const char* _tr)
      {
         int i{0};
         while(*_tr!='\0')
         {
            ref[i]=*_tr;
            _tr++;
            i++;
         }
      }
      friend std::ostream &operator<<(std::ostream &out, const String &obj);
      friend bool operator==(String &obj1, String &obj2);
      friend char *operator+(String &obj1, String &obj2);
   };
  bool operator==(String &obj1, String &obj2)
  {
      const unsigned int a = obj1.size();
      const unsigned int b = obj2.size();
      if (a != b)
      {
          bool temp = true;
          int i{0};
          while (i != std::min(a, b))
          {
              if (obj1.value[i] != obj2.value[i])
              {
                  temp = false;
                  return temp;
              }
              i++;
          }
          return temp;
      }
      bool temp = true;
      int i{0};
      while (i != a)
      {
          if (obj1.value[i] != obj2.value[i])
          {
              temp = false;
              return temp;
          }
          i++;
      }
      return temp;
  }
  char *operator+(String &obj1, String &obj2)
  {
      const unsigned int m = obj1.size();
      const unsigned int n = obj2.size();
      char *temp = new char[m+n+4];
      int i{0};
      while (obj1.value[i] != '\0')
      {
          temp[i] = obj1.value[i];
          i++;
      }
      while (obj2.value[i] != '\0')
      {
          temp[i] = obj2.value[i];
          i++;
      }
      return temp;
  }
  std::ostream &operator<<(std::ostream &out, const String &obj)
  {
      out << obj.value;
      return out;
  }
}

int main()
{
  my::String s1{"satej"};
  my::String s2{"shivp"};
  s1=s2;
  if(s1==s2)
  {
    std::cout<<"true\n";
  }
  else
  {
    std::cout<<"false\n";
  }
  my::String s3{s1+s2};
  std::cout<<s1<<" "<<s3<<"\n";
}

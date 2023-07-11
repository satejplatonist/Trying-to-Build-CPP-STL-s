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
      inline size_type size() const noexcept
      {
          return size(value);
      }
      inline size_type length() const noexcept
      {
          return size(value);
      }
      char& at(size_type pos)
      {
        if(pos>=size())
        {
          std::cout<<"ERROR:STD::OUT_OF_RANGE";
        }
        else if(pos<0)
        {
          std::cout<<"ERROR:STD::BAD_LENGTH";
        }
        return value[pos];
      }
      char& front()
      {
        return value[0];
      }
      char& back()
      {
        return value[size()-1];
      }
      constexpr void swap(String& other) noexcept
      {
        char* _tr=nullptr;
        _tr=value;
        value=other.value;
        other.value=_tr;
      }
      size_type capacity() const noexcept
      {
        return (string_size_t);
      }
      void resize(size_type count)
      {
        if(value==nullptr )
        {
          value=new char[count];
        }
        else
        {
          char* temp=new char[count];
          int i{0};
          char* ptr=value;
          while(i!=count)
          {
            temp[i]=*ptr;
            ptr++;
            i++;
          }
          delete[] value;
          value=temp;
        }
      }
      void resize(size_type count,char ch)
      {
        if(value==nullptr)
        {
          value=new char[count];
          for(int i=0;i<=count;i++)
          {
            value[i]=ch;
          }
        }
        else
        {
          char* temp=new char[count];
          
        }
      }
      void reserve(size_type newCap)
      {
        if(value==nullptr)
        {
          string_size_t=newCap;
          value=new char[string_size_t];
        }
        else
        {
          string_size_t=newCap;
          char* temp=new char[string_size_t];
          str_copy(temp,value);
          value=temp;
        }
      }
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
      friend bool operator!=(String &obj1, String &obj2);
      friend char *operator+(String &obj1, String &obj2);
      char& operator[](size_type index)
      {
        return value[index];
      }
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
  bool operator!=(String &obj1, String &obj2)
  {
      const unsigned int a = obj1.size();
      const unsigned int b = obj2.size();
      if (a != b)
      {
          bool temp = false;
          int i{0};
          while (i != std::min(a, b))
          {
              if (obj1.value[i] != obj2.value[i])
              {
                  temp = true;
                  return temp;
              }
              i++;
          }
          return temp;
      }
      bool temp = false;
      int i{0};
      while (i != a)
      {
          if (obj1.value[i] != obj2.value[i])
          {
              temp = true;
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
      char *temp = new char[m+n];
      int i{0};
      char *tp1 = obj1.value;
      char *tp2 = obj2.value;
      while (*tp1 != '\0')
      {
          temp[i] = *tp1;
          tp1++;
          i++;
      }
      while (*tp2 != '\0')
      {
          temp[i] = *tp2;
          tp2++;
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
  if(s1!=s2)
  {
    std::cout<<"true\n";
  }
  else
  {
    if(s1==s2)
    {
      std::cout<<"false\n";
      s1.at(2)='s';
      my::String s3{s1+s2};
      s3.resize(7);
      std::cout<<s1<<" "<<s3<<"\n";
      s1.reserve(20);
      std::cout<<s1.capacity()<<"\n";
      s1.swap(s2);
      std::cout<<s1<<" "<<s2<<"\n";
    }
  }
}

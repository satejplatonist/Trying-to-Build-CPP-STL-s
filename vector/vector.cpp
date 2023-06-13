#include <iostream>

namespace std
{
   template<typename T>
   class vector
   {
      private:
      T* value;
      T* temp;
      int arraySize{1};
      public:
      vector()
      {
        value=NULL;
        temp=NULL;
      }
      int size()
      {
          return arraySize;
      }
      void push(T val)
      {
        if(value==NULL)
        {
          value=new T[arraySize];
          value[arraySize-1]=val;
        }
        else if(value!=NULL)
        {
          arraySize=arraySize+1;
          temp=new T[arraySize];
          int lastIndex=arraySize-1;
          for(int j=0;j<lastIndex;j++)
            {
              temp[j]=value[j];
            }
          temp[lastIndex]=val;
          delete[] value;
          value=temp;
          temp=NULL;
        }
      }
      T pop()
      {
        int popIndex=arraySize-1;
        T t = value[popIndex];
        arraySize=arraySize-1;
        if(arraySize>=0)
        {
          temp=new T[arraySize];
          for(int j=0;j<popIndex;j++)
            {
              temp[j]=value[j];
            }
          delete[] value;
          value=temp;
          temp=NULL;
          return t;
        }
        else if(arraySize<0)
        {
          std::cout<<"Memory underflow\n";  
          reset();
        }
      }
      void reset()
      {
        arraySize=1;
        vector();
      }
   };
}

int main() 
{
  std::vector<int> v;
  v.push(1);
  v.push(2);
  v.push(3);
  std::cout<<"size : "<<v.size()<<"\n";
  std::cout<<v.pop()<<"\n";
  std::cout<<v.pop()<<"\n";
  std::cout<<"size : "<<v.size()<<"\n";
  v.push(4);
  std::cout<<"size : "<<v.size()<<"\n";
  std::cout<<v.pop()<<"\n";
  std::cout<<"size : "<<v.size()<<"\n";
}

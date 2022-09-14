#include <iostream>
#include <string>
#include <vector>

using namespace std;
//data calculation
class Data
{
  public:
//current data set
  vector<int> currentdate;
//current birth date
  vector<int> birthdate;
//Age calculation
    int Age(vector<int> currentdate, vector<int> birthdate)
  {
    int age;
    age = currentdate[0] - birthdate[0];
    if (currentdate[1]<birthdate[1]) age-=1;
    else if (currentdate[1]==birthdate[1]&&currentdate[2]<birthdate[2]) age-=1;
    //output
    return age;
  }
//calculates days until birthday
    int DaysUntil(vector<int> currentdate, vector<int> birthdate)
  {
    //days count
    int count=0;
//if current month lower than birthday
    if(currentdate[1]<birthdate[1])
    {
      //add a count based on a specifik month
      for(int i=currentdate[1]+1;i<birthdate[1];i++)
        { if(i==1||i==3||i==5||i==7||i==8||i==10||i==12) count+=31;
          else if(i==4||i==6||i==9||i==11) count+=30;
          else if(i==2&&currentdate[0]%4==0) count+=29;
          else if(i==2&&currentdate[0]%4!=0) count+=28;
        }
    }
//if current month bigger than birthday
    else if(currentdate[1]>birthdate[1])
    {
      //difference
      int goal=currentdate[1]+(12-(currentdate[1]-birthdate[1]));
      for(int i=currentdate[1]+1;i<goal;i++)
        {
          int num=i;
          if(num>12) num-=12;
          if(num==1||num==3||num==5||num==7||num==8||num==10||num==12) count+=31;
          else if(num==4||num==6||num==9||num==11) count+=30;
          else if(num==2&&currentdate[0]%4==0) count+=29;
          else if(num==2&&currentdate[0]%4!=0) count+=28;
        }
      
    }
    //if current day lower than birthday
    if(currentdate[2]<birthdate[2]) count+=abs(currentdate[2]-birthdate[2]);
    //if current day bigger than birthday
    else if(currentdate[2]>birthdate[2])
    {
    if(currentdate[1]==1||currentdate[1]==3||currentdate[1]==5||currentdate[1]==7||currentdate[1]==8||currentdate[1]==10||currentdate[1]==12) count+=(31-currentdate[2])+birthdate[2];
        else if(currentdate[1]==4||currentdate[1]==6||currentdate[1]==9||currentdate[1]==11) count+=(30-currentdate[2])+birthdate[2];
        else if(currentdate[1]==2&&currentdate[0]%4==0) count+=(29-currentdate[2])+birthdate[2];
        else if(currentdate[1]==2&&currentdate[0]%4!=0) count+=(28-currentdate[2])+birthdate[2];
    }
  //output
  return count;
  }
    //personal data output
    void PersonalData(string name,string surname,int age)
  {
    cout<<"\nPersoal Information: "<<endl;
    cout<<"Your name is: "<<name<<endl;
    cout<<"Your surname is: "<<surname<<endl;
    cout<<"Your age is: "<<age<<endl;
  }
};
//person data
class Person
{
  public:
    string name;
    string surname;
    vector<int> birthdate;
};

int main() 
{
  int age,days;
  string name,surname;
    //First person
  Person first;
  first.name = "Vitold";
  first.surname = "Skuder";
  first.birthdate = {2001,10,2};
    //Set current name
  name=first.name;
    //Set current surname
  surname=first.surname;
    //Set current birth date
  Data setcurrentbirthdate;
  setcurrentbirthdate.birthdate=first.birthdate;
    //Set current date
  Data setcurrentdate;
  setcurrentdate.currentdate={2022,9,15};
    //Age Calculation
  Data AgeCalculation;
  age=AgeCalculation.Age(setcurrentdate.currentdate,setcurrentbirthdate.birthdate);
  cout<<"Calculated age: "<<age<<endl;
    //days until birthday
  Data DaysCalculation;
  days=DaysCalculation.DaysUntil(setcurrentdate.currentdate,setcurrentbirthdate.birthdate);
  cout<<"Days left until birthday: "<<days<<endl;
    //Personal data
  Data PersonalData;
  PersonalData.PersonalData(name,surname,age);
}

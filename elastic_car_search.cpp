#include<bits/stdc++.h>
#include<dos.h>
#include<windows.h>
using namespace std;
void delay(unsigned int mseconds)
{
    clock_t goal = mseconds + clock();
    while (goal > clock());
}
void SetColor(int ForgC)
 {
 WORD wColor;

  HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
  CONSOLE_SCREEN_BUFFER_INFO csbi;

                       //We use csbi for the wAttributes word.
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                 //Mask out all but the background attribute, and add in the forgournd color
      wColor = (csbi.wAttributes & 0xF0) + (ForgC & 0x0F);
      SetConsoleTextAttribute(hStdOut, wColor);
 }
 return;
 }
void ClearConsoleToColors(int ForgC, int BackC)
{
 WORD wColor = ((BackC & 0x0F) << 4) + (ForgC & 0x0F);
               //Get the handle to the current output buffer...
 HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
                     //This is used to reset the carat/cursor to the top left.
 COORD coord = {0, 0};
                  //A return value... indicating how many chars were written
                    //   not used but we need to capture this since it will be
                      //   written anyway (passing NULL causes an access violation).
  DWORD count;

                               //This is a structure containing all of the console info
                      // it is used here to find the size of the console.
 CONSOLE_SCREEN_BUFFER_INFO csbi;
                 //Here we will set the current color
 SetConsoleTextAttribute(hStdOut, wColor);
 if(GetConsoleScreenBufferInfo(hStdOut, &csbi))
 {
                          //This fills the buffer with a given character (in this case 32=space).
      FillConsoleOutputCharacter(hStdOut, (TCHAR) 32, csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

      FillConsoleOutputAttribute(hStdOut, csbi.wAttributes, csbi.dwSize.X * csbi.dwSize.Y, coord, &count );
                          //This will set our cursor position for the next print statement.
      SetConsoleCursorPosition(hStdOut, coord);
 }
 return;
}

void preKMP(string pattern, int f[])
{
    int m = pattern.length(), k;
    f[0] = -1;
    for (int i = 1; i < m; i++)
    {
        k = f[i - 1];
        while (k >= 0)
        {
            if (pattern[k] == pattern[i - 1])
                break;
            else
                k = f[k];
        }
        f[i] = k + 1;
    }
}

//check whether target string contains pattern
bool KMP(string pattern, string target)
{
    int m = pattern.length();
    int n = target.length();
    int f[m];
    preKMP(pattern, f);
    int i = 0;
    int k = 0;
    while (i < n)
    {
        if (k == -1)
        {
            i++;
            k = 0;
        }
        else if (target[i] == pattern[k])
        {
            i++;
            k++;
            if (k == m)
                return 1;
        }
        else
            k = f[k];
    }
    return 0;
}
char igno[][100]={{'f','o','r'},{'b','u','t'},{'o','r'},{'y','e','t'},{'s','o'},{'i','n'},{'i','s'},{'c','a','r'}};
int main()
{

struct car
{
    int ID;
    string cost;
    string name;
    string company;
    string specs;
    string description;



};
struct car obj[10] = {{1,"3 lakhs","800","maruti","LPG 796cc petrol","look and style Decent and simple look comfort extremely comfortable than newly launched alto 800 due to larger seats. Its suspension can withsatnd any kind of pathholes we throw at it. Pickup peppy engine"},
{2,"6 lakhs","swift dzire","maruti","1248cc 26.6 kmpl AC"," Based on Suzuki's new Heartect platform (borrowed from the Baleno), the 2017 Swift DZire is 40mm wider and 40mm shorter than the outgoing model. There's a 20mm increment in the wheelbase as well. Also, it is lighter by up to 105kg for the diesel and 85kg for the petrol compared to the second-gen model. The boot space has gone up from 316litres to 376litres"},
{3,"3 lakhs", "omni","maruti","16.8 kmpl 796cc no ac","Maruti Suzuki India has launched a limited edition version of its flagship vehicle, the Omni van. The special edition Omni gets many new features including floor mats , new seat covers, a CD player with four-speakers and AUX input support and the left side ORVM. The engine however remains the same 3-cylinder, 796cc petrol engine that churns out the maximum power output of 37bhp and 62Nm of torque"},
{4,"9 lakhs", "ciaz", "maruti" ,"19.1 kmpl 1373cc transition automatic","Design statement could have been made more sleek with tinkering with body line. The quality of interiors could have been better. Comfort : Very comfortable if high dashboard can be ignored. Leg room and storage points for small things are its USP. During test drive, AC appeared a bit weak despite tuning manually. Pickup: Not so great but no very bad too. Ideal for city driving, but need to shift gears frequently in city driving"},
{
5,"4 lakhs", "alto k10" ,"maruti", "24.1 kmpl 998cc ac central lock"," The safety feature will be provided as an optional attribute from the base variant of Alto K10. The addition means that the buyers can now experience improved safety in Maruti’s entry-level hatchback. The carmaker is also offering left side rear view mirror with all variants of Alto. The announcement comes at a time when Indian Government recently said that it will make airbags mandatory in all cars. Maruti Suzuki has also launched the Alto K10 MS Dhoni edition"},
{
6,"15 lakhs" , "civic" , "honda", "manual petrol 18.1 kmpl","Look and Style IT will be good looking and also stylish very much  Comfort I thought that it will be more comfortable and luxirous Pickup IT pickup will be more powerpul then honda civic Petrol Mileage IT mileage will also good and best mileage Best Features it will looking more attractive,more stylish,more systems,more powerfull engine ETC Needs to improve"},
{
7,"37 lakhs" , "accord" , "honda" ,"23.1 kmpl 1993 cc cruise control parking sensor" ," latest entry of Honda in the festival season is Honda Accord this time Honda comes with new features and technology oriented ,the new machine is full of comfort and luxury"},
{
8,"10 lakhs" , "city" , "honda","25.6 kmpl 1498 cc manual transition rear ac", "exterior : This is proven fact that this is the best looking car in this segment.    Interior (Features, Space & Comfort): Lack of few features which its competition has like, vanity mirror does not have illuminated light. Visibility for rear objects from mirror is poor. But once you get used to, you can judge it"},
{
9,"4 lakhs" ,"eon" ,"hyundai","20.3 kmpl 998 cc ac central lock","The Eon Sports Edition features Sporty Roof Rails, side body moulding graphics and a 6.2-inch touchscreen infotainment system which has phone link, USB, AUX and Bluetooth connectivity. However, the Sports Edition is only available with the smaller 0.8-litre engine and not with the bigger 1.0-litre. The Sports Edition is available with the Era+ variant at about Rs 16,000 more over the stock variant and with the Magna+ variant for a premium of about Rs 10,000. The Eon is powered by a 0.8-litre or a 1.0-litre petrol"},
{

10,"10 lakhs","verna","hyundai","19.1 kmpl 1582 cc automatic transition driver airbag","Hyundai Verna attracted handsome bookings when its new version ie Fluidic verna was launched back in 2011. Due to its up level design and completely refreshed look with featured packed up to the brim, its negativities got ignored. One of those is its extremely low ground guaranteeing bump at each and every speed breaker if filled with two or three"},
};

vector<string> arr;
for(int i=0;i<8;i++)
{

    arr.push_back(igno[i]);
    //cout<<arr[i]<<" ";

}

string s7 = "......";
    ClearConsoleToColors(12,0);
cout<<"\t\t\t";
string q ="WELCOME TO E-CaR SEARCH";

for(int i=0;i<q.size();i++)
    {
        cout<<q[i];
        delay(120);

    }
    cout<<endl;

cout<<"This is a type of";
SetColor(10);
cout<<" Elastic Search ";
SetColor(12);


cout<<"in which user types any string and the best matches are shown with their hit rate of matches. The user can tell how many top matches he wishes to see. The ignorant words are ignored while searching.";
cout<<endl;
char ch;
        cout<<"Press any character to continue : ";
        cin>>ch;


do{

        system("cls");
    cout<<"\n1. Display ignorant words \n2. Search your car \n3. Add ignorant words \n4. EXIT\n";
    cout<<"Enter your choice";
    int a;
    cin>>a;
    switch(a)
    {
        case 1 : {
            system("cls");
         cout<<endl;
        cout<<"The ignorant words are : ";
        for(int i=0;i<arr.size();i++)
        {
            cout<<arr[i]<<" ";


        }
        cout<<endl;
        char ch;
        cout<<"Press any character to continue : ";
        cin>>ch;

        break;
        }
        case 2 : {
            system("cls");
            float hit;
            int co;
            string s1;
            float count=0;
            float match = 0;

        cout<<"Enter the search string : ";
        getline(cin>>ws,s1);
        vector<string> arr2;
        vector<  pair <float,int> > arr3;
        for(int i=0;i<10;i++)
        {
            int p=0;
            for(int j=0;j<s1.size();j++)
            {

                if(s1[j]==' ')
                {
                    string s2 = s1.substr(p,j+p);
                    //cout<<s2.size()<<" ";


                    p=j+1;
                    int m=0;
                    //cout<<s2<<" ";



                for(int k=0;k<obj[i].name.size();k++)
                {
                    if(obj[i].name[k]==' ')
                {
                    string s3 = obj[i].name.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }

               string  s3 = obj[i].name.substr(m,obj[i].name.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;

                 m=0;


                for(int k=0;k<obj[i].cost.size();k++)
                {
                    if(obj[i].cost[k]==' ')
                {
                    string s3 = obj[i].cost.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                 s3 = obj[i].cost.substr(m,obj[i].cost.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;
                 m=0;

                for(int k=0;k<obj[i].company.size();k++)
                {
                    if(obj[i].company[k]==' ')
                {
                    string s3 = obj[i].company.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                 s3 = obj[i].company.substr(m,obj[i].company.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;

                 m=0;

                for(int k=0;k<obj[i].specs.size();k++)
                {
                    if(obj[i].specs[k]==' ')
                {
                    string s3 = obj[i].specs.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                s3 = obj[i].specs.substr(m,obj[i].specs.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;

                 m=0;

                for(int k=0;k<obj[i].description.size();k++)
                {
                    if(obj[i].description[k]==' ')
                {
                    string s3 = obj[i].description.substr(m,k+m);
                    m=k+1;
                    //cout<<s3<<" ";

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                 s3 = obj[i].description.substr(m,obj[i].description.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;


                }



            }
            string s2 = s1.substr(p,s1.size()-p);



                     int m=0;

                for(int k=0;k<obj[i].name.size();k++)
                {
                    if(obj[i].name[k]==' ')
                {
                    string s3 = obj[i].name.substr(m,m+k);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                string s3 = obj[i].name.substr(m,obj[i].name.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;

                 m=0;

                for(int k=0;k<obj[i].cost.size();k++)
                {
                    if(obj[i].cost[k]==' ')
                {
                    string s3 = obj[i].cost.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                s3 = obj[i].cost.substr(m,obj[i].cost.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;
                 m=0;

                for(int k=0;k<obj[i].company.size();k++)
                {
                    if(obj[i].company[k]==' ')
                {
                    string s3 = obj[i].company.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                s3 = obj[i].company.substr(m,obj[i].company.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;

                 m=0;

                for(int k=0;k<obj[i].specs.size();k++)
                {
                    if(obj[i].specs[k]==' ')
                {
                    string s3 = obj[i].specs.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
               s3 = obj[i].specs.substr(m,obj[i].specs.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;

                 m=0;

                for(int k=0;k<obj[i].description.size();k++)
                {
                    if(obj[i].name[k]==' ')
                {
                    string s3 = obj[i].description.substr(m,k+m);
                    m=k+1;

                    if(KMP(s2,s3))
                        match++;

                        count++;

                }

                }
                s3 = obj[i].description.substr(m,obj[i].description.size()-m);
                if(KMP(s2,s3))
                        match++;

                        count++;
            hit = match/count;

        arr3.push_back(make_pair(hit,obj[i].ID));


        }
        sort(arr3.rbegin(),arr3.rend());
        int val ;
        cout<<"Enter the number of entries you wish to look : ";
        cin>>val;
        cout<<"Your top "<<val<<" hit entries are : ";
        for(int i=0;i<6;i++)
                {
                    delay(400);
                    cout<<s7[i];
                }
                cout<<endl;
        for(int i=0;i<val;i++)
        {
            int y = arr3[i].second;
            SetColor(10);
            cout <<"HIT RATE : " << arr3[i].first <<endl;
            cout <<"ID : "<<obj[y-1].ID<<endl;;
            cout <<"Name : "<<obj[y-1].name<<endl;
            cout <<"Company : "<<obj[y-1].company<<endl;
            cout <<"Specs : "<<obj[y-1].specs<<endl;
            cout <<"Description : "<<obj[y-1].description<<endl<<endl;
            SetColor(12);




        }
        cout<<endl;
        char ch;
        cout<<"Press any character to continue : ";
        cin>>ch;
        break;


        }
        case 3 : {
            system("cls");
        cout<<"Enter you ignorant word : ";
        string s3;
        getline(cin>>ws,s3);
        arr.push_back(s3);
        cout<<endl;
        char ch;
        cout<<"Press any character to continue : ";
        cin>>ch;
        break;


        }

        case 4 : {

        exit(0);
        }

    }

}while(1);

}

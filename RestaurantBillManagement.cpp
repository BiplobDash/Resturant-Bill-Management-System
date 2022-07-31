#include<bits/stdc++.h>
using namespace std;

class Resturant
{
public:
    int food_item_codes[12];
    string food_item_names[12];
    int food_item_price[12];
    int total_tax;
};

int main()
{
    Resturant resturent;
    int n;
    cin>>n;

   for(int i = 0; i<n; i++)
   {
       cin>> resturent.food_item_codes[i];
       getchar();
       getline(cin, resturent.food_item_names[i]);
       cin>> resturent.food_item_price[i];
   }
    cout<< n <<endl;
   for(int i = 0; i < n; i++)
   {
       cout<< resturent.food_item_codes[i] <<endl;
       cout<< resturent.food_item_names[i] <<endl;
       cout<< resturent.food_item_price[i] <<endl;
   }

   // Print All Items Name Price and Code
    cout<<"\t\t\t "<< " MAKE BILL"<<"\t\t\t"<<endl;
    cout<<"\t\t\t"<<"---------------"<<"\t\t\t"<<endl;
    cout<<"Item Code"<<"\t\t"<<"Item Name"<<"\t\t"<<"Item Price"<<endl;
   for(int i = 0; i < n; i++)
   {
       cout<< resturent.food_item_codes[i] <<"\t\t\t "<<resturent.food_item_names[i]<<"\t\t\t "<< resturent.food_item_price[i]<<endl;
   }
    cout<<"\n\n";
   // User Input
   cout<<"Enter Table No: ";
   int T;
   cin>>T;
   cout<<"Enter Number of Items: ";
   int t;
   cin>>t;
   int ItemCode[12], Quantity[12];
   for(int i = 1; i <= t; i++)
   {
       cout<<"Enter Item "<<i<<" Code: ";
       cin>>ItemCode[i];
       cout<<"Enter Item "<<i<<" Quantity: ";
       cin>>Quantity[i];
   }
    bool cd = false;
    for(int i = 0; i < t; i++)
    {
        int code = ItemCode[i];
        for(int j = 0; j < 12; j++)
        {
            if(code == resturent.food_item_codes[j])
            {
                cd = true;
            }
        }
    }
    if(cd == false)
    {
        cout<<"Invalid Option"<<endl;
    }
    if(cd == true)
    {
          // Print Bill Statement
       cout<<"\t\t\t "<< " BILL SUMMARY "<<"\t\t\t"<<endl;
       cout<<"\t\t\t"<<"-------------------"<<"\t\t\t"<<endl;
       cout<<"Table No: "<<T<<endl;
       cout<<"Item Code\t\t"<<"Item Name\t\t"<<"Item Price\t"<<"Item Quantity\t"<<"Total Price"<<endl;

        int price1 = 0;
       for(int i = 1; i <= t; i++)
       {
          int mycode = ItemCode[i];
          int quantity = Quantity[i];
          int price = 0;
          for(int j = 0; j < 12; j++)
          {
              if(resturent.food_item_codes[j] == mycode)
              {
                  price = resturent.food_item_price[j] * quantity;
                  cout<<resturent.food_item_codes[j]<<"\t\t\t"<<resturent.food_item_names[j]<<"\t\t\t"<<resturent.food_item_price[j]<<"\t\t"<<quantity<<"\t\t"<<price<<endl;
              }
          }
          price1 += price;
   }
    float tax = (price1 * 5) % 100;
    cout<<"TAX"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t"<<tax<<endl;
    cout<<"----------------------------------------------------------------------------------------------------"<<endl;
    cout<<"NET TOTAL"<<"\t\t\t\t\t\t\t\t\t\t\t\t\t"<<tax+price1;
    return 0;
    }
}

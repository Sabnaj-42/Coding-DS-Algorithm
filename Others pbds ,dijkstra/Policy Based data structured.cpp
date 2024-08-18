#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
//#include <functional>
#include <iostream>

using namespace __gnu_pbds;
using namespace std;
/*typedef tree<pair<int, int>, null_type,   //for using pair
             less<pair<int, int> >, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_multiset;*/

typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update>//sudhu less dile uniqe element rakhbe ,,less_equal dile duplicate value rakhbe
new_data_set;
int main() {
   new_data_set data;
   data.insert(34);
   data.insert(785);
   data.insert(2);
   data.insert(2);
   data.insert(87);
   cout<<"The value at index 0 is "<<*data.find_by_order(0)<<endl;
    cout<<"The value at index 1 is "<<*data.find_by_order(1)<<endl;
   cout<<"The index of number 86 is "<<data.order_of_key(86)<<endl;
   cout<<"The index of number 2 is "<<data.order_of_key(2)<<endl;

   /*
    int num=data.order_of_key(2);//if we keep duplicate delement in pbds..then we have to erase element in this process
    auto temp = data.find_by_order(num);//return the iterator of num index
    data.erase(temp);*///here 2 is removing
    for(auto it=data.begin();it!=data.end();it++)
        cout<<*it<<" ";
    //auto x=data.lower_bound(34);//lower_bound upper_bond er moto kaj kore,,upper_bound lower_bond er moto kaj kore
    //auto y=data.upper_bound(34);
    //cout<<*x<<" "<<*y<<endl;
   //return 0;
}

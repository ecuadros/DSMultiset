#include <iostream>
#include <iterator>
#include <set>
#include <vector>
 
using namespace std;

template <typename Container>
void print(Container &container)
{
    auto itr = container.begin();
    for (; itr != container.end(); itr++)
    {
        cout << *itr<<" ";
    }
    cout << endl;
}

int main()
{ 
    vector<int> v {10, 20, 30, 40, 40, 50, 50, 50, 60, 60, 70, 70, 80, 90};
    multiset<int> MSet; // less<int> default 10 20 30 40 50 60 70 80 90
    multiset<int>::iterator one, end;
    MSet.insert(v.begin(), v.end());
    print(MSet);
    one = MSet.lower_bound (50); 
    end = MSet.upper_bound (80); // 50 <= x <= 80;
    MSet.erase(one , --end); // 10 20 30 40         90
    cout<<"Elements are: ";
    print(MSet);
    cout << '\n';
    v.clear();
    print(MSet);

    MSet.insert(v.begin(), v.end());
    // Removes 60, 70, 80
    //MSet.erase(MSet.find(60) , MSet.find(70)); // 60 <= x < 90
    print(MSet);

    multiset<int> alice{1, 2, 3};
    multiset<int> bob{7, 8, 9, 10};
    multiset<int> eve{1, 2, 3};
 
    cout << boolalpha;
 
    // Compare non equal containers
    cout << "alice == bob returns " << (alice == bob) << '\n';
    cout << "alice != bob returns " << (alice != bob) << '\n';
    cout << "alice <  bob returns " << (alice < bob) << '\n';
    cout << "alice <= bob returns " << (alice <= bob) << '\n';
    cout << "alice >  bob returns " << (alice > bob) << '\n';
    cout << "alice >= bob returns " << (alice >= bob) << '\n';
 
    cout << '\n';
 
    // Compare equal containers
    cout << "alice == eve returns " << (alice == eve) << '\n';
    cout << "alice != eve returns " << (alice != eve) << '\n';
    cout << "alice <  eve returns " << (alice < eve) << '\n';
    cout << "alice <= eve returns " << (alice <= eve) << '\n';
    cout << "alice >  eve returns " << (alice > eve) << '\n';
    cout << "alice >= eve returns " << (alice >= eve) << '\n';
    
    //cout << "alice <=> eve returns " << (alice <=> eve) << '\n';
    //cout << "alice <=> bob returns " << (alice <=> bob) << '\n';

    return 0;
}
#include <bits/stdc++.h>
#define ll long long
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;

// template<class T> using oset = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef tree<ll, null_type, less<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set1; // less => Small to Big

typedef tree<ll, null_type, greater<ll>, rb_tree_tag, tree_order_statistics_node_update> ordered_set2;

// For Pair
typedef tree<pair<ll, ll>, null_type, less<pair<int, int>>, rb_tree_tag, tree_order_statistics_node_update> ordered_set3;

/* Time Complexity: O(log n)
        - Order_of_key(k): Number of items strictly smaller then k
        => name.order_of_key(100);
        - find_by_order(k): K-th element in a set ( Counting from zero)
        => *name.find_by_order(5);
*/


int main()
{

}

#include <bits/stdc++.h>
#include <bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;

template <typename T>
using pbds_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

template <typename K, typename V>
using pbds_map = tree<K, V, less<K>, rb_tree_tag, tree_order_statistics_node_update>;

int main() {
    pbds_set<int> s;
    s.insert(7);
    s.insert(2);
    s.insert(3);
    s.insert(7);    //deduplicated
    printf("%d\n", *s.find_by_order(1));        //prints 3, order is 0-indexed
    printf("%d\n", s.order_of_key(7));          //prints 2, order is 0-indexed
    
    pbds_map<string, int> m;
    m["Rar"] = 3;
    m["Jacq"] = 4;
    m["Cat"] = 7;
    m["Dinosaur"] = 9;
    printf("%s %d\n", m.find_by_order(1)->first.c_str(), m.find_by_order(1)->second);   //prints Dinosaur 9
    printf("%d\n", m.order_of_key("Jacq"));                                             //prints 2
}

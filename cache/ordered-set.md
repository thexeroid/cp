```cpp
#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;

typedef tree<
    pair<int,int>,   // store (value, id)
    null_type,
    less<pair<int,int>>,
    rb_tree_tag,
    tree_order_statistics_node_update
> ordered_set;
```

Creating:
```
ordered_set os;
```

Inserting:
```cpp
int id = 0;
os.insert({value, id++});
```

Count < K
```cpp
int count = os.order_of_key({k, INT_MIN});
```

Kth smallest element (0 index) (weird behaviour if out of bounds)
```cpp
auto it = os.find_by_order(k);
cout << it->first << "\n";
```

we can even lower_bound
```cpp
os.lower_bound()
```
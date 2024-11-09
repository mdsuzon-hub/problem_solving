
// 1. Vectors (std::vector)
// Definition: Dynamic array that allows resizing.
// Use Case: When the number of elements is unknown or changes frequently.

#include <vector>
std::vector<int> vec = {1, 2, 3};  // Declare and initialize
vec.push_back(4);                  // Add an element
vec.pop_back();                    // Remove last element
// Common Applications: Dynamic lists, stack-like structures, resizable arrays.

// 2. Deque (std::deque)
// Definition: Double-ended queue; allows insertion/removal from both ends.
// Use Case: Situations where elements are added/removed frequently at both ends.

#include <deque>
std::deque<int> dq;
dq.push_back(1);   // Add to end
dq.push_front(2);  // Add to front
dq.pop_back();     // Remove from end
dq.pop_front();    // Remove from front
// Common Applications: Sliding window problems, maintaining a list with front and back modifications.

// 3. Set (std::set)
// Definition: Ordered collection of unique elements.
// Use Case: When unique elements are needed and order is important.

#include <set>
std::set<int> s;
s.insert(3);
s.insert(1);
s.insert(2);
if (s.count(1)) { /* Element 1 exists */ }
// Common Applications: Deduplication, range queries, maintaining sorted unique items.

// 4. Unordered Set (std::unordered_set)
// Definition: Hash-based set for unique elements, no specific order.
// Use Case: When unique elements are needed but order doesn’t matter.

#include <unordered_set>
std::unordered_set<int> us;
us.insert(5);
us.insert(10);
// Common Applications: Quick lookups, hash-based deduplication, constant time insertion/deletion.

// 5. Map (std::map)
// Definition: Key-value pairs, sorted by key.
// Use Case: When data must be accessed by unique keys, and keys should be ordered.

#include <map>
std::map<int, std::string> mp;
mp[1] = "apple";
mp[2] = "banana";
std::cout << mp[1];  // Output: apple
// Common Applications: Dictionary lookups, ordered association between keys and values.

// 6. Unordered Map (std::unordered_map)
// Definition: Hash-based map, key-value pairs with no specific order.
// Use Case: When key-value access is required but order doesn’t matter.

#include <unordered_map>
std::unordered_map<int, std::string> ump;
ump[3] = "car";
ump[4] = "bike";
// Common Applications: Hash-based dictionary for fast insertions and lookups, constant time complexity on average.

// 7. Stack (std::stack)
// Definition: Last In, First Out (LIFO) structure.
// Use Case: When the most recent item needs to be processed first.

#include <stack>
std::stack<int> st;
st.push(1);
st.push(2);
st.pop();         // Removes the top element
// Common Applications: Parsing expressions, function call stacks, undo functionality.

// 8. Queue (std::queue)
// Definition: First In, First Out (FIFO) structure.
// Use Case: When the first-added item needs to be processed first.

#include <queue>
std::queue<int> q;
q.push(1);
q.push(2);
q.pop();          // Removes the front element
// Common Applications: Task scheduling, level-order traversal in trees, breadth-first search (BFS).

// 9. Priority Queue (std::priority_queue)
// Definition: Elements are stored based on priority, usually in descending order.
// Use Case: When elements must be accessed in priority order.

#include <queue>
std::priority_queue<int> pq;
pq.push(10);
pq.push(20);
pq.pop();         // Removes the highest-priority element
// Common Applications: Dijkstra’s algorithm, A* search, scheduling tasks based on priority.

// 10. Algorithm Library (<algorithm>)
// Sorting:

#include <algorithm>
std::vector<int> v = {4, 2, 3, 1};
std::sort(v.begin(), v.end());  // Sorts vector in ascending order
Binary Search (for sorted containers):

if (std::binary_search(v.begin(), v.end(), 3)) {
    // 3 is found in vector
}

// Next Permutation:

std::next_permutation(v.begin(), v.end());  // Generates the next lexicographical permutation
Reverse:

std::reverse(v.begin(), v.end());

// 11. Pair (std::pair)
// Definition: Container that stores two heterogeneous objects.
// Use Case: Often used in associative data structures to store key-value pairs.

#include <utility>
std::pair<int, std::string> p = {1, "hello"};
int key = p.first;     // Access first element
std::string val = p.second;  // Access second element
// Common Applications: Coordinate points, key-value pairs in data structures, storing values with ranks or priorities.


// 12. Tuple (std::tuple)
// Definition: Container that stores multiple heterogeneous objects.
// Use Case: When more than two elements need to be grouped together.

#include <tuple>
std::tuple<int, std::string, double> t = {1, "hello", 3.14};
int id = std::get<0>(t);
std::string msg = std::get<1>(t);
double pi = std::get<2>(t);
// Common Applications: Storing multiple attributes of an object, returning multiple values from a function.

// 13. String (std::string)
// Definition: Container for managing and manipulating sequences of characters.
// Use Case: Manipulating text or processing sequences of characters.

#include <string>
std::string str = "hello";
str += " world";        // Concatenate
int len = str.length(); // Get length
//Common Applications: Text processing, parsing, storing data with complex formatting.
#include <iostream>
#include <vector>
#include <string>
#include <random>
#include <functional>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using data = int;


template <class T>
vector<T> random_vector(unsigned int size, T min, T max)
{
  /**
   * make a vector containing random values that are larger than or 
   * equal to "min" and smaller than "max".
   */
  std::random_device rnd;

  vector<T> ret(size);
  for(auto& e : ret)
    e = rnd() % (max - min) + min;

  return ret;
}


template<class T>
void print_vector(vector<T>& vec)
{
  /**
   * print contents of the vector to stdout.
   */
  for(const auto e : vec)
    cout << e << " ";
  cout << endl;
}



template<class T>
void insertion_sort(vector<T>& vec, std::function<bool(T, T)> cmp)
{
  /**
   * INSERTION SORT
   *
   * parameters:
   *    vec ---- a vector to be sorted.
   *    cmp ---- returns true if (1st parameter) < (2nd parameter).
   */

  int i, j;
  T key;

  for(i=1; i<vec.size(); i++)
    {
      key = vec[i];

      // cout << "i = " << i << ", key = " << key << endl;
      
      // Assume that vec[0] -- vec[i-1] have been already sorted.
      // What we will do here is to decide where to INSERT key=vec[i].
      j = i - 1;
      while(j >= 0 and cmp(key, vec[j]))
	j--;

      // cout << "j = " << j << endl;

      vec.erase(vec.begin() + i);
      vec.insert(vec.begin() + j + 1, key);

      // print_vector(vec);
    }
}


template<class T>
vector<T> insertion_sort_recursive(vector<T> vec,
				   class vector<T>::iterator end)
{
  /**
   * RECURSIVE INSERTION SORT
   * 
   * parameters:
   *    begin, end:
   *    key_index: index of the key.
   */

  if(end - vec.begin() <= 1)
    return vec;
  
  insertion_sort_recursive(vec, end-1);
  auto itr = end - 1;
  while(itr >= vec.begin() and *end < *itr) itr--;
  vec.insert(itr+1, *end);
  vec.erase(end+1);

  return vec;
}


int main()
{
  vector<int> vec{1, 4, 2, 10, 5, 5};
  cout << "before: " << endl;
  print_vector(vec);

  // insertion_sort<int>(vec,
  // 	      [](int a, int b)->bool {return a < b;});
  

  cout << "after: " << endl;
  //print_vector(vec);
  vector<int> result = insertion_sort_recursive(vec, vec.end());
  print_vector(result);
}

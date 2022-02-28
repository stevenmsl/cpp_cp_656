#include <iostream>
#include <tuple>
#include <vector>
#include <string>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol656;

/*
Example 1:
Input: [1,2,4,-1,2], 2
Output: [1,3,5]
*/
tuple<vector<int>, int, vector<int>>
testFixture1()
{
  return make_tuple(vector<int>{1, 2, 4, -1, 2}, 2, vector<int>{1, 3, 5});
}

/*
Example 2:
Input: [1,2,4,-1,2], 1
Output: []
*/

tuple<vector<int>, int, vector<int>>
testFixture2()
{
  return make_tuple(vector<int>{1, 2, 4, -1, 2}, 1, vector<int>());
}

/*
Example 3:
Input: [1,4,2,0,0], B=2
Output:[1,3,4,5]
*/

tuple<vector<int>, int, vector<int>>
testFixture3()
{
  return make_tuple(vector<int>{1, 4, 2, 0, 0}, 2, vector<int>{1, 3, 4, 5});
}

void test1()
{
  auto f = testFixture1();
  cout << "Test 1 - exepct to see " << Util::toString(get<2>(f)) << endl;
  auto result = Solution::jump(get<0>(f), get<1>(f));
  cout << "result: " << Util::toString(result) << endl;
}
void test2()
{
  auto f = testFixture2();
  cout << "Test 2 - exepct to see " << Util::toString(get<2>(f)) << endl;
  auto result = Solution::jump(get<0>(f), get<1>(f));
  cout << "result: " << Util::toString(result) << endl;
}
void test3()
{
  auto f = testFixture3();
  cout << "Test 3 - exepct to see " << Util::toString(get<2>(f)) << endl;
  auto result = Solution::jump(get<0>(f), get<1>(f));
  cout << "result: " << Util::toString(result) << endl;
}

main()
{
  test1();
  test2();
  test3();
  return 0;
}
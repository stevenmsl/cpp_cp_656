#include "solution.h"
#include "util.h"
#include <queue>
#include <map>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
#include <functional>

using namespace sol656;
using namespace std;

/*takeaways
  - given two paths that have the same cost, the longer one is
    lexicographically smaller
    - A = [1,4,2,0,0], B=2
    - explanation is based on 1-based array
    - two paths that have the same cost
      p1 = [1,3,5]
      p2 = [1,3,4,5]
    - p2 is lexicographically smaller as index p2[3] < p1[3]
    - for p1 to achieve the same cost but in fewer steps, it
      must jump more aggressively at some point than p2. This
      means p1 will have a larger index in this case, 5, at
      the position where it differs from p2
*/

vector<int> Solution::jump(vector<int> A, int B)
{
  const int n = A.size();
  if (n == 0 || A[n - 1] == -1)
    return {};

  /*maintain the min accumulated cost
    oj jumping to i from the start
  */
  auto costs = vector<int>(n, INT_MAX);
  /*record the previous location along
    the path that has min accumulated
    cost
  */
  auto prev = vector<int>(n, -1);
  /*record the max length among
    paths that have same min
    accumulated cost
  */
  auto length = vector<int>(n, 0);

  costs[0] = 0;

  for (int i = 0; i < n; ++i)
  {
    if (A[i] == -1)
      continue;

    /* exhaust all possible locations (i-B...i-1) that
       can jump to this location (i)
    */
    for (int j = max(0, i - B); j < i; j++)
    {
      if (A[j] == -1)
        continue;
      /* we are scanning from left to right
         - j  < i
         - so at this point costs[j] would
           have been set already and will
           not be INT_MAX
      */
      auto cost = costs[j] + A[i];
      /* if the cost is the same
         - pick the longer one as it's lexicographically
           smaller
      */
      if (cost < costs[i] || (cost == costs[i] && length[j] + 1 > length[i]))
        costs[i] = cost, prev[i] = j, length[i] = length[j] + 1;
    }
  }

  auto result = vector<int>();
  result.push_back(n);

  auto p = n - 1;

  while (prev[p] != -1 && p > 0)
  {
    /* change it to 1-based */
    result.insert(result.begin(), prev[p] + 1);
    p = prev[p];
  }

  /* can't go all the way back to the start */
  if (result[0] != 1)
    return {};

  return result;
}
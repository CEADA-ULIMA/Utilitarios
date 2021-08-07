#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>
using namespace std;

//#define mod 1e9 + 7;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;


// MISC FUNCTIONS
void print(string message)
{
  cout << message;
}

// VECTOR<INT> FUNCTIONS
int findIndexInVector(vector<int> v, int K)
{
  auto it = find(v.begin(), v.end(), K);
  if (it != v.end())
  {
    int index = it - v.begin();
    return index;
  }
  else
  {
    return -1;
  }
}

vector<int> sortInVector(vector<int> values, bool ascend = true)
{
  if (ascend == true)
  {
    sort(values.begin(), values.end());
  }
  else
  {
    sort(values.begin(), values.end(), greater<int>());
  }
  return values;
}

int sumInVector(vector<int> v)
{
  int sum = accumulate(v.begin(), v.end(), 0);
  return sum;
}

vector<int> deleteDuplicates(vector<int> v)
{
  set<int> s;
  unsigned size = v.size();
  for (unsigned i = 0; i < size; ++i)
    s.insert(v[i]);
  v.assign(s.begin(), s.end());
  return v;
}

void subsetsUtil(vector<int> &A, vector<vector<int>> &res, vector<int> &subset, int index)
{
  res.push_back(subset);
  for (int i = index; i < A.size(); i++)
  {

    // include the A[i] in subset.
    subset.push_back(A[i]);

    // move onto the next element.
    subsetsUtil(A, res, subset, i + 1);

    // exclude the A[i] from subset and triggers
    // backtracking.
    subset.pop_back();
  }

  return;
}

const int mod = 1'000'000'007;
const int N = 3e5;

ll modpow(ll x, ll e)
{
  if (e == 0)
    return 1;
  ll a = modpow(x, e >> 1);
  a = a * a % mod;
  if (e & 1)
    a = a * x % mod;
  return a;
}

/// Returns:
/// -------- vector<vector<int>>
/// Usage:
/// -------- vector<vector<int>> res = subsets(array);
vector<vector<int>> subsets(vector<int> &A)
{
  vector<int> subset;
  vector<vector<int>> res;

  // keeps track of current element in vector A;
  int index = 0;
  subsetsUtil(A, res, subset, index);

  return res;
}
//-------------------------------------------------

int main()
{
  // vector<int> arreglo = {2, 2, 3, 4, 5, 6};
  // arreglo = deleteDuplicates(arreglo);
  // for (int i : arreglo)
  // {
  //   print(to_string(i));
  // }
  ll a = 2;
  ll potencia = 8;
  ll result = modpow(a, potencia);
  print(to_string(result));
  return 0;
}
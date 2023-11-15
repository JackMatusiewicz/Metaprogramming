#include <vector>
#include <tuple>

#include "TypeList.h"
#include "Concat.h"
#include "Map.h"
#include "Aggregate.h"
#include "ToType.h"
#include "HList.h"

using FirstList = JML::TypeList<int, float>;
using SecondList = JML::TypeList<char, bool>;

using ConcatList = JML::Concat<FirstList, SecondList>::Result;
using ListOfVectors = JML::Map<std::vector, ConcatList>::Result;
using TupleList = JML::Aggregate<std::tuple, ListOfVectors>::Result;
using ActualType = JML::ToType<TupleList>::Result;

// Proof that it works.
// ActualType is std::tuple<std::vector<int>, std::vector<float>, std::vector<char>, std::vector<bool>>
ActualType foo{{1}, {2.5}, {'a', 'b'}, {true, true, false, true}};

auto end = JML::nil();
std::shared_ptr<JML::HList<int, void>> a = JML::cons(5, end);
std::shared_ptr<JML::HList<const char* , int, void>> b = JML::cons("hello!", a);
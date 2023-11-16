#include <vector>
#include <tuple>

#include "TypeList.h"
#include "Concat.h"
#include "Map.h"
#include "Aggregate.h"
#include "ToType.h"
#include "HList.h"
#include "Count.h"
#include "Repeat.h"
#include "Exists.h"

using FirstList = JML::TypeList<int, float>;
using SecondList = JML::TypeList<char, bool>;

using ConcatList = JML::Concat<FirstList, SecondList>::Result;
using ListOfVectors = JML::Map<std::vector, ConcatList>::Result;
using TupleList = JML::Aggregate<std::tuple, ListOfVectors>::Result;
using ActualType = JML::ToType<TupleList>::Result;

// Proof that it works.
// ActualType is std::tuple<std::vector<int>, std::vector<float>, std::vector<char>, std::vector<bool>>
ActualType foo{{1}, {2.5}, {'a', 'b'}, {true, true, false, true}};

using Quad = JML::Repeat<4u, int>;
using TupleQuad = JML::ToType<JML::Aggregate<std::tuple, Quad>::Result>::Result;

using DoesExist = JML::Exists<int, Quad>::type;
using DoesNotExist = JML::Exists<float, Quad>::type;

TupleQuad x{1,2,3,4};

auto end = JML::singleton(5);
auto a = JML::cons(5, end);
auto b = JML::cons("hello!", a);

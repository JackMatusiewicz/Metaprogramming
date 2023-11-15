#include <vector>
#include <tuple>

#include "TypeList.h"
#include "Concat.h"
#include "Map.h"
#include "Aggregate.h"
#include "ToType.h"

using FirstList = JML::TypeList<int, float>;
using SecondList = JML::TypeList<char, bool>;

using ConcatList = JML::Concat<FirstList, SecondList>::Result;
using ListOfVectors = JML::Map<std::vector, ConcatList>::Result;
using TupleList = JML::Aggregate<std::tuple, ListOfVectors>::Result;
using ActualType = JML::ToType<TupleList>::Result;

// Proof that it works.
ActualType foo{1, 1.5, 'a', false};
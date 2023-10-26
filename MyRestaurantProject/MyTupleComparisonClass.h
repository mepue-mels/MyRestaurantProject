#pragma once
#include <tuple>

using namespace System;

public ref class MyTupleComparisonClass
{
public:
    int Compare(Tuple<String^, int>^ x, Tuple<String^, int>^ y)
    {
        return y->Item2.CompareTo(x->Item2);
    }
};

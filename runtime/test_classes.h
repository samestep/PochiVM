#pragma once

#include "src/common.h"

class TestClassA
{
public:
    void SetY(int y);

    int GetY() const
    {
        return m_y;
    }

    int GetXPlusY(int x)
    {
        return x + m_y;
    }

    void PushVec(int val)
    {
        m_vec.push_back(val);
    }

    size_t GetSize()
    {
        return m_vec.size();
    }

    void SortVector();

    int64_t GetVectorSum()
    {
        int64_t sum = 0;
        for (int val : m_vec)
        {
            sum += val;
        }
        return sum;
    }

    std::string GetStringY()
    {
        return std::string("mystr_") + std::to_string(m_y);
    }

    std::vector<int> m_vec;
    int m_y;
};

class TestClassB
{
public:
    void SetAp(TestClassA* ap)
    {
        m_ap = ap;
    }

    TestClassA* GetAp();

    void SetA(TestClassA* r);

    TestClassA* GetA()
    {
        return &m_a;
    }

    bool TestBool(bool b)
    {
        return m_ap == nullptr || b;
    }

    bool TestBoolStar(bool* b)
    {
        return m_ap == nullptr || *b;
    }

    TestClassA m_a;
    TestClassA* m_ap;
};

inline int FreeFunctionAPlusB(int a, int b)
{
    return a + b;
}

void FreeFunctionStoreValue(int* dst, int src);

template<typename T1, typename T2, typename T3>
int FreeFunctionOverloaded(int x)
{
    if (std::is_same<T1, int>::value) { x += 1; }
    if (std::is_same<T2, int>::value) { x += 2; }
    if (std::is_same<T3, int>::value) { x += 4; }
    return x;
}

template<typename T1, typename T2, typename T3>
int FreeFunctionOverloaded(int x, int y)
{
    if (std::is_same<T1, int>::value) { x += 1; }
    if (std::is_same<T2, int>::value) { x += 2; }
    if (std::is_same<T3, int>::value) { x += 4; }
    return x + y;
}

inline double FreeFunctionOverloaded(double x)
{
    return x + 2.3;
}

template<typename T, int v>
int FreeFunctionTemplated(int x)
{
    if (std::is_same<T, int>::value) { x += 1; }
    return x + v;
}

inline void FreeFunctionPrintFile(FILE* fp, const std::string& content)
{
    fprintf(fp, "FreeFunctionPrintFile: %s\n", content.c_str());
}

inline std::string FreeFunctionConcatStr(TestClassA* a, const std::string& b)
{
    return a->GetStringY() + "_freefnConcatStr_" + b;
}

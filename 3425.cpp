#include<iostream>
#include<stdio.h>
#include<stack>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int main()
{
    string str;
    while (1)
    {
        vector <string> vec;
        vector <long long int> vec2;
        while (1)
        {
            long long int num;
            cin >> str;
            if (str == "QUIT")
                return 0;
            if (str == "END")
                break;
            if (str == "NUM")
            {
                scanf("%lld", &num);
                vec2.push_back(num);
            }
            vec.push_back(str);
        }
        int n;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            int err = 0;
            stack <long long int> st;
            int index = 0;
            int num;
            scanf("%d", &num);
            st.push(num);
            for (int j = 0; j < vec.size(); j++)
            {
                if (err == 1)
                    break;
                if (vec[j] == "NUM")
                {
                    st.push(vec2[index]);
                    index++;
                }
                else if (vec[j] == "POP")
                {
                    if (!st.empty())
                        st.pop();
                    else
                        err = 1;
                }
                else if (vec[j] == "INV")
                {
                    if (!st.empty())
                        st.top() = -1 * st.top();
                    else
                        err = 1;
                }
                else if (vec[j] == "DUP")
                {
                    if (!st.empty())
                        st.push(st.top());
                    else
                        err = 1;
                }
                else if (vec[j] == "SWP")
                {
                    if (st.size() >= 2)
                    {
                        long long int a = st.top();
                        st.pop();
                        long long int b = st.top();
                        st.pop();
                        st.push(a);
                        st.push(b);
                    }
                    else
                        err = 1;
                }
                else if (vec[j] == "ADD")
                {
                    if (st.size() >= 2)
                    {
                        long long int a = st.top();
                        st.pop();
                        long long int b = st.top();
                        st.pop();
                        long long int value = a + b;
                        if (value > 1000000000 || value < -1000000000)
                            err = 1;
                        else
                            st.push(value);
                    }
                    else
                        err = 1;
                }
                else if (vec[j] == "SUB")
                {
                    if (st.size() >= 2)
                    {
                        long long int a = st.top();
                        st.pop();
                        long long int b = st.top();
                        st.pop();
                        long long int value = b - a;
                        if (value > 1000000000 || value < -1000000000)
                            err = 1;
                        else
                            st.push(value);
                    }
                    else
                        err = 1;
                }
                else if (vec[j] == "MUL")
                {
                    if (st.size() >= 2)
                    {
                        long long int a = st.top();
                        st.pop();
                        long long int b = st.top();
                        st.pop();
                        long long int value = a * b;
                        if (value > 1000000000 || value <-1000000000)
                            err = 1;
                        else
                            st.push(value);
                    }
                    else
                        err = 1;
                }
                else if (vec[j] == "DIV")
                {
                    if (st.size() >= 2)
                    {
                        long long int a = st.top();
                        st.pop();
                        long long int b = st.top();
                        st.pop();
                        if (a == 0)
                            err = 1;
                        else
                        {
                            long long int value = b / a;
                            st.push(value);
                        }
                    }
                    else
                        err = 1;
                }
                else if (vec[j] == "MOD")
                {
                    if (st.size() >= 2)
                    {
                        long long int a = st.top();
                        st.pop();
                        long long int b = st.top();
                        st.pop();
                        if (a == 0)
                            err = 1;
                        else
                        {
                            long long int value = b % a;
                            if (b < 0 && value > 0) value = ~value + 1;
                            else if (b > 0 && value < 0) value = ~value + 1;
                            st.push(value);
                        }
                    }
                    else
                        err = 1;
                }
            }
            if (err == 1 || st.size() != 1)
                printf("ERROR\n");
            else
                printf("%lld\n", st.top());   
        }
        printf("\n");
    }
}
// function parser.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>

using namespace std;

double eVAL(string);
bool isValue(string);
bool isOperator(string, string, int);
int find_operator(string, string);

const string  basic_operations="-+/*^";
int _tmain(int argc, _TCHAR* argv[])
{
    string inputexpr;

    cin >> inputexpr;
    while(inputexpr != "exit")
    {
        cout << eVAL(inputexpr) << endl;
        cin >> inputexpr;
    }

    system("pause");
    
    return 0;
}

/**
 * The method which parses and evaluates the string.
 * @param  pexpr string to be evaluated
 * @return       result of evaluation
 */
double eVAL(string pexpr)
{
    int pos;
    string part1, part2, op, func;
    double val1, val2;

    for(int i=0; i<5; i++)
    {
        op=basic_operations[i];
        pos=find_operator(pexpr, op);
        while(pos != -1)
        {
            if(isOperator(pexpr, op, pos))
            {
                part1=pexpr.substr(0,pos);
                part2=pexpr.substr(pos+1, pexpr.length()-pos-1);
                if(part1.empty() || part2.empty())
                {
                    cout << "kkterr" << endl;
                    exit(-1);
                }
                val1=eVAL(part1);
                val2=eVAL(part2);

                switch(i)
                {
                    case 0: return val1-val2; break;
                    case 1: return val1+val2; break;
                    case 2: if(val2==0)
                            {
                                cout << "Error: Division by 0!";
                                exit(-1);
                            }
                            return val1/val2; break;
                    case 3: return val1*val2; break;
                    case 4: return pow(val1, val2); break;
                }
            }
            if(pos > 0) 
                pos=pexpr.rfind(op, pos-1);
            else if(pos == 0)
                pos = -1;
        }
    }
    pos=pexpr.find("(");
    if(pos!=-1 && pexpr[pexpr.length()-1]==')')
    {
        func=pexpr.substr(0,pos);
        part2=pexpr.substr(pos+1, pexpr.length()-2-pos);
        val2=eVAL(part2);
        
        if(func=="sqrt" || func=="-sqrt")return sqrt((double)val2)*pow((double)-1,(double)(func=="-sqrt"));

        else if(func=="abs" || func=="-abs")return abs((double)val2)*pow((double)-1,(double)(func=="-abs"));

        else  if(func=="log10" || func=="-log10")return log10((double)val2)*pow((double)-1,(double)(func=="-log10"));

        else  if(func=="log" || func=="-log")return log((double)val2)*pow((double)-1,(double)(func=="-log"));

        else if(func=="pow" || func=="-pow")return pow((double)2, (double)val2)*pow((double)-1,(double)(func=="-pow"));

        else if(func=="ceil" || func=="-ceil")return ceil((double)val2)*pow((double)-1,(double)(func=="-ceil"));

        else if(func=="floor" || func=="-floor")return floor((double)val2)*pow((double)-1,(double)(func=="-floor"));

        else if(func=="sin" || func=="-sin")return sin((double)val2)*pow((double)-1,(double)(func=="-sin"));

        else if(func=="cos" || func=="-cos")return cos((double)val2)*pow((double)-1,(double)(func=="-cos"));

        else if(func=="tan" || func=="-tan")return tan((double)val2)*pow((double)-1,(double)(func=="-tan"));

        else if(func=="asin" || func=="-asin")return asin((double)val2)*pow((double)-1,(double)(func=="-asin"));

        else if(func=="acos" || func=="-acos")return acos((double)val2)*pow((double)-1,(double)(func=="-acos"));

        else if(func=="atan" || func=="-atan")return atan((double)val2)*pow((double)-1,(double)(func=="-atan"));

        else if(func=="sinh" || func=="-sinh")return sinh((double)val2)*pow((double)-1,(double)(func=="-sinh"));

        else if(func=="cosh" || func=="-cosh")return cosh((double)val2)*pow((double)-1,(double)(func=="-cosh"));

        else if(func=="tanh" || func=="-tanh")return tanh((double)val2)*pow((double)-1,(double)(func=="-tanh"));
 
        
        else return val2;


        // else {cout << "kkterr" << endl;exit(-1);}

    }
    if(isValue(pexpr))
    {
        stringstream ss;
        ss << pexpr;
        double val3;
        ss >> val3;
        return val3;
    } 
    if(pexpr=="pi")
        return 3.14;
    else if(pexpr=="e")
        return 2.71;
}
bool isOperator(string expr, string sop, int n)
{
    string sign;
    char op=sop[0];
    if(op=='-')
    {
        if(n == 0) return false;
        else
        {
            sign = expr[n-1];
            if(basic_operations.find(sign)  !=  -1) return false;
        }
    }
    return true;
}

bool isValue(string str)
{
	double number;
	number = atof(str.c_str());
	
	stringstream ss;
    ss << str;
    double val3;
    ss >> val3;
    
	if(number==val3)
        return true;

    return false;
}

/**
 * Search for the last position of opr in the current
 * string, outside of brackets
 * @param  pexpr string
 * @param  opr   operation
 * @return       positing where is found or -1
 */
int find_operator(string pexpr, string opr)
{
    int opr_pos, open_pos, closed_pos;
    
    closed_pos=pexpr.rfind(')');
	open_pos=pexpr.find('(');
	
	opr_pos=pexpr.rfind(opr);
	if(opr_pos>closed_pos && (closed_pos!=-1))
        return opr_pos;

	opr_pos=pexpr.find(opr);
	if(opr_pos<open_pos && (open_pos!=-1))
		return opr_pos;

	if(open_pos==-1 && closed_pos==-1)
		return opr_pos;
    return -1;
}
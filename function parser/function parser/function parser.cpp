#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <math.h>
#include <vector>

using namespace std;

double eVAL(string);
bool isValue(string);
bool isOperator(string, string, int);
int find_operator(string, string);

const string  basic_operations="-+/*^";
vector<string> functions = vector<string>();


// the structure which stores functions on the GPU
typedef struct function{
	
	int function_id;
	int isNumber;	// can be 0 1
	float value;
	
	string func_name;	// ?????????
	
	//cum fac legatura pt fet and right child?
	function *left_child;
	function *right_child;
};




int main(int argc, _TCHAR* argv[])
{
    string inputexpr;

    cin >> inputexpr;
    while(inputexpr != "exit")
    {
        cout << endl << eVAL(inputexpr) << endl;
		
		cout << "vector: " << endl;
		for(int i = 0; i < functions.size(); ++i)
			cout << functions[i];
		functions.clear();
		cout << endl << endl;

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
    double val1, val2, val3 = 0;

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

				// store the operator
				//cout << "operator: " << op <<" leftpart: " << part1 << " rigth part: " << part2 << endl;
				cout << op << " ";
				functions.push_back(op);
				val1=eVAL(part1);
				val2=eVAL(part2);
				
				/*cout << "eval left >>>>" << endl;
				val1=eVAL(part1);
				cout << "eval left returned: " << val1 << endl;
				
				cout << "eval rigth >>>" << endl;
                val2=eVAL(part2);
				cout << "eval rigth returned: " << val2 << endl;
*/
			
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

	// no operators found, so this is either a bracket or a mathematical function
    pos=pexpr.find("(");
    if(pos!=-1 && pexpr[pexpr.length()-1]==')')
    {
        func=pexpr.substr(0,pos);
        part2=pexpr.substr(pos+1, pexpr.length()-2-pos);
		cout << func << " ";
		functions.push_back(func);
        val2=eVAL(part2);


		double (*functionPtr[200])(double,double);   // array of funcitons holding 2 params


		while(sober<100?sober:sober-100)
			beer++;

		*functionPtr[0]= &sqrt;
		*functionPtr[1]=&sin;

		double (*f2[200])(double); //array holding functions with 1 param
		 /*
		 fn:
		 1= sin
		 2 = cos
		 3 = log
		 ...
		 */
		__shared calculate_this_shit(fn, param1, param2)
		{
			rezultat=functionPtr[fn](param1, param2);
		}
		__shared calculate_this_shit(fn, param1)
		{
			rezultat=f2[fn](plm, param2);
		}

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
    }

    if(isValue(pexpr))
    {
        stringstream ss;
        ss << pexpr;
        ss >> val3;
    } 
    if(pexpr=="pi")
        val3 = 3.14;
    else if(pexpr=="e")
        val3 = 2.71;

	cout << val3 << " ";
	stringstream ss;
    string aux;
	ss << val3;
	ss >> aux;
	functions.push_back(aux);

	return val3;
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
    int opr_pos, bopen, bclosed;
    string sign;

	opr_pos = pexpr.length()-1;
	bopen = bclosed = 0;

	while(opr_pos >= 0)
	{
		sign = pexpr[opr_pos];
		if(sign==opr && bopen==bclosed)
			return opr_pos;
		if(sign=="(")
			++bopen;
		if(sign==")")
			++bclosed;
		--opr_pos;
	}
	return -1;
}
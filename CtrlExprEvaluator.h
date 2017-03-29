#pragma once

#include<iostream>
#include<vector>
#include<stack>
#include<string>
#include<cassert>
#include "MacroDefine.h"
using namespace std;

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//  The following are all PA2 code
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////
// See 3.9.1: Fundamental Types
enum EFundamentalType
{
	// 3.9.1.2
	FT_SIGNED_CHAR,
	FT_SHORT_INT,
	FT_INT,
	FT_LONG_INT,
	FT_LONG_LONG_INT,

	// 3.9.1.3
	FT_UNSIGNED_CHAR,
	FT_UNSIGNED_SHORT_INT,
	FT_UNSIGNED_INT,
	FT_UNSIGNED_LONG_INT,
	FT_UNSIGNED_LONG_LONG_INT,

	// 3.9.1.1 / 3.9.1.5
	FT_WCHAR_T,
	FT_CHAR,
	FT_CHAR16_T,
	FT_CHAR32_T,

	// 3.9.1.6
	FT_BOOL,

	// 3.9.1.8
	FT_FLOAT,
	FT_DOUBLE,
	FT_LONG_DOUBLE,

	// 3.9.1.9
	FT_VOID,

	// 3.9.1.10
	FT_NULLPTR_T,

	FT_INVALID,
	FT_DEFAULT
};

// FundamentalTypeOf: convert fundamental type T to EFundamentalType
// for example: `FundamentalTypeOf<long int>()` will return `FT_LONG_INT`
template<typename T> constexpr EFundamentalType FundamentalTypeOf();
template<> constexpr EFundamentalType FundamentalTypeOf<signed char>() { return FT_SIGNED_CHAR; }
template<> constexpr EFundamentalType FundamentalTypeOf<short int>() { return FT_SHORT_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<int>() { return FT_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<long int>() { return FT_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<long long int>() { return FT_LONG_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned char>() { return FT_UNSIGNED_CHAR; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned short int>() { return FT_UNSIGNED_SHORT_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned int>() { return FT_UNSIGNED_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned long int>() { return FT_UNSIGNED_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<unsigned long long int>() { return FT_UNSIGNED_LONG_LONG_INT; }
template<> constexpr EFundamentalType FundamentalTypeOf<wchar_t>() { return FT_WCHAR_T; }
template<> constexpr EFundamentalType FundamentalTypeOf<char>() { return FT_CHAR; }
template<> constexpr EFundamentalType FundamentalTypeOf<char16_t>() { return FT_CHAR16_T; }
template<> constexpr EFundamentalType FundamentalTypeOf<char32_t>() { return FT_CHAR32_T; }
template<> constexpr EFundamentalType FundamentalTypeOf<bool>() { return FT_BOOL; }
template<> constexpr EFundamentalType FundamentalTypeOf<float>() { return FT_FLOAT; }
template<> constexpr EFundamentalType FundamentalTypeOf<double>() { return FT_DOUBLE; }
template<> constexpr EFundamentalType FundamentalTypeOf<long double>() { return FT_LONG_DOUBLE; }
template<> constexpr EFundamentalType FundamentalTypeOf<void>() { return FT_VOID; }
template<> constexpr EFundamentalType FundamentalTypeOf<nullptr_t>() { return FT_NULLPTR_T; }

///////////////////////////////////////////////////////////////////////////////////////////////////////////
//  The above are all PA2 code
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////

const map<string, int> TerminaltoCodeMap = {

	{"OP_RPAREN",0},	
	{"defined",1},
	{"UNARYOP_PLUS",2},
	{"UNARYOP_MINUS",3},
	{"OP_LNOT",4},
	{"OP_COMPL",5},

	{"OP_STAR",6},
	{"OP_DIV",7},
	{"OP_MOD",8},

	{"OP_PLUS",9},
	{"OP_MINUS",10},
	
	{"OP_LSHIFT",11},
	{"OP_RSHIFT",12},

	{"OP_LT",13},
	{"OP_GT",14},
	{"OP_LE",15},
	{"OP_GE",16},

	{"OP_EQ",17},
	{"OP_NE",18},

	{"OP_AMP",19},
	{"OP_XOR",20},
	{"OP_BOR",21},
	{"OP_LAND",22},
	{"OP_LOR",23},

	{"OP_LPAREN",24},
	{"$",25},

	{"OP_QMARK",26},
	{"OP_COLON",27},

	{"integral-literal",28},
	{"identifier_or_keyword",29},
	{"empty",30}
	
};

const char precede[26][26]={
	{'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'#',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'>',	'<',	'>'},
	{'>',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'>',	'<',	'>'},
	{'=',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'#'},
	{'#',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'<',	'='}
};

string long2str(intmax_t n, bool issigned, int maxwidth = -1){
		string res = "";
		if(!issigned){
			for(uintmax_t a=n;a;a/=10){
				res += char(a % 10 + '0');
			}
			reverse(res.begin(),res.end());
			if(res == "") res = "0";
			res += 'u';
		}else{
			if(n >= 0){
				for(intmax_t a=n;a;a/=10){
					res += char(a % 10 + '0');
				}
				reverse(res.begin(),res.end());
			}else{
				intmax_t n1 = ~n+1;
				for(intmax_t a=n1;a;a/=10){
					res += char(a % 10 + '0');
				}
				res += '-';
				reverse(res.begin(),res.end());
			}
			if(res == "") res = "0";
		}
		if(maxwidth > 0){
			while(res.length() < (unsigned int)maxwidth) res += ' ';
		}
		return res;
	}

class CtrlExprEvaluator{ 

	class SyntaxTreeNode{
	
	public:	
		int Code;
		int preorder,proorder;
		intmax_t syn;
		bool issigned,iserror;
		string idword;	
	
		SyntaxTreeNode():Code(-1),preorder(0),proorder(0),syn(0),issigned(true),iserror(false){
			idword = "";
		}

		SyntaxTreeNode(int c):Code(c),preorder(0),proorder(0),syn(0),issigned(true),iserror(false){
			idword = "";
		}
	};
	
	vector<SyntaxTreeNode*> exp;
	SyntaxTreeNode* result;

public:	CtrlExprEvaluator(){
		result = NULL;
	}

	// mock implementation of IsDefinedIdentifier for PA3
	// return true iff first code point is odd
	bool PA3Mock_IsDefinedIdentifier(const string& identifier)
	{
		bool ans = 0;
		if(Mapname2Mapindex.find(identifier) != Mapname2Mapindex.end()){
			ans = true;
		}else{
			ans = false;
		}
		if(identifier == "__FILE__" || identifier == "__LINE__"){
			ans = true;
		}
		return ans;
	}

	bool Input_a_Integer(long data, EFundamentalType type, bool isunsigned){
		SyntaxTreeNode* node = new SyntaxTreeNode(TerminaltoCodeMap.at("integral-literal"));		
		node -> preorder = node -> proorder = exp.size();
		node -> syn = data;
		node -> issigned = !isunsigned;
		exp.push_back(node);
		return true;
	}

	bool Input_a_simple(const string& source, string token_type){
		
		if(token_type.substr(0,2) == "KW"){
			//cout<<"KW"<<source<<endl;
			if(source == "true" || source == "false"){
				//cout<<"KW true "<<source<<endl;
				return Input_a_Integer(source == "true" ? 1:0, FundamentalTypeOf<bool>(), false);
			}else{
				return Input_a_id(source);				
			}		
		}else{
			//cout<<"OP "<<source<<endl;
			if(TerminaltoCodeMap.find(token_type) == TerminaltoCodeMap.end()){
				return false;
			}
			SyntaxTreeNode* node = new SyntaxTreeNode(TerminaltoCodeMap.at(token_type));			
			node -> preorder = node -> proorder = exp.size();
			exp.push_back(node);
			return true;
		}
		
	}
	bool Input_a_id(const string& source){
		SyntaxTreeNode* node = NULL;
		if(source != "defined"){
			node = new SyntaxTreeNode(TerminaltoCodeMap.at("identifier_or_keyword"));
			node -> idword = source;
		}else 
			node = new SyntaxTreeNode(TerminaltoCodeMap.at("defined"));
		node -> preorder = node -> proorder = exp.size();
		exp.push_back(node);
		return true;
	}
	
	bool precedence_before(SyntaxTreeNode* a, SyntaxTreeNode* b){
		bool res = false;
		if(b -> preorder == a -> proorder + 1){
			if(b -> Code == TerminaltoCodeMap.at("OP_PLUS")){
				b -> Code = TerminaltoCodeMap.at("UNARYOP_PLUS");
			}else if(b -> Code == TerminaltoCodeMap.at("OP_MINUS")){
				b -> Code = TerminaltoCodeMap.at("UNARYOP_MINUS");
			}
		}
		if(precede[a->Code][b->Code]=='>') res = true;
		else if(precede[a->Code][b->Code]=='<') res = false;
		else if(precede[a->Code][b->Code]=='=') res = false;
		else if(precede[a->Code][b->Code]=='#'){
			a -> iserror = true;
			b -> iserror = true;
			res = true;
		}
		return res;
	}

	SyntaxTreeNode* Calculate(SyntaxTreeNode* oper, SyntaxTreeNode* num1, SyntaxTreeNode* num2){
		//cout<<oper->Code<<" "<<num1->iserror<<" "<<num2->iserror<<endl;
		SyntaxTreeNode* res = new SyntaxTreeNode(TerminaltoCodeMap.at("integral-literal"));
		if(oper -> Code == TerminaltoCodeMap.at("defined")){
			res -> syn = PA3Mock_IsDefinedIdentifier(num2 -> idword);			
		}else if(oper -> Code == TerminaltoCodeMap.at("UNARYOP_PLUS")){
			if(num2 -> iserror){
				res -> iserror = true;
			}
			res -> syn = num2 -> syn;
			res -> issigned = num2 -> issigned;
		}else if(oper -> Code == TerminaltoCodeMap.at("UNARYOP_MINUS")){
			if(num2 -> iserror){
				res -> iserror = true;
			}
			res -> syn = - num2 -> syn;
			res -> issigned = num2 -> issigned;
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_LNOT")){
			if(num2 -> iserror){
				res -> iserror = true;
			}
			res -> syn = ! num2 -> syn;
			res -> issigned = true;
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_COMPL")){
			if(num2 -> iserror){
				res -> iserror = true;
			}
			res -> syn = ~ num2 -> syn;
			res -> issigned = num2 -> issigned;
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_STAR")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			if(res -> issigned) res -> syn = num1 -> syn * num2 -> syn;
			else res -> syn = uintmax_t(num1 -> syn) * uintmax_t(num2 -> syn);
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_DIV")){
			if(num1 -> iserror || num2 -> iserror || num2 -> syn == 0){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			if(res -> iserror == false){
				if(res -> issigned) res -> syn = num1 -> syn / num2 -> syn;
				else res -> syn = uintmax_t(num1 -> syn) / uintmax_t(num2 -> syn);
			}
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_MOD")){
			if(num1 -> iserror || num2 -> iserror || num2 -> syn == 0){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			if(res -> iserror == false){
				if(res -> issigned) res -> syn = num1 -> syn % num2 -> syn;
				else res -> syn = uintmax_t(num1 -> syn) % uintmax_t(num2 -> syn);
			}
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_PLUS")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			if(res -> issigned) res -> syn = num1 -> syn + num2 -> syn;
			else res -> syn = uintmax_t(num1 -> syn) + uintmax_t(num2 -> syn);
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_MINUS")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			if(res -> issigned) res -> syn = num1 -> syn - num2 -> syn;
			else res -> syn = uintmax_t(num1 -> syn) - uintmax_t(num2 -> syn);
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_LSHIFT")){
			if(num1 -> iserror || num2 -> iserror || num2 -> syn >= 64 || num2 -> syn < 0){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned;
			if(res -> iserror == false){
				if(res -> issigned) res -> syn = num1 -> syn << num2 -> syn;
				else res -> syn = uintmax_t(num1 -> syn) << uintmax_t(num2 -> syn);
			}
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_RSHIFT")){
			if(num1 -> iserror || num2 -> iserror || num2 -> syn >= 64 || num2 -> syn < 0){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned;
			if(res -> iserror == false){
				if(res -> issigned) res -> syn = num1 -> syn >> num2 -> syn;
				else res -> syn = uintmax_t(num1 -> syn) >> uintmax_t(num2 -> syn);
			}
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_LT")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = true;
			if(num1 -> issigned && num2 -> issigned) 
				res -> syn = num1 -> syn < num2 -> syn;
			else if(num1 -> issigned && !num2 -> issigned) 
				res -> syn = num1 -> syn < uintmax_t(num2 -> syn);
			else if(!num1 -> issigned && num2 -> issigned) 
				res -> syn = uintmax_t(num1 -> syn) < num2 -> syn;
			else
				res -> syn = uintmax_t(num1 -> syn) < uintmax_t(num2 -> syn);
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_GT")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = true;
			if(num1 -> issigned && num2 -> issigned) 
				res -> syn = num1 -> syn > num2 -> syn;
			else if(num1 -> issigned && !num2 -> issigned) 
				res -> syn = num1 -> syn > uintmax_t(num2 -> syn);
			else if(!num1 -> issigned && num2 -> issigned) 
				res -> syn = uintmax_t(num1 -> syn) > num2 -> syn;
			else
				res -> syn = uintmax_t(num1 -> syn) > uintmax_t(num2 -> syn);
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_LE")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = true;
			if(num1 -> issigned && num2 -> issigned) 
				res -> syn = num1 -> syn <= num2 -> syn;
			else if(num1 -> issigned && !num2 -> issigned) 
				res -> syn = num1 -> syn <= uintmax_t(num2 -> syn);
			else if(!num1 -> issigned && num2 -> issigned) 
				res -> syn = uintmax_t(num1 -> syn) <= num2 -> syn;
			else
				res -> syn = uintmax_t(num1 -> syn) <= uintmax_t(num2 -> syn);
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_GE")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = true;
			if(num1 -> issigned && num2 -> issigned) 
				res -> syn = num1 -> syn >= num2 -> syn;
			else if(num1 -> issigned && !num2 -> issigned) 
				res -> syn = num1 -> syn >= uintmax_t(num2 -> syn);
			else if(!num1 -> issigned && num2 -> issigned) 
				res -> syn = uintmax_t(num1 -> syn) >= num2 -> syn;
			else
				res -> syn = uintmax_t(num1 -> syn) >= uintmax_t(num2 -> syn);
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_EQ")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = true;
			res -> syn = num1 -> syn == num2 -> syn;
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_NE")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = true;
			res -> syn = num1 -> syn != num2 -> syn;
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_AMP")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			res -> syn = num1 -> syn & num2 -> syn;
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_XOR")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			res -> syn = num1 -> syn ^ num2 -> syn;
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_BOR")){
			if(num1 -> iserror || num2 -> iserror){
				res -> iserror = true;
			}
			res -> issigned = num1 -> issigned && num2 -> issigned;
			res -> syn = num1 -> syn | num2 -> syn;
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_LAND")){
			res -> issigned = true;
			if(bool(num1 -> syn)){
				res -> syn = bool(num2 -> syn);
				res -> iserror = num1 -> iserror || num2 -> iserror;
			}else{
				res -> syn = false;	
				res -> iserror = num1 -> iserror;			
			}
			
		}else if(oper -> Code == TerminaltoCodeMap.at("OP_LOR")){
			res -> issigned = true;
			if(bool(num1 -> syn)){
				res -> syn = true;
				res -> iserror = num1 -> iserror;
			}else{
				res -> syn = bool(num2 -> syn);	
				res -> iserror = num1 -> iserror || num2 -> iserror;	
			}
			
		}else{
			cerr<<"Tell me what the hell it is !!!!!! For God sake!!!"<<endl;
		}		

		if(oper -> Code == TerminaltoCodeMap.at("defined") || oper -> Code == TerminaltoCodeMap.at("UNARYOP_PLUS") || 
		oper -> Code == TerminaltoCodeMap.at("UNARYOP_MINUS") || oper -> Code == TerminaltoCodeMap.at("OP_LNOT") || 
		oper -> Code == TerminaltoCodeMap.at("OP_COMPL")){
			res -> preorder = oper -> preorder;
			res -> proorder = num2 -> proorder;
		}else{
			res -> preorder = num1 -> preorder;
			res -> proorder = num2 -> proorder;
		}
		return res;									
	}
		
	SyntaxTreeNode* Expression(uint sta,uint end){
		stack<SyntaxTreeNode*> op,opnum;
		SyntaxTreeNode* endop = new SyntaxTreeNode(TerminaltoCodeMap.at("$"));
		SyntaxTreeNode* res = new SyntaxTreeNode(TerminaltoCodeMap.at("integral-literal"));
		op.push(endop);
		op.top() -> preorder = op.top() -> proorder = sta - 1;	

		SyntaxTreeNode* temp = exp[end+1];
		exp[end+1] = new SyntaxTreeNode(TerminaltoCodeMap.at("$"));

		for(uint i = sta; i <= end + 1; i++){
			if(exp[i]->Code == TerminaltoCodeMap.at("integral-literal") || exp[i]->Code == TerminaltoCodeMap.at("identifier_or_keyword")){
				opnum.push(exp[i]);
			}else{
				if(op.top() -> Code == TerminaltoCodeMap.at("OP_LPAREN") && exp[i] -> Code == TerminaltoCodeMap.at("OP_RPAREN")){
					//cout<<"brackets"<<endl;	
					if(opnum.empty()){
						res -> iserror = true;
						return res;
					}else if(opnum.top()->preorder == op.top()->proorder + 1 && exp[i]->preorder == opnum.top()->proorder + 1){
						opnum.top()->preorder--;opnum.top()->proorder++;
					}else{
						res -> iserror = true;
						return res;
					}			
					op.pop();
				}else if(precedence_before(op.top(),exp[i])){
					if(exp[i]->iserror){
						res -> iserror = true;
						return res;
					}	
					//cout<<"precedence "<<op.top()->Code<<" "<<exp[i]->Code<<endl;
					SyntaxTreeNode* num1 = NULL,*num2 = NULL,*oper = NULL;
					if(op.top() -> Code == TerminaltoCodeMap.at("defined") || 
					op.top() -> Code == TerminaltoCodeMap.at("UNARYOP_PLUS") || 
					op.top() -> Code == TerminaltoCodeMap.at("UNARYOP_MINUS") || 
					op.top() -> Code == TerminaltoCodeMap.at("OP_LNOT") || 
					op.top() -> Code == TerminaltoCodeMap.at("OP_COMPL")){
						if(op.top() -> proorder + 1 == opnum.top() -> preorder){
							num2 = opnum.top(); opnum.pop();		
						}else{
							res -> iserror = true;
							return res;
						}		
					}else{
						num2 = opnum.top(); opnum.pop();
						num1 = opnum.top(); opnum.pop();
						if(num1 -> proorder + 1 == op.top() -> preorder && op.top() -> proorder + 1 == num2 -> preorder){		
						}else{
							res -> iserror = true;
							return res;
						}		
						
					}
						
					oper = op.top(); op.pop();	
					SyntaxTreeNode* r = Calculate(oper,num1,num2);
					opnum.push(r);
					//cout<<"cal result:"<<r->syn<<endl;
					i--;
				}else{
					//cout<<"push "<<exp[i]->Code<<endl;
					op.push(exp[i]);
				}
			}
		}
		exp[end+1] = temp;
		res = opnum.top();
		return res;
	}

	SyntaxTreeNode* ControlExpression(uint ista, uint iend){
		SyntaxTreeNode* res = new SyntaxTreeNode(TerminaltoCodeMap.at("integral-literal"));
		uint qmark = 0, colon = 0;	
		uint qmarkc = 0, colonc = 0;
		for(uint i = ista;i <= iend;i++){
			if(exp[i]->Code == TerminaltoCodeMap.at("OP_QMARK")){
				if(qmarkc == 0) qmark = i;
				qmarkc++;
				
			}else if(exp[i]->Code == TerminaltoCodeMap.at("OP_COLON")){
				if(colonc + 1 == qmarkc && colon == 0) colon = i;
				colonc++;
			}
		}
		//cout<<"qmark "<<qmark<<"  "<<colon<<endl;
		if(qmarkc != colonc){
			res -> iserror = true;
			return res;
		}
		if(qmarkc == 0){
			//cout<<"cont "<<ista<<"  "<<iend<<endl;
			res = Expression(ista,iend);
			return res;

		}else{
			
			SyntaxTreeNode* log,*c1,*c2;
			log = ControlExpression(ista,qmark-1);
			c1 = ControlExpression(qmark+1,colon-1);
			c2 = ControlExpression(colon+1,iend);
			if(log->syn) {
				res->syn = c1->syn; 
				res->iserror = c1->iserror;
			}else {
				res->syn = c2->syn; 
				res->iserror = c2->iserror;
			}
			res->issigned = c1->issigned && c2->issigned;
			
			return res;
		}
	}

	void printvector(){
		for(uint i=0;i<exp.size();i++){
			cout<<exp[i]->Code<<" ";
		}cout<<endl;
	}

	bool Input_end(){
		exp.push_back(new SyntaxTreeNode(TerminaltoCodeMap.at("$")));
		result = ControlExpression(0,exp.size()-2);
		if(result == NULL || result -> iserror) return false;
		else return true;
	}
	
		

	string GetResult(){
		string res = long2str(result -> syn, result -> issigned);
		return res;
	}

	bool empty(){
		return exp.empty() && result == NULL;
	}

	void clear(){
		if(empty()) return;
		exp.clear();
		delete result;
		result = NULL;
	}
};

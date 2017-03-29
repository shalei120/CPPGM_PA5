#pragma once
#include<string>
#include<map>
#include<vector>
#include<stack>
using namespace std;

class PA4_pptoken;

class Macro{
public:
	string name;
	bool isfunc;
	//vector<string> parameters;
	map<string,int> parameter2pos;
	vector<PA4_pptoken*> replacementlist;

	Macro():name(""),isfunc(false){}
	bool isfunction(){
		return isfunc;
	}
};
vector<Macro*> macros;
map<string,int> Mapname2Mapindex;        
stack<int> undef_macro_pos_stack;
vector<PA4_pptoken*> textsequence;



class PA5_PreprocIE{
public:
	string name;
	bool active;           //whether this branch is active
	bool pre_has_active;
	bool inuse;		// whether this is preproc s=us active;

	PA5_PreprocIE():name(""), active(false), pre_has_active(false),inuse(true){}
	PA5_PreprocIE(string s, bool act, bool pre = false, bool use = true):name(s), active(act), pre_has_active(pre), inuse(use){}
};
stack<PA5_PreprocIE*> Include_file_stack;

/*************************************************************************
    > File Name: Term.h
    > Author: zhangke
    > Mail: ch.zhangke@gmail.com 
    > Created Time: 2015年09月22日 星期二 20时13分24秒
 ************************************************************************/

#include<iostream>
using namespace std;
class Plyonminal;
class Term
{
	public:
		Term(int c,int e);
		Term(int c,int e,Term *nxt);
		Term* InsertAfter(int c,int e);
	private:
		int coef;
		int exp;
		Term *link;
		friend ostream & operator<<(ostream &,const Term &);
		friend class Polynominal;
};
Term::Term(int c,int e):coef(c),exp(e)
{
	link=0;
}
Term::Term(int c,int e,Term *nxt):coef(c),exp(e)
{
	link=nxt;
}
Term *Term::InsertAfter(int c,int e)                           //Insert a new Term object after the exist Term node
{                                                              //This first  and the second link is " this->link "
	link=new Term(c,e,link);                                   //Befor doing the function this=q1,q1->link=q2;
	return link;                                               //After doing the function , creat a new Term node (p) ; the Function Term(int c,int e,Term *nxt) is transfered.
}                                                              //p->link=q1->link=q2;	q1->link=p;
ostream &operator << (ostream & out,const Term& val)
{
	if(val.coef==0)
		return out;
	out<<val.coef;
	switch(val.exp)
	{
		case 0:
			break;
		case 1:out<<"X";
			break;
		default:
			   out<<"X^"<<val.exp;
			   break;

	}
	return out;
}

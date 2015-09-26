/*************************************************************************
    > File Name: Polynominal.h
    > Author: zhangke
    > Mail: ch.zhangke@gmail.com 
    > Created Time: 2015年09月22日 星期二 21时12分34秒
 ************************************************************************/
#include<iostream>
#include"Term.h"
using namespace std;
class Polynominal
{
	public:
		Polynominal();
		~Polynominal();
		void AddTerms(istream& in);
		void Output(ostream& out) const;
		void PolyAdd(Polynominal& r);
	private:
		Term* theList;
		friend ostream & operator << (ostream & ,const Polynominal &);
		friend istream & operator >> (istream & ,Polynominal &);
		friend Polynominal & operator +(Polynominal & ,Polynominal &);
};
Polynominal::Polynominal()
{
	theList=new Term(0,-1);
	theList->link=theList;
}
Polynominal::~Polynominal()
{
	Term* p=theList->link;
	while (p!=theList)
	{
		theList->link=p->link;
		delete p;
		p=theList->link;
	}
	delete theList;
}
void Polynominal::AddTerms (istream & in)
{
	Term *q=theList;
	int c,e;
	for(;;)
	{
		cout<<"Input a term(coef,exp): "<<endl;
		cin>>c>>e;
		if(e<0)
			break;
		q=q->InsertAfter(c,e);
	}
}
void Polynominal::Output(ostream & out) const
{
	int first=1;
	Term *p=theList->link;
	cout<<"The polynominal is : "<<endl;
	for(;p!=theList;p=p->link)
	{
		if(!first && (p->coef))
			out<<"+";
		first=0;
		out<<*p;
	}
	cout<<endl;
}
void Polynominal::PolyAdd(Polynominal & r)
{
	Term* q,*q1=theList,*p;
	p=r.theList->link;

	q=q1->link;
	while(p->exp>=0)
	{
		while(p->exp<q->exp)
		{
			q1=q;
			q=q->link;
		}
		if(p->exp == q->exp)
		{
			q->coef=q->coef+p->coef;
			if(q->coef==0)
			{
				q1->link=q->link;
				delete(q);
				q=q1->link;
			}
			else
			{
				q1=q;
				q=q->link;
			}
		}
		else
			q1=q1->InsertAfter(p->coef,p->exp);
		p=p->link;
	}
}
ostream& operator << (ostream &out,const Polynominal &x)
{
	x.Output(out);
	return out;
}
istream &operator >> (istream &in,Polynominal &x)
{
	x.AddTerms(in);
	return in;
}
Polynominal &operator +(Polynominal &a,Polynominal &b)
{
	a.PolyAdd(b);
	return a;
}


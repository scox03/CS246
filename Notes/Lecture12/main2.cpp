/******************************************
Binary Trees & Binary Search Trees
******************************************/
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "BTNode.h"
#include "Repository.h"
#include "Stack.h"
#include "Node.h"

namespace ds
{
	template <typename T>
    	int Size(sn::BTNode<T>* root)
    	{
        	if(root == NULL)
        	{
            		return 0;
        	}
        	else 
        	{
            		return 1 + Size(root->left) + Size(root->right);
        	}
    	}

	sn::Stack<int> Ancestors(int p)
	{
		sn::Stack<int> a;

		while(p > 0)
		{
			p = (p - 1) / 2; //parent index
			a.Push(p);
		}
		return a;
	}

	template <typename T>
	void BTInsert(sn::BTNode<T>*& root,const T& value)
    	{
        	if(root == NULL)
        	{
            		root = sn::TCreate(value);
            		return;
        	}

        	int sz = Size(root);
        	int p = sz;
        	sn::Stack<int> ac = Ancestors(p);
        	sn::BTNode<T>* t = root;
        	int pp = 0;
        	ac.Pop();

        	while(!ac.IsEmpty())
        	{
            		p = ac.Top();
            		ac.Pop();

            		if(2 * pp + 1 == p)
            		{
                		t = t->left;
            		}
            		else 
            		{
                		t = t->right;
            		}
            		pp = p;
        	}

        	if(t->left == NULL)
        	{
            		t->left = ds::sn::TCreate(value);
        	}
        	else
        	{
            		t->right = ds::sn::TCreate(value);
        	}
	}

    template <typename T>
    void BSTInsert(sn::BTNode<T>*& root,const T& value)
    {
        if(root == NULL)
        {
            root = ds::sn::TCreate(value);
        }
        else if(root->data > value)
        {
            BSTInsert(root->left,value);            
        }
        else
        {
            BSTInsert(root->right,value);            
        }
    }

    template <typename T>
    sn::BTNode<T>* BTSearch(sn::BTNode<T>* root,const T& value)
    {
        if(root == NULL)
        {
            return NULL;
        }
        else if(root->data == value)
        {
            return root;
        }
        else
        {
            sn::BTNode<T>* ltNode = BTSearch(root->left,value);
            sn::BTNode<T>* rtNode = BTSearch(root->right,value);

            if(ltNode == NULL && rtNode == NULL)
            {
                return NULL;
            }
            else if(ltNode != NULL)
            {
                return ltNode;
            }
            else
            {
                return rtNode;
            }
        }
    }

    template <typename T>
    sn::BTNode<T>* BSTSearch(sn::BTNode<T>* root,const T& value)
    {
        if(root == NULL || root->data == value)
        {
            return root;
        }
        else if(root->data > value)
        {
            return BSTSearch(root->left,value);
        }
        else
        {
            return BSTSearch(root->right,value);
        }
    }
}

int main()
{
	ds::sn::BTNode<int>* tB[2];
	int values[7] = {3,5,1,2,7,4,6};
	void (*prints[3])(ds::sn::BTNode<int>*) = {ds::Infix<int>,ds::Prefix<int>,ds::Postfix<int>};
	std::string btn[2] = {"Binary Search Tree","Binary Tree"};
	std::string ptn[3] = {"Infix","Prefix","Postfix"};

	for(int i = 0;i < 2;i += 1)
	{
		tB[i] = NULL;
	}

	for(int i = 0;i < 7;i += 1)
	{
		ds::BSTInsert(tB[0],values[i]);
		ds::BTInsert(tB[1],values[i]);
	}
	
	for(int i = 0;i < 2;i += 1)
	{
		std::cout << btn[i] << "\n";

		for(int j = 0;j < 3;j += 1)
		{
			std::cout << ptn[j] << ": ";
			prints[j](tB[i]); 
			std::cout << "\n";	
		}
	}

	for(int i = 0;i < 2;i += 1)
	{
		ds::sn::Clear(tB[i]);
    	}
	return 0;
}

#include <iostream>
#include <string>
#include <fstream>
#include "Node.h"
#include "Queue.h"
#include "Vector.h"

bool RookMove(ds::Vector<char>& bd,int s,int e)
{
	//check that parameters are valid
	if(bd.Length() == 64 && s >= 0 && s <= 63 && e >= 0 && e <= 63)
	{
		//indicates if positions are visited
		ds::Vector<bool> visits(64);
		ds::mn::Queue<int> possibilities;
		int adjs[4], r, c, idx;

		//initialize visits
		for(int i = 0;i < 64;i += 1)
		{
			visits.Insert(false);
		}

		possibilities.Enqueue(s);
		visits[s] = true;

		//search board for a path to end if possible
		while(!possibilities.IsEmpty())
		{
			idx = possibilities.Peek();
			possibilities.Dequeue();
			r = idx / 8;
			c = idx % 8;
			adjs[0] = 8 * (r + 1) + c; //one above i.e idx += 8
			adjs[1] = 8 * (r - 1) + c; //one below i.e idx -= 8
			adjs[2] = 8 * r + (c + 1); //one right i.e idx += 1
			adjs[3] = 8 * r + (c - 1); //one left i.e idx -= 1

			for(int i = 0;i < 4;i += 1)
			{
				if(adjs[i] == e)
				{
					return true;
				}
				else if(adjs[i] >= 0 && adjs[i] <= 63)
				{
					if(!visits[adjs[i]] && bd[adjs[i]] != 'x')
					{
						visits[adjs[i]] = true;
						possibilities.Enqueue(adjs[i]);
					}
				}
			}
		}
	}
	return false;
}

int main()
{
	std::string path;
	std::fstream in;
	int start, end;
	ds::Vector<char> board;

	std::cout << "Enter board file: ";
	std::cin >> path;

	in.open(path.data(),std::fstream::in);

	if(in.is_open())
	{
		char ch;
		
		while(in >> ch)
		{
			board.Insert(ch);
		}

		in.close();
	}

	std::cout << "Enter start position: ";
	std::cin >> start;

	std::cout << "Enter end position: ";
	std::cin >> end;

	std::cout << std::boolalpha;
	std::cout << "It is " << RookMove(board,start,end) << " that a rook can make it to " << end << " from " << start << "\n";
		
	return 0;
}

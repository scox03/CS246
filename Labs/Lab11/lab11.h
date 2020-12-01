#ifndef LAB11_H
#define LAB11_H

#include <iostream>
#include <string>
#include <sstream>

template<class K,class V>
class MapInterface
{
	public:
	virtual void Put(const K&,const V&) = 0;
	virtual V& Get(const K&) = 0;
	virtual bool Contains(const K&) const = 0;
	virtual void Remove(const K&) = 0;
	virtual std::string ToString() const = 0;
};

template<class K,class V>
class Map : public MapInterface<K,V>
{
	private:
	K keys[100];
	V values[100];
	int size;
	
	Map(const Map<K,V>&);
	Map& operator=(const Map<K,V>&);

	public:
	Map() : size(0) {}

	~Map() {}
	//define methods below here


	//define methods above here
};

#endif

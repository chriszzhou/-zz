#pragma once
#include<vector>
#include<iostream>
#include<string>
#include"common.h"
enum state{ EMPTY,EXIST,DELETE };
template<class T>
struct Elem{
	Elem(const T& date=T())
		:_date(date)
		,_state(EMPTY)
	{}
	T _date;
	state _state;
};
template<class T>
class DFDef {
public :
	size_t operator()(const T& date) {
		return date;
	}
};
class DFstr {
public:
	size_t operator()(const std::string& date) {
		return BKDRHash(date.c_str());
	}
private:
	size_t BKDRHash(const char*str)
	{
		register size_t hash = 0;
		while (size_t ch = (size_t)*str++)
		{
			hash = hash * 131 + ch;
		}
		return hash;
	}
};
//约定：哈希表格中的元素必须唯一
template<class T,class DF=DFDef<T>,bool isline=true>
class hashtable {
public:
	hashtable(size_t capacity= Getnextprime(10))
	:_size(0)
	,_total(0)
	{
		_table.resize(capacity);
	}
	bool insert(const T& date) {
		checkcapacity();
		//1.通过哈希函数，计算哈希地址
		size_t hashaddr = hashfunc(date);
		size_t i = 0;
		while (_table[hashaddr]._state != EMPTY) {
			//元素已存在
			if (_table[hashaddr]._state == EXIST && _table[hashaddr]._date == date)
				return false;
			if (isline) {
				//线性探测
				hashaddr++;
				if (hashaddr == _table.capacity()) {
					hashaddr = 0;
				}
			}
			else {
				//二次探测
				i++;
				hashaddr += 2 * i + 1;
				//方式一
				hashaddr %= _table.capacity();
			}
		}
		//插入元素
		_table[hashaddr]._date = date;
		_table[hashaddr]._state = EXIST;
		++_size;
		++_total;
		return true;
	}
	int find(const T& date) {
		size_t hashaddr = hashfunc(date);
		while (_table[hashaddr]._state != EMPTY) {
			if (_table[hashaddr]._state == EXIST && _table[hashaddr]._date == date) {
				return hashaddr;
			}
			hashaddr++;
			if (hashaddr == _table.capacity()) {
				hashaddr = 0;
			}
		}
		return -1;
	}
	bool erase(const T& date) {
		int pos = find(date);
		if (pos == -1) {
			return false;
		}
		_table[pos]._state = DELETE;
		_size--;
		return true;
	}
	void swap(hashtable<T, DF, isline>& ht) {
		_table.swap(ht._table);
		std::swap(_size, ht._size);
	}
private:
	void checkcapacity() {
		if (_total*10 / _table.capacity() >= 7) {
			//扩容方式：将元素重新哈希函数确定位置！然后插入新空间
			//1.新创建一个哈希表
			hashtable<T, DF, isline> newHt(Getnextprime(_table.capacity()));
			//插入元素
			for (auto e : _table) {
				if (e._state == EXIST) {
					newHt.insert(e._date);
				}
			}
			swap(newHt);

		}
	}
	size_t hashfunc(const T& date) {
		
		return DF()(date) % _table.capacity();
	}
	std::vector<Elem<T>> _table;
	size_t _size;
	size_t _total;

};
void test() {
	/*int array[] = { 21,67,112,99,5,13,44 };
	hashtable<int,false> ht;
	for (auto e : array) {
		ht.insert(e);
	}
	std::cout<< ht.find(13)<<"\n";
	ht.erase(13);
	std::cout<<ht.find(13);*/
}
void test2(){
	hashtable<std::string, DFstr, false> ht;
	ht.insert("1111");
	ht.insert("2222");
	ht.insert("3333");
	ht.insert("4444");
}
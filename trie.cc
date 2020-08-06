#include "trie.h"
#include <string>
#include <iostream>
using namespace std;

TrieNode::TrieNode(){
	size = 1;
	words = 0;
	isWord = false;
	letters = new TrieNode*[NUM_CHARS];
	for (int i = 0; i < NUM_CHARS; i++){
		letters[i] = nullptr;
	}
}	

TrieNode::~TrieNode(){
	size = 1;
	words = 0;
	isWord = false;
	if(letters){
		for( int i = 0; i < NUM_CHARS; i++){
			delete letters[i];
		}	
	}
	delete [] letters;
}

TrieNode::TrieNode( const TrieNode & other ){
	size = other.size;
	words = other.words;
	isWord = other.isWord;
	letters = new TrieNode*[NUM_CHARS];
	for (int i = 0; i < NUM_CHARS; i++){
		if(other.letters[i]){
			letters[i]  = new TrieNode(*other.letters[i]);
		}
	}
}

TrieNode::TrieNode( TrieNode && other ){
	size = other.size;
	words = other.words;
	isWord = other.isWord;
/*	if(letters){
		for( int i = 0; i < NUM_CHARS; i++){
                	delete letters[i];
        	}
	}	
        delete [] letters;*/
	letters = other.letters;
	other.letters = nullptr;
}

TrieNode & TrieNode::operator=( const TrieNode & other ){
	if(this == &other) return *this;
	size = other.size;
        words = other.words;
        isWord = other.isWord;
//        letters = new TrieNode*[NUM_CHARS];
        if(letters){
                for( int i = 0; i < NUM_CHARS; i++){
                        delete letters[i];
                }
        }
//        delete [] letters;
        for (int i = 0; i < NUM_CHARS; i++){
                if(other.letters[i]){
                        letters[i] = new TrieNode(*other.letters[i]);
                }
        }
	return *this;
}

void TrieNode::swap(TrieNode & other){
	std::swap(size, other.size);
	std::swap(words, other.words);
	std::swap(isWord, other.isWord);
	std::swap(letters, other.letters);
}

TrieNode & TrieNode::operator=( TrieNode && other ){
	if(this == &other) return *this;
	swap(other);
	return *this;
}

void TrieNode::insert( const std::string & word ){
	if(this->member( word )) return;
	TrieNode * cur = this;
	for (std::string::size_type i = 0; i < word.size(); ++i){
		int ind = word[i] - 'a';
		if(!cur->letters[ind]){
			cur->letters[ind] = new TrieNode();
		}
		cur->words++;
		cur = cur->letters[ind];
	}
	cur->words++;
	cur->isWord = true;		
//	this->updateSize();
}

void TrieNode::updateSize(){
	//if(!letters) return;
	int s = 1;
//	cout<<0<<endl;
	for(int i = 0; i < NUM_CHARS; i++){
		if(letters[i]){
			letters[i]->updateSize();
			s+=letters[i]->size;	
		}
	}
//	cout<<1<<endl;
	size = s;
}

bool TrieNode::member( const std::string & word ){
	TrieNode * cur = this;
        for (std::string::size_type i = 0; i < word.size(); ++i){
                int ind = word[i] - 'a';
                if(!cur->letters[ind]){
                        return false;
                }
                cur = cur->letters[ind];
        }
	return cur->isWord;
}

void TrieNode::remove( const std::string & word ){
	if(!this->member( word )) {
		return;
	};
	TrieNode * cur = this;
        for (std::string::size_type i = 0; i < word.size(); ++i){
                int ind = word[i] - 'a';
               	cur->words--;
                cur = cur->letters[ind];
        }
	cur->isWord = false;
	cur->words--;
}

std::string TrieNode::find( const std::string & word ){
	TrieNode * cur = this;
	for (std::string::size_type i = 0; i < word.size(); ++i){
		int ind = word[i] - 'a';
		if(!cur->letters[ind]) return "";
		cur = cur->letters[ind];
	}
	string temp = word;
	string arg = "";
	arg =  cur->fHelper( temp, arg );
	if(arg.empty()) return arg;
	return arg.substr(0, arg.size()-1);
}

std::string TrieNode::fHelper( std::string & word, std::string res ){
	if(isWord){
		res += word;
		res.push_back(' ');
	}
	for ( int i = 0; i < NUM_CHARS; i++ ){
		if(letters[i]){
			string temp = word;
                	temp.push_back('a'+i);
                	res = letters[i]->fHelper( temp, res );
		}
	}
	return res;
}
int TrieNode::getSize() const{
	return size;
}

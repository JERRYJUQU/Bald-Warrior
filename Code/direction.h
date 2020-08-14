#include <iostream>
enum class Direction { no,so,ea,we,ne,nw,se,sw,COUNT };
static std::string dirtos(Direction dir){
  switch(dir){
    case Direction::no: return "no";
    case Direction::so: return "so";
    case Direction::ea: return "ea";
    case Direction::we: return "we";
    case Direction::ne: return "ne";
    case Direction::nw: return "nw";
    case Direction::se: return "se";
    case Direction::sw: return "sw";
  }
}

static Direction stodir(std::string s){
  if(s == "no"){
    return Direction::no;
  }else if(s == "so"){
    return Direction::so;
  }else if(s == "ea"){
    return Direction::ea;
  }else if(s == "we"){
    return Direction::we;
  }else if(s == "ne"){
    return Direction::ne;
  }else if(s == "nw"){
    return Direction::nw;
  }else if(s == "se"){
    return Direction::se;
  }else{
    return Direction::sw;
  }
}

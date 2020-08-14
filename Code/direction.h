#include <iostream>
enum class Direction { no,so,ea,we,ne,nw,se,sw,COUNT };
static std::string dirtos(Direction dir){
  switch(dir){
    case Direction::no: return "North";
    case Direction::so: return "South";
    case Direction::ea: return "East";
    case Direction::we: return "West";
    case Direction::ne: return "North East";
    case Direction::nw: return "North West";
    case Direction::se: return "South East";
    case Direction::sw: return "South West";
    case Direction::COUNT: return "";
    default: return "";
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

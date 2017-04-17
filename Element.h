#ifndef ELEMENT_H
#define ELEMENT_H
#include <climits>

class Element{
private:
  static int count, maxKey, minKey, range;
  int key, relposition;
  double width, height, absposition;
  int getRange(){
    return maxKey-minKey;
  }
public:
  Element(int key) : key(key), relposition(count++){
    if(key > maxKey){
      maxKey = key;
    }else if(key < minKey){
      minKey = key;
    }
  }
  int getKey(){
    return key;
  }
  void setKey(int key){
    this->key = key;
  }
  void initDims(double nonwhitespace){
    range = maxKey - minKey;
    width = 1.98 / count * nonwhitespace;
    height = (key / range) * 1.98;
    absposition = relposition * (width / nonwhitespace);
  }
  double getWidth(){
    return width;
  }
  double getHeight(){
    return height;
  }

};
int Element::count = 0;
int Element::maxKey = INT_MIN;
int Element::minKey = INT_MAX;


#endif

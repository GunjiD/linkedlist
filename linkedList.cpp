#include <iostream>
#include <iterator>
#include <ostream>
#include <string>

class linkedList {

public:
  struct Node {
    int data;
    Node *next_ptr;
  };

private:
  // 単方向リストの宣言
  Node *node;

public:
  // 実体を持たないので nullptr で初期化
  linkedList() { node = nullptr; }

  ~linkedList() {}

  void appendElement(int data);
  void insertElement(int data);
  void deleteElement(int data);
  void displayList();
};

/*************************************
void appendElement(std::string data)
リストの最後に要素を追加する
1. 新しい要素を作成する
2. リストの最後に新しい要素を追加する
  - リストが空のとき
    - 新しい要素のポインタをセットする
  - そうでないとき
    - リストの最後までループする
    - 新しいノードを最後のノードの参照としてセットする
*************************************/
void linkedList::appendElement(int data) {
  // 新しいノード
  Node *newNode = new Node;
  newNode->data = data;
  newNode->next_ptr = nullptr;
  // 先頭の要素が nullptr ならば先頭に挿入
  if (node == nullptr) {
    std::cout << "先頭に要素を設定します" << std::endl;
    // 先頭のアドレスに
    node = newNode;
    std::cout << node->data << std::endl;
  } else {
    Node *tailNode = node;
    // next_ptr が null になるまで進む
    while (tailNode->next_ptr != nullptr)
      tailNode = tailNode->next_ptr;
    tailNode->next_ptr = newNode;
    std::cout << "tailNode の値は = " << tailNode->data << std::endl;
    std::cout << "next_ptr の値は = " << tailNode->next_ptr << std::endl;
  }
  //  displayList();
}

void linkedList::insertElement(int) {}
void linkedList::deleteElement(int) {}

/*************************************
void linkedList::displayList() const
*************************************/
void linkedList::displayList() {
  Node *findNode = node;
  std::cout << "***現在のリスト***" << std::endl;

  while (findNode->next_ptr != nullptr) {
    std::cout << findNode->data << std::endl;
    findNode = findNode->next_ptr;
  }
  std::cout << findNode->data << std::endl;
  std::cout << "***リスト表示完了***" << std::endl;
}

int main() {
  linkedList lists;
  lists.appendElement(1);
  lists.appendElement(2);
  lists.appendElement(3);
  lists.appendElement(4);
  lists.displayList();
  std::cout << "実行終了" << std::endl;
}
